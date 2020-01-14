/*
 * Copyright 2019-2020 Pieter Lexis <pieter.lexis@powerdns.com>
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
#include <vector>
#include <sysrepo-cpp/Session.hpp>

using namespace std;

namespace sr
{
class Session : public sysrepo::Session
{
public:
  Session(sysrepo::S_Connection conn, sr_datastore_t datastore = (sr_datastore_t)sysrepo::DS_RUNNING) :
    sysrepo::Session(conn, datastore) {};
  ~Session();

  /*
   * Returns the LibYANG datanode rooted at '/pdns-server:pdns-server'
  */
  libyang::S_Data_Node getConfigTree(uint32_t timeout_ms = 0);

  /**
   * @brief Returns all masters for a configured zone
   * 
   * @param zone 
   * @param timeout_ms 
   * @return vector<string> 
   */
  vector<string> getZoneMasters(const string &zone, uint32_t timeout_ms = 0);
};
} // namespace sr
