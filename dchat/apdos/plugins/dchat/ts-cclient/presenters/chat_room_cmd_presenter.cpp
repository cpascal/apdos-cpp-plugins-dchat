#include "chat_room_cmd_presenter.h"

using namespace apdos::kernel::event;
using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter::cclient::presenters;
using namespace apdos::plugins::dchat_connecter::presenters;
using namespace apdos::plugins::dchat_connecter::cclient::models;

Chat_Room_Cmd_Presenter::Chat_Room_Cmd_Presenter() {
}


Chat_Room_Cmd_Presenter::~Chat_Room_Cmd_Presenter() {
}

void Chat_Room_Cmd_Presenter::set_components(Client_Presenter_Shared_Ptr client_presenter) {
  this->client_presenter = client_presenter;
}

void Chat_Room_Cmd_Presenter::process_cmd(std::string line_input) {
  std::cout << "Chat_Room_Cmd_Presenter::process_cmd:" << line_input << std::endl;

  if (0 == line_input.compare("leave_room")) {
    client_presenter->leave_room();
  }
  else if (0 == line_input.compare("logout")) {
    client_presenter->logout();
  }
  else
    client_presenter->user_chat(line_input);
}
