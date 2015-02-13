#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_REQ_USER_CHAT_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_REQ_USER_CHAT_H

#include <iostream>
#include <libs/apdos/kernel/event/event.h>

namespace apdos {
	namespace plugins {
    namespace dchat_connecter {
      class Req_User_Chat: public apdos::kernel::event::Event {
      public:
        static const char* REQ_USER_CHAT;

      public:
        Req_User_Chat(std::string message);
      };
    }
	}
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_REQ_USER_CHAT_H