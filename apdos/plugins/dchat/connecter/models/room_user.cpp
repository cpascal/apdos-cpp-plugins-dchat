#include "room_user.h"
#include <libs/apdos/plugins/uuid/null_object_id.h>

using namespace apdos::plugins::dchat_connecter::models;
using namespace apdos::plugins::uuid;

Room_User::Room_User(Object_Id id, std::string name) {
  this->id = id;
  this->name = name;
}

Object_Id Room_User::get_id() {
  return this->id;
}

std::string Room_User::get_name() {
  return this->name;
}