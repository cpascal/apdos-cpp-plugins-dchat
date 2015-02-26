#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_REQ_LEAVE_ROOM_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_REQ_LEAVE_ROOM_H

#include <iostream>
#include <apdos/kernel/event/event.h>
#include <apdos/plugins/uuid/object_id.h>

namespace apdos {
	namespace plugins {
    namespace dchat_connecter {
      class Req_Leave_Room: public apdos::kernel::event::Event {
      public:
        static const char* REQ_LEAVE_ROOM;

      public:
        Req_Leave_Room();
      };
    }
	}
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_REQ_LEAVE_ROOM_H