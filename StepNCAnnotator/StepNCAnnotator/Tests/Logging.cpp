//
// CLogging.cpp
//  
// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif 

#include "stdafx.h"
#include "Logging.h"

#include <tchar.h>
#include <stdarg.h>
#include <share.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <stdlib.h>
#include <io.h>
#include <FCNTL.H>
//#include <atlconv.h>

//_COM_SMARTPTR_TYPEDEF(ILoggingDisplay, __uuidof(ILoggingDisplay));
 
#define MAXBUFFERSIZE (2048)
#if BUGSLAYERTRACE
static	ITrace * trace=NULL;
#endif

int CLogging::masterFlag=1;

CLogging CLogging::Log;

CLogging g; // simple way to clean up 

static int ReadAFile(char * filename, CString& str)
{
	long lSize;
	char * buffer;
	size_t result;
	FILE * pFile;
	pFile = fopen ( filename , "rb" );
	if (pFile==NULL)
	{
		return -1;
	}

	// obtain file size:
	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);
	rewind (pFile);

	// allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {return -1;}

	// copy the file into the buffer:
	result = fread (buffer, 1, lSize, pFile);
	if (result != lSize) {return -1;}

	/* the whole file is now loaded in the memory buffer. */

	// terminate
	fclose (pFile);
	str=buffer;
	free (buffer);
	return 0;
}

class InitLogger
{
public:
	InitLogger()
	{
		CLogging::Log.hf=NULL;
	}
	~InitLogger()
	{
		if(CLogging::Log.hf!=NULL)
			fclose(CLogging::Log.hf);
		CLogging::Log.hf=NULL;
	}

};
static InitLogger dummy;

////////////////////////////////////////////////////////////////////////////////////////////////
//  CLogging
/** 
 * Default constructor that allocates buffer of size 2048. CLogging will automatically
 * reallocate this if it is too small. 
 */
CLogging::CLogging()
{
	fd=NULL;
	errfd=NULL;
	regression_fd=NULL;
	logFlag=1;
	logmode=CLogging::File;
	_buffer=NULL;
	_buffersize=MAXBUFFERSIZE;
	_linenumber=0;	
	strFile="";
	nLineNum=-99;
	//strcpy(buffer,"CLogging buffer init");
#if BUGSLAYERTRACE
	trace=NULL;
#endif
	// Initialize buffer
	_buffer=NULL;
	resize(MAXBUFFERSIZE);
}

#include <objbase.h>
void CLogging::InitComConnection()
{
#ifdef COMDISPLAYWINDOW
    HRESULT  hr;
    IUnknown *   lpUnknown ;
	
	hr=CoCreateInstance(CLSID_LoggingDisplay, NULL, CLSCTX_ALL,
		IID_ILoggingDisplay, (void **)&lpUnknown);
	ASSERT(SUCCEEDED(hr));
	hr = lpUnknown->QueryInterface ( IID_ILoggingDisplay       ,
		(LPVOID*)&display  ) ;
	lpUnknown->Release ( ) ;
#endif
#if BUGSLAYERTRACE
	hr = CoCreateInstance ( CLSID_Trace     ,
		NULL            ,
		CLSCTX_SERVER   ,
		IID_IUnknown    ,
		(LPVOID*)&lpUnknown ) ;
	hr = lpUnknown->QueryInterface ( IID_ITrace       ,
		(LPVOID*)&trace  ) ;
    lpUnknown->Release ( ) ;
#endif
}



/**
 * Destructor that cleans up the global variables. This is invoked
 * by a locally declared CLogging in this file. Destructor deletes
 * the logging and regression file name StringExs, and closes any
 * open file descriptors.
 */
