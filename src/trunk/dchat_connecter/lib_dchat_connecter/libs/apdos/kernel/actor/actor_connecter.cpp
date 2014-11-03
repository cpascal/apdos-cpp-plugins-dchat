#include "actor_connecter.h"
#include <libs/apdos/kernel/actor/events/proxy_event.h>
#include <string>

using namespace apdos::kernel::actor;
using namespace apdos::kernel::actor::events;
using namespace apdos::kernel::event;

Actor_Connecter::Actor_Connecter() : Component() {
}

void Actor_Connecter::send_by_path(std::string sender_path, std::string receiver_path, Event event) {
  Proxy_Event proxy_event(sender_path, receiver_path, event);
  std::cout << Event::serialzie(proxy_event) << std::endl;
}
