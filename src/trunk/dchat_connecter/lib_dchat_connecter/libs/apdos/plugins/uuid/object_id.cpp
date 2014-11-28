#include "object_id.h"

using namespace apdos::plugins::uuid;

Object_Id::Object_Id(std::string id) {
  this->id = id;
}

Object_Id::~Object_Id() {
}

bool Object_Id::operator==(Object_Id id) {
  return 0 == this->id.compare(id.id);
}