CLogging::~CLogging(){

	if(CLogging::fd!=NULL) 
		fclose(CLogging::fd);
	if(CLogging::errfd!=NULL) 
		fclose(CLogging::errfd);
	if(CLogging::regression_fd!=NULL) 
		fclose(regression_fd);
	if(logmode&Regression && (CLogging::_linenumber!=-1))	
		MessageBox(0, _T("Regression Test Succeeded!"), _T("") , MB_OK);
	if(CLogging::_buffer!=NULL)
	{
		delete CLogging::_buffer;
		CLogging::_buffer=NULL;
	}
	CLogging::fd=NULL;
	CLogging::errfd=NULL;
	CLogging::regression_fd=NULL;

	// Don't release or COM component goes away ?
	//	if(display!=NULL) display->Release();
//	if(trace!=NULL) trace->Release();
//	trace=NULL;
}


void CLogging::setHeader(char * file, int line)
{
   strFile= file;
   nLineNum= line;

}
void CLogging::resize(long n)
{
	if(CLogging::_buffer!=NULL) 
		delete CLogging::_buffer;
	CLogging::_buffer = new CHAR[n];
	CLogging::_buffersize=n;
}
int CLogging::SetupConsole()
{
	int i;
	if(hf!=NULL)
		return 0;
	AllocConsole();
	hCrt = _open_osfhandle(
		(long) GetStdHandle(STD_OUTPUT_HANDLE),
		_O_TEXT
		);
	if( (hf = _fdopen( hCrt, "w" )) == NULL)
	{
		return -1;
	}
	*stdout = *hf;
	i = setvbuf( stdout, NULL, _IONBF, 0 );
	return 0;
}

/*
// Diagnostics
CMemoryState  CLogging::oldMemState;
CMemoryState  CLogging::newMemState; 
CMemoryState  CLogging::diffMemState; 
CMemoryState  CLogging::dumpMemState;

void CLogging::startMemorySnapshot(){
		oldMemState.Checkpoint();
		
}
*/



/**
  * Sets the  break point within the memory alloc { n}
  * Really  just a call to _CrtSetBreakAlloc, but is here so that it can accessed
  * in  a central location.
  */
void CLogging::set_CrtSetBreakAlloc( int n ){
		_CrtSetBreakAlloc( n );
}
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/locking.h>
#include <share.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Method to open the logfile given a new filename. The parameter
 * char &#42; newfilename is the  new file name. If an existing logfile
 * is open it is first closed. The new logfile  is opened with "w"
 * permissions. 
 */ 
void CLogging::openLogFile(CString newfilename){
	if(CLogging::fd!=NULL) closeLogFile();
	if(newfilename.GetLength()<1)
		return;
	_filename=newfilename;
#ifdef NOLOGFILESHARING
	CLogging::fd=fopen(newfilename, "w+"); // FIXME: allow append
#else
	CLogging::fd=_fsopen(newfilename, "w+", _SH_DENYNO); // FIXME: allow append
//	fseek(CLogging::fd,0,0);
//	_locking(fileno(CLogging::fd), LK_UNLCK, 30L );
#endif
}

/**
 * Method to reopen a logfile of given name. The parameter
 * char &#42; newfilename is the  file name. If an existing logfile
 * is open it is first closed. The new logfile  is reopened with "a"
 * permissions. 
 */ 
void CLogging::reopenLogFile(CString newfilename)
{
	if(CLogging::fd!=NULL)
		closeLogFile();
	if(newfilename!=L"") 
		_filename=newfilename;
	if(_filename.GetLength()<1) 
		_filename="debug.txt";
	CLogging::fd=fopen(_filename, "a"); // FIXME: allow append

}

/**
 * Method to close the logfile FD and delete logfile name StringEx.
 * The logfile file descriptor   and StringEx name are both set to NULL.
 */ 
void CLogging::closeLogFile()
{
	if(CLogging::fd!=NULL) fclose(CLogging::fd);
	CLogging::fd=NULL;

}

/**
 * Method to flush logging buffer contents to the logfile file descriptor.
 */ 
void CLogging::flush()
{
	if(CLogging::fd!=NULL) fflush(CLogging::fd);
}

