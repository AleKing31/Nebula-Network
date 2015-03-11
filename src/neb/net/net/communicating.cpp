#include <gal/net/message.hpp>

#include <gal/log/log.hpp>
#include <gal/stl/wrapper.hpp>

#include <neb/fnd/net/msg/Base.hpp>
#include <neb/fnd/net/comm/util/Parent.hpp>

#include <neb/net/net/communicating.hh>

typedef neb::net::comm::Base THIS;

THIS::Base()
{
	printv_func(DEBUG);


	//abort();
}
THIS::Base(gal::net::communicating&& c):
	gal::net::communicating(std::move(c))
{
	printv_func(DEBUG);


}
THIS&			THIS::operator=(gal::net::communicating&& c)
{
	printv_func(DEBUG);
	gal::net::communicating::operator=(std::move(c));
	return *this;
}
void			THIS::init(parent_t * const & parent)
{
	printv_func(DEBUG);

	setParent(parent);
	
	auto self = shared_from_this();

	_M_process_func = boost::bind(
			&neb::net::comm::Base::process,
			self,
			_1);

}
void			THIS::release()
{
	gal::net::communicating::release();
	neb::fnd::net::comm::Base::release();
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
	
	buffer->init_input();
	
	printv(DEBUG, "read into wrapper\n");

	*buffer->get_iar() >> *w;
}


