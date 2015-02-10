
#include <PhysX/core/actor/actor/remote.hpp>

phx::core::actor::actor::remote::remote(std::shared_ptr<phx::core::actor::util::parent> parent):
	neb::fnd::actor::base(parent),
	neb::fnd::actor::actor::base(parent),
	neb::fnd::actor::remote(parent),
	neb::fnd::actor::actor::remote(parent),
	phx::core::actor::base(parent),
	phx::core::actor::remote(parent),
	phx::core::actor::actor::base(parent)
{}
void		phx::core::actor::actor::remote::init() {
	
	neb::fnd::actor::actor::remote::init();
	phx::core::actor::actor::base::init();
	
}
/*void		phx::core::actor::actor::remote::release() {

	neb::fnd::actor::actor::remote::release();
	phx::core::actor::actor::base::release();

}*/
void		phx::core::actor::actor::remote::step(gal::etc::timestep const & ts) {
	
	neb::fnd::actor::actor::remote::step(ts);
	phx::core::actor::actor::base::step(ts);


}