void CLogging::header2log(const char * format, ...)
{
	va_list ap;
	va_start(ap, format);
	vlog(format, ap);
	va_end(ap);
	fseek (fd , 0 , SEEK_END);
	_bookmark = ftell (fd);
;
}
void CLogging::graphit(const char * format, ...)
{
	int eof = ftell (fd);
	fseek(fd,_bookmark,0);
	long lSize = eof-_bookmark;
	char * buffer = (char *) malloc(eof-_bookmark);
	int result = fread (buffer, 1, lSize, fd);
	buffer[result]=0;

	CString tmp;
	FILE * gfd = fopen("C:\\Temp\\xyz.plt", "w+");
	tmp+="set ylabel \"Y-AXIS\"\n";
	tmp+="set xlabel \"X-AXIS\"\n";
	tmp+="set zlabel \"Z-AXIS\"\n";
	tmp.AppendFormat("splot 'C:\\Temp\\xyz.dat' using 1:2:3 title '%s' with points\n", format);
	fwrite(tmp, 1, tmp.GetLength(), gfd);
	fclose(gfd);

	gfd = fopen("C:\\Temp\\xyz.dat", "w+");
	fwrite(buffer,1,strlen(buffer), gfd);
	fclose(gfd);
	system("wgnuplot.exe C:\\Temp\\xyz.plt -");
	//WinExec ( "wgnuplot.exe C:\\Temp\\xyz.plt -", SW_SHOWNORMAL );
	return;

}

CString CLogging::readRegressionLine()
{
	static char buffer[1028];
	buffer[0]=0;
	if(regression_fd!=NULL)
		fgets(buffer,1028, regression_fd);
	return CString(buffer);
}

void CLogging::openRegressionLogFile(CString newfilename, CString title)
{	
	struct tm *ptr; char str[100];
	time_t tm = time(NULL);
	if(CLogging::fd!=NULL) 
		closeLogFile();
	if(newfilename.GetLength()<1)
		return;
	_filename=newfilename;

	CLogging::fd=_fsopen(newfilename, "w+", _SH_DENYNO); // FIXME: allow append
	fseek(CLogging::fd,0,0);
//	_locking(fileno(CLogging::fd), LK_UNLCK, 30L );

	if(fd==NULL)
		return;
	strftime(str ,100 , "%A %c", localtime(&tm));
	log("%s, Created: %s CLogger Version: %s\n", title, str, CLogging::GetVersion() );

}
/**
 * Method to open the regression logfile given a new filename. The parameter
 * char * newfilename is the  new regression logfile name. If an existing regression logfile
 * is open it is first closed. The new regression logfile  is opened with "r"
 * permissions.  The routine also resets the CLogging::linenumber to zero.
 */ 
void CLogging::useRegressionLogFile(CString newfilename)
{
	if(CLogging::regression_fd!=NULL) 
		fclose(regression_fd);

	_regressionFilename=newfilename;
	if(!logmode&Regression)
	{
		logmode|=Regression;
	}
	if((CLogging::regression_fd=fopen(_regressionFilename, "r"))==NULL){
		MessageBox(0, _T("Unable to Perform Regression: Couldn't Open File - check permissions"), _T("") , MB_OK);

		CLogging::_linenumber=0;
	}
	// else MessageBox(0, "Unable to Perform Regression: Couldn't Open File - must set Regression Mode First", "" , MB_OK);
}


/** 
 *  Set logging level. 0 is off. 9 is the highest level of debugging. (Opposite
 * of many debuggers, but setting to 0 turns it off, which is intuitive.
 * @parameter flag is the level.
  * Turn on (1) or off (0) the logging of information
  */
void CLogging::setLog(int flag)
{
	logFlag=flag;
}

