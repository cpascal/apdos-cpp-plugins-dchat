#include "actor.h"

using namespace apdos::kernel::actor;

Actor::Actor(std::string path) {
  this->path = path;
}

Actor::~Actor() {
}

void Actor::dispatch_event(apdos::kernel::event::Event& event) {
  std::vector<boost::shared_ptr<Component>>::iterator iter;
  for (iter = components.begin(); iter != components.end(); ++iter) {
    (*iter)->dispatch_event(event);
  }
}
