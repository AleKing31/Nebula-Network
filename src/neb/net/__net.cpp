#include <neb/fnd/app/Base.hpp>

//#include <neb/debug.hh>
//#include <neb/util/wrapper.hpp>
#include <neb/__net.hpp>

typedef neb::net::app::Base THIS;

void THIS::reset_server(ip::tcp::endpoint const & endpoint)
{
	auto app = getParent();
	
	//NEBULA_DEBUG_0_FUNCTION;
	server_.reset(new neb::Network::Server(app->ios_, endpoint));
}
void THIS::reset_client(ip::tcp::resolver::iterator endpoint_iterator)
{
	auto app = getParent();
	
	//NEBULA_DEBUG_0_FUNCTION;
	client_.reset(new neb::Network::Client(app->ios_, endpoint_iterator));
}
void		THIS::sendServer(std::shared_ptr<gal::net::omessage> msg)
{
	//NEBULA_DEBUG_1_FUNCTION;

	if(server_) {
		server_->write(msg);
	} else {
		printv(DEBUG, "no server\n");
	}
}
void		THIS::sendClient(std::shared_ptr<gal::net::omessage> msg)
{
	//NEBULA_DEBUG_1_FUNCTION;

	if(client_) {
		client_->write(msg);
	} else {
		printv(DEBUG, "no client\n");
	}
}
void		THIS::sendClient(std::shared_ptr<neb::fnd::net::msg::Base> message)
{
	assert(message);
	
	/** @todo wtf */
	//neb::stl::wrapper wrap(message);

	auto buffer = sp::make_shared<gal::net::omessage>();

	/** @todo boost serial warning */
	//buffer->ar_ << wrapper;

	sendClient(buffer);
}
void		THIS::sendServer(std::shared_ptr<neb::fnd::net::msg::Base> message)
{
	assert(message);

	/** @todo wtf */
	//neb::stl::wrapper wrapper(message);

	auto buffer = sp::make_shared<gal::net::omessage>();

	/** @todo boost serial warning */
	//buffer->ar_ << wrapper;

	sendServer(buffer);
}






