#ifndef NEBULA_MESSAGE_ACTOR_BASE_HPP
#define NEBULA_MESSAGE_ACTOR_BASE_HPP

#include <neb/net/message/Base.hh>

namespace neb { namespace net { namespace msg { namespace actor {
	class base:
		virtual public neb::net::msg::base
	{
		public:
			/** @brief index
			 *
			 * index of actor
			 */
			gal::itf::index_type			index_;
	};
	class IBase:
		virtual public neb::net::msg::IBase,
		virtual public neb::net::msg::actor::base
	{
		private:
			IBase&			operator=(IBase const &);
		public:
			virtual void		serialize(
					boost::archive::polymorphic_iarchive & ar,
					unsigned int const & version)
			{
				ar & index_;
			}
	};
	class OBase:
		virtual public neb::net::msg::OBase,
		virtual public neb::net::msg::actor::base
	{
		public:
			virtual void		serialize(
					boost::archive::polymorphic_oarchive & ar,
					unsigned int const & version)
			{
				ar & index_;
			}
	};
}}}}

#endif

