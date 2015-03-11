#include <neb/fnd/net/comm/Base.hpp>

#include <neb/net/net/communicating.hh>

namespace NS0 = neb::fnd::net::comm;
namespace NS1 = neb::net::comm;

typedef NS0::Base T0;

typedef NS1::Base T;

extern "C" T0*	comm_create(int)
{
	return new T;
}
extern "C" void	comm_destroy(T0* t)
{
	delete t;
}

