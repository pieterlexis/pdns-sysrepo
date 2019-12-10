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
#include <stdio.h>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <libyang/Libyang.hpp>
#include <sysrepo-cpp/Sysrepo.hpp>
#include <sysrepo-cpp/Session.hpp>

#include "configurator/configurator.hh"

using std::make_shared;
using std::runtime_error;
using std::cerr;
using std::endl;

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

#define MODULE_NAME "pdns-server"

string yangDir;

libyang::S_Data_Node getBasicConfig() {
  libyang::S_Context ctx = make_shared<libyang::Context>(libyang::Context(yangDir.c_str()));
  auto mod = ctx->load_module(MODULE_NAME);

  libyang::S_Data_Node node = make_shared<libyang::Data_Node>(libyang::Data_Node(ctx, "/pdns-server:pdns-server", nullptr, LYD_ANYDATA_CONSTSTRING, 0));
  return node;
}

libyang::S_Data_Node getMasterConfig() {
  libyang::S_Context ctx = make_shared<libyang::Context>(libyang::Context(yangDir.c_str()));
  auto mod = ctx->load_module(MODULE_NAME);

  libyang::S_Data_Node node = make_shared<libyang::Data_Node>(libyang::Data_Node(ctx, "/pdns-server:pdns-server", nullptr, LYD_ANYDATA_CONSTSTRING, 0));
  libyang::S_Data_Node master(new libyang::Data_Node(node, mod, "master", "true"));
  return node;
}

libyang::S_Data_Node getAllowAxfrConfig() {
  libyang::S_Context ctx = make_shared<libyang::Context>(libyang::Context(yangDir.c_str()));
  auto mod = ctx->load_module(MODULE_NAME);

  libyang::S_Data_Node node = make_shared<libyang::Data_Node>(libyang::Data_Node(ctx, "/pdns-server:pdns-server", nullptr, LYD_ANYDATA_CONSTSTRING, 0));
  libyang::S_Data_Node allow_axfr(new libyang::Data_Node(node, mod, "allow-axfr", "testACL"));

  return node;
}



class TestSession : public sysrepo::Session
{
public:
  TestSession(sysrepo::S_Connection conn, sr_datastore_t datastore = (sr_datastore_t)sysrepo::DS_RUNNING) :
    sysrepo::Session(conn, datastore) {};
  ~TestSession(){} ;

  libyang::S_Data_Node get_subtree(const char* path, uint32_t timeout_ms = 0) {
    string thePath(path);
    std::cout<<"the path is: "<<thePath<<std::endl;
    if (thePath == "/pdns-server:axfr-access-control-list[name='testACL']") {
      libyang::S_Context ctx = make_shared<libyang::Context>(libyang::Context(yangDir.c_str()));
      auto mod = ctx->load_module(MODULE_NAME);
      libyang::S_Data_Node ret = make_shared<libyang::Data_Node>(libyang::Data_Node(ctx, "/pdns-server:axfr-access-control-list[name='testACL']", nullptr, LYD_ANYDATA_DATATREE, 0));
      libyang::S_Data_Node name(new libyang::Data_Node(ret, mod, "name", "testACL"));
      libyang::S_Data_Node network(new libyang::Data_Node(ret, mod, "network"));
      libyang::S_Data_Node n1(new libyang::Data_Node(network, mod, "ip-prefix", "192.0.2.0/25"));
      libyang::S_Data_Node n2(new libyang::Data_Node(network, mod, "ip-prefix", "2001:DB8:22::/64"));
      return ret;
    }
    throw std::runtime_error("Unimplemented path: " + thePath);
  }
};

void testAllBasicsExcept(const string &config, const string &e) {
  if (e != "master") {
    ASSERT_THAT(config, HasSubstr("master = no\n"));
  }
  if (e != "slave") {
    ASSERT_THAT(config, HasSubstr("slave = no\n"));
  }
  if (e != "launch") {
    ASSERT_THAT(config, HasSubstr("launch =\n"));
  }
  if (e != "local-address") {
  ASSERT_THAT(config, HasSubstr("local-address =\n"));
  }
  if (e != "webserver") {
    ASSERT_THAT(config, HasSubstr("webserver = no\n"));
  }
  if (e != "webserver-loglevel") {
    ASSERT_THAT(config, HasSubstr("webserver-loglevel = normal\n"));
  }
  if (e != "allow-axfr-ips") {
    ASSERT_THAT(config, HasSubstr("allow-axfr-ips =\n"));
  }
}

TEST(config_test, empty_config) {
  auto node = getBasicConfig();
  auto configurator = pdns_conf::PdnsServerConfig(node);
  auto config = configurator.getConfig();
  testAllBasicsExcept(config, "none");
}

TEST(config_test, master) {
  auto node = getMasterConfig();
  auto configurator = pdns_conf::PdnsServerConfig(node);
  auto config = configurator.getConfig();
  testAllBasicsExcept(config, "master");
  ASSERT_THAT(config, HasSubstr("master = yes\n"));
}

TEST(config_test, axfr_allow_ips) {
  auto conn = make_shared<sysrepo::Connection>();
  auto sess = make_shared<sysrepo::Session>(conn);
  auto session = std::static_pointer_cast<TestSession>(sess);
  auto node = getMasterConfig();
  auto configurator = pdns_conf::PdnsServerConfig(node, session);
  auto config = configurator.getConfig();
  ASSERT_THAT(config, HasSubstr("allow-axfr-ips += 192.0.2.0/25\n"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  if (argc != 2) {
    cerr<<"Please prove the path to the yang directory"<<endl;
    return 1;
  }
  yangDir = argv[1];
  return RUN_ALL_TESTS();
}