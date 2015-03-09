#ifndef NEBULA_NETWORK_SERVER_HPP
#define NEBULA_NETWORK_SERVER_HPP

#include <gal/net/server.hpp>

#include <neb/fnd/plug/net/server/Base.hpp>

#include <neb/net/net/communicating.hh>

namespace neb { namespace net { namespace server {
	class Base:
		virtual public neb::fnd::plug::net::server::Base,
		public gal::net::server
	{
		public:
			typedef std::shared_ptr<boost::asio::io_service> S_IO;
			/** @brief ctor
			 *
			 * @param io_service boost asio io service
			 */
			Base();
			virtual void		init(parent_t * const &);
			virtual void		step(gal::etc::timestep const &);
			virtual void		connect(
					S_IO io_service,
					ip::tcp::endpoint const & endpoint);
			virtual void		release();
			void			accept(S_COM);
			void			write(S_MSG msg);
		private:
			std::vector< std::shared_ptr< neb::net::Communicating > >	clients_;

	};
}}}

#endif



