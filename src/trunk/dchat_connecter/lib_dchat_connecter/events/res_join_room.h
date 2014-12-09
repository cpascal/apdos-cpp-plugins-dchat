#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_RES_JOIN_ROOM_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_RES_JOIN_ROOM_H

#include <iostream>
#include <libs/apdos/kernel/event/event.h>
#include <vector>
#include <map>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      class Res_Join_Room: public apdos::kernel::event::Event {
      public:
        static const char* RES_JOIN_ROOM;

      public:
        Res_Join_Room();

        std::string get_user_id();
        std::string get_user_name();
        std::string get_room_id();
        std::string get_room_name();
        int get_users_count();
      };
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_RES_JOIN_ROOM_H