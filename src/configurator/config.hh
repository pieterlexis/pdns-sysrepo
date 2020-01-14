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
#include <string>

using std::string;

namespace pdns_conf
{
class Config
{
public:
  /**
   * @brief Construct a new Config object
   * 
   * This Config object contains the configuration of the pdns-sysrepo
   * progam.
   * 
   * @param fpath  The path to the YAML configuration file to read
   * @throw std::runtime_error  When the file cannot be read or parsed
   */
  Config(string fpath);

  /**
   * @brief Get the path to the PowerDNS Authoritative Server config file
   * 
   * @return string 
   */
  string getPdnsConfigFilename() { return d_pdns_conf; };

  /**
   * @brief Get the name of the PowerDNS service
   * 
   * @return string
   */
  string getServiceName() { return d_pdns_service; };

private:
  string d_config_path;
  string d_pdns_service = "pdns.service";
  string d_pdns_conf = "/etc/powerdns/pdns.conf.d/sysrepo.conf";
};
} // namespace pdns_conf