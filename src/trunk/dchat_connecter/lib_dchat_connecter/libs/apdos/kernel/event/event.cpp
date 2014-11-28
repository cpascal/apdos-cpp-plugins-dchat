#include "event.h"
#include <map>
#include <boost/tokenizer.hpp>

using namespace apdos::kernel::event;

Event::Event() {
}

Event::Event(std::string type, std::string name) {
  this->type = type;
  this->name = name;
  this->data = boost::shared_ptr<std::map<const char*, boost::any>>(new std::map<const char*, boost::any>());
}

void Event::set_data(boost::shared_ptr<std::map<const char*, boost::any>> data) {
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

  boost::shared_ptr<std::map<const char*, boost::any>> data = this->get_data();
  serialize_data(json_map["data"], *data.get());

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
    if (p.type() == typeid(boost::shared_ptr<std::map<const char*, boost::any>>)) {
      boost::shared_ptr<std::map<const char*, boost::any>> m = boost::any_cast<boost::shared_ptr<std::map<const char*, boost::any>>>(p);
      value[it->first] = Json::Value();
      serialize_data(value[it->first], *m.get());
    }
  }
}

void Event::deserialize(std::string& json_data) {
  Json::Value json_map; 
  Json::Reader reader;
  reader.parse(json_data, json_map);
  this->type = json_map["type"].asString();
  this->name = json_map["name"].asString();
  this->deserialize_data(*this->data.get(), std::string("data"), json_map);
}

void Event::deserialize_data(std::map<const char*, boost::any>& store_map, std::string key, Json::Value& value) {
  switch (value.type()) {
  case Json::objectValue: 
    {
      Json::Value::Members members(value.getMemberNames());
      for (Json::Value::Members::iterator iter = members.begin(); iter != members.end(); ++iter) {
        const  std::string& name = *iter;
        store_map[name.c_str()] = boost::any(new std::map<const char*, boost::any>());
        this->deserialize_data(store_map, name, value[name]);
      }
    }
    break;
  case Json::stringValue:
    {
      std::map<const char*, boost::any> m = boost::any_cast<std::map<const char*, boost::any>>(store_map[key.c_str()]);
      m[key.c_str()] = boost::any(value.asString());
    }
    break;
  default:
    break;
  }
}