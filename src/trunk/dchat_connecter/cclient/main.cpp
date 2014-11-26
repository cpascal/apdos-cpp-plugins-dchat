#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <events/req_login.h>
#include <events/res_login.h>
#include <libs/apdos/kernel/kernel.h>
#include <libs/apdos/kernel/actor/actor.h>
#include <libs/apdos/kernel/actor/actor_connecter.h>
#include "models/line_input.h"
#include "presenters\cmd_presenter.h"
#include "models/events/line_input_event.h"

using namespace std;
using namespace boost;
using namespace boost::system;
using namespace boost::asio;
using namespace boost::asio::ip;

using namespace apdos::kernel;
using namespace apdos::kernel::event;
using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter;
using namespace apdos::plugins::dchat_connecter::cclient::presenters;
using namespace apdos::plugins::dchat_connecter::cclient::models;
using namespace apdos::plugins::dchat_connecter::cclient::models::events;


int main() {
  boost::shared_ptr<Actor> actor = Kernel::get_instance()->new_object<Actor>("/sys/connecter");
	boost::shared_ptr<Actor_Connecter> connecter = actor->add_component<Actor_Connecter>();
  
  boost::shared_ptr<Actor> line_input_actor = Kernel::get_instance()->new_object<Actor>("/sys/mopdels/line_input");
  boost::shared_ptr<Line_Input> line_input = line_input_actor->add_component<Line_Input>();

  boost::shared_ptr<Actor> cmd_presenter_actor = Kernel::get_instance()->new_object<Actor>("/sys/presenter/cmd_presenter");
  boost::shared_ptr<Cmd_Presenter> cmd_presenter = cmd_presenter_actor->add_component<Cmd_Presenter>();
  cmd_presenter->set_line_input(line_input);

  connecter->connect("tcp://211.50.119.84:10001");
  cmd_presenter->start();
  //connecter->disconnect();
	return 0;
}