//
// Misc.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#define SMARTPOINTER

#include <vector>
#include "atlrx.h"
#include "atlcomtime.h"
#include "atlfile.h"
#include "Comutil.h"
#include <atlstr.h>

#ifdef SMARTPOINTER
#include <boost/intrusive_ptr.hpp>

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
typedef std::vector<CString>::iterator CStringVectorIterator;
inline CString LoadResString(UINT id) { CString txt; txt.LoadString((UINT) id); return txt; }

inline int StrCount(CString s, char c) { int n=0; for(int i=0; i<s.GetLength(); i++) if(s.GetAt(i)==c) n++; return n; }


template<class T>
class TResizingTable  
{
public:
	typedef std::vector<T>  StepTableRow; 


	TResizingTable<T>() //: table (10, std::vector<T>(10)) 
	{
		
	}
	T & operator ()( int i, int j) 
	{
		if(i>=table.size() ) 
			table.resize(i+1);
		if(j>=table[i].size())
			table[i].resize(j+1);
		return table[i][j];

	}
	std::vector<T> & operator[](int i) 
	{ 
		if(i>=table.size() ) 
			table.resize(i+1);
		return table[i]; 
	}
	void clear() {table.clear();   }
	int rows() {  table.size();}
	int cols(int i) {  table[i].size(); }
	int size() { return table.size(); }
	 std::vector< std::vector<T> > table;
	 bool isDuplicate(std::vector<T> & row)
	 {
		for(int i=0; i< table.size(); i++)
			if(table[i]==row)
				return true;
		return false;		
	 }
};
typedef TResizingTable<_variant_t>  VarTable;
typedef std::vector<_variant_t> VarList;
typedef TResizingTable<CString>  StringTable;

inline bool CompareVariants(_variant_t a, _variant_t b, VARTYPE vt)
{
	try {
		if(a.vt == b.vt)
			return a==b;
		a.ChangeType(vt);
		b.ChangeType(vt);
		if(a==b)
			return true;

	}
	catch(...)
	{
	}
	return false;

}


inline  _variant_t operator + (const _variant_t& x, const _variant_t& y) { return _variant_t((double) x + (double) y); }

inline  _variant_t operator - (const _variant_t& x, const _variant_t& y) { return _variant_t((double) x - (double) y); }
inline  _variant_t operator * (const _variant_t& x, const _variant_t& y) { return _variant_t((double) x * (double) y); }
inline  _variant_t operator / (const _variant_t& x, const _variant_t& y) { return _variant_t((double) x / (double) y); }
inline  _variant_t & operator += (_variant_t& x, const _variant_t& y) { x= _variant_t((double) x + (double) y);  return x;}
inline  _variant_t & operator -= (_variant_t& x, const _variant_t& y) { x= _variant_t((double) x - (double) y);  return x;}
inline  _variant_t & operator *= (_variant_t& x, const _variant_t& y) { x= _variant_t((double) x * (double) y);  return x;}
inline  _variant_t & operator /= (_variant_t& x, const _variant_t& y) { x= _variant_t((double) x / (double) y);  return x;}
inline  bool operator < (const _variant_t& x, const _variant_t& y) { return ((double) x) < ((double) y); }
inline  bool operator <= (const _variant_t& x, const _variant_t& y) { return ((double) x) <= ((double) y); }
inline  bool operator > (const _variant_t& x, const _variant_t& y) { return ((double) x )> ((double) y); }
inline  bool operator >= (const _variant_t& x, const _variant_t& y) { return ((double) x )>= ((double) y); }

inline  bool operator == (const _variant_t& x, const int y) { return x == _variant_t(y); }
inline  bool operator != (const _variant_t& x, const int y) { return x != _variant_t(y); }
inline  double fmod (const _variant_t& x, const _variant_t& y) { return fmod((double) x , (double) y); }

