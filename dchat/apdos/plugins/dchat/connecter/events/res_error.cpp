#include "res_error.h"

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Res_Error::RES_ERROR = "res_error";

Res_Error::Res_Error(): Event("Res_Error", RES_ERROR) {
}

int Res_Error::get_error_code() {
  boost::shared_ptr<std::map<std::string, boost::any> > data = this->get_data();
  std::map<std::string, boost::any>& map = *data.get();
  return boost::any_cast<int>(map["error_code"]);
}

std::string Res_Error::get_error_message() {
  boost::shared_ptr<std::map<std::string, boost::any> > data = this->get_data();
  std::map<std::string, boost::any>& map = *data.get();
  return boost::any_cast<std::string>(map["error_message"]);
}