/**
 * Bitwise or together the enumeration CLogging modes. Enumeration modes are:
 <UL>
 <LI> CLogging::Off - no logging is performed. </LI>
 <LI> CLogging::Echo  - echo the logged message to stdout. </LI>
	<LI>	CLogging::Pause  - after logging each message, wait for character from stdin, before continuing</LI>
	<LI>	CLogging::File  - log message to file (default file is debut.txt). </LI>
	<LI>	CLogging::Memory - log message to ring buffer, not implemented yet.</LI>
	<LI>	CLogging::Trace - send messages to the visual studio TRACE debugging facility</LI>
	<LI>	CLogging::Batch </LI>
	<LI>	CLogging::Regression - check message against that logged in regression file, if message doesn't match that logged on
	 on generation file, then pop up message box stating so. Uses method useRegressionLogFile() to set regression_fd to do regression matching.
	</LI>
	</UL>
 */
void CLogging::setMode(LoggingMode type)
{
	logmode=type;
}

/**
 * Bitwise or together the new modes with the current logmode.
 */
void CLogging::addMode(LoggingMode type)
{
	int oldmode = logmode;
	logmode|=type;
#ifdef COMDISPLAYWINDOW

	if(display==NULL)
	{
		InitComConnection();
	}
#endif
}

/**
 * Bitwise negative and together the new logmode with the current logmode.
 */
void CLogging::removeMode(LoggingMode type)
{
	logmode&=~type;
}
/**
  * Protected method to save, echo, and analyze logging information.
  * Depending on the logmode, file write, echo, keyboard pause for acknowledgement,
  * and regression testing can occur.
  * If no logging file has been opened, the file debug.txt will be opened.
  * Potential exceptions in the routine include:<P>
  * Testing Failure:No Logging - File Open Problem. <P>
  * Testing Failure:Unable to Perform Regression: No File Given.<P>
  * Testing Failure:Regression Test Mismatch (if regression logmode is set)
  */
void CLogging::vlog(const char * format, va_list ap)
{
	USES_CONVERSION;
	std::string  outputbuffer;

	// If master logging switch off return
	if(!masterFlag) 
		return;

	// If no local logging switch off return
	if(!logFlag) 
		return;

	// If bad format, really an error
	if(format==NULL) 
		return;

	if(_buffer==NULL) 
		resize(_buffersize * 10); 
	
	for(int i=1; ;i++)
	{
		int size = _vsnprintf(_buffer, _buffersize, format, ap);
		if(size<0) 	resize(_buffersize * 10); 
		else break;
	}

	// Add time entry to front of logging message
	if(logmode&Timed)
	{
		char tmpbuf[128];
		
		struct _timeb tstruct;

		_strtime( tmpbuf );
		outputbuffer.append(tmpbuf);
		outputbuffer.append(":");
		_ftime( &tstruct );
		char tbuf[4];
		sprintf(tbuf,"%03d",tstruct.millitm);
		outputbuffer.append(tbuf); 
		outputbuffer.append(" ");
	}

	// Add file and line number to front of logging message
	if(strFile.GetLength()>0)
	{
		char linenum[20];
		outputbuffer.append(strFile);
		outputbuffer.append("(");
		outputbuffer.append(_itoa(nLineNum, linenum, 10));
		outputbuffer.append("):");

		strFile="";
		nLineNum=-99;

	}
//	outputbuffer.append(buffer);
	outputbuffer+=_buffer;

	if(logmode & Unique)
	{
		if(!lastoutputbuffer.Compare(CString( _buffer)))
		return;
	}
	lastoutputbuffer=_buffer;

//	pBuffer=const_cast < char * > ( outputbuffer.c_str());
//	pBuffer=buffer;
//	pBuffer=&outputbuffer[0];

	if(logmode&File)
	{
		if(CLogging::fd==NULL) {
			CLogging::openLogFile("debug.txt"); 
		}
		if(CLogging::fd==NULL) { 
			MessageBox(0, _T("No Logging - File Open Problem"), _T("") , MB_OK);
			throw "Testing Failure: No Logging - File Open Problem";
			
		}
		
		fputs(outputbuffer.c_str(),fd);
	}

	if(logmode&MsgBox)
	{
		MessageBox(0, A2CT(outputbuffer.c_str()), _T("") , MB_OK);
	}
	if(logmode&CLogging::Console)
	{
		if(CLogging::hf==NULL)
			SetupConsole();

		if(CLogging::hf!=NULL)
		{
			fprintf(stdout, "%s", outputbuffer.c_str());
			//OutputDebugString(outputbuffer.c_str());
		}
	}
	if(logmode&ErrFile)
	{
		if(CLogging::errfd==NULL) 
		{
#ifdef NOLOGFILESHARING
			CLogging::errfd=fopen("errlog.txt", "w"); // FIXME: allow append
#else
			CLogging::errfd=_fsopen("errlog.txt", "w", _SH_DENYNO); // FIXME: allow append
#endif			
		}
		
		if(CLogging::errfd==NULL) { 
			MessageBox(0, _T("No Error Logging File - File Open Problem\r\nError Logging Disabled"), _T("") , MB_OK);
			
		}
		
		if(CLogging::errfd!=NULL) 
			fputs(outputbuffer.c_str(),fd);
	}
	if(logmode&Memory)
	{
		// Not implemented yet
		//fprintf(stderr, format, ap);
	}

#ifdef COMDISPLAYWINDOW
	if(logmode&COM)
	{

		if(	display==NULL) InitComConnection(); // keep trying to attach to pipe
		if(	display!=NULL)
		{	
			_bstr_t tmp(outputbuffer.c_str());
			display->AddStringEx(tmp.copy());
#if BUGSLAYERTRACE
			if(	trace!=NULL)
				trace->Trace ( (BSTR) tmp ) ;
#endif	
		}
	}
	
#endif

	if(logmode&Echo) fputs(outputbuffer.c_str(),stderr);
#if 0
	if(logmode&Regression)
	{
		// Enabling regression may have come after use
		if(CLogging::regression_fd==NULL) {
			CLogging::useRegressionLogFile(regressionFilename); 
		}
		if(CLogging::regression_fd==NULL) {
			MessageBox(0, "Unable to Perform Regression: No File Given", "" , MB_OK);
			throw "Testing Failure:Unable to Perform Regression: No File Given";
			
		}	
		int n = strlen(pBuffer);
		char tmp[20];
		int i;
		for(i=0;i<n; i++){
			// fgets(tmp,1,fd) only returns the trailing zero!!
			// There could be faster way, but not as simple
			if(fgets(tmp,2, regression_fd)==0) throw "Regression Test Mismatch";;
			if(pBuffer[i]!=tmp[0]) break;
			if(tmp[0]=='\n') CLogging::linenumber++;
		}
		if(i!=n) {
			char *tmp = strdup(pBuffer);
			sprintf(buffer, "Regression Test Mismatch: at line %d\n    %s\n", CLogging::linenumber, tmp);
			MessageBox(0, buffer, "" , MB_OK);
			delete tmp;
			CLogging::linenumber=-1;
			// Throw exception so that in the debugger you can do a 
			// stack trace to see where the exception was generated

			// throwing this exception causes the following debugging info to be displayed: 
			//  e.g. "First-chance exception in TestClasses.exe (KERNEL32.DLL): 0xE06D7363: Microsoft C++ Exception."
			throw pBuffer;
		}
	
	}
	if(logmode&Trace)
	{ 
		int n = strlen(pBuffer);
		if(n<511) OutputDebugString(pBuffer);
		else {
			int m= (n/512) + 1;
			for(int i=0; i<m; i++){
				char tmp = buffer[((i+1)*512)-1];
				pBuffer[((i+1)*512)-1]=0; // truncate
				OutputDebugString(&pBuffer[i*512]);
				pBuffer[((i+1)*512)-1]=tmp; // truncate
			}
		}
	}
#endif
	// Regression Untested since change to std::StringEx, since rarely used
	if(logmode&Regression)
	{
		// Enabling regression may have come after use
		if(CLogging::regression_fd==NULL) 
		{
			CLogging::useRegressionLogFile(_regressionFilename); 
		}
		if(CLogging::regression_fd==NULL) 
		{
			MessageBox(0, _T("Unable to Perform Regression: No File Given"), _T("") , MB_OK);
			
		}	
		int n = outputbuffer.length(); // strlen(pBuffer);
#define REGRESSION_SIZE 1028
		char tmp[REGRESSION_SIZE];
		int i;
		if(n==0)
			return;
		for(i=0;i<n; )
		{
			if(fgets(&tmp[i],2, regression_fd)==0) 
				break;
			if(tmp[0]=='\r')
				continue;
			if(outputbuffer[i]!=tmp[i]) 
				break;
			if(tmp[0]=='\n') 
				CLogging::_linenumber++;
			i++;
		}
		tmp[i]=0;
		if(i!=n) 
		{
			CString buffer;
			buffer.Format("Regression Test Mismatch: at line %d\tExpect: %s\n\tGot: %s\n", _linenumber,  tmp, outputbuffer.c_str());
			//MessageBox(0, A2T(buffer), _T("") , MB_OK);
			OutputDebugString(buffer);

		}
	
	}
	if(logmode&Trace)
	{ 
		USES_CONVERSION;
		int n = outputbuffer.length(); // strlen(pBuffer);
		if(n<511){
			OutputDebugString(A2CT(outputbuffer.c_str()));
		}
		else {
			int m= (n/511) + 1;
			for(int i=0; i<m; i++)
			{
				std::string  tmpbuf = outputbuffer.substr(i*511, 511);
				OutputDebugString(A2CT(tmpbuf.c_str()));
			}
		}
	}	
	if(logmode&Pause && !(logmode&Batch)) {
		fprintf(stderr,"Press any key to continue\n");
		getchar();
	}

#if _ATL_VER == 0x0700
	outputbuffer.clear();
#else
	outputbuffer="";
#endif
}

