#include "req_login.h"
#include <boost/any.hpp>
#include <events/test.h>

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Req_Login::REQ_LOGIN = "req_login";

Req_Login::Req_Login(std::string user_name): Event("Req_Login", REQ_LOGIN) {
  boost::shared_ptr<std::map<const char*, boost::any>> data(new std::map<const char*, boost::any>());
  data->insert(std::make_pair("user_name", boost::any(user_name)));
  this->set_data(data);
}