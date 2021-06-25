//
// Logging.h
//
// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#ifndef _Logging_h_
#define _Logging_h_

#include <stdio.h>
#include <stdarg.h>
#include <crtdbg.h>
#include <vector>

#include "atlstr.h"
// or you could use CStdString "tdString.h"

//#define LOGGERTRACE CLogging::Log.setHeader(__FILE__, __LINE__); \
//	CLogging::Log.log

#define LOGGERTRACE CLogging::Log.log

/**
 * A simple logging class to assist in debugging. Has provisions for global naming with
 * static class. Logging class will automatically generate a default "debug.txt" file
 * in which to log messages. The capability to do regression testing against a previously
 * generated log file is possible. Warning, since this uses vfprintf it can only accept
 * logging up to about 1024 bytes, due to a limitation of the system not this class.
 * Modes include:
 *<DL>
		<DT><B> Off        </B></DT><DD> No logging is performed.</DD>
		<DT><B> Echo       </B></DT><DD> Echo to stdout.</DD>
		<DT><B> Pause      </B></DT><DD>  Pause after every log.</DD>
		<DT><B> File       </B></DT><DD>  output to logging file.</DD>
		<DT><B> Memory     </B></DT><DD> log to memory buffer - not implemented.</DD>
		<DT><B> Batch      </B></DT><DD> Batch, no pausing.</DD>
		<DT><B> Regression </B></DT><DD>  Regression testing, compare each log to regression file.</DD>
		<DT><B> Trace      </B></DT><DD> Send echo to visual C++ TRACE debug window.</DD>
 * </DL>
 * <P> Basic use is to include Logging.h and then use static function defined in CLogging.
 * @example

    "Facility for default Global Logging "
	CLogging::Log.openLogFile("mydebugfile.txt");          "else debug.txt is default file"
	CLogging::Log.addMode(CLogging::Echo);                 "add echo to stdout mode"
	CLogging::Log.log("Hello World %dth time\n", 1000);    "can use all printf formatting"
	CLogging::Log.setLog(5);                               "and levels of loggings"
	CLogging::Log.log(1, "Hello World %dth time\n", 1000); "skip this one 1>5 NOT."
	CLogging::Log.log(9, "Hello World %dth time\n", 1000); "but log this one 9>5"
	CLogging::Log.setLog(1);                               "to see all debug messages"

    "Instance of a Logger"
	CLogging logger;
	logger.openLogFile("log.txt");
	logger.log("Hello World %dth time\n", 1001);    
	logger.closeLogFile();                        


 */
class CLogging{
public:
	CLogging();
	~CLogging();
	BOOL logFlag;
	int logmode;
	static int masterFlag;
	static const char * GetVersion() { return  "1.1"; }
	typedef enum{ 
		Off=0x00, 
		Trace =0x01,         // Send echo to visual C++ TRACE debug window
		File =0x02,        //  output to logging file - debug.txt default
		Pause=0x04,		   // Pause after every log 
		Memory=0x08,       // log to memory buffer - not implemented
		Batch=0x10,        // Batch, no pausing
		Regression=0x20,   // Regression testing, compare each log to regression file
		Echo=0x40,         //  Echo to stdout 
		COM=0x100,           // Send echo through COM to exe list Window
		Timed=0x200,           // Prepend time stamp
		ErrFile=0x400,		// Error file output too, not just regular logging file
		MsgBox=0x800,		// Display message in Message Box once \n received?
		Console=0x1000,		// Display messages  in console
		Unique=0x2000   // No duplicate buffer entries
	} LoggingMode;

	virtual void addMode(LoggingMode type);
	virtual void alert(const char * format, ...);
	virtual void closeLogFile();
	virtual void flush();
	virtual void errlog(const char * format, ...);
	virtual void header2log(const char * format, ...);
	virtual void graphit(const char * format, ...);
	virtual void log(const char * format, ...);
	virtual void log(LoggingMode mode, const char * format, ...);
	virtual void log(int mode, const char * format, ...);
	virtual void openLogFile(CString filename="debug.txt");
	virtual void openRegressionLogFile(CString newfilename, CString title);
	virtual void pause(int level=1000);
	virtual void removeMode(LoggingMode type);
	virtual void reopenLogFile(CString filename=_T(""));
	virtual void resize(long n);
	virtual void setMode(LoggingMode type);
	virtual void setLog(int flag);
	virtual void useRegressionLogFile(CString filename);
	virtual CString readRegressionLine();
	virtual void vlog(const char * format, va_list ap);
	virtual void wlog(const LPWSTR format, ...);
	virtual bool HexDump(void * memory, int BytesToDump, int BytesPerLine=0x10);
	virtual int  SetupConsole();

	//////////////////////////////////////////////////////////
	FILE * fd;
	FILE * errfd;
	FILE * regression_fd;
	FILE * hf;  // console handle
	int    hCrt;
	CString _filename;
	CString _regressionFilename;
	char * _buffer;
	int _buffersize;
	int _linenumber;
	int _bookmark;
    
	void setHeader(char * file, int line);
	CString  strFile;
	CString lastoutputbuffer;
	int nLineNum;

	// Com Logging Utility;
	void                         InitComConnection();

	/*
	static  CMemoryState  oldMemState;
	static  CMemoryState  newMemState; 
	static  CMemoryState  diffMemState; 
	static  CMemoryState  dumpMemState;

	static  void  startMemorySnapshot();
	// Set the  break point within the memory alloc { n}
	*/
	static  void  set_CrtSetBreakAlloc( int n );
	// Usage:
	//	CLogging::startMemorySnapshot(); // take a snapshot of all memory
	//	CLogging::set_CrtSetBreakAlloc(1165); //141, 152, 153

	static CLogging Log;
};

// CLogging extension to allow "automated" unit testing by building a method table.
// Graphing of results also permitted. Use _bGraphUnits=1 to turn on feature. 
// UNITTEST_ENTRY_INFO(fn, graphable) defines method and graphability (xyz only).
// This is very quick and dirty but does offer some accountability for upward compatability .

template<class T>
struct _UNITTEST_ENTRY
{
	void ( T::*pfn)();
	char * _name;
	int _bGraphable;
};

//Sink map is used to set up event handling
#define BEGIN_UNITTEST_MAP(_class)\
	typedef _class _GetUnitTestMapFinder;\
	typedef _UNITTEST_ENTRY<_class> UnitTestEntry; \
	typedef void ( _class:: *UnitTestFcn)() ; \
	void TestAll(){\
	const UnitTestEntry * tests = _GetUnitFcnMap();\
	for(int i=0; tests[i].pfn!=NULL; i++){\
		_regressionLogger.header2log("\n%s()\n", tests[i]._name);\
		void ( _class::* const pfn)(void) = tests[i].pfn;\
		(this->*pfn)();\
		if(_bGraphUnits && tests[i]._bGraphable)\
			_regressionLogger.graphit(StrFormat("%s()", tests[i]._name));\
	}}\
	bool _bGraphUnits;\
	static const UnitTestEntry* _GetUnitFcnMap()\
	{\
		PTM_WARNING_DISABLE \
		typedef _class _unittest_classtype;\
		static const _UNITTEST_ENTRY<_class> map[] = {

#define END_UNITTEST_MAP() \
	{0, ""} }; return map;\
	PTM_WARNING_RESTORE \
	}
//#define UNITTEST_ENTRY_INFO(fn) {(void (_unittest_classtype::*)())fn, #fn},
#define UNITTEST_ENTRY_INFO(fn, graphable) { &_unittest_classtype::fn, #fn, graphable},

#endif
