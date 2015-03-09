#include <neb/fnd/plug/net/app/Base.hpp>

#include <neb/net/app/Base.hpp>

namespace NS0 = neb::fnd::plug::net::app;
namespace NS1 = neb::net::app;

typedef NS0::Base T0;

typedef NS1::Base T;

extern "C" T0*	app_create(int)
{
	return new T;
}
extern "C" void	app_destroy(T0* t)
{
	delete t;
}

