#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_NULL_USER_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_NULL_USER_H

#include "user.h"

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      namespace models {
        class Null_User: public User {
        public:
          Null_User();

          virtual bool is_null() { return true; }
        };
      }
    }
  }
}


#endif //APDOS_PLUGINS_DCHAT_CONNECTER_MODELS_NULL_USER_H