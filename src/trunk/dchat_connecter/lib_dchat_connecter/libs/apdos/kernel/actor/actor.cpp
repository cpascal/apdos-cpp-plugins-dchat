#include <libs/apdos/kernel/kernel.h>
#include "actor.h"
#include "null_actor.h"

using namespace apdos::kernel::actor;

Actor::Actor(std::string path) {
  this->path = path;
}

Actor::~Actor() {
}

void Actor::dispatch_event(apdos::kernel::event::Event& event) {
  Event_Dispatcher::dispatch_event(event);
  std::vector<boost::shared_ptr<Component> >::iterator iter;
  for (iter = components.begin(); iter != components.end(); ++iter) {
    (*iter)->dispatch_event(event);
  }
}

boost::shared_ptr<Actor> Actor::lookup(std::string path) {
  boost::shared_ptr<Node> node = Kernel::get_instance()->lookup(path);
  if (node->is_null()) {
    return boost::shared_ptr<Null_Actor>(new Null_Actor(""));
  }
  boost::shared_ptr<Actor> actor = boost::dynamic_pointer_cast<Actor>(node);
  if (actor == 0)
    return boost::shared_ptr<Null_Actor>(new Null_Actor(""));
  return actor;
}
