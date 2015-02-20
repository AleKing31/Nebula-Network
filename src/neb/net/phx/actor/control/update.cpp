

//#include <Galaxy-Standard/registry.hpp>

#include <neb/core/core/actor/rigidbody/Base.hpp>
#include <neb/core/core/actor/control/rigidbody/Base.hpp>

#include <neb/net/phx/actor/control/rigidbody/update.hpp>

void			phx::message::actor::control::rigidbody::iupdate::serialize(
		boost::archive::polymorphic_iarchive & ar,
		unsigned int const & version)
{
	neb::message::actor::IBase::serialize(ar, version);
	ar >> control_;
	

	auto actor = std::dynamic_pointer_cast<phx::core::actor::base>(gal::itf::shared::registry_.get(index_));
	assert(actor);

	auto rigidbody = actor->isPxActorRigidBodyBase();

	assert(rigidbody);

	assert(rigidbody->control_);

	rigidbody->control_->operator=(*control_.ptr_);
}




