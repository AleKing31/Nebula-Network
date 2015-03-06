#include <assert.h>

#include <gal/net/server.hpp>

//#include <neb/util/typedef.hpp>
#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/core/actor/Base.hpp>
#include <neb/fnd/core/scene/Base.hpp>

#include <neb/net/net/server.hh>

typedef neb::Network::Server THIS;

THIS::Server(
		boost::asio::io_service& io_service,
		ip::tcp::endpoint const & endpoint):
	gal::net::server<neb::Network::Communicating>(io_service, endpoint)
{
}
void		THIS::release()
{
}
void		THIS::accept(std::shared_ptr<neb::Network::Communicating> client)
{
	

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
void		neb::Network::Server::write(std::shared_ptr< gal::net::omessage > omessage) {
	/** @todo impl */
}



