#ifndef __GLUTPP_NETWORK_ACTOR_UPDATE_HPP__
#define __GLUTPP_NETWORK_ACTOR_UPDATE_HPP__

#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <neb/fnd/core/scene/util/decl.hpp>

//#include <neb/config.hh> // gru/config.hpp.in
//#include <neb/master.hh>
//#include <neb/core/scene/desc.hh>
//#include <neb/core/actor/desc.hh>
//#include <neb/core/actor/event.hh>
#include <neb/fnd/core/actor/util/decl.hpp>

//#include <neb/core/scene/Base.hh>

#include <neb/net/message/Actor/Base.hh>

namespace neb { namespace net { namespace msg { namespace actor {
	struct Update:
		virtual public neb::net::msg::actor::base
	{	
		Update() {}
	};
	class OUpdate:
		virtual public neb::net::msg::actor::OBase,
		virtual public neb::net::msg::actor::Update
	{
		public:
			/** @brief Save %Actor. */
			OUpdate&		operator<<(std::shared_ptr<neb::fnd::core::actor::base> actor);

			virtual void		serialize(boost::archive::polymorphic_oarchive& ar, unsigned int const & version);

			::std::vector< std::shared_ptr<neb::fnd::core::actor::base> >	actors_;
	};
	class IUpdate:
		virtual public neb::net::msg::actor::IBase,
		virtual public neb::net::msg::actor::Update
	{
		/** @brief Load */
		virtual void		serialize(boost::archive::polymorphic_iarchive& ar, unsigned int const & version);
	};
}}}}

#endif



