#include <neb/fnd/plug/net/util/decl.hpp>
#include <neb/fnd/plug/net/core/scene/util/decl.hpp>

#include <neb/net/core/scene/Local.hpp>
#include <neb/net/core/scene/Remote.hpp>

namespace NS_PLUG = neb::fnd::plug::net;

namespace NS0 = neb::fnd::plug::net::core::scene;
namespace NS1 = neb::net::core::scene;

typedef NS0::Base T0;

typedef NS1::Base T;
typedef NS1::Local L;
typedef NS1::Remote R;

extern "C" T0*	scene_create(int i)
{
	switch(i) {
	case NS_PLUG::type::LOCAL:
		return new L;
	case NS_PLUG::type::REMOTE:
		return new R;
	}

	return 0;
}
extern "C" void	scene_destroy(T0* t)
{
	delete t;
}

