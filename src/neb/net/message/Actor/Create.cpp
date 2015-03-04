
#include <neb/fnd/core/actor/Base.hpp>

#include <neb/net/message/Actor/Create.hh>

void		neb::net::msg::actor::Create::load(std::shared_ptr<neb::fnd::core::actor::base> actor)
{
	assert(actor);

	parent_i_ = actor->getParent()->_M_index;
	
	i_ = actor->_M_index;
	
	wrapper_.ptr_ = actor;
}





