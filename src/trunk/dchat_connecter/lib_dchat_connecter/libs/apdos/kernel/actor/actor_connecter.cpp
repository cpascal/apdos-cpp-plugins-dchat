#include "actor_connecter.h"
#include <libs/apdos/kernel/actor/events/proxy_event.h>
#include <string>
#include <boost/tokenizer.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>

typedef boost::tokenizer<boost::char_separator<char>> tokenizer;

using namespace apdos::kernel::actor;
using namespace apdos::kernel::actor::events;
using namespace apdos::kernel::event;

Actor_Connecter::Actor_Connecter() : Component(),
  socket(io_service),
  recv_data(READ_BUFFER_SIZE),
  recv_buffer(READ_BUFFER_SIZE),
  read_index(0) {
}


void Actor_Connecter::connect(std::string address) {
  std::vector<std::string> tokens = this->get_address_tokens(address);
  std::string protocol = tokens[0];
  std::string ip = tokens[1];
  std::string port = tokens[2];

  boost::asio::ip::tcp::resolver resolver(io_service);
  boost::asio::ip::tcp::resolver::query query(ip, port);
  boost::asio::ip::tcp::resolver::iterator iter = resolver.resolve(query);
  boost::asio::async_connect(socket, iter, boost::bind(&Actor_Connecter::handle_connect, this, boost::asio::placeholders::error));

  thread = boost::shared_ptr<boost::thread>(new boost::thread(boost::bind(&boost::asio::io_service::run, &io_service)));
}

void Actor_Connecter::disconnect() {
  socket.close();
  thread->join();
}

void Actor_Connecter::handle_connect(const boost::system::error_code& error) {
  if (error) {
		std::cout << "Connect failed. error no: " << error.value() 
			<< ", message: " << error.message() << std::endl;
    return;	
  }
  socket.async_read_some(boost::asio::buffer(recv_data, READ_BUFFER_SIZE), 
    boost::bind(&Actor_Connecter::handle_read, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)); 
}

void Actor_Connecter::handle_read(const boost::system::error_code& error, size_t bytes_transferred) {
  if (error) {
		std::cout << "Read failed. error no: " << error.value() 
			<< ", message: " << error.message() << std::endl;
    return;
	}

  if ((read_index + bytes_transferred) >= READ_BUFFER_SIZE) {
    std::cout << "Read failed. recv buffer is Full" << std::endl;
    return;
  }

  std::copy(recv_data.begin(), recv_data.begin() + bytes_transferred, recv_buffer.begin() + read_index);
  read_index += bytes_transferred;

  std::vector<std::string> messages = get_messages();

  std::cout << "messages count: " << messages.size() << std::endl;
  for (int i = 0; i < messages.size(); ++i)
    std::cout << "token:" << messages[i] << std::endl;

  if (has_fragment_message(messages)) {
    std::string fragment_data = messages[messages.size() - 1];
    read_index = fragment_data.length();
    recv_buffer.assign(READ_BUFFER_SIZE, 0);
    std::copy(fragment_data.begin(), fragment_data.end(), recv_buffer.begin());

    for (int i = 0; i < messages.size() - 1; ++i) {
      std::cout << "1Event: " << messages[i] << std::endl;
    }
  }
  else {
    read_index = 0;
    recv_buffer.assign(READ_BUFFER_SIZE, 0);

    for (int i = 0; i < messages.size(); ++i) {
      std::cout << "2Event: " << messages[i] << std::endl;
    }
  }

  socket.async_read_some(boost::asio::buffer(recv_data, READ_BUFFER_SIZE), 
    boost::bind(&Actor_Connecter::handle_read, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)); 
}

std::vector<std::string> Actor_Connecter::get_messages() {
  std::string buffer(recv_buffer.begin(), recv_buffer.begin() + read_index);

  boost::char_separator<char> sep("\n");
  tokenizer tokens(buffer, sep);
  std::vector<std::string> result;
  for (tokenizer::iterator iter = tokens.begin(); iter != tokens.end(); ++iter) {
    result.push_back(*iter);
  }
  return result;
}

bool Actor_Connecter::has_fragment_message(std::vector<std::string>& messages) {
  size_t last = messages[messages.size() - 1].length() - 1;
  return messages[messages.size() - 1].compare(last, 1, "}") == std::string::npos ? true : false;
}

std::vector<std::string> Actor_Connecter::get_address_tokens(std::string address) {
  boost::char_separator<char> sep("://");
  tokenizer tokens(address, sep);

  std::vector<std::string> address_tokens;
  for (tokenizer::iterator iter = tokens.begin(); iter != tokens.end(); ++iter) {
    address_tokens.push_back(std::string(*iter));
  }
  return address_tokens;
}

void Actor_Connecter::send_by_path(std::string sender_path, std::string receiver_path, Event event) {
  Proxy_Event proxy_event(sender_path, receiver_path, event);
  std::cout << proxy_event.serialize() << std::endl;

  send_buffer = proxy_event.serialize();
  boost::asio::async_write(this->socket, 
    boost::asio::buffer(send_buffer),
    boost::bind(&Actor_Connecter::handle_write, this, boost::asio::placeholders::error));
}

void Actor_Connecter::handle_write(const boost::system::error_code& error) {
}