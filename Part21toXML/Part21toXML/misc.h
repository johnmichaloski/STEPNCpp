//
// Misc.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once

#include <vector>
#include "atlrx.h"
#include "atlcomtime.h"
#include "atlfile.h"
#include "Comutil.h"
#include <atlstr.h>
#include <comdef.h>


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sstream>
#include <iosfwd>
#ifdef UNICODE
typedef std::wstring  tstring;
typedef	std::wifstream tifstream;
typedef std::wstringstream  tstringstream;
typedef std::wstreambuf tstreambuf;
typedef std::wfstream tfstream;
typedef	std::wofstream tofstream;
#define t_str w_str
#else
typedef std::string  tstring;
typedef	std::ifstream tifstream;
typedef std::stringstream  tstringstream;
typedef std::streambuf tstreambuf;
typedef std::fstream tfstream;
#define t_str c_str
typedef	 std::ofstream tofstream;
#define A2T(X) X

#endif
typedef std::vector<CString>::iterator CStringVectorIterator;




template<typename T>
class LogTemplate
{

	void SetDebugLevel(int n) { nDebugLevel=n; }
protected:
	int nDebugLevel;
#ifdef DEBUG
	virtual void Debug(std::string str, int n=0)
	{
		if(n<nDebugLevel)
			OutputDebugString(str.c_str());
	}
#else
#define Debug(X)
#endif
};



//http://www.partow.net/programming/templatecallback/index.html
template < class Class,typename ReturnType=void>
class SingularCallBack
{
public:

	typedef ReturnType (Class::*Method)();

	SingularCallBack(Class* _class_instance, Method _method)
	{
		class_instance = _class_instance;
		method        = _method;
	};

	ReturnType operator()()
	{
		return (class_instance->*method)();
	};

	ReturnType execute()
	{
		return operator()();
	};

private:

	Class*  class_instance;
	Method  method;
};


#define SMARTPOINTER

#ifdef SMARTPOINTER
#include <boost/intrusive_ptr.hpp>



/**
* Generic Template for using boost smart pointer.
*/
template<typename T>
class ISmartPointer
{
public:
	ISmartPointer() : _refs(0) {}
	//! destructor
	virtual ~ISmartPointer(){};
//private:
	int _refs; //! reference count
	friend inline void intrusive_ptr_release(T* pThis)
	{
		if(--pThis->_refs == 0 ) { 
			delete pThis;
		}
	}
	friend inline void intrusive_ptr_add_ref(T* pThis)
	{
		pThis->_refs++;
	}
	friend inline void intrusive_ptr_release(const T* pThis)
	{
		if(--const_cast<T*>(pThis)->_refs == 0 ) { 
			delete const_cast<T*>(pThis);
		}
	}
	friend inline void intrusive_ptr_add_ref(const T* pThis)
	{
		const_cast<T*>(pThis)->_refs++;

	}
};
#endif

/** Load a string given a resource id @param id is the resorce id. */
inline CString LoadResString(UINT id) { CString txt; txt.LoadString((UINT) id); return txt; }


class CStringVector : public std::vector<CString> 
{
public:
	typedef std::vector<CString>  Baseclass;
	CStringVector(){}

