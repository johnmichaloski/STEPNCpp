//
// UnitTests.h
//
#pragma once

#include "Logging.h"
#include "Misc.h"  // requires StrFormat


class CUnitTests
{
public:
	CUnitTests(void);
	~CUnitTests(void){};

	void NewRegression(CString filename);
	void RegressionTest(CString filename);

	// Tests
	void TestProject();
	void TestInheritance();
	void TestSelection();
	void TestList();

	BEGIN_UNITTEST_MAP(CUnitTests)
		UNITTEST_ENTRY_INFO(TestProject, 0)
		UNITTEST_ENTRY_INFO(TestInheritance, 0)
		UNITTEST_ENTRY_INFO(TestSelection, 0)
		UNITTEST_ENTRY_INFO(TestList, 0)
	END_UNITTEST_MAP()

	CLogging _dumpLogger;
	CLogging _regressionLogger;

};
