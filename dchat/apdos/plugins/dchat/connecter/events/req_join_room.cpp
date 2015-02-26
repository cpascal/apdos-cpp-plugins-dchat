#include "req_join_room.h"
#include <boost/any.hpp>

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;
using namespace apdos::plugins::uuid;

const char* Req_Join_Room::REQ_JOIN_ROOM = "req_join_room";

Req_Join_Room::Req_Join_Room(Object_Id room_id): Event("Req_Join_Room", REQ_JOIN_ROOM) {
  boost::shared_ptr<std::map<std::string, boost::any> > data(new std::map<std::string, boost::any>());
  data->insert(std::make_pair("room_id", boost::any(room_id.get_value())));
  this->set_data(data);
}