#include "res_login.h"

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Res_Login::RES_LOGIN = "res_login";

Res_Login::Res_Login(std::string user_name): Event("Res_Login", RES_LOGIN) {
}