#include <iostream>
#include <string>
#include <boost/version.hpp>
#include <apdos/kernel/actor/actor.h>
#include <apdos/kernel/kernel.h>
#include <apdos/plugins/dchat/ws-cclient/presenters/ws_client_presenter.h>

using namespace std;
using namespace boost;

using namespace apdos::kernel;
using namespace apdos::kernel::event;
using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter::cclient::presenters;

typedef boost::shared_ptr<Actor> Actor_Shared_Ptr;

const char* HOST_ADDRESS = "ws://angames2.iptime.org:20002";

int main() {
  Actor_Shared_Ptr actor = Kernel::get_instance()->new_object<Actor>("/sys/connecter");
  boost::shared_ptr<Ws_Client_Presenter> client = actor->add_component<Ws_Client_Presenter>();
  client->start(HOST_ADDRESS);
  exit(0);
}