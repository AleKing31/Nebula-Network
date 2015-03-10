#ifndef __NEBULA_ASIO_NETWORK_COMMUNICATING_H__
#define __NEBULA_ASIO_NETWORK_COMMUNICATING_H__

//#include <neb/util/decl.hpp>

#include <gal/net/communicating.hpp>
#include <gal/stl/verbosity.hpp>

#include <neb/fnd/net/comm/Base.hpp>

namespace neb { namespace net { 
	class Communicating:
		virtual public gal::tmp::Verbosity<neb::net::Communicating>,
		virtual public gal::net::communicating,
		virtual public neb::fnd::net::comm::Base
	{
		public:
			using gal::tmp::Verbosity<neb::net::Communicating>::printv;
			typedef std::shared_ptr<boost::asio::io_service>	S_IO;
			typedef std::shared_ptr<gal::net::message>		S_MSG;
			Communicating();
			Communicating(gal::net::communicating &&);
			void		init(parent_t * const & parent);
			void		connect(S_IO io_service, S_SOC socket);
			void		connect(S_IO io_service);
			void		process(S_MSG);
	};
}}

#endif