	operator const std::vector<CString> () {std::vector<CString>  to_vector;  copy( this->begin(), this->end(), to_vector.begin() ); return to_vector;} 
	CStringVector & operator = (const  std::vector<CString> & from)
	{
		this->resize(from.size());
		copy( from.begin(), from.end(), this->begin() );
		return *this;
	}
 	CStringVector( std::vector<CString> & from)
	{
		this->resize(from.size());
		copy( from.begin(), from.end(), this->begin() );
	}
	explicit CStringVector(int n, ...) 
	{ 
		va_list ap;	
		va_start(ap,n); 
		for(int i=0; i< n; i++)
		{
			CString s =va_arg ( ap, CString );
			push_back(s);
		}
		va_end(ap);
	}
	CString Merge() { CString tmp; for(UINT i=0; i< size(); i++) tmp+=at(i);  return tmp; }
	CString ToString(CString separator=_T(" ")) { 
		CString tmp; 
		for(UINT i=0; i< size(); i++) 
		{
			if(i>0)
				tmp.AppendFormat(_T("%s"), separator);  
			tmp.AppendFormat(_T("%s"), at(i));  
		}
		return tmp; 
	}
	void RemoveBlankStrings()
	{
		for(int i=0; i<size(); i++)
		{
			CString tmp = this->at(i);
			tmp.Replace(_T(" "), _T(""));
			tmp.Replace(_T("\t"), _T(""));
			if(tmp.GetLength() < 1)
			{
				erase(begin() + i);
				i--;
			}

		}
	}
	static CStringVector Tokenize(CString str, CString tokens, int bSave=0)
	{
		CString resToken;
		int curPos= 0;
		CStringVector strs;

		resToken= str.Tokenize(tokens,curPos);
		while (resToken != "")
		{
			strs.push_back((!bSave) ? resToken: resToken+str[curPos-1]);  
			resToken= str.Tokenize(tokens,curPos);
		};
		return strs;
	}
	static CStringVector Extract(CString str, CString tokenA, CString tokenB, int bSave=0)
	{
		CStringVector strs;
		int curPos= str.Find(tokenA);

		str=str.Mid(curPos+1);

		while((curPos=str.Find(tokenB))>=0)
		{
			strs.push_back(str.Mid(0,curPos));
			str=str.Mid(curPos+1);
			if((curPos= str.Find(tokenA)) < 0)
				break;
			str=str.Mid(curPos+1); 
			
		}
		return strs;
	}


};

inline _bstr_t bstrFormat(const WCHAR* format, ...)
{
	USES_CONVERSION;
		CString str;
		va_list ptr; va_start(ptr, format);
#ifdef UNICODE
		str.FormatV(format, ptr);
#else
		str.FormatV(W2A(format), ptr);

#endif
		// Trace model: ATL::CTrace::s_trace.TraceV(m_pszFileName, m_nLineNo, dwCategory, nLevel, pszFmt, ptr);
		va_end(ptr);
		return _bstr_t((LPCTSTR) str);

}

inline CString StrFormat(const TCHAR* format, ...)
{
		CString str;
		va_list ptr; va_start(ptr, format);
		str.FormatV(format, ptr);
		// Trace model: ATL::CTrace::s_trace.TraceV(m_pszFileName, m_nLineNo, dwCategory, nLevel, pszFmt, ptr);
		va_end(ptr);
		return str;

}

inline CString StrReplace(CString inStr, int pos, int n, CString newStr)
{
		return inStr.Mid(0,pos)+ newStr + inStr.Mid(pos+n);

}

inline boolean ReplacePattern(CString & inStr, CString oldBeginningStr, CString oldEndingStr, CString newStr){
	int i,j,k;

	// Sanity checks
	if(inStr.IsEmpty()) 
		return false;
	if(oldBeginningStr.IsEmpty()) 
		return false;
	if(oldEndingStr.IsEmpty()) 
		return false;

	// Setup up StringEx sizes
	int newCnt = newStr.GetLength();  

	i=0; // Let find determine where to start.

	int cnt=0;
	for(;i<inStr.GetLength();)
	{
		if((j=inStr.Find(oldBeginningStr,  i))<0)
			break;
		if((k=inStr.Find(oldEndingStr, j))<0) 
			break;
		inStr = inStr.Mid(0,j)+ newStr + inStr.Mid(k+oldEndingStr.GetLength());
		i=j+newCnt;
		cnt++;
	}
	if(cnt>0) return true;
	return false;
}

