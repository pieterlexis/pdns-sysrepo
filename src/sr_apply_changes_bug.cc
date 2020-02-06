#include <libyang/Libyang.hpp>
#include <sysrepo-cpp/Sysrepo.hpp>
#include <sysrepo-cpp/Session.hpp>

void print_errors(sysrepo::S_Session &sess) {
    auto errors = sess->get_error();
    for (size_t i = 0; i < errors->error_cnt(); i++) {
      std::string xpath = errors->xpath(i) == nullptr ? "" : errors->xpath(i);
      std::string message = errors->message(i) == nullptr ? "" : errors->message(i);
      std::cout<<"  xpath='"<<xpath<<"' message='"<<message<<"'"<<std::endl;
    }
}

int main() {
    sysrepo::S_Connection conn(new sysrepo::Connection());
    sysrepo::S_Session sess(new sysrepo::Session(conn, SR_DS_RUNNING));

    std::string config_json = R"XXX(
        {
            "sr-apply-changes:foo": {
                "rrset-state": [
                    {
                        "owner": "owner",
                        "type": "type",
                        "ttl": 3600,
                        "rdata": {
                            "SOA": {
                                "mname": "mname",
                                "rname": "rname",
                                "serial": 12
                            }
                        }
                    }
                ]
            }
        }
    )XXX";

    sess->session_switch_ds(SR_DS_OPERATIONAL);
    auto ctx = sess->get_context();
    auto node = ctx->parse_data_mem(config_json.c_str(), LYD_JSON, LYD_OPT_DATA_NO_YANGLIB);

    try {
      sess->edit_batch(node, "replace");
    } catch(const sysrepo::sysrepo_exception &e) {
        std::cout<<"Error in edit_batch: "<< e.what() <<std::endl;
        print_errors(sess);
        return 1;
    }
    try {
        sess->validate();
    } catch(const sysrepo::sysrepo_exception &e) {
        std::cout<<"Error in validate: "<< e.what() <<std::endl;
        print_errors(sess);
        return 1;
    }
    try {
      sess->apply_changes(); // This fails
    } catch(const sysrepo::sysrepo_exception &e) {
        std::cout<<"Error in apply_changes: "<< e.what() <<std::endl;
        print_errors(sess);
        return 1;
    }
    sess.reset();
    return 0;
}