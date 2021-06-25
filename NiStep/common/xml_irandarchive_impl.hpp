#ifndef BOOST_ARCHIVE_XML_RAND_IARCHIVE_HPP
#define BOOST_ARCHIVE_XML_RAND_IARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// xml_irandarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <istream>

//#include <boost/scoped_ptr.hpp>
#include <boost/archive/detail/auto_link_archive.hpp>
#include <boost/archive/basic_text_iprimitive.hpp>
#include <boost/archive/basic_xml_iarchive.hpp>

#include <boost/archive/detail/abi_prefix.hpp> // must be the last header
#include "QueryPath.h"

namespace boost { 
namespace archive {

template<class CharType>
class basic_xml_grammar;
typedef basic_xml_grammar<char> xml_grammar;

template<class Archive>
class xml_irandarchive_impl  :
    public detail::common_iarchive<Archive>
{
#ifdef BOOST_NO_MEMBER_TEMPLATE_FRIENDS
public:
#else
    friend class detail::interface_iarchive<Archive>;
    friend class basic_xml_iarchive<Archive>;
    friend class load_access;
protected:
#endif
 public:

    typedef detail::common_iarchive<Archive> detail_common_iarchive;
 #if 0
     xml_grammar *gimpl;
  std::istream & get_is(){
        return is;
    }
#endif


	    unsigned int depth;
    BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
    load_start(const char *name);
    BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
    load_end(const char *name);

    // Anything not an attribute and not a name-value pair is an
    // should be trapped here.
    template<class T>
    void load_override(T & t,  BOOST_PFTO int)
    {
        // If your program fails to compile here, its most likely due to
        // not specifying an nvp wrapper around the variable to
        // be serialized.
        BOOST_MPL_ASSERT((serialization::is_wrapper<T>));
        this->detail_common_iarchive::load_override(t, 0);
    }
  // Anything not an attribute - see below - should be a name value
    // pair and be processed here
    template<class T>
    void load_override(
        #ifndef BOOST_NO_FUNCTION_TEMPLATE_ORDERING
        const
        #endif
        boost::serialization::nvp<T> & t,
        int
    ){
        this->This()->load_start(t.name());
        this->detail_common_iarchive::load_override(t.value(), 0);
        this->This()->load_end(t.name());
    }
   // instances of micro xml parser to parse start preambles
    // scoped_ptr doesn't play nice with borland - so use a naked pointer
	// scoped_ptr<xml_grammar> gimpl;


    void load_override(class_id_optional_type & /* t */, int)
	{

	}
	BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
		load_override(object_id_type & t, int){
			//   t = this->This()->gimpl->rv.object_id;
	}

	BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
		load_override(version_type & t, int){
			//  t = this->This()->gimpl->rv.version;
	}

	BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
		load_override(class_id_type & t, int){
			//  t = this->This()->gimpl->rv.class_id;
	}

	BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
		load_override(tracking_type & t, int){
			//  t = this->This()->gimpl->rv.tracking_level;
	}

    BOOST_ARCHIVE_DECL(void)
    load_override(class_name_type & t, int);
	
    template<class T>
    void load(T & t){
        //basic_text_iprimitive<std::istream>::load(t);
    }
    BOOST_ARCHIVE_DECL(void)
    load(char * t);
    #ifndef BOOST_NO_INTRINSIC_WCHAR_T
    BOOST_ARCHIVE_DECL(void)
    load(wchar_t * t);
    #endif
    BOOST_ARCHIVE_DECL(void)
    load(std::string &s);
    #ifndef BOOST_NO_STD_WSTRING
    BOOST_ARCHIVE_DECL(void)
    load(std::wstring &ws);
    #endif
   

    BOOST_ARCHIVE_DECL(void)
    init();
    BOOST_ARCHIVE_DECL(BOOST_PP_EMPTY()) 
    xml_irandarchive_impl(unsigned int flags);
    BOOST_ARCHIVE_DECL(BOOST_PP_EMPTY())
    ~xml_irandarchive_impl();
};

// do not derive from the classes below.  If you want to extend this functionality
// via inhertance, derived from text_iarchive_impl instead.  This will
// preserve correct static polymorphism.
#if 0
// same as xml_iarchive below - without the shared_ptr_helper
class naked_xml_iarchive : 
    public xml_iarchive_impl<naked_xml_iarchive>
{
public:
    naked_xml_iarchive(std::istream & is, unsigned int flags = 0) :
        xml_iarchive_impl<naked_xml_iarchive>(is, flags)
    {}
    ~naked_xml_iarchive(){}
};
#endif
} // namespace archive
} // namespace boost

// note special treatment of shared_ptr. This type needs a special
// structure associated with every archive.  We created a "mix-in"
// class to provide this functionality.  Since shared_ptr holds a
// special esteem in the boost library - we included it here by default.
#include <boost/archive/shared_ptr_helper.hpp>
#if 0

namespace boost { 
namespace archive {
class xml_irandarchive : 
    public xml_irandarchive_impl<xml_iarchive>,
    public detail::shared_ptr_helper
{
public:
    xml_irandarchive(std::istream & is, unsigned int flags = 0) :
        xml_irandarchive_impl<xml_irandarchive>(is, flags)
    {}
    ~xml_irandarchive(){};
};
} // namespace archive
} // namespace boost

// required by export
BOOST_SERIALIZATION_REGISTER_ARCHIVE(boost::archive::xml_irandarchive)
#endif

#include <boost/archive/detail/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // BOOST_ARCHIVE_XML_IARCHIVE_HPP
