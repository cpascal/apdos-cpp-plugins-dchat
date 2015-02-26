#include "req_logout.h"
#include <boost/any.hpp>

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Req_Logout::REQ_LOGOUT = "req_logout";

Req_Logout::Req_Logout(): Event("Req_Logout", REQ_LOGOUT) {
}