#include "wait_room_cmd_presenter.h"

using namespace apdos::kernel::event;
using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter::cclient::presenters;
using namespace apdos::plugins::dchat_connecter::presenters;
using namespace apdos::plugins::dchat_connecter::models;
using namespace apdos::plugins::dchat_connecter::cclient::models;

Wait_Room_Cmd_Presenter::Wait_Room_Cmd_Presenter() {
}


Wait_Room_Cmd_Presenter::~Wait_Room_Cmd_Presenter() {
}

void Wait_Room_Cmd_Presenter::set_components(Client_Presenter_Shared_Ptr client_presenter, Rooms_Shared_Ptr rooms) {
  this->client_presenter = client_presenter;
  this->rooms = rooms;
}

void Wait_Room_Cmd_Presenter::process_cmd(std::string line_input) {
  std::cout << "Wait_Room_Cmd_Presenter::process_cmd:" << line_input << std::endl;

  if (0 == line_input.compare("login")) {
    std::string user_name = "test";
    client_presenter->login(user_name);
  }
  if (0 == line_input.compare("add_room")) {
    std::string room_name = "test_room";
    client_presenter->add_room(room_name);
  }
  if (0 == line_input.compare("logout")) {
    client_presenter->logout();
  }
  if (0 == line_input.compare("rooms")) {
    this->print_rooms();
  }
}

void Wait_Room_Cmd_Presenter::print_rooms() {
  Room_List_Shared_Ptr list = rooms->get_rooms();
  std::cout << "Room List" << std::endl;
  std::cout << "room num | room_id | room_name | user_count | max_user_count" << std::endl;
  for (Room_Vector::iterator iter = list->begin(); iter != list->end(); ++iter) {
    std::cout << iter->get()->get_num() << " | " 
      << iter->get()->get_id().get_value() << " | " 
      << iter->get()->get_name() << " | " 
      << iter->get()->get_user_count() << " | "
      << iter->get()->get_max_user_count() << std::endl;
  }
}
