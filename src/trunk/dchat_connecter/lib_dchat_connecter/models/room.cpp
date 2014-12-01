#include "room.h"
#include <libs/apdos/plugins/uuid/null_object_id.h>

using namespace apdos::plugins::dchat_connecter::models;
using namespace apdos::plugins::uuid;

Room::Room(Object_Id id, int num, std::string name) {
  this->id = id;
  this->num = num;
  this->name = name;
}

Room::~Room() {
}

Object_Id Room::get_id() {
  return this->id;
}

int Room::get_num() {
  return this->num;
}

std::string Room::get_name() {
  return this->name;
}