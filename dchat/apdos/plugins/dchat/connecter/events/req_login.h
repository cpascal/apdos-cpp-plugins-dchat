#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_REQ_LOGIN_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_REQ_LOGIN_H

#include <iostream>
#include <apdos/kernel/event/event.h>

namespace apdos {
	namespace plugins {
    namespace dchat_connecter {
      class Req_Login: public apdos::kernel::event::Event {
      public:
        static const char* REQ_LOGIN;

      public:
        Req_Login(std::string user_name);
      };
    }
	}
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_REQ_LOGIN_H