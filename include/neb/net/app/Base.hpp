#ifndef __NEBULA_APP___NET_H__
#define __NEBULA_APP___NET_H__

#include <fstream>

#include <boost/archive/polymorphic_xml_iarchive.hpp>

#include <gal/itf/shared.hpp>
#include <gal/stl/verbosity.hpp>

#include <gal/net/decl.hpp>

#include <neb/fnd/net/msg/util/decl.hpp>

#include <neb/fnd/plug/net/app/Base.hpp>

//#include <neb/app/__base.hpp>
#include <neb/net/net/server.hh>
#include <neb/net/net/client.hh>

namespace neb { namespace net { namespace app {
	class Base:
		public gal::tmp::Verbosity<neb::net::app::Base>,
		virtual public neb::fnd::plug::net::app::Base
	{
		public:
			typedef std::shared_ptr<neb::net::server::Base> SS;
			typedef std::shared_ptr<neb::net::client::Base> SC;
			typedef std::shared_ptr<gal::net::message>	S_MSG;
			virtual void		init(parent_t * const & parent);
			virtual void		release();
			virtual void		step(gal::etc::timestep const & ts);
			void			reset_server(ip::tcp::endpoint const & endpoint);
			void			reset_client(ip::tcp::resolver::iterator endpoint_iterator);
			void			sendServer(S_MSG);
			void			sendServer(std::shared_ptr<neb::fnd::net::msg::Base> message);
			void			sendClient(S_MSG);
			void			sendClient(std::shared_ptr<neb::fnd::net::msg::Base> message);
	};
}}}

#endif


