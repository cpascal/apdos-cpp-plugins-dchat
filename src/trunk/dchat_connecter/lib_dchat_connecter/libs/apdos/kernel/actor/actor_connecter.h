#ifndef APDOS_KERNEL_ACTOR_ACTOR_CONNECTER_H
#define APDOS_KERNEL_ACTOR_ACTOR_CONNECTER_H

#include <iostream>
#include <libs/apdos/kernel/actor/component.h>
#include <libs/apdos/kernel/event/event.h>

namespace apdos {
  namespace kernel {
    namespace actor {
      class Actor_Connecter: public Component {
      public:
        Actor_Connecter();

        void send_by_path(std::string sender_path, std::string receiver_path, apdos::kernel::event::Event event);
      };
    }
  }
}

#endif //APDOS_KERNEL_ACTOR_ACTOR_CONNECTER_H