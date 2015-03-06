#include <neb/fnd/core/scene/Base.hpp>

#include <neb/net/core/scene/Base.hpp>

typedef neb::net::core::scene::Base THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);
}

