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

    sess->session_switch_ds(SR_DS_OPERATIONAL);

    sess->set_item_str("/sr-apply-changes:foo/rrset-state[owner='owner'][type='type']/ttl", "1200");
    sess->set_item_str("/sr-apply-changes:foo/rrset-state[owner='owner'][type='type']/rdata/NS/nsdname", "name1");
    // sess->set_item_str("/sr-apply-changes:foo/rrset-state[owner='owner'][type='type']/rdata/NS/nsdname", "name2");
    try {
      sess->apply_changes();
    } catch(const sysrepo::sysrepo_exception &e) {
        std::cout<<"Error in apply_changes: "<< e.what() <<std::endl;
        print_errors(sess);
        return 1;
    }
    sess.reset(); // Close the session

    return 0;
}