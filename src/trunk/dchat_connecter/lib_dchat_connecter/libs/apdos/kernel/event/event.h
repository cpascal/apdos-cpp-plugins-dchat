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
      typedef std::map<std::string, boost::any> Any_Map;
      typedef boost::shared_ptr<Any_Map> Any_Map_Shared_Ptr;
      typedef std::vector<boost::any> Any_Vector;
      typedef boost::shared_ptr<Any_Vector> Any_Vector_Shared_Ptr;

      class Event {
      public:
        Event();
        Event(std::string type, std::string name);
        Event(std::string type, std::string name, Any_Map_Shared_Ptr data);

        std::string get_type();
        std::string get_name() { return this->name; }
        Any_Map_Shared_Ptr get_data() { return this->data; }

      protected:
        void set_data(Any_Map_Shared_Ptr data);

      protected:
        std::string type;
        std::string name;
        Any_Map_Shared_Ptr data;

      public:
        virtual std::string serialize();
        virtual void deserialize(std::string& json_data);
      
      protected:
        void serialize_object(Json::Value& store_value, Any_Map& properties);
        void serialize_array(Json::Value& store_value, Any_Vector& values);

        void deserialize_object(Any_Map &store_map, std::string& key, Json::Value& value);
        void deserialize_array(Any_Vector &store_vector, Json::Value& value);
      };
    }
  }
}

#endif //APDOS_KERNEL_EVENT_EVENT_H