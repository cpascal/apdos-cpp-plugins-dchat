#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_ADD_ROOM_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_ADD_ROOM_H

#include <iostream>
#include <apdos/kernel/event/event.h>
#include <vector>
#include <map>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      class Notify_Add_Room: public apdos::kernel::event::Event {
      public:
        static const char* NOTIFY_ADD_ROOM;

      public:
        Notify_Add_Room();

        std::string get_room_id();
        std::string get_room_name();
      };
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_ADD_ROOM_H