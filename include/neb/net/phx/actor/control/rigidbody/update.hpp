#ifndef PHYSX_MESSAGE_ACTOR_CONTROL_HPP
#define PHYSX_MESSAGE_ACTOR_CONTROL_HPP

#include <gal/stl/wrapper.hpp>

#include <neb/fnd/core/actor/util/decl.hpp>

#include <neb/net/message/Actor/Base.hh>

//#include <neb/net/phx/core/actor/util/decl.hpp>

namespace neb { namespace net { namespace msg { namespace actor { namespace control { namespace rigidbody {
	/** @brief %create. */
	class create:
		virtual public neb::net::msg::actor::Base
	{
	public:
		typedef neb::fnd::core::actor::control::rigidbody::base T;
		virtual void			load(
				boost::archive::polymorphic_iarchive & ar,
				unsigned int const & version);
		virtual void			save(
				boost::archive::polymorphic_oarchive & ar,
				unsigned int const & version);
		gal::stl::wrapper<T>		control_;
	};
	/** @brief %Update. */
	class update:
		virtual public neb::net::msg::actor::Base
	{
	public:
		typedef neb::fnd::core::actor::control::rigidbody::base T;
		virtual ~update();
		virtual void			load(
				boost::archive::polymorphic_iarchive & ar,
				unsigned int const & version);
		virtual void			save(
				boost::archive::polymorphic_oarchive & ar,
				unsigned int const & version);
		BOOST_SERIALIZATION_SPLIT_MEMBER();
		gal::stl::wrapper<T>		control_;
	};
}}}}}}

#endif




