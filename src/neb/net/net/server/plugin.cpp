#include <neb/fnd/plug/net/server/Base.hpp>

#include <neb/net/net/server.hh>

namespace NS0 = neb::fnd::plug::net::server;
namespace NS1 = neb::net::server;

typedef NS0::Base T0;

typedef NS1::Base T;

extern "C" T0*	server_create(int)
{
	return new T;
}
extern "C" void	server_destroy(T0* t)
{
	delete t;
}