/**
 *  Method to log messages using a (f)printf format StringEx. VarArgs 
 *  are used to allow variable stack size parameters. The method
 *  allows users to change the logmode. 
 * FIXME: add logmode to allow conditional pause, by passing condition method pointer.
 * @parameter newmode indicates type of logmode in which to log
 <UL>
 <LI> Off - no logging is performed. </LI>
 <LI> Echo  - echo the logged message to stdout. </LI>
	<LI>	Pause  - after logging each message, wait for character from stdin, before continuing</LI>
	<LI>	File  - log message to file (default file is debut.txt). </LI>
	<LI>	Memory - log message to ring buffer, not implemented yet.</LI>
	<LI>	Batch </LI>
	<LI>	Regression - check message against that logged in regression file, if message doesn't match that logged on
	 on generation file, then pop up message box stating so. Uses method useRegressionLogFile() to set regression_fd to do regression matching.
	</LI>
	</UL>
@see useRegressionLogFile.
 */
void CLogging::log(LoggingMode newmode, const char * format, ...){
	// If no logging return
	int oldmode = logmode;
	logmode=newmode;

	va_list ap;
	va_start(ap, format);
	vlog(format, ap);
	va_end(ap);
	logmode=oldmode;
}

/**
 *  Method to log messages using a (f)printf format StringEx. VarArgs 
 *  are used to allow variable stack size parameters. The method

  *  allows users to change the logmode.
 *  @parameter level threshold for testing, e.g., log(3,"Hello World")
 *  then if the logging level = 5 it will be logged/displayed, and if logging level = 1
 *  it will not be logged/displayed.
 */
void CLogging::log(int level,const  char * format, ...){

	// If -1 level, then interrupt to find error (like assert)
	// FIXME: add flag to just log error
	if(level==-1)
	{
		_asm int 3;
		level=logFlag; // make sure message logged

	}
	// If no logging return
	if(level>=logFlag){
		
		va_list ap;
		va_start(ap, format);
		vlog(format, ap);
		va_end(ap);
	}
}

