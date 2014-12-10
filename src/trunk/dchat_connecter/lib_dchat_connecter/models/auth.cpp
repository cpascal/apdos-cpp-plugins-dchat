#include "auth.h"

using namespace apdos::plugins::dchat_connecter::models;

Auth::Auth() {
  boost::shared_ptr<Null_User> null_user(new Null_User());
  this->user = boost::dynamic_pointer_cast<User>(null_user);
}

Auth::~Auth() {
}