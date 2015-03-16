#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_REQ_ADD_ROOM_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_REQ_ADD_ROOM_H

#include <iostream>
#include <apdos/kernel/event/event.h>

namespace apdos {
	namespace plugins {
    namespace dchat_connecter {
      class Req_Add_Room: public apdos::kernel::event::Event {
      public:
        static const char* REQ_ADD_ROOM;

      public:
        Req_Add_Room(std::string room_type, std::string room_name);
      };
    }
	}
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_REQ_ADD_ROOM_H