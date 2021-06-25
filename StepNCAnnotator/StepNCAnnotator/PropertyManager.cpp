#include "StdAfx.h"
#include "PropertyManager.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>
#include <set>
#include <exception>
#include "Misc.h"



CPropertyManager::CPropertyManager(void)
{
}

CPropertyManager::~CPropertyManager(void)
{
}

std::string debug_settings::ToString()
{
	std::string tmp;
	tmp+= (LPCTSTR) StrFormat("Debug Settings\n");
	tmp+=(LPCTSTR) StrFormat("Level = %d\n", m_level);
	tmp+= (LPCTSTR) StrFormat("Filename = %s\n", m_file);
	return tmp;

}
void debug_settings::load(const std::string &filename)
{

    // Create empty property tree object
    using boost::property_tree::ptree;
    ptree pt;

    // Load XML file and put its contents in property tree. 
    // No namespace qualification is needed, because of Koenig 
    // lookup on the second argument. If reading fails, exception
    // is thrown.
    read_xml(filename, pt);

    // Get filename and store it in m_file variable. Note that 
    // we specify a path to the value using notation where keys 
    // are separated with dots (different separator may be used 
    // if keys themselves contain dots). If debug.filename key is 
    // not found, exception is thrown.
    m_file = pt.get<std::string>("debug.filename");
    
    // Get debug level and store it in m_level variable. This is 
    // another version of get method: if debug.level key is not 
    // found, it will return default value (specified by second 
    // parameter) instead of throwing. Type of the value extracted 
    // is determined by type of second parameter, so we can simply 
    // write get(...) instead of get<int>(...).
    m_level = pt.get("debug.level", 0);


}
void debug_settings::save(const std::string &filename)
{
    // Create empty property tree object
    using boost::property_tree::ptree;
    ptree pt;

    // Put log filename in property tree
    pt.put("debug.filename", m_file);

    // Put debug level in property tree
    pt.put("debug.level", m_level);
    
    // Write property tree to XML file
    write_xml(filename, pt);


}

