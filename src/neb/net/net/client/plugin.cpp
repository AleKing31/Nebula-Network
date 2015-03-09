#include <neb/fnd/net/client/Base.hpp>

#include <neb/net/net/client.hh>

namespace NS0 = neb::fnd::net::client;
namespace NS1 = neb::net::client;

typedef NS0::Base T0;

typedef NS1::Base T;

extern "C" T0*	client_create(int)
{
	return new T;
}
extern "C" void	client_destroy(T0* t)
{
	delete t;
}


