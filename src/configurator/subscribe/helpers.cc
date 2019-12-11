/*
 * Copyright 2019 Pieter Lexis <pieter.lexis@powerdns.com>
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
#include "../subscribe.hh"
#include "ZonesApi.h"
#include "../util.hh"

namespace pdns_conf
{
string ServerConfigCB::getZoneId(const string& zone) {
  pdns_api::ZonesApi zonesApiClient(d_apiClient);

  auto zones = zonesApiClient.listZones("localhost", zone).get();
  if (zones.size() != 1) {
    throw runtime_error(fmt::format("API returned the wrong number of zones ({}) for '{}', expected 1", zones.size(), zone));
  }
  return zones.at(0)->getId();
}

void ServerConfigCB::configureApi(const libyang::S_Data_Node &node) {
  spdlog::trace("Reconfiguring API Client");
  auto apiConfig = make_shared<pdns_api::ApiConfiguration>();

  try {
    auto apiKeyNode = node->find_path("/pdns-server:pdns-server/webserver/api-key")->data().at(0);
    apiConfig->setApiKey("X-API-Key", make_shared<libyang::Data_Node_Leaf_List>(apiKeyNode)->value_str());
    auto addressNode = node->find_path("/pdns-server:pdns-server/webserver/address")->data().at(0);
    auto portNode = node->find_path("/pdns-server:pdns-server/webserver/port")->data().at(0);
    ComboAddress ws(string(make_shared<libyang::Data_Node_Leaf_List>(addressNode)->value_str()), make_shared<libyang::Data_Node_Leaf_List>(portNode)->value()->uint16());
    apiConfig->setBaseUrl("http://" + ws.toStringWithPort() + "/api/v1");
    spdlog::debug("API Client config set to: API-Key={}, URL={}", apiConfig->getApiKey("X-API-Key"), apiConfig->getBaseUrl());
  }
  catch (const out_of_range &e) {
    // ignore, We implicitly disable the API with the "wrong" config
    spdlog::debug("API is disabled in config, client will reflect this");
  }

  apiConfig->setUserAgent("pdns-sysrepo/" + string(VERSION));
  d_apiClient->setConfiguration(apiConfig);
  spdlog::trace("API Client reconfigured");
}

vector<string> ServerConfigCB::getAclAddresses(const libyang::S_Data_Node &node, const sysrepo::S_Session &session) {
  spdlog::trace("");
  if (node->schema()->nodetype() != LYS_LEAFLIST) {
    throw std::runtime_error(fmt::format("Node is not a leaf-list but a {}", util::libyangNodeType2String(node->schema()->nodetype())));
  }
  if (session == nullptr) {
    throw std::runtime_error("Session cannot be null");
  }

  vector<string> ret;

  string nodeName(node->schema()->name());
  auto child = node;
  while (child && string(child->schema()->name()) == nodeName) {
    auto leaf = make_shared<libyang::Data_Node_Leaf_List>(child);
    auto aclNode = session->get_subtree(fmt::format("/pdns-server:axfr-access-control-list[name='{}']", leaf->value_str()).c_str());
    if (aclNode) {
      for (auto const networkNode : aclNode->find_path("/pdns-server:axfr-access-control-list/pdns-server:network/pdns-server:ip-prefix")->data()) {
        auto networkLeaf = make_shared<libyang::Data_Node_Leaf_List>(networkNode);
        // spdlog::trace("Have ACL leafref target path={} name={} type={} value={}", networkNode->path(), networkNode->schema()->name(), util::libyangNodeType2String(networkNode->schema()->nodetype()), networkLeaf->value_str());
        ret.push_back(networkLeaf->value_str());
      }
    }
    child = child->next();
  }
  return ret;
}
} // namespace pdns_conf