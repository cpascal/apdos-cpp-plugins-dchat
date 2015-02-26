#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_RES_LOGOUT_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_RES_LOGOUT_H

#include <iostream>
#include <apdos/kernel/event/event.h>
#include <vector>
#include <map>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      class Res_Logout: public apdos::kernel::event::Event {
      public:
        static const char* RES_LOGOUT;

      public:
        Res_Logout();

        std::string get_user_id();
        std::string get_user_name();
      };
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_RES_LOGOUT_H