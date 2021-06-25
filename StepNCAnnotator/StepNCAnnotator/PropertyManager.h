//
// PropertyManager.h
//

#pragma once
#include <string>

// DebugProperties.xml

struct debug_settings
{
	void load(const std::string &filename);
	void save(const std::string &filename);
	std::string ToString();

	std::string m_file;          // log filename
	int m_level;                 // debug level
};


class CPropertyManager
{
public:
	CPropertyManager(void);
	~CPropertyManager(void);
};
