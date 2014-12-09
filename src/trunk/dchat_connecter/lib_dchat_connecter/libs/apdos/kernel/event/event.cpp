#include "event.h"
#include <map>
#include <boost/tokenizer.hpp>

using namespace apdos::kernel::event;

Event::Event() {
  this->data = Any_Map_Shared_Ptr(new Any_Map());
}

Event::Event(std::string type, std::string name) {
  this->type = type;
  this->name = name;
  this->data = Any_Map_Shared_Ptr(new Any_Map());
}


Event::Event(std::string type, std::string name, Any_Map_Shared_Ptr data) {
  this->type = type;
  this->name = name;
  this->data = data;
}

void Event::set_data(Any_Map_Shared_Ptr data) {
  this->data = data;
}

std::string Event::get_type() {
  return this->type;
}

std::string Event::serialize() {
  Json::Value json_map; 
  json_map["type"] = this->get_type();
  json_map["name"] = this->get_name();
  json_map["data"] = Json::Value();

  Any_Map_Shared_Ptr data = this->get_data();
  serialize_object(json_map["data"], *data.get());

  Json::FastWriter writer;
  return writer.write(json_map);
}

void Event::serialize_object(Json::Value& value, Any_Map& properties) {
  Any_Map::iterator it = properties.begin(), end = properties.end();
  for (; it != end; ++it) {
    boost::any p = it->second;
    if (p.type() == typeid(std::string)) {
      value[it->first] = boost::any_cast<std::string>(p);
    }
    if (p.type() == typeid(Any_Vector_Shared_Ptr)) {
      Any_Vector_Shared_Ptr v = boost::any_cast<Any_Vector_Shared_Ptr>(p);
      value[it->first] = Json::Value();
      serialize_array(value[it->first], *v.get());
    }
    if (p.type() == typeid(Any_Map_Shared_Ptr)) {
      Any_Map_Shared_Ptr m = boost::any_cast<Any_Map_Shared_Ptr>(p);
      value[it->first] = Json::Value();
      serialize_object(value[it->first], *m.get());
    }
  }
}


void Event::serialize_array(Json::Value& store_value, Any_Vector& values) {
  for (int i = 0; i < values.size(); ++i) {
    boost::any p = values[i];
    if (p.type() == typeid(std::string)) {
      store_value.append(boost::any_cast<std::string>(p));
    }
    if (p.type() == typeid(Any_Vector_Shared_Ptr)) {
      Any_Vector_Shared_Ptr v = boost::any_cast<Any_Vector_Shared_Ptr>(p);
      store_value.append(Json::Value());
      serialize_array(store_value[store_value.size() - 1], *v.get());
    }
    if (p.type() == typeid(Any_Map_Shared_Ptr)) {
      Any_Map_Shared_Ptr m = boost::any_cast<Any_Map_Shared_Ptr>(p);
      store_value.append(Json::Value());
      serialize_object(store_value[store_value.size() - 1], *m.get());
    }
  }
}

void Event::deserialize(std::string& json_data) {
  Json::Value json_map; 
  Json::Reader reader;
  reader.parse(json_data, json_map);
  this->type = json_map["type"].asString();
  this->name = json_map["name"].asString();

  Json::Value::Members members(json_map["data"].getMemberNames());
  for (Json::Value::Members::iterator iter = members.begin(); iter != members.end(); ++iter) {
    std::string& property_name = *iter;
    this->deserialize_object(*this->data.get(), property_name, json_map["data"]);
  }

  std::cout << serialize() << std::endl;
}

void Event::deserialize_object(Any_Map& store_map, std::string& key, Json::Value& value) {
  Json::Value& read_value = value[key];
  switch (read_value.type()) {
  case Json::objectValue: 
    {
      Any_Map_Shared_Ptr map(new Any_Map());
      store_map[key] = boost::any(map);

      Json::Value::Members members(read_value.getMemberNames());
      for (Json::Value::Members::iterator iter = members.begin(); iter != members.end(); ++iter) {
        std::string& property_name = *iter;
        this->deserialize_object(*map.get(), property_name, read_value);
      }
    }
    break;
  case Json::arrayValue:
    {
      Any_Vector_Shared_Ptr values(new Any_Vector());
      store_map[key] = boost::any(values);

      for (int i = 0; i < read_value.size(); ++i) {
        Json::Value element = read_value[i];
        this->deserialize_array(*values.get(), element);
      }
    }
    break;
  case Json::stringValue:
    {
      store_map[key] = boost::any(read_value.asString());
    }
    break;
  default:
    break;
  }
}

void Event::deserialize_array(Any_Vector &store_vector, Json::Value& value) {
  switch (value.type()) {
  case Json::objectValue:
    {
      Any_Map_Shared_Ptr map(new Any_Map());
      store_vector.push_back(boost::any(map));

      Json::Value::Members members(value.getMemberNames());
      for (Json::Value::Members::iterator iter = members.begin(); iter != members.end(); ++iter) {
        std::string& property_name = *iter;
        this->deserialize_object(*map.get(), property_name, value);
      }
    }
    break;
  case Json::arrayValue:
    {
      Any_Vector_Shared_Ptr values(new Any_Vector());
      store_vector.push_back(boost::any(values));

      for (int i = 0; i < value.size(); ++i) {
        Json::Value element = value[i];
        this->deserialize_array(*values.get(), element);
      }
    }
    break;
  case Json::stringValue:
    {
      store_vector.push_back(boost::any(value.asString()));
    }
    break;
  }
}
