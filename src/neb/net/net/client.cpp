#include <assert.h>

#include <gal/net/message.hpp>

#include <neb/fnd/core/actor/Base.hpp>

#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/core/scene/Base.hpp>
#include <neb/fnd/net/msg/Base.hpp>

#include <neb/net/net/client.hh>

typedef neb::net::client::Base THIS;

THIS::Base()
{
}
void			THIS::connect(
		boost::asio::io_service& io_service,
		ip::tcp::resolver::iterator endpoint_iterator)
{
	//gal::net::communicating(io_service),
	//neb::Network::Communicating(io_service),
	//gal::net::client(io_service, endpoint_iterator)
}
void		THIS::init(parent_t * const & parent)
{
	setParent(parent);
	
	auto a = get_fnd_app();
	
	auto ios = a->_M_ios;
	
	io_service_ = ios;
	
	char buf[8];
	sprintf(buf, "%i", portno);

	ip::tcp::resolver resolver(*ios);
	//boost::asio::ip::address::from_string(ip)
	ip::tcp::resolver::query q(ip, buf);

	ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(q);
	
	//gal::net::communicating(io_service),
	//neb::Network::Communicating(io_service),
	
	gal::net::client::connect(ios, endpoint_iterator);
}
void		THIS::step(gal::etc::timestep const &)
{
}
void		THIS::release()
{
}
void		THIS::process(std::shared_ptr<gal::net::message> message)
{
	abort();

	//assert(msg->body_length() == sizeof(neb::packet::packet));

	//neb::packet::packet p;
	//memcpy(&p, msg->body(), sizeof(neb::packet::packet));

	//size_t len = msg->body_length();
	/*
	int type;
	msg->read(&type, sizeof(int));
	
	math::hexdump(&type, sizeof(int));
	
	// possibly used
	std::shared_ptr<glutpp::network::scene::create>			scene_create;
	std::shared_ptr<glutpp::network::actor::create>			actor_create;
	std::shared_ptr<glutpp::network::actor::update>			actor_update;
	std::shared_ptr<neb::network::control::rigid_body::create>	control_create;
	
	//
	
	std::shared_ptr<glutpp::window::window> window;
	
	std::shared_ptr<neb::fnd::actor::base>			actor;
	std::shared_ptr<neb::fnd::actor::rigidbody::RigidBody>	rigidbody;
	
	std::shared_ptr<glutpp::scene::desc> sd;
	
	
	std::shared_ptr<glutpp::scene::addr> scene_addr;
	
	std::shared_ptr<glutpp::actor::addr> actor_addr;
	std::shared_ptr<glutpp::actor::desc> actor_desc;
	
	std::shared_ptr<neb::control::rigid_body::raw>	control_raw;
	
	std::shared_ptr<glutpp::network::actor::vec_addr_raw> vec;

	int window_name = 0;
	
	switch(type) {
		case glutpp::network::type::SCENE_CREATE:
			printf("DEBUG: message SCENE_CREATE received\n");
			
			scene_create.reset(new glutpp::network::scene::create);
			//scene_desc.reset(new glutpp::scene::desc);
			//vec_actor_desc.reset(new gal::network::vector<glutpp::actor::desc>)
			
			scene_create->read(msg);
			
			
			window_name = 0;
			
			sd = std::get<0>(scene_create->tup_);
			
			
			app->load_scene_remote(sd);
			
			app->activate_scene(window_name, sd->get_id()->i_);
			
			break;
		case glutpp::network::type::ACTOR_CREATE:
			printf("DEBUG: message ACTOR_CREATE received\n");

			actor_create.reset(new glutpp::network::actor::create);
			
			actor_create->read(msg);
			
			actor_desc = actor_create->get_desc();
			actor_addr = actor_create->get_addr();
			
			scene_addr = actor_addr->get_scene_addr();
			
			app->get_scene(scene_addr)->create_actor_remote(
					actor_addr,
					actor_desc);
			
			break;
		case glutpp::network::type::ACTOR_UPDATE:
			printf("DEBUG: message ACTOR_UPDATE received\n");

			actor_update.reset(new glutpp::network::actor::update);

			actor_update->read(msg);
			
			vec = std::get<0>(actor_update->tup_);
			
			for(auto it = vec->vec_.begin(); it != vec->vec_.end(); ++it)
			{
				auto t = *it;
				std::shared_ptr<glutpp::actor::addr> addr = std::get<1>(t);
				std::shared_ptr<glutpp::actor::raw> raw = std::get<0>(t);
				
				auto a = app->get_actor(addr);
				if(a)
				{
					a->get_raw()->operator=(*raw);
				}
				else
				{
					printf("WARNING: actor not found\n");
				}
			}
			
			break;
		case glutpp::network::type::CONTROL_CREATE:
			printf("DEBUG: message CONTROL_CREATE received\n");
			
			control_create.reset(new neb::network::control::rigid_body::create);
			
			control_create->read(msg);
			
			actor_addr = control_create->get_addr();
			
			window = app->get_window(0);
			
			actor = app->get_actor(actor_addr);
			rigidbody = actor->isRigidBody();
			
			if(window && rigidbody)
			{
				rigidbody->connect(window);
				
				rigidbody->create_control(control_raw);
			}
			
			break;
		default:
			printf("unknwon message type %i\n", type);
			//abort();
	}
*/
}
void			THIS::send(
		std::shared_ptr<neb::fnd::net::msg::Base> m)
{
	assert(m);

	typedef neb::fnd::net::msg::Base T;
	
	/** @todo wtf */
	gal::stl::wrapper<T> wrapper(std::move(m));

	auto buffer = S_MSG(new gal::net::message);
	buffer->init_output();

	/** @todo boost serial warning */
	*buffer->get_oar() << wrapper;

	write(buffer);
}



