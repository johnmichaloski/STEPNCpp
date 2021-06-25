#pragma once
#include <map>
#include "Misc.h"

class CHelpInfo
{
public:
	CHelpInfo(void);
	~CHelpInfo(void);

	std::map<CString, CString> description;
};
