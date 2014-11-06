#ifndef APDOS_PLUGINS_DCHAT_CONNECTER_LINE_INPUT_H
#define APDOS_PLUGINS_DCHAT_CONNECTER_LINE_INPUT_H

#include <boost/asio.hpp>

namespace apdos {
  namespace plugins {
    namespace dchat_connecter {
      class Line_Input {
      public:
        Line_input(boost::asio::io_service& io_service):
          io_service(ios_service) {
        }

      private:
        boost::asio::io_service& io_service;
        boost::asio::streambuf input_buffer;
        boost::asio::windows::stream_
      }
    }
  }
}

#endif //APDOS_PLUGINS_DCHAT_CONNECTER_LINE_INPUT_H