#include <PhysX/core/actor/rigidbody/local.hpp>


phx::core::actor::rigidbody::local::local(std::shared_ptr<phx::core::actor::util::parent> parent):
	neb::fnd::actor::base(parent),
	neb::fnd::actor::actor::base(parent),
	neb::fnd::actor::rigidactor::base(parent),
	neb::fnd::actor::local(parent),
	neb::fnd::actor::actor::local(parent),
	neb::fnd::actor::rigidactor::local(parent),
	neb::fnd::actor::rigidbody::base(parent),
	neb::fnd::actor::rigidbody::local(parent),
	phx::core::actor::base(parent),
	phx::core::actor::local(parent),
	phx::core::actor::actor::base(parent),
	phx::core::actor::actor::local(parent),
	phx::core::actor::rigidactor::base(parent),
	phx::core::actor::rigidactor::local(parent),
	phx::core::actor::rigidbody::base(parent)
{}
void		phx::core::actor::rigidbody::local::init() {
	neb::fnd::actor::rigidbody::base::init();
	neb::fnd::actor::rigidactor::local::init();
}
/*void		phx::core::actor::rigidbody::local::release() {
	neb::fnd::actor::rigidbody::base::release();
	neb::fnd::actor::rigidactor::local::release();
}*/
void		phx::core::actor::rigidbody::local::step(gal::etc::timestep const & ts) {
	neb::fnd::actor::rigidbody::base::step(ts);
	neb::fnd::actor::rigidactor::local::step(ts);
}

