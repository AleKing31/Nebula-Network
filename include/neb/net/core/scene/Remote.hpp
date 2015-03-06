#ifndef PHYSX_CORE_SCENE_REMOTE_H__
#define PHYSX_CORE_SCENE_REMOTE_H__

#include <vector>


/*
#include <neb/fnd/scene/Remote.hh>

#include <neb/config.hh> // Nebula/config.hpp.in
#include <neb/gfx/glsl/program.hpp>

#include <neb/fnd/actor/Util/Parent.hh>

#include <neb/gfx/camera/view/Base.hh>

#include <PhysX/core/scene/base.hpp>
*/

//#include <glutpp/shader.h>

#include <neb/net/core/scene/Base.hpp>

namespace neb { namespace net { namespace core { namespace scene {

	class Remote:
		virtual public neb::net::core::scene::Base
	{
		virtual void			step(gal::etc::timestep const & ts);
/*
		virtual void			fire(std::shared_ptr<neb::fnd::actor::base> actor);
		*/
		/** @brief create rigidstatic
		 *
		 * @note typeof returned actor will be determined by final implementation of this
		 *
		 * @warning return actor is not initialized
		 */
//		std::weak_ptr<neb::fnd::actor::rigidstatic::base>	createActorRigidStaticUninitialized();
	};
}}}}

#endif


