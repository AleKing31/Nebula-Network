#ifndef NEBULA_MESSAGE_BASE_HPP
#define NEBULA_MESSAGE_BASE_HPP

#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>

#include <gal/net/message.hpp>

#include <neb/core/itf/shared.hpp>

#include <neb/net/message/Types.hh>

namespace neb {
	namespace message {
		/** \brief %Base
		 *
		 * 
		 */
		class base:
			virtual public neb::fnd::itf::shared
		{
			protected:
				base();
				virtual ~base() {}
		};
		class OBase:
			virtual public neb::message::base
		{
			public:
				OBase();
				virtual void			serialize(
						boost::archive::polymorphic_oarchive & ar,
						unsigned int const & version) = 0;			
			public:
				std::shared_ptr<gal::net::omessage>	msg_;
		};
		class IBase:
			virtual public neb::message::base
		{
			public:
				IBase();
				virtual void			serialize(boost::archive::polymorphic_iarchive & ar, unsigned int const & version) = 0;
			public:
				std::shared_ptr<gal::net::omessage>	msg_;
		};
	}
}

#endif

/** \example Nebula/message/example.cc
 * Example.
 */


