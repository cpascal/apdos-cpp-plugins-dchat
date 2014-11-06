#include "event.h"
#include <map>
#include <boost/tokenizer.hpp>

using namespace apdos::kernel::event;

Event::Event(std::string type, std::string name) {
  this->type = type;
  this->name = name;
}

void Event::set_data(std::map<const char*, boost::any> data) {
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

  std::map<const char*, boost::any> data = this->get_data();
  serialize_data(json_map["data"], data);
  
  Json::FastWriter writer;
  return writer.write(json_map);
}

void Event::serialize_data(Json::Value& value, std::map<const char*, boost::any>& properties) {
  std::map<const char*, boost::any>::iterator it = properties.begin(), end = properties.end();
  for (; it != end; ++it) {
    boost::any p = it->second;
    if (p.type() == typeid(std::string)) {
      value[it->first] = boost::any_cast<std::string>(p);
    }
    if (p.type() == typeid(std::map<const char*, boost::any>)) {
      std::map<const char*, boost::any> m = boost::any_cast<std::map<const char*, boost::any>>(p);
      value[it->first] = Json::Value();
      serialize_data(value[it->first], m);
    }
  }
}
