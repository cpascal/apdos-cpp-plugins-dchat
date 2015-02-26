#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_LEAVE_ROOM_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_LEAVE_ROOM_H

#include <iostream>
#include <apdos/kernel/event/event.h>
#include <apdos/plugins/uuid/object_id.h>

namespace apdos {
	namespace plugins {
    namespace dchat_connecter {
      class Notify_Leave_Room: public apdos::kernel::event::Event {
      public:
        static const char* NOTIFY_LEAVE_ROOM;

      public:
        Notify_Leave_Room();

        std::string get_user_id();
        std::string get_user_name();
        std::string get_room_id();
        std::string get_room_name();
      };
    }
	}
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_LEAVE_ROOM_H