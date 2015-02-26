#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_REQ_JOIN_ROOM_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_REQ_JOIN_ROOM_H

#include <iostream>
#include <apdos/kernel/event/event.h>
#include <apdos/plugins/uuid/object_id.h>

namespace apdos {
	namespace plugins {
    namespace dchat_connecter {
      class Req_Join_Room: public apdos::kernel::event::Event {
      public:
        static const char* REQ_JOIN_ROOM;

      public:
        Req_Join_Room(apdos::plugins::uuid::Object_Id room_id);
      };
    }
	}
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_REQ_JOIN_ROOM_H