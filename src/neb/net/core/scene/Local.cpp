
#include <neb/net/core/scene/Local.hpp>

typedef neb::net::core::scene::Local THIS;

void			THIS::step(gal::etc::timestep const & ts)
{

}


/*

#include <Galaxy-Log/log.hpp>

#include <neb/app/Base.hh>
#include <neb/fnd/scene/Local.hh>
#include <neb/fnd/actor/RigidBody/Base.hh>
#include <neb/timer/Actor/Release.hpp>
#include <neb/debug.hh>



#include <PhysX/util/convert.hpp>
#include <PhysX/core/scene/local.hpp>
#include <PhysX/core/actor/rigiddynamic/local.hpp>
#include <PhysX/core/actor/rigidstatic/local.hpp>

phx::core::scene::local::local(std::shared_ptr<neb::fnd::scene::util::parent> parent):
	neb::fnd::scene::base(parent),
	neb::fnd::scene::local(parent),
	phx::core::scene::base(parent)
{
	if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "phx core scene", debug) << __PRETTY_FUNCTION__;
}
void			phx::core::scene::local::init() {
	if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "phx core scene", debug) << __PRETTY_FUNCTION__;

	neb::fnd::scene::local::init();
	phx::core::scene::base::init();
}
void			phx::core::scene::local::release() {
	if(DEBUG_NEB) BOOST_LOG_CHANNEL_SEV(lg, "phx core scene", debug) << __PRETTY_FUNCTION__;

	neb::fnd::scene::local::release();
	phx::core::scene::base::release();
}

*/

