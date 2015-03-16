#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_REQ_CHAT_HISTORY_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_REQ_CHAT_HISTORY_H

#include <iostream>
#include <apdos/kernel/event/event.h>
#include <apdos/plugins/uuid/object_id.h>

namespace apdos {
	namespace plugins {
    namespace dchat_connecter {
      class Req_Chat_History: public apdos::kernel::event::Event {
      public:
        static const char* REQ_CHAT_HISTORY;

      public:
        Req_Chat_History(apdos::plugins::uuid::Object_Id room_id, int chat_count);
      };
    }
	}
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_REQ_CHAT_HISTORY_H