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
#pragma once

#include <sysrepo-cpp/Session.hpp>
#include <spdlog/spdlog.h>
#include <sdbusplus/message.hpp>

#include "configurator.hh"
#include "config.h"

#include "ApiClient.h"

using std::map;
using std::shared_ptr;
using std::string;
using std::vector;
using std::make_shared;
namespace pdns_api = org::openapitools::client::api;

namespace pdns_conf
{
class ZoneCB : public sysrepo::Callback
{
  public:
  ZoneCB(const string &url, const string &passwd) : sysrepo::Callback() {
    spdlog::trace("Creating ZoneCB url={}, password={}", url, passwd);
    std::shared_ptr<pdns_api::ApiConfiguration> apiConfig(new pdns_api::ApiConfiguration);
    apiConfig->setBaseUrl("http://" + url + "/api/v1");
    apiConfig->setApiKey("X-API-Key", passwd);
    apiConfig->setUserAgent("pdns-sysrepo/" + string(VERSION));
    d_apiClient = make_shared<pdns_api::ApiClient>(pdns_api::ApiClient(apiConfig));
    d_apiClient->setConfiguration(apiConfig);
    spdlog::trace("Done creating ZoneCB");
  };
  ~ZoneCB(){};

  /**
   * @brief Callback called when an application is requesting operational or config data
   * 
   * @see sysrepo::Callback::oper_get_items
   * 
   * @param session 
   * @param module_name 
   * @param path 
   * @param request_xpath 
   * @param request_id 
   * @param parent 
   * @param private_data 
   * @return int 
   */
  int oper_get_items(sysrepo::S_Session session, const char* module_name,
    const char* path, const char* request_xpath,
    uint32_t request_id, libyang::S_Data_Node& parent, void* private_data) override;

  void setApiKey(const string &apiKey);

  private:
  shared_ptr<pdns_api::ApiClient> d_apiClient;
};

class ServerConfigCB : public sysrepo::Callback
{
public:
/**
 * @brief Construct a new ServerConfigCB object
 * 
 * This class implements the sysrepo::Callback specifically for the
 * PowerDNS Authoritative Server. An instance of this should be used in
 * a sysrepo::Subscribe, it then receives the changes in the datastore.
 * Please use pdns_conf::getServerConfigCB to create an instance.
 * 
 * @param privData  Data that the functions can use
 */
  ServerConfigCB(const map<string, string>& privData) :
    sysrepo::Callback(),
    privData(privData){};
  ~ServerConfigCB(){};


  /**
   * @brief Callback for when data in a module changes.
   * 
   * @see sysrepo::Callback::module_change
   * 
   * @param session 
   * @param module_name 
   * @param xpath 
   * @param event 
   * @param request_id 
   * @param private_data 
   * @return int 
   */
  int module_change(sysrepo::S_Session session, const char* module_name,
    const char* xpath, sr_event_t event,
    uint32_t request_id, void* private_data) override;

  void setZoneCB(shared_ptr<ZoneCB> &zoneCB) {
    d_zoneCB = zoneCB;
  };

private:
  /**
   * @brief Return a file path to a tempfile
   * 
   * @param request_id  A number that should be unique for the
   *                    whole transaction
   * @return string 
   */
  string tmpFile(const uint32_t request_id);

  /**
   * @brief Restarts a systemd service
   * 
   * This function uses the dbus interface to systemd to call the
   * RestartUnit method. It will then wait to see if the restart succeeded.
   * 
   * @param service  The service to restart
   * @throw std::runtime_error  When communication over dbus fails
   */
  void restartService(const string& service);

  /**
   * @brief ZoneCB that will receive APIKey updates
   */
  shared_ptr<ZoneCB> d_zoneCB{nullptr};

  /**
   * @brief Private data that this class can use
   */
  map<string, string> privData;
};

/**
 * @return sysrepo::S_Callback 
 */

/**
 * @brief Get a shared pointer to a ServerConfigCB object
 * 
 * @param fpath                 The path to the PowerDNS Authoritative Server
 *                              configuration file
 * @param serviceName           Name of the PowerDNS service
 * @return std::shared_ptr<ServerConfigCB> 
 */
std::shared_ptr<ServerConfigCB> getServerConfigCB(const string& fpath, const string& serviceName);

/**
 * @brief Get a new ZoneCB object wrapped in a shared_ptr
 * 
 * @param url     Domain name for the API, "http://" wil be prepended, "/api/v1" will be appended
 * @param passwd  The API Key to use
 * @return std::shared_ptr<ZoneCB> 
 */
std::shared_ptr<ZoneCB> getZoneCB(const string &url, const string &passwd);

} // namespace pdns_conf