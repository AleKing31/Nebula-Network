#ifndef NEB_NET_CORE_SCENE_LOCAL_HPP
#define NEB_NET_CORE_SCENE_LOCAL_HPP

#include <neb/net/core/scene/Base.hpp>

namespace neb { namespace net { namespace core { namespace scene {
	class Local:
		virtual public neb::net::core::scene::Base
	{
		public:
			virtual void			step(gal::etc::timestep const & ts);
/*
			local(std::shared_ptr<neb::fnd::scene::util::parent> parent);
			virtual void			init();
			virtual void			release();

			virtual void			serialize(boost::archive::polymorphic_iarchive & ar, unsigned int const & version) {}
			virtual void			serialize(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) {}
			*/
	};
}}}}

#endif



