#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_RES_ADD_ROOM_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_RES_ADD_ROOM_H

#include <iostream>
#include <apdos/kernel/event/event.h>
#include <vector>
#include <map>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      class Res_Add_Room: public apdos::kernel::event::Event {
      public:
        static const char* RES_ADD_ROOM;

      public:
        Res_Add_Room();

        std::string get_room_id();
        std::string get_room_type();
        std::string get_room_name();
        int get_room_max_user_count();
      };
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_RES_ADD_ROOM_H