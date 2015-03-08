#ifndef __NEBULA_ASIO_NETWORK_COMMUNICATING_H__
#define __NEBULA_ASIO_NETWORK_COMMUNICATING_H__

//#include <neb/util/decl.hpp>

#include <gal/net/communicating.hpp>

namespace neb {
	namespace Network {
		class Communicating:
			virtual public gal::net::communicating
		{
			public:
				typedef std::shared_ptr<boost::asio::io_service> S_IO;
				void		connect(S_IO io_service, ip::tcp::socket&& socket);
				void		connect(S_IO io_service);
				void		process(std::shared_ptr< gal::net::imessage >);
		};
	}
}

#endif







