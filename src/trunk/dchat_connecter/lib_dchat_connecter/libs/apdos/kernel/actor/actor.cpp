#include "actor.h"

using namespace apdos::kernel::actor;

Actor::Actor(std::string path) {
  this->path = path;
}

Actor::~Actor() {
}
