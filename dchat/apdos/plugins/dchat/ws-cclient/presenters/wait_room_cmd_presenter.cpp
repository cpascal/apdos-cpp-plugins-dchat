#include "wait_room_cmd_presenter.h"

using namespace apdos::kernel::event;
using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter::cclient::presenters;
using namespace apdos::plugins::dchat_connecter::presenters;
using namespace apdos::plugins::dchat_connecter::cclient::models;

Wait_Room_Cmd_Presenter::Wait_Room_Cmd_Presenter() {
}


Wait_Room_Cmd_Presenter::~Wait_Room_Cmd_Presenter() {
}

void Wait_Room_Cmd_Presenter::set_components(Client_Presenter_Shared_Ptr client_presenter) {
  this->client_presenter = client_presenter;
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
}
