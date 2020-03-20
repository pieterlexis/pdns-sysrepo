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

#include <sysrepo-cpp/Session.hpp>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {
  try {
    sysrepo::S_Connection conn(new sysrepo::Connection());
    auto sess = std::make_shared<sysrepo::Session>(conn);
    cout << "switching DS to operational" << endl;
    sess->session_switch_ds(SR_DS_OPERATIONAL);
    cout << "Setting some data" << endl;
    sess->set_item_str("/pdns-server:pdns-server/listen-address[name='foo']/ip-address", "192.0.2.1");
    cout << "Calling validate" << endl;
    try {
      sess->validate();
      cout << "Calling apply_changes" << endl;
      sess->apply_changes();
    }
    catch (const sysrepo::sysrepo_exception& e) {
      cout << "Sysrepo error:" << endl;
      auto errors = sess->get_error();
      for (size_t i = 0; i < errors->error_cnt(); i++) {
        string xpath = errors->xpath(i) == nullptr ? "" : errors->xpath(i);
        string message = errors->message(i) == nullptr ? "" : errors->message(i);
        cout << "  xpath='" << xpath << "' message='" << message << "'" << endl;
      }
      return 1;
    }
  }
  catch (const std::exception& e) {
    cout << e.what() << endl;
    return 1;
  }
}