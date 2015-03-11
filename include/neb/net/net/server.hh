#ifndef NEBULA_NETWORK_SERVER_HPP
#define NEBULA_NETWORK_SERVER_HPP

#include <gal/net/server.hpp>

#include <neb/fnd/net/server/Base.hpp>

#include <neb/net/net/communicating.hh>

namespace neb { namespace net { namespace server {
	class Base:
		public gal::tmp::Verbosity<neb::net::server::Base>,
		virtual public gal::net::server,
		virtual public neb::fnd::net::server::Base
	{
		public:
			using gal::tmp::Verbosity<neb::net::server::Base>::printv;

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
			virtual void		accept(S_COM &&);
			void			write(S_MSG msg);
		private:
			//std::vector< std::shared_ptr< neb::net::Communicating > >	clients_;

	};
}}}

#endif