/**
 *  Method to log messages using a (f)printf format StringEx. VarArgs 
 *  are used to allow variable stack size parameters. Format is char *
 *  type.
 */
void CLogging::log(const char * format, ...){
	va_list ap;
	va_start(ap, format);
	vlog(format, ap);
	va_end(ap);
}

/**
 *  Method to log error messages using a (f)printf format StringEx to a separater file. VarArgs 
 *  are used to allow variable stack size parameters. Format is char *
 *  type.
 */
void CLogging::errlog(const char * format, ...){
	va_list ap;
	va_start(ap, format);
	int oldmode  = logmode;
	logmode = logmode|ErrFile;
	vlog(format, ap);
	va_end(ap);
	logmode=oldmode;
}

/**
 *  Method to log messages using a (f)printf format StringEx. VarArgs 
 *  are used to allow variable stack size parameters. Format type is
 *  wide StringEx pointer.
 */
void CLogging::wlog(const LPWSTR format, ...){
	va_list ap;
	va_start(ap, format);
	int len = wcslen(format);
	char * cformat = (char *) malloc(len);  
	wcstombs(cformat, format, len);
	vlog(cformat, ap);
	free((void *) cformat);
	va_end(ap);
}
/**
 *  Method to alert user of something significant. Current implementation
 *  displays message on stderr, and then awaits a character.
 */
void CLogging::alert(const char * format, ...){
	// If no logging return

	va_list ap;
	va_start(ap, format);
	vfprintf(fd, format, ap);
	fprintf(stderr,"Alert - Press any key to continue\n");
	getchar();
	va_end(ap);
}

/**
  * Method to manually cause a pause. Need to hit any key
  * to continue. Prints to stderr and awaits a key from stdin. Really, getchar()
  * would work as well, but this will only work if not Batch logmode.
  * @parameters level is the indicator to determine whether to pause or not. Default
  * is to pause.
  */
void CLogging::pause(int level){
	if(logmode&Batch)  return;
	if(level>=logFlag){
		fprintf(stderr,"Press any key to continue\n");
		getchar();
	}
}




inline char PrintChar(unsigned char in)
{
  return in>=33 && in <128 ? in : '.';
}


/**
Do a hex dump at location given by a memory  address  given a buffer size and line length (default 16).
Displays the input address in hexadecimal, followed by 16 space-separated,
hexadecimal bytes, followed by the same 16 bytes in Ascii format.

@example 	CLogging::Log.HexDump(pNewAxisHomingTask, sizeof(CComAxisHomingTask));
*/

bool CLogging::HexDump(void * memory, int BytesToDump, int BytesPerLine)
{  
	unsigned char Bytes[1024];
	char tmp[128];
	std::string        dump="";
	int           curChar,i,j;
	int bytesDumped;
	
	char * pos  = (char *) memory;
	char * HeaderOffset  = (char *) memory;
	if(BytesToDump<=0) return false;
	while(BytesToDump>0)
	{
		sprintf(tmp,"%08X: ", HeaderOffset);
		dump+=tmp;
		HeaderOffset += BytesPerLine; 

		for(i=bytesDumped=0;i<BytesPerLine;i++)
		{
			curChar = (char) *pos;
			pos++;

			if (BytesToDump>0)	
			{
				sprintf(tmp,"%02X ",(curChar&0xFF));
				dump+=tmp;
				Bytes[i] = (unsigned char) (curChar&0xFF);
				--BytesToDump;
				bytesDumped ++;
			} 
			else
			{
				dump+="   ";
				curChar = ' ';
			}
			if (i>0 && ((i+1)%4)==0)
				dump+=" ";
		}	                            
		for(j=0;j<bytesDumped;j++)
		{
			sprintf(tmp,"%c",PrintChar(Bytes[j]));
			dump+=tmp;
		}
		dump+="\n";
	}
	 
	log(const_cast  <char *> (dump.c_str()));
	return true;
}

