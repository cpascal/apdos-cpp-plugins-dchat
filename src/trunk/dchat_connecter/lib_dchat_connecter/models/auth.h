#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_AUTH_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_AUTH_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <libs/apdos/kernel/actor/component.h>
#include "user.h"

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace models {
        class Auth: public apdos::kernel::actor::Component {
        public:
          void login(boost::shared_ptr<User> user) {
            this->user = user;
          }

          boost::shared_ptr<User> get_login_user() {
            return user;
          }

        private:
          boost::shared_ptr<User> user;
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_AUTH_H