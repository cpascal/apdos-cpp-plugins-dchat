#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_RES_ERROR_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_RES_ERROR_H

#include <iostream>
#include <apdos/kernel/event/event.h>
#include <vector>
#include <map>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      class Res_Error: public apdos::kernel::event::Event {
      public:
        static const char* RES_ERROR;

        //--------------------------------------------------
        //  Error Codes
        //--------------------------------------------------
        // 채팅 서버 처리 실패로 인한 오류
        static const int ERROR_SYSTEM_FAIL = 1000;
        // 로그인 하지 않은 유저의 요청입니다.
        static const int ERROR_NOT_LOGIN_USER = 2000;
        static const int ERROR_ALREADY_EXIST_NAME = 2001;
        // 존재하지 않는 방입니다.
        static const int ERROR_NOT_EXIST_ROOM = 3000;
        // 이미 존재하는 Crouter shard_id 입니다.
        static const int ERROR_EXIST_CROUTER_SHAR_ID = 4000;

      public:
        Res_Error();

        int get_error_code();
        std::string get_error_message();
      };
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_RES_ERROR_H