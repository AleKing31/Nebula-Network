#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/net/msg/Base.hpp>

//#include <neb/debug.hh>
//#include <neb/util/wrapper.hpp>
#include <neb/net/app/Base.hpp>

typedef neb::net::app::Base THIS;

void			THIS::init(parent_t * const & parent)
{
	setParent(parent);
}
void			THIS::release()
{
}
void			THIS::step(gal::etc::timestep const & ts)
{
}
void			THIS::reset_server(ip::tcp::endpoint const & endpoint)
{
	abort();
	//auto app = getParent();
	
	//NEBULA_DEBUG_0_FUNCTION;
	//server_.reset(new neb::Network::Server(app->_M_ios, endpoint));
}
void		THIS::sendServer(S_MSG msg)
{
	abort();
	//NEBULA_DEBUG_1_FUNCTION;

	/*
	if(server_) {
		server_->write(msg);
	} else {
		printv(DEBUG, "no server\n");
	}
	*/
}
void		THIS::sendClient(S_MSG msg)
{
	abort();
	//NEBULA_DEBUG_1_FUNCTION;
	/*
	if(client_) {
		client_->write(msg);
	} else {
		printv(DEBUG, "no client\n");
	}
	*/
}
typedef neb::fnd::net::msg::Base T;
void		THIS::sendClient(std::shared_ptr<neb::fnd::net::msg::Base> m)
{
	assert(m);
	
	/** @todo wtf */
	gal::stl::wrapper<T> wrapper(std::move(m));

	auto buffer = S_MSG(new gal::net::message);
	buffer->init_output();

	/** @todo boost serial warning */
	*buffer->get_oar() << wrapper;

	sendClient(buffer);
}
void		THIS::sendServer(std::shared_ptr<neb::fnd::net::msg::Base> m)
{
	assert(m);

	/** @todo wtf */
	gal::stl::wrapper<T> wrapper(std::move(m));
	
	auto buffer = S_MSG(new gal::net::message);
	buffer->init_output();

	/** @todo boost serial warning */
	*buffer->get_oar() << wrapper;

	sendServer(buffer);
}






