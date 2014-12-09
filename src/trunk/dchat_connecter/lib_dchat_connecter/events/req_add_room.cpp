#include "req_add_room.h"
#include <boost/any.hpp>

using namespace apdos::plugins::dchat_connecter;
using namespace apdos::kernel::event;

const char* Req_Add_Room::REQ_ADD_ROOM = "req_add_room";

Req_Add_Room::Req_Add_Room(std::string room_name): Event("Req_Add_Room", REQ_ADD_ROOM) {
  boost::shared_ptr<std::map<std::string, boost::any>> data(new std::map<std::string, boost::any>());
  data->insert(std::make_pair("room_name", boost::any(room_name)));
  this->set_data(data);
}