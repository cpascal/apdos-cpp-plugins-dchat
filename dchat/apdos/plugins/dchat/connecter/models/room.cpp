#include "room.h"
#include <apdos/plugins/uuid/null_object_id.h>

using namespace apdos::plugins::dchat_connecter::models;
using namespace apdos::plugins::uuid;

Room::Room(Object_Id id, int num, std::string name, int user_count, int max_user_count) {
  this->id = id;
  this->num = num;
  this->name = name;
  this->user_count = user_count;
  this->max_user_count = max_user_count;
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

int Room::get_user_count() {
  return this->user_count;
}

int Room::get_max_user_count() {
  return this->max_user_count;
}

void Room::increase_user_count() {
  this->user_count++;
}

void Room::decrease_user_count() {
  this->user_count--;
  if (this->user_count < 0)
    this->user_count = 0;
}