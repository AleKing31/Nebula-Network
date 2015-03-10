#include <gal/net/message.hpp>

#include <gal/log/log.hpp>
#include <gal/stl/wrapper.hpp>

#include <neb/fnd/net/message/Base.hpp>
#include <neb/fnd/net/comm/util/Parent.hpp>

#include <neb/net/net/communicating.hh>

typedef neb::net::Communicating THIS;

THIS::Communicating()
{
	printv_func(DEBUG);

	//abort();
}
THIS::Communicating(gal::net::communicating&& c):
	gal::net::communicating(std::move(c))
{
	printv_func(DEBUG);


}
void			THIS::init(parent_t * const & parent)
{
	printv_func(DEBUG);

	setParent(parent);
	
	
}
void			THIS::connect(
		S_IO io_service,
		S_SOC socket)
{
	printv_func(DEBUG);

	gal::net::communicating::connect(io_service, std::move(socket));
}
void			THIS::connect(S_IO io_service)
{
	printv_func(DEBUG);

	gal::net::communicating::connect(io_service);
}
void			THIS::process(S_MSG buffer)
{
	//if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "neb::Network", debug) << __PRETTY_FUNCTION__;
	printv_func(DEBUG);

	
	typedef gal::stl::wrapper<neb::fnd::net::msg::Base> W;
	
	W* wp = new W();
	std::shared_ptr<W> w(wp);
	
	w->init_shared(_M_shared_parent);
	
	*buffer->get_iar() >> *w;
}


