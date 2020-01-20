/**
 * Copyright Pieter Lexis <pieter.lexis@powerdns.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "remote-backend.hh"
#include "iputils/iputils.hh"

namespace pdns_sysrepo::remote_backend
{
void RemoteBackend::getUnfreshSlaveInfos(const Pistache::Rest::Request& request, Http::ResponseWriter response) {
  logRequest(request);
  auto session = getSession();
  libyang::S_Data_Node zonesNode;
  try {
    zonesNode = getZoneTree(session);
    zonesNode = zonesNode->child();
    if (!zonesNode) {
      throw std::out_of_range("No zones defined");
    }
  }
  catch (const std::exception& e) {
    sendResponse(request, response, nlohmann::json({{"result", false}, {"log", nlohmann::json::array({e.what()})}}));
    return;
  }

  time_t now = time(nullptr);
  nlohmann::json::array_t allZones;
  for (auto const& zone : zonesNode->tree_for()) {
    auto zoneNode = zone->child(); // /pdns-server:zones/zones[name]/name
    nlohmann::json domainInfo;
    string zoneName;

    auto zoneNameLeaf = std::make_shared<libyang::Data_Node_Leaf_List>(zoneNode);
    zoneName = zoneNameLeaf->value_str();

    auto zonetypeXPath = fmt::format("/pdns-server:zones/zones[name='{}']/zonetype", zoneName);
    auto zonetypeLeaf = std::make_shared<libyang::Data_Node_Leaf_List>(zoneNode->find_path(zonetypeXPath.c_str())->data().at(0));
    if (std::string(zonetypeLeaf->value_str()) != "slave") {
      continue;
    }

    domainInfo["zone"] = zoneName;
    domainInfo["kind"] = "slave";

    auto domainId = getDomainID(zoneName);
    domainInfo["id"] = domainId;

    nlohmann::json::array_t masters;
    auto zoneMastersXPath = fmt::format("/pdns-server:zones/zones[name='{}']/masters", zoneName);
    auto zoneMastersNode = zoneNode->find_path(zoneMastersXPath.c_str());
    for (auto const &zoneMasterNode : zoneMastersNode->data()) {
      auto masterNameLeaf = std::make_shared<libyang::Data_Node_Leaf_List>(zoneMasterNode);
      auto masterXPath = fmt::format("/pdns-server:master-endpoint[name='{}']", masterNameLeaf->value_str());
      auto masterNode = session->get_subtree(masterXPath.c_str());
      for (auto const &masterAddressNode : masterNode->find_path("/pdns-server:master-endpoint/address")->data()) {
        auto n = masterAddressNode->child()->next(); // /pdns-server/master-endpoint[name]/address[name]/ip-address
        auto addrLeaf = std::make_shared<libyang::Data_Node_Leaf_List>(n);
        n = n->next(); // /pdns-server:master-endpoint[name]/address[name]/port
        auto portLeaf = std::make_shared<libyang::Data_Node_Leaf_List>(n);
        iputils::ComboAddress a(addrLeaf->value_str(), portLeaf->value()->uint16());
        masters.push_back(a.toStringWithPort());
      }
    }
    domainInfo["masters"] = masters;

    auto refreshXPath = fmt::format("/pdns-server:zones/zones[name='{}']/rrset-state[owner='{}'][type='SOA']/rdata/SOA/refresh", zoneName, zoneName);
    libyang::S_Data_Node zoneSOARefreshNode;
    try {
      zoneSOARefreshNode = zone->find_path(refreshXPath.c_str())->data().at(0);
    } catch (const std::out_of_range &e) {
      domainInfo["last_check"] = 0;
      domainInfo["serial"] = 0;
      allZones.push_back(domainInfo);
      continue;
    }

    auto zoneSOARefresh = std::make_shared<libyang::Data_Node_Leaf_List>(zoneSOARefreshNode)->value()->uintu32();
    uint32_t lastCheck = 0;
    auto freshnessCheckedIt = d_slaveFreshnessChecks.find(domainId);
    if (freshnessCheckedIt != d_slaveFreshnessChecks.end()) {
      lastCheck = freshnessCheckedIt->second;
    }
    domainInfo["last_check"] = lastCheck;

    if (now + zoneSOARefresh > lastCheck) {
      allZones.push_back(domainInfo);
    }
  }
  nlohmann::json ret = {{"result", allZones}};
  sendResponse(request, response, ret);
}
} // namespace pdns_sysrepo::remote_backend