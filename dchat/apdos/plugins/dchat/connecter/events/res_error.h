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
        // ä�� ���� ó�� ���з� ���� ����
        static const int ERROR_SYSTEM_FAIL = 1000;
        // �α��� ���� ���� ������ ��û�Դϴ�.
        static const int ERROR_NOT_LOGIN_USER = 2000;
        static const int ERROR_ALREADY_EXIST_NAME = 2001;
        // �������� �ʴ� ���Դϴ�.
        static const int ERROR_NOT_EXIST_ROOM = 3000;
        // �̹� �����ϴ� Crouter shard_id �Դϴ�.
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