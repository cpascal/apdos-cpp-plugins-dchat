#ifndef APDOS_KERNEL_EVENT_EVENT_H
#define APDOS_KERNEL_EVENT_EVENT_H

#include <iostream>
#include <map>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>
#include <libs/apdos/libs/json/json.h>

namespace apdos {
  namespace kernel {
    namespace event {
      class Event {
      public:
        Event(std::string type, std::string name);

        std::string get_type();
        std::string get_name() { return this->name; }
        std::map<const char*, boost::any> get_data() { return this->data; }

      protected:
        void set_data(std::map<const char*, boost::any> data);

      private:
        std::string type;
        std::string name;
        std::map<const char*, boost::any> data;

      public:
        virtual std::string serialize();
      
      protected:
        void serialize_data(Json::Value& value, std::map<const char*, boost::any>& properties);
      };
    }
  }
}

#endif //APDOS_KERNEL_EVENT_EVENT_H