class CStringVector : public std::vector<CString> 
{
public:
	CString Merge() { CString tmp; for(UINT i=0; i< size(); i++) tmp+=at(i);  return tmp; }
	CString ToString(CString separator=_T(" ")) { 
		CString tmp; 
		for(UINT i=0; i< size(); i++) 
		{
			if(i>0)
				tmp.AppendFormat("%s", separator);  
			tmp.AppendFormat("%s", at(i));  
		}
		return tmp; 
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
	CStringVector(){}
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

};

inline CString StrFormat(const char* format, ...)
{
		CString str;
		va_list ptr; va_start(ptr, format);
		str.FormatV(format, ptr);
		// Trace model: ATL::CTrace::s_trace.TraceV(m_pszFileName, m_nLineNo, dwCategory, nLevel, pszFmt, ptr);
		va_end(ptr);
		return str;

}
inline std::vector<CString> DoubleZeroString(const char* str, int size)
{
	CString tmp;
	int curPos= 0;
	char last = '1';
	std::vector<CString> strs;
	
	for(int i=0; i<size; i++) 
	{
		if(last==0 && str[i]==0)
			break;
		if(str[i]==0)
		{
			strs.push_back(tmp);  
			tmp.Empty();
		}
		else
		{
			tmp+=str[i];
		}
		last=str[i];

	};
	if(!tmp.IsEmpty())
		strs.push_back(tmp);  
	return strs;

}
inline CString StrReplace(CString inStr, int pos, int n, CString newStr)
{
		return inStr.Mid(0,pos)+ newStr + inStr.Mid(pos+n);

}

inline boolean ReplacePattern(CString & inStr, CString oldBeginningStr, CString oldEndingStr, CString newStr){
	int i,j,k;

	// Sanity checks
	if(inStr.IsEmpty()) return false;
	if(oldBeginningStr.IsEmpty()) return false;
	if(oldEndingStr.IsEmpty()) return false;

	// Setup up StringEx sizes
	int newCnt = newStr.GetLength();  

	i=0; // Let find determine where to start.

	int cnt=0;
	for(;i<inStr.GetLength();){
		if((j=inStr.Find(oldBeginningStr,  i))<0)break;
		if((k=inStr.Find(oldEndingStr, j))<0) break;
		inStr = inStr.Mid(0,j)+ newStr + inStr.Mid(k+1);
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

inline int HandleWindowsMessages()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
	{
		//OutputDebugString(StringEx("After Message=%x wParam = %d  lParam = %d LOWORD(lParam) = %d HIWORD(lParam) = %d\n",msg.message, msg.wParam,msg.lParam, LOWORD(msg.lParam), HIWORD(msg.lParam)));
		if (msg.message == WM_QUIT)
			return 1;       

		::GetMessage(&msg, NULL, 0, 0);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}	


#if 0
inline CString GetTimeStamp(COleDateTime inft, CString szFormat=_T("%A, %B %d %Y %H:%M:%S"))
{
	return inft.Format(szFormat);

}
#endif

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
	path = path.Left(path.ReverseFind('\\')+1);
	return path;
}
inline CString GetIniFile()
{
	return StrFormat("%s\\Setup.ini", GetExeDirectory());

}

inline CString UpDirectory(CString szDir) 
{
	CString path = szDir.Left(szDir.ReverseFind('\\')+1);
	return path;
}

inline BOOL SaveDocument(CString filename, CString buffer)
{
	DWORD dwBytesWritten;
	try
	{
		HANDLE	hFile = CreateFile( filename, // file name 
			GENERIC_READ | GENERIC_WRITE, // open r-w 
			0,                    // do not share 
			NULL,                 // default security 
			CREATE_ALWAYS,        // overwrite existing
			FILE_ATTRIBUTE_NORMAL,// normal file 
			NULL); 
		// no template 
		if (hFile == INVALID_HANDLE_VALUE) 
		{ 
			throw StrFormat ("CreateFile %s failed with error %d.\n", filename,  GetLastError());
		} 
		WriteFile(hFile, 
			buffer, 
			buffer.GetLength(),
			&dwBytesWritten, 
			NULL); 
		CloseHandle(hFile);
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