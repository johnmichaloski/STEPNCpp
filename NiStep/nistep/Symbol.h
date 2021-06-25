// Symbol.h : Declaration of the CSymbol

#pragma once
#include "resource.h"       // main symbols

#include "NiStep_i.h"
#include "Misc.h"
#include <atlstr.h>
#include <vector>
#include "Globals.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



inline CString ExpMangle(CString classname) 
{
	if(classname.GetAt(0)==_T('E'))
		return classname; 
	return StrFormat(_T("E%s") ,(const TCHAR *) classname); 
}
inline CString ExpDemangle(CString classname) 
{
	// remove leading selection classname type
	if(classname.GetAt(0)==_T('_')) 
		classname=classname.Mid(1);

	if(classname.GetAt(0)==_T('E'))
		classname=classname.Mid(1); 
	
	classname.MakeLower();

	return classname;
}

class ISymbolBase :
	public ISmartPointer<ISymbolBase> 
{
public:

	ISymbolBase(): m_bVisited(0), m_eType( nulltype_), m_eListType(unknown_), m_nDimension(0) {}
	virtual ~ISymbolBase() {}

	CString & Name() { return m_sName; }
	CString & Namespace() { return m_sNamespace; }
	CString & Classname() { return m_sClassname; }
	CString   ExpressClassname() { return ExpDemangle(Classname()); }
	CString & ListClassname() { return m_sListClassname; }
	CString   ExpressListClassname() { return ExpDemangle(m_sListClassname); }

	StepNodeType & Type () { return m_eType; }
	StepNodeType & ListType () { return m_eListType; }

	bool IsASimpleListType(StepNodeType _eType ) 
	{
		return (_eType==integer_ || _eType==real_ || _eType == number_ || _eType == boolean_ || _eType == logical_ || _eType==string_ || _eType==enumeration_); 
	}

	bool IsSimpleType() 
	{
		return (m_eType==integer_ || m_eType==real_ || m_eType == number_ || m_eType == boolean_ || m_eType == logical_ || m_eType==string_ || m_eType==enumeration_); 
	}
	bool IsListType() { return Type()== list_ || Type()== set_ || Type()== aggregate_ || Type()== array_ || Type()== bag_; }
	bool IsSimpleListType();
	int GetVisited() { return m_bVisited; }
	void SetVisited(int bval) { m_bVisited = (int) bval; }
	int & Dimension() { return m_nDimension; }
	///////////////////////////////////////////////////////////////////////
	CString m_sName;
	CString m_sNamespace;
	CString m_sClassname;
	CString m_sListClassname;
	CString m_sFile;
	int m_nLine;
	StepNodeType m_eType;

	StepNodeType m_eListType;
	int m_nDimension;
	std::vector<int> m_vLowerBounds;
	std::vector<int> m_vUpperBounds;

	int m_bVisited;
	// vs IExpress * _parent; //???


};
EXP_DECLARE_SMARTPOINTER(ISymbolBase);



