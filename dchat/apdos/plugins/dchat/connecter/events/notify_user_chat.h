#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_USER_CHAT_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_USER_CHAT_H

#include <iostream>
#include <apdos/kernel/event/event.h>
#include <vector>
#include <map>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      class Notify_User_Chat: public apdos::kernel::event::Event {
      public:
        static const char* NOTIFY_USER_CHAT;

      public:
        Notify_User_Chat();

        std::string get_user_id();
        std::string get_user_name();
        std::string get_user_message();
      };
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_NOTIFY_USER_CHAT_H