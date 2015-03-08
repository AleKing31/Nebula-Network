#ifndef __NEBULA_NETWORK_CLIENT_H__
#define __NEBULA_NETWORK_CLIENT_H__

#include <gal/net/client.hpp>

#include <neb/net/net/communicating.hh>
#include <neb/fnd/plug/net/client/Base.hpp>

namespace neb { namespace Network {
	class Client:
		virtual public neb::Network::Communicating,
		virtual public gal::net::client,
		virtual public neb::fnd::plug::net::client::Base
	{
		public:
			Client();
			virtual void		init(parent_t * const & parent);
			void			connect(
					boost::asio::io_service& io_service,
					ip::tcp::resolver::iterator endpoint_iterator);
			void			process(
					std::shared_ptr< gal::net::imessage > message);
			virtual void		release();
	};
}}

#endif





