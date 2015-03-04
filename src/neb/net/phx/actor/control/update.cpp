


#include <gal/itf/registry.hpp>

#include <neb/fnd/core/actor/rigidbody/Base.hpp>
#include <neb/fnd/core/actor/control/rigidbody/Base.hpp>

#include <neb/net/phx/actor/control/rigidbody/update.hpp>

void			neb::net::msg::actor::control::rigidbody::iupdate::serialize(
		boost::archive::polymorphic_iarchive & ar,
		unsigned int const & version)
{
	neb::net::msg::actor::IBase::serialize(ar, version);
	ar >> control_;
	
	auto actor = std::dynamic_pointer_cast<neb::fnd::core::actor::base>(gal::itf::shared::registry_.get(index_));
	assert(actor);

	auto rigidbody = actor->is_fnd_actor_rigidbody_base(); //PxActorRigidBodyBase();

	assert(rigidbody);

	assert(rigidbody->control_);

	rigidbody->control_->operator=(*control_.ptr_);
}




