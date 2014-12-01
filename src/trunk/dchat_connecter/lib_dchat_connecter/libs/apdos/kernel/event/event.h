#ifndef APDOS_KERNEL_EVENT_EVENT_H
#define APDOS_KERNEL_EVENT_EVENT_H

#include <iostream>
#include <map>
#include <vector>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>
#include <libs/apdos/libs/json/json.h>

namespace apdos {
  namespace kernel {
    namespace event {
      class Event {
      public:
        Event();
        Event(std::string type, std::string name);
        Event(std::string type, std::string name, boost::shared_ptr<std::map<std::string, boost::any>> data);

        std::string get_type();
        std::string get_name() { return this->name; }
        boost::shared_ptr<std::map<std::string, boost::any>> get_data() { return this->data; }

      protected:
        void set_data(boost::shared_ptr<std::map<std::string, boost::any>> data);

      protected:
        std::string type;
        std::string name;
        boost::shared_ptr<std::map<std::string, boost::any>> data;

      public:
        virtual std::string serialize();
        virtual void deserialize(std::string& json_data);
      
      protected:
        void serialize_object(Json::Value& store_value, std::map<std::string, boost::any>& properties);
        void serialize_array(Json::Value& store_value, std::vector<boost::any>& values);

        void deserialize_object(std::map<std::string, boost::any> &store_map, std::string& key, Json::Value& value);
        void deserialize_array(std::vector<boost::any> &store_vector, Json::Value& value);
      };
    }
  }
}

#endif //APDOS_KERNEL_EVENT_EVENT_H