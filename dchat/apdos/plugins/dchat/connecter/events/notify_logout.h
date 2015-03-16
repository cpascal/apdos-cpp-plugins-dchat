#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_LOGOUT_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_LOGOUT_H

#include <iostream>
#include <apdos/kernel/event/event.h>
#include <vector>
#include <map>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      class Notify_Logout: public apdos::kernel::event::Event {
      public:
        static const char* NOTIFY_LOGOUT;

      public:
        Notify_Logout();

        std::string get_user_id();
        std::string get_user_name();
      };
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_LOGOUT_H