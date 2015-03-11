#ifndef __NEBULA_ASIO_NETWORK_COMMUNICATING_BASE_HPP
#define __NEBULA_ASIO_NETWORK_COMMUNICATING_BASE_HPP

//#include <neb/util/decl.hpp>

#include <gal/net/communicating.hpp>
#include <gal/stl/verbosity.hpp>

#include <neb/fnd/net/comm/Base.hpp>

namespace neb { namespace net { namespace comm {
	class Base:
		virtual public gal::tmp::Verbosity<neb::net::comm::Base>,
		virtual public gal::enable_shared_from_this<neb::net::comm::Base>,
		virtual public gal::net::communicating,
		virtual public neb::fnd::net::comm::Base
	{
		public:
			using gal::tmp::Verbosity<neb::net::comm::Base>::printv;
			using gal::enable_shared_from_this<neb::net::comm::Base>::shared_from_this;
			typedef std::shared_ptr<boost::asio::io_service>	S_IO;
			typedef std::shared_ptr<gal::net::message>		S_MSG;
			Base();
			Base(gal::net::communicating &&);
			Base&			operator=(gal::net::communicating &&);
			virtual void		init(parent_t * const & parent);
			virtual void		release();
			void			connect(S_IO io_service, S_SOC socket);
			void			connect(S_IO io_service);
			void			process(S_MSG);
	};
}}}

#endif


