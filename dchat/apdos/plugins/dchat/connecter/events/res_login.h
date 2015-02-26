#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_RES_LOGIN_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_RES_LOGIN_H

#include <iostream>
#include <apdos/kernel/event/event.h>
#include <vector>
#include <map>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      class Res_Login: public apdos::kernel::event::Event {
      public:
        static const char* RES_LOGIN;

      public:
        Res_Login();

        std::string get_user_id();
        std::string get_user_name();
        apdos::kernel::event::Any_Vector_Shared_Ptr get_rooms();
      };
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_RES_LOGIN_H