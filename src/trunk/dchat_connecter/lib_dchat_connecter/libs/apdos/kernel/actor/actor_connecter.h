#ifndef APDOS_KERNEL_ACTOR_ACTOR_CONNECTER_H
#define APDOS_KERNEL_ACTOR_ACTOR_CONNECTER_H

#include <iostream>
#include <vector>
#include <queue>
#include <libs/apdos/kernel/actor/component.h>
#include <libs/apdos/kernel/event/event.h>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

namespace apdos {
  namespace kernel {
    namespace actor {
      class Actor_Connecter: public Component {
      public:
        static const int READ_BUFFER_SIZE = 1024;

        Actor_Connecter();

        /**
         * 다른 Actor에 접속
         * 
         * @param address Actor의 주소( ex. tcp://localhost:5001)
         */
        void connect(std::string address);
        void disconnect();

        void send_by_path(std::string sender_path, std::string receiver_path, apdos::kernel::event::Event event);

      private:
        void handle_read(const boost::system::error_code& error, size_t bytes_transferred);
        void handle_connect(const boost::system::error_code& error);
        void handle_write(const boost::system::error_code& error);

      private:
        std::vector<std::string> get_messages();
        // 전송받고 있는 이벤트 데이터가 있는지 조사 
        bool has_fragment_message(std::vector<std::string>& messages);
        std::vector<std::string> get_address_tokens(std::string address);

        void process_event(std::string message);

      private:
	      boost::asio::io_service io_service;
        boost::asio::ip::tcp::socket socket;

        std::string send_buffer;
        int read_index;
        std::vector<char> recv_data;
        std::vector<char> recv_buffer;

        boost::shared_ptr<boost::thread> thread;
      };
    }
  }
}

#endif //APDOS_KERNEL_ACTOR_ACTOR_CONNECTER_H