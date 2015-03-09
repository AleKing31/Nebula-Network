#ifndef __NEBULA_NETWORK_CLIENT_H__
#define __NEBULA_NETWORK_CLIENT_H__

#include <gal/etc/timestep.hpp>

#include <gal/net/client.hpp>

#include <neb/net/net/communicating.hh>
#include <neb/fnd/net/client/Base.hpp>

namespace neb { namespace net { namespace client {
	class Base:
		virtual public gal::net::client,
		virtual public neb::fnd::net::client::Base,
		virtual public neb::net::Communicating
	{
		public:
			using neb::fnd::net::client::Base::parent_t;
			using neb::fnd::net::client::Base::setParent;
			using neb::fnd::net::client::Base::getParent;
			using neb::fnd::net::client::Base::get_fnd_app;

			Base();
			virtual void		init(parent_t * const & parent);
			virtual void		step(gal::etc::timestep const &);
			void			connect(
					boost::asio::io_service& io_service,
					ip::tcp::resolver::iterator endpoint_iterator);
			void			process(S_MSG msg);
			virtual void		release();
	};
}}}

#endif





