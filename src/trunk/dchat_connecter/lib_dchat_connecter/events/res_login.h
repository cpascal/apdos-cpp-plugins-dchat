#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_RES_LOGIN_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_RES_LOGIN_H

#include <iostream>
#include <libs/apdos/kernel/event/event.h>
#include <vector>
#include <map>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      class Res_Login: public apdos::kernel::event::Event {
      public:
        static const char* RES_LOGIN;

      public:
        Res_Login(std::string user_name);

        std::string get_user_id();
        std::string get_user_name();
        boost::shared_ptr<std::vector<boost::any>> get_rooms();
      };
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_RES_LOGIN_H