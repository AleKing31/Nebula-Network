


#include <gal/itf/registry.hpp>

#include <neb/fnd/core/actor/rigidbody/Base.hpp>
#include <neb/fnd/core/actor/control/rigidbody/Base.hpp>

#include <neb/net/phx/actor/control/rigidbody/update.hpp>

typedef neb::net::msg::actor::control::rigidbody::update THIS;

THIS::~update()
{
}
void			THIS::load(
		boost::archive::polymorphic_iarchive & ar,
		unsigned int const & version)
{
	neb::net::msg::actor::Base::serialize(ar, version);
	ar >> control_;

	typedef neb::fnd::core::actor::base T;

	auto reg = get_registry();

	auto actor = std::dynamic_pointer_cast<T>(reg->get(index_));
	assert(actor);

	auto rigidbody = actor->is_fnd_actor_rigidbody_base(); //PxActorRigidBodyBase();

	assert(rigidbody);

	assert(rigidbody->control_);

	rigidbody->control_->operator=(*control_.ptr_);
}
void			THIS::save(
		boost::archive::polymorphic_oarchive & ar,
		unsigned int const & version)
{
}


