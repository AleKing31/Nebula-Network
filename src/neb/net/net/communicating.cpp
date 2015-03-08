#include <gal/net/message.hpp>

#include <gal/log/log.hpp>
#include <gal/stl/wrapper.hpp>

#include <neb/fnd/net/message/Base.hpp>

#include <neb/net/net/communicating.hh>

typedef neb::Network::Communicating THIS;

void			THIS::connect(
		S_IO io_service,
		ip::tcp::socket&& socket)
{
	gal::net::communicating::connect(io_service, std::move(socket));
}
void			THIS::connect(S_IO io_service)
{
	gal::net::communicating::connect(io_service);
}
void		THIS::process(std::shared_ptr<gal::net::imessage> buffer)
{
	//if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "neb::Network", debug) << __PRETTY_FUNCTION__;
	
	typedef gal::stl::wrapper<neb::net::msg::Base> W;
	
	W* wp = new W();
	std::shared_ptr<W> w(wp);
	
	w->init_shared(_M_shared_parent);
	
	buffer->ar_ >> *w;
}


