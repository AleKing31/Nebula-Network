#ifndef __NEBULA_APP___NET_H__
#define __NEBULA_APP___NET_H__

#include <fstream>

#include <boost/archive/polymorphic_xml_iarchive.hpp>

#include <gal/itf/shared.hpp>
#include <gal/stl/verbosity.hpp>

#include <gal/net/decl.hpp>

#include <neb/fnd/net/message/util/decl.hpp>

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
			typedef std::shared_ptr<neb::Network::Server> SS;
			typedef std::shared_ptr<neb::Network::Client> SC;
			void			reset_server(ip::tcp::endpoint const & endpoint);
			void			reset_client(ip::tcp::resolver::iterator endpoint_iterator);
			void			sendServer(std::shared_ptr<gal::net::omessage>);
			void			sendServer(std::shared_ptr<neb::fnd::net::msg::Base> message);
			void			sendClient(std::shared_ptr<gal::net::omessage>);
			void			sendClient(std::shared_ptr<neb::fnd::net::msg::Base> message);
			SS			server_;
			SC			client_;
	};
}}}

#endif


