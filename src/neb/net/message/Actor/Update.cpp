#include <gal/itf/registry.hpp>

#include <neb/core/core/actor/base.hpp>

#include <neb/net/message/Actor/Update.hh>

void					neb::message::actor::IUpdate::serialize(boost::archive::polymorphic_iarchive & ar, unsigned int const & version) {
	gal::itf::index_type i;
	std::shared_ptr<neb::fnd::core::actor::base> actor;
	
	size_t size;
	ar >> size;
	
	for(size_t a = 0; a < size; ++a) {
		ar >> i;
		actor = std::dynamic_pointer_cast< neb::fnd::core::actor::base >(gal::itf::shared::registry_.get(i));
		ar >> *actor;
	}
}


void					neb::message::actor::OUpdate::serialize(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) {
	size_t size = actors_.size();
	ar << size;
	
	for(auto it = actors_.cbegin(); it != actors_.cend(); ++it) {
		//std::shared_ptr<neb::fnd::actor::base> const & actor = *it;
		/** @todo why?!?!?!? */
		//ar << actor->i_;
		//ar << *actor;
	}
}

