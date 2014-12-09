#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_REQ_LOGOUT_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_REQ_LOGOUT_H

#include <iostream>
#include <libs/apdos/kernel/event/event.h>

namespace apdos {
	namespace plugins {
    namespace dchat_connecter {
      class Req_Logout: public apdos::kernel::event::Event {
      public:
        static const char* REQ_LOGOUT;

      public:
        Req_Logout();
      };
    }
	}
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_REQ_LOGOUT_H