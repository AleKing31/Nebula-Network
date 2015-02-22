
#include <neb/fnd/core/actor/base.hpp>

#include <neb/net/message/Actor/Create.hh>

void		neb::message::actor::Create::load(std::shared_ptr<neb::fnd::actor::base> actor) {
	assert(actor);

	parent_i_ = actor->get_parent()->i_;
	
	i_ = actor->i_;
	
	wrapper_.ptr_ = actor;
}





