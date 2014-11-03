#include "event.h"
#include <map>
#include <libs/apdos/libs/json/json.h>

using namespace apdos::kernel::event;

Event::Event(std::string name) {
  this->name = name;
}

void Event::set_data(std::map<const char*, boost::any> data) {
  this->data = data;
}

void serialize_map(Json::Value& value, std::map<const char*, boost::any>& properties) {
  std::map<const char*, boost::any>::iterator it = properties.begin(), end = properties.end();
  for (; it != end; ++it) {
    boost::any p = it->second;
    if (p.type() == typeid(std::string)) {
      value[it->first] = boost::any_cast<std::string>(p);
    }
    if (p.type() == typeid(std::map<const char*, boost::any>)) {
      std::map<const char*, boost::any> m = boost::any_cast<std::map<const char*, boost::any>>(p);
      value[it->first] = Json::Value();
      serialize_map(value[it->first], m);
    }
  }
}

std::string Event::serialzie(Event event) {
  Json::Value json_map;
  json_map["type"] = "unkonwn";
  json_map["name"] = event.get_name();
  json_map["data"] = Json::Value();


  boost::any aa(std::string("234234234234"));
  std::cout << aa.type().raw_name() << std::endl;

  std::map<const char*, boost::any> data = event.get_data();
  serialize_map(json_map["data"], data);
  
  Json::StyledWriter writer;
  return writer.write(json_map);
}

