#include <iostream>
#include <boost/asio.hpp>
#include <events/req_login.h>
#include <events/res_login.h>
#include <libs/apdos/kernel/actor/actor.h>
#include <libs/apdos/kernel/actor/actor_connecter.h>

using namespace std;
using namespace boost;
using namespace boost::system;
using namespace boost::asio;
using namespace boost::asio::ip;

using namespace apdos::kernel::actor;
using namespace apdos::plugins::dchat_connecter;

const char SERVER_IP[] = "211.50.119.84";
const unsigned short PORT_NUMBER = 10001;

int main() {
	io_service io_service;
	tcp::endpoint endpoint(address::from_string(SERVER_IP), PORT_NUMBER);
	system::error_code connect_error;
	tcp::socket socket(io_service);
	socket.connect(endpoint, connect_error);
	if (connect_error) {
		std::cout << "Connect failed. error no: " << connect_error.value() 
			<< ", message: " << connect_error.message() << std::endl;
	}
	Actor* actor = new Actor("/sys/connecter");
	boost::shared_ptr<Actor_Connecter> connecter = actor->add_component<Actor_Connecter>();
	Req_Login req_login("test_user1");
	connecter->send_by_path("/sys", "/sys/preqenters/server_presenter", req_login);
	return 0;
}