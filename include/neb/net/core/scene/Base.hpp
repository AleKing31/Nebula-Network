#ifndef NEB_NET_CORE_SCENE_BASE_HPP
#define NEB_NET_CORE_SCENE_BASE_HPP

#include <neb/fnd/plug/net/core/scene/Base.hpp>

namespace neb { namespace net { namespace core { namespace scene {
	class Base:
		virtual public neb::fnd::plug::net::core::scene::Base
	{
		public:
			virtual void			init(parent_t * const & p);
			/*
			Base();
			virtual void			init();
			virtual void			release();
			virtual void			step(::gal::etc::timestep const & ts);
			virtual void			serialize(boost::archive::polymorphic_iarchive & ar, unsigned int const & version) {}
			virtual void			serialize(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) {}
			*/
	};
}}}}

#endif



