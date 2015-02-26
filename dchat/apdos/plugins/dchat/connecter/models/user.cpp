#include "user.h"
#include <apdos/plugins/uuid/null_object_id.h>

using namespace apdos::plugins::dchat_connecter::models;
using namespace apdos::plugins::uuid;

User::User(Object_Id_Shared_Ptr id, std::string name): room_id(Object_Id_Shared_Ptr(new Null_Object_Id())) {
  this->id = id;
  this->name = name;
}

Object_Id_Shared_Ptr User::get_id() {
  return this->id;
}

std::string User::get_name() {
  return this->name;
}

void User::join_room(Object_Id_Shared_Ptr room_id) {
  this->room_id = room_id;
}

void User::leave_room() {
  this->room_id = Object_Id_Shared_Ptr(new Null_Object_Id());
}

Object_Id_Shared_Ptr User::get_room_id() {
  return this->room_id;
}