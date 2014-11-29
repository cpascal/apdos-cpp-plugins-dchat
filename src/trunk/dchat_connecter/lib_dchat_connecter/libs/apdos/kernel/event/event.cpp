#include "event.h"
#include <map>
#include <boost/tokenizer.hpp>

using namespace apdos::kernel::event;

Event::Event() {
  this->data = boost::shared_ptr<std::map<std::string, boost::any>>(new std::map<std::string, boost::any>());
}

Event::Event(std::string type, std::string name) {
  this->type = type;
  this->name = name;
  this->data = boost::shared_ptr<std::map<std::string, boost::any>>(new std::map<std::string, boost::any>());
}


Event::Event(std::string type, std::string name, boost::shared_ptr<std::map<std::string, boost::any>> data) {
  this->type = type;
  this->name = name;
  this->data = data;
}

void Event::set_data(boost::shared_ptr<std::map<std::string, boost::any>> data) {
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

  boost::shared_ptr<std::map<std::string, boost::any>> data = this->get_data();
  serialize_data(json_map["data"], *data.get());

  Json::FastWriter writer;
  return writer.write(json_map);
}

void Event::serialize_data(Json::Value& value, std::map<std::string, boost::any>& properties) {
  std::map<std::string, boost::any>::iterator it = properties.begin(), end = properties.end();
  for (; it != end; ++it) {
    boost::any p = it->second;
    if (p.type() == typeid(std::string)) {
      value[it->first] = boost::any_cast<std::string>(p);
    }
    if (p.type() == typeid(boost::shared_ptr<std::map<std::string, boost::any>>)) {
      boost::shared_ptr<std::map<std::string, boost::any>> m = boost::any_cast<boost::shared_ptr<std::map<std::string, boost::any>>>(p);
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

  Json::Value::Members members(json_map["data"].getMemberNames());
  for (Json::Value::Members::iterator iter = members.begin(); iter != members.end(); ++iter) {
    std::string& property_name = *iter;
    this->deserialize_data(*this->data.get(), property_name, json_map["data"]);
  }

  std::cout << serialize() << std::endl;
}

void Event::deserialize_data(std::map<std::string, boost::any>& store_map, std::string& key, Json::Value& value) {
  Json::Value& read_value = value[key];
  switch (read_value.type()) {
  case Json::objectValue: 
    {
      boost::shared_ptr<std::map<std::string, boost::any>> mm(new std::map<std::string, boost::any>());
      store_map[key] = boost::any(mm);

      Json::Value::Members members(read_value.getMemberNames());
      for (Json::Value::Members::iterator iter = members.begin(); iter != members.end(); ++iter) {
        std::string& property_name = *iter;
        this->deserialize_data(*mm.get(), property_name, read_value);
      }
    }
    break;
  case Json::stringValue:
    {
      store_map[key] = boost::any(read_value.asString());
      //std::cout << key << ":" << read_value.asString() << std::endl;
    }
    break;
  default:
    break;
  }
}