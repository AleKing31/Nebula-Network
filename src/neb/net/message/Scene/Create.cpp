
//#include <neb/app/Base.hh>
#include <neb/fnd/core/scene/base.hpp>
#include <neb/net/message/Scene/Create.hpp>

neb::message::scene::Create::Create() {
}
void neb::message::scene::Create::load(std::shared_ptr<neb::fnd::scene::base> scene) {
	scene_.ptr_ = scene;
}



