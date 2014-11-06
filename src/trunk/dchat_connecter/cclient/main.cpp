#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <events/req_login.h>
#include <events/res_login.h>
#include <libs/apdos/kernel/kernel.h>
#include <libs/apdos/kernel/actor/actor.h>
#include <libs/apdos/kernel/actor/actor_connecter.h>

using namespace std;
using namespace boost;
using namespace boost::system;
using namespace boost::asio;
using namespace boost::asio::ip;

using namespace apdos::kernel;
using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter;

int main() {
  boost::shared_ptr<Kernel> k = Kernel::get_instance();
  Kernel::get_instance();
  Kernel::get_instance();

	Actor* actor = new Actor("/sys/connecter");
	boost::shared_ptr<Actor_Connecter> connecter = actor->add_component<Actor_Connecter>();
  connecter->connect("tcp://211.50.119.84:10001");
  std::string buffer;	
  while (std::getline(std::cin, buffer)) {
    if (0 == buffer.compare("login")) {
      //tokens
      Req_Login req_login("test");
      connecter->send_by_path("/sys", "/sys/presenters/server_presenter", req_login);
    }

    if (0 == buffer.compare("exit"))
      break;
  }
  connecter->disconnect();
	return 0;
}