// other pattern uses 	GetPartSpecifics("1857-R1.tap", CString("{[0-9]+}[-_]{[0-9a-zA-Z]+}\\..*"), szProdLine, szPartNumber);
inline CString ReplacePattern(CString &inStr,  CString szRegexPattern, CString szReplacement=_T(""))
{
	CString tmp(inStr);
	CString test(inStr);;
	CAtlRegExp<> regexp;
	CAtlREMatchContext<> mc;
	CString szMatch;
	int pos=0;
	try {
		//pattern.Replace(_T("*"), _T(".*"));  // Change from Regular expression to Bourne Expression
		if(regexp.Parse(szRegexPattern) == REPARSE_ERROR_OK)
		{
			while(regexp.Match(test, &mc) )
			{
				const CAtlREMatchContext<>::RECHAR* szStart = 0;
				const CAtlREMatchContext<>::RECHAR* szEnd = 0;

				//for(UINT i=0; i< mc.m_uNumGroups; i++){
					mc.GetMatch(0, &szStart, &szEnd);
					ptrdiff_t nLength = szEnd - szStart;
					szMatch.SetString( szStart,  nLength );
					UINT n = test.Find(szMatch);
					tmp = StrReplace(tmp, n+pos, (int) nLength, szReplacement) ; // inStr.Replace(szMatch, szReplacement);
					pos = pos + n +  nLength - szReplacement.GetLength() ;
				//}
				test=tmp.Mid(pos);
			}
		}

	}
	catch(...) {}
	return tmp;
}

inline int FindPattern(CString inStr, CString szRegexPattern)
{
	CString tmp;
	CAtlRegExp<> regexp;
	CAtlREMatchContext<> mc;
	int n=-1;
	try {
		//pattern.Replace(_T("*"), _T(".*"));  // Change from Regular expression to Bourne Expression
		if(regexp.Parse(szRegexPattern) == REPARSE_ERROR_OK)
		{
			if(regexp.Match(inStr, &mc) )
			{
				const CAtlREMatchContext<>::RECHAR* szStart = 0;
				const CAtlREMatchContext<>::RECHAR* szEnd = 0;

				if(mc.m_uNumGroups>0)
				{
					mc.GetMatch(0, &szStart, &szEnd);
					return (int) (inStr.GetBuffer() - szEnd );
//					szProdLine.SetString( szStart,  nLength );
				}


			}
		}
	}catch(...) {}
	return n;
}


inline void CopyClipboard(CString source)
{
	// Converts TCHAR into char for ascii clipboard
	if(::OpenClipboard(NULL))
	{
		HGLOBAL clipbuffer;
		::EmptyClipboard();
		clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, sizeof(TCHAR) * (source.GetLength()+1));

#ifdef UNICODE
		WCHAR * buffer;
		buffer = (WCHAR *)::GlobalLock(clipbuffer);
		wcscpy(buffer, source);
		::GlobalUnlock(clipbuffer);	
		::SetClipboardData(CF_UNICODETEXT,clipbuffer);

#else
		char * buffer;
		buffer = (char *)::GlobalLock(clipbuffer);
		strcpy(buffer, (LPCTSTR) source);
		::GlobalUnlock(clipbuffer);		
		::SetClipboardData(CF_TEXT,clipbuffer);

#endif
		::CloseClipboard();
	}
}



inline CString ReadAFile(CString lpszPathName)
{
	CString sBuffer;
	HANDLE	hFile = CreateFile(lpszPathName,
		GENERIC_READ,              // open for reading 
		FILE_SHARE_READ,           // share for reading 
		NULL,                      // no security 
		OPEN_EXISTING,             // existing file only 
		FILE_ATTRIBUTE_NORMAL,     // normal file 
		NULL);                  

	if (INVALID_HANDLE_VALUE == hFile)
	{
		//m_sLastErrmsg="File INVALID_HANDLE_VALUE Error";
		return _T("");
	}
	DWORD dwBytesRead;
	DWORD dwFileSize = GetFileSize(hFile, NULL);

	BYTE * lpBuffer = new BYTE[dwFileSize+1];

	if (!ReadFile(hFile, lpBuffer, dwFileSize, &dwBytesRead, NULL) != FALSE)
	{
		return _T("");
	}

	lpBuffer[dwBytesRead]=0;
	sBuffer=lpBuffer;
	delete [] lpBuffer;        

	CloseHandle(hFile);
	return sBuffer;
}

inline CString GetExeDirectory() 
{
	TCHAR buf[1000];
	CString path;
	GetModuleFileName(NULL, buf, 1000);
	path=buf;
	path = path.Left(path.ReverseFind('\\')+1);
	return path;
}

inline CString GetExeTitle() 
{
	TCHAR buf[1000];
	CString path;
	GetModuleFileName(NULL, buf, 1000);
	path=buf;
	path = path.Mid(path.ReverseFind('\\')+1);
	path.Replace(".exe", "");
	return path;
}
#if 0
inline CStringVector GetFileListInFolder(CString myDirectory, CString extension)
{
 // Get a list of files   CFileFind finder;   BOOL finding = finder.FindFile (myDirectory + CString ("\\*.") + extension);    //iterate the results   while (finding)    {      finding = finder.FindNextFile();       //get file path      CString path = finder.GetFilePath());       //get file title      CString title = finder.GetFileTitle()     }     //dont forget to close    finder.Close ();   // Get a list of <strong class="highlight">files</strong>
   CFindFile finder;
   BOOL finding = finder.FindFile (myDirectory + CString ("\\*.") + extension);
   CStringVector files;
   //iterate the results
   while (finding)
    {
      finding = finder.FindNextFile();
    
      //get file path
      CString path = finder.GetFilePath();
      files.push_back(path);
      //get file title
	  //CString title = finder.GetFileTitle();
    }

    //dont forget to close
    finder.Close ();
	return files;
}
#endif
inline CString GetIniFile()
{
	return StrFormat(_T("%s\\Setup.ini"), GetExeDirectory());

}

inline CString UpDirectory(CString szDir) 
{
	CString path = szDir.Left(szDir.ReverseFind('\\')+1);
	return path;
}

#include <fstream>

inline BOOL SaveDocument(CString filename, CString buffer)
{
	try
	{
		tfstream outputfile;
		outputfile.open (filename, tfstream::out );
		if (!outputfile.is_open())
			return FALSE;
		outputfile <<  (LPCTSTR) buffer;
		outputfile.close();
	}	
	catch (...)
	{
		return FALSE;
	}
	return TRUE;
}

inline boolean  GetFileExists(CString filename)
{
	DWORD dw = ::GetFileAttributes(filename);
	return((dw == 0xfffffffff) ? FALSE : dw );

}

inline double DVal(CString values, int n,  CString separator)
{
	CStringVector tokens=CStringVector::Tokenize(values, separator);
	if(n<0 || n>=tokens.size())
		return 0;
	return _tstof(tokens[n]);

}


inline CString dump_com_error(_com_error &e)
{
	CString tmp;
	tmp+=StrFormat(_T("Error\n"));
	tmp+=StrFormat(_T("\a\tCode = %08lx\n"), e.Error());
	tmp+=StrFormat(_T("\a\tCode meaning = %s"), e.ErrorMessage());
	tmp+=StrFormat(_T("\a\tSource = %s\n"), (LPCTSTR) e.Source());
	tmp+=StrFormat(_T("\a\tDescription = %s\n"), (LPCTSTR) e.Description());
	return tmp;
}

#include <atlapp.h>
#include <atldlgs.h>
inline bool SaveFileDialogString(CString szString, LPCTSTR szFilter)
{
	CFileDialog dlg(FALSE,
		_T("*"),
		NULL,
		OFN_HIDEREADONLY,
		szFilter);
	if( dlg.DoModal() != IDOK )
		return 1;
	SaveDocument(dlg.m_szFileName, szString);
	return 0;
}
inline CString LoadFileDialogString(LPCTSTR szFilter)
{
	CFileDialog dlg(TRUE,
		_T("*"),
		NULL,
		OFN_HIDEREADONLY,
		szFilter);
	if( dlg.DoModal() != IDOK )
		return CString();
	return ReadAFile(dlg.m_szFileName);
}



inline CString ReviseFilename(CString filename, CString newtitle, CString titleaddendum, CString newextension)
{
	CString extension;
	CString path = filename.Left(filename.ReverseFind('\\')+1);
	CString title = filename.Mid(filename.ReverseFind('\\')+1);
	extension = title.Mid(title.ReverseFind('.'));
	title = title.Left(title.ReverseFind('.'));
	if(!newtitle.IsEmpty())
		title=newtitle;
	if(!newextension.IsEmpty())
		extension = newextension;

	if(!titleaddendum.IsEmpty())
		title+=titleaddendum;

	CString newFilename = ::UpDirectory(filename)  + title  + extension;
	return newFilename;
}
