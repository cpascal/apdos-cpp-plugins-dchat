#ifndef APDOS_CPP_PLUGINS_DCHAT_CONNECTER_RES_LOGIN_H
#define APDOS_CPP_PLUGINS_DCHAT_CONNECTER_RES_LOGIN_H

#include <iostream>
#include <libs/apdos/kernel/event/event.h>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      class Res_Login: public apdos::kernel::event::Event {
      public:
        static const const char* RES_LOGIN;

      public:
        Res_Login(std::string user_name);
      };
    }
  }
}

#endif //APDOS_CPP_PLUGINS_DCHAT_CONNECTER_RES_LOGIN_H