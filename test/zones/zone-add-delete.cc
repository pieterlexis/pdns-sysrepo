#include "test-common.hh"

#include "configurator/subscribe.hh"

#include "callback-wrapper.hh"
#include "api-mock.hh"

/// Server started in main().
static httpmock::TestEnvironment<httpmock::MockServerHolder>* mock_server_env = nullptr;
static std::shared_ptr<pdns_api::ApiClient> apiClient;

TEST(zone_test, modify_zonetype) {
  auto cb = TestServerConfigCB({{}}, apiClient);
  cb.modifyZoneType("example.com.", "master");
  ASSERT_NO_THROW(cb.doDoneZoneModify());
}

TEST(zone_test, add_zone) {
  auto cb = TestServerConfigCB({{}}, apiClient);
  cb.addZone("create.example.com.", "master");
  ASSERT_NO_THROW(cb.doDoneZoneAddAndDelete());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  if (argc != 2) {
    cerr << "Please prove the path to the yang directory" << endl;
    return 1;
  }
  yangDir = argv[1];

  ::testing::Environment* const env = ::testing::AddGlobalTestEnvironment(httpmock::createMockServerEnvironment<PDNSApiMock>(9200));
  mock_server_env = dynamic_cast<httpmock::TestEnvironment<httpmock::MockServerHolder>*>(env);

  std::shared_ptr<pdns_api::ApiConfiguration> apiConfig(new pdns_api::ApiConfiguration);
  apiConfig->setBaseUrl("http://127.0.0.1:" + std::to_string(mock_server_env->getMock()->getPort()) + "/api/v1");
  apiConfig->setApiKey("X-API-Key", APIKEY);
  apiConfig->setUserAgent("pdns-sysrepo/" + string(VERSION));
  apiClient = make_shared<pdns_api::ApiClient>(pdns_api::ApiClient(apiConfig));

  return RUN_ALL_TESTS();
}