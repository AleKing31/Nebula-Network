#include <assert.h>

#include <gal/net/server.hpp>

//#include <neb/util/typedef.hpp>
#include <neb/fnd/app/Base.hpp>
//#include <neb/fnd/core/actor/Base.hpp>
//#include <neb/fnd/core/scene/Base.hpp>

#include <neb/net/net/server.hh>

typedef neb::net::server::Base THIS;

THIS::Base()
{

}
void			THIS::init(parent_t * const & parent)
{
	printv_func(DEBUG);

	setParent(parent);

	neb::fnd::net::server::Base::init(parent);

	auto app = get_fnd_app();
	
	if(acceptor_) {
		printv(DEBUG, "already initialized\n");
		return;
	}
	
	auto ios = app->_M_ios;
	assert(ios);

	ip::tcp::endpoint ep(ip::tcp::v4(), portno);
	
	connect(ios, ep);
}
void			THIS::step(gal::etc::timestep const & ts)
{
	printv_func(DEBUG);

}
void			THIS::connect(
		S_IO io_service,
		ip::tcp::endpoint const & endpoint)
{
	printv_func(DEBUG);

	gal::net::server::connect(io_service, endpoint);
}
void			THIS::release()
{
	printv_func(DEBUG);

	gal::net::server::release();
	neb::fnd::net::server::Base::release();
}
void			THIS::accept(
		std::shared_ptr<gal::net::communicating> && client)
{
	printv_func(DEBUG);
	
	typedef neb::net::comm::Base C;
	
	// get proper communicating type
	auto comm = std::dynamic_pointer_cast<C>(create_communicating());
	
	// copy data to new object
	*comm = std::move(*client);
	
	//std::shared_ptr<C> c(cp);
	
	//auto p = getParent();

	gal::weak_ptr<C> w(comm);
	
	neb::fnd::net::comm::util::Parent::S s(std::move(comm));
	
	insert(std::move(s));
	
	w->do_read_header();
	
	// do some other stuff??


	// exp
	//std::shared_ptr<neb::fnd::actor::Control::RigidBody::raw> control_raw(new neb::control::rigid_body::raw);

	/** @todo move all this to Box */

	/*
	   auto scene = app->get_scene(0);
	   assert(scene);

	   std::shared_ptr<glutpp::actor::desc> ad = scene->actors_deferred_[(char*)"player0"];
	   assert(ad);

	   auto actor = app->scenes_[0]->create_actor_local(ad);
	   auto rigidbody = actor->isRigidBody();

	   rigidbody->create_control(control_raw);

	// exp

	app->transmit_scenes(c);

	// exp

	neb::network::control::rigid_body::create control_create;
	control_create.get_addr()->load_this(rigidbody);

	std::shared_ptr<gal::net::message> msg(new gal::net::message);

	msg->write(glutpp::network::type::CONTROL_CREATE);
	control_create.write(msg);

	c->write(msg);

	// exp
	 */
}
void			THIS::write(std::shared_ptr< gal::net::message > omessage)
{
	printv_func(DEBUG);

	/** @todo impl */
	abort();
}



