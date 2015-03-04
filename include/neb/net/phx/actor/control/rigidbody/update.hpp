#ifndef PHYSX_MESSAGE_ACTOR_CONTROL_HPP
#define PHYSX_MESSAGE_ACTOR_CONTROL_HPP

#include <gal/stl/wrapper.hpp>

#include <neb/fnd/core/actor/util/decl.hpp>

#include <neb/net/message/Actor/Base.hh>

//#include <neb/net/phx/core/actor/util/decl.hpp>

namespace neb { namespace net { namespace msg { namespace actor { namespace control { namespace rigidbody {


	/** @brief %create. */
	class create:
		virtual public neb::net::msg::actor::base
	{
		gal::stl::wrapper<neb::fnd::core::actor::control::rigidbody::base>		control_;
	};
	/** @brief %create. */
	class icreate:
		virtual public neb::net::msg::actor::base
	{
		public:
			/** @brief derived serialize. */
			virtual void					serializederived(
					boost::archive::polymorphic_iarchive & ar,
					unsigned int const & version);
	};
	/** @brief %create. */
	class ocreate:
		virtual public neb::net::msg::actor::base
	{
		public:
			/** @brief derived serialize. */
			virtual void					serializeDerived(
					boost::archive::polymorphic_oarchive & ar,
					unsigned int const & version);
	};
	/** @brief %Update. */
	class update:
		virtual public neb::net::msg::actor::base
	{
		public:
			virtual ~update() = 0;
		public:
			gal::stl::wrapper<neb::fnd::core::actor::control::rigidbody::base>		control_;
	};
	/** @brief %update. */
	class iupdate:
		virtual public neb::net::msg::actor::IBase,
		virtual public neb::net::msg::actor::control::rigidbody::update
	{
		public:
			virtual ~iupdate();
			/** @brief derived serialize. */
			virtual void					serialize(
					boost::archive::polymorphic_iarchive & ar,
					unsigned int const & version);
	};
	/** @brief %update. */
	class oupdate:
		virtual public neb::net::msg::actor::OBase,
		virtual public neb::net::msg::actor::control::rigidbody::update
	{
		public:
			/** @brief derived serialize. */
			virtual void					serialize(
					boost::archive::polymorphic_oarchive & ar,
					unsigned int const & version);
	};
}}}}}}

#endif




