#include <PhysX/core/actor/util/parent.hpp>
#include <PhysX/core/actor/remote.hpp>

phx::core::actor::remote::remote(std::shared_ptr<phx::core::actor::util::parent> parent):
	neb::fnd::actor::base(parent),
	neb::fnd::actor::remote(parent),
	phx::core::actor::base(parent)
{
}
/*void				phx::core::actor::remote::release() {
	neb::fnd::actor::remote::release();
	phx::core::actor::base::release();
}*/
void				phx::core::actor::remote::init() {
	neb::fnd::actor::remote::init();
	phx::core::actor::base::init();
}
void				phx::core::actor::remote::step(gal::etc::timestep const & ts) {
	neb::fnd::actor::remote::step(ts);
	phx::core::actor::base::step(ts);

}








