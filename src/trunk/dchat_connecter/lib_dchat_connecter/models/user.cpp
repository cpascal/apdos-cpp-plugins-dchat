#include "user.h"
#include <libs/apdos/plugins/uuid/null_object_id.h>

using namespace apdos::plugins::dchat_connecter::models;
using namespace apdos::plugins::uuid;

User::User(Object_Id id, std::string name): room_id(Null_Object_Id()) {
  this->id = id;
  this->name = name;
}

Object_Id User::get_id() {
  return this->id;
}

std::string User::get_name() {
  return this->name;
}

void User::join_room(apdos::plugins::uuid::Object_Id room_id) {
  this->room_id = room_id;
}

void User::leave_room() {
  this->room_id = Null_Object_Id();
}

apdos::plugins::uuid::Object_Id User::get_room_id() {
  return this->room_id;
}