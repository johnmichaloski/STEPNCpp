//
// StepPath.h : Declaration of the CStepPath
//

#pragma once
#include "resource.h"       // main symbols

#include "ExpressUtils.h"
#include "Part21Generator.h"
#include "AttributeList.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

/**
SPath is the StepPath language that provides the ability to navigate around a Step Instance tree, selecting step nodes by a variety of criteria.
SPath approximates a small subset of XPath, the XML Expression Path language. 
In SPath Step Nodes are the equivalent to Express Schema class instances. Each Step Node can have several variables or attributes.
Each attribute is described by the IAttribute interface and implemented by CVarDef.  

SPath consists of  a location path that can be refined by a set of filters. SPath only supports a small set of filters at this time.
A location path selects a set of Step Nodes relative to the context node. As an example 
/feature_placement/location/coordinates
traverses the tree from the current Step node down the attribute/node first feature_placement, then location and finally
coordinates.

The result of evaluating an expression that is a location path is the node-set containing the nodes selected by the location path.
There are two kinds of location path: relative location paths and absolute location paths.
Some difference between SPath and XPath, include the need for SPath to be able to create node elements based on an inheritance hierarchy 

*/
class CExpQueryParser
{
public:
const static int cNewListItem =-1;
const static int cNoListItem =-2;
	CExpQueryParser(CString attrname=L"") { Parse(attrname); }
	int Size() { return _attrs.size(); }
	int size() { return _attrs.size(); }
	CString & operator[](int i)
	{
		static CString tmp;
		if (i<0 || i>_attrs.size())
			return tmp;
		return _attrs[i];
	}
	static void Prune(CString & attr)
	{
		GetItemIndex(attr);
		GetItemClassname(attr);
	}
	static void ParentChild(CString attrname, CString &parent, CString &child)
	{
		int n;
		child.Empty();
		parent.Empty();
		if(attrname[attrname.GetLength()-1]=='/')
			attrname=attrname.Mid(0,attrname.GetLength()-1);
		// remove last attribute
		if((n = attrname.ReverseFind('/'))<0)
		{
			child=attrname;
			return ;
		}
		child = attrname.Mid(n+1); // +1 to skip /
		parent = attrname.Left(n);
	}
	void Parse(CString attr)
	{
		_attr = attr;
		_qualifiers.clear();
		_attrs = CStringVector::Tokenize(attr, _T("/"));
		_qualifiers.resize(_attrs.size());
		for(int i=0; i< _attrs.size(); i++)
		{
			int n;
			_qualifiers[i].index = GetItemIndex(_attrs[i]);
			_qualifiers[i].classname = GetItemClassname(_attrs[i]);

		}

	}
	int & Index(int i) { if(i<0 || i>=_qualifiers.size()) throw std::exception();  return  _qualifiers[i].index; }
	CString & Classname(int i) {if(i<0 || i>=_qualifiers.size()) throw std::exception();  return  _qualifiers[i].classname; }
protected:
	static int GetItemIndex(CString & item)
	{
		int n=cNoListItem;
		CStringVector items = CStringVector::Tokenize(item, _T("[]"));
		if(items.size() < 2)
		{
			return n;
		}
		else if(items.size() > 1)
		{
			item=items[0];
			n = _tstoi(items[1]);
		}
		if(items.size() > 2)
		{
			item+=items[2];
		}
		return n; 
	}

	static  CString GetItemClassname(CString & item)
	{
		CString tmp;
		CStringVector items = CStringVector::Tokenize(item, _T("{}"));
		if(items.size() < 2)
		{
			return tmp;
		}
		else if(items.size() > 1)
		{
			item=items[0];
			return items[1];
		}
		if(items.size() > 2)
		{
			item+=items[2];
		}
		return tmp; 


	}
	struct CExpQueryAttributes
	{
		CExpQueryAttributes() { index=-2; }
		int index;
		CString indexqualifier;
		CString classname;

	};

	CString _attr;
	CStringVector _attrs;
	std::vector<CExpQueryAttributes> _qualifiers;

};



// CStepPath

class ATL_NO_VTABLE CStepPath :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CStepPath, &CLSID_StepPath>,
	public ISupportErrorInfo,
	public IDispatchImpl<IStepPath, &IID_IStepPath, &LIBID_NiStepLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	tstring szP21filename;
	CErrPairs _verifyerrors;
	CPart21Generator _part21gen;
	CVarDefPtr projectvardef;  // top level of STEPNC++ Tree variables
	CVarDefs  stepncvardefs;
	CVarDefs  projectvardefs;

	CStepPath();

DECLARE_REGISTRY_RESOURCEID(IDR_STEPPATH)


BEGIN_COM_MAP(CStepPath)
	COM_INTERFACE_ENTRY(IStepPath)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()
	HRESULT FinalConstruct(){	return S_OK;}
	void FinalRelease(){}

public:

// ISupportsErrorInfo
	STDMETHODDECL InterfaceSupportsErrorInfo(REFIID riid);

	STDMETHODDECL loadStep(BSTR bstrStep, VARIANT_BOOL* isSuccessful);
	STDMETHODDECL loadFile(BSTR bstrFilename, VARIANT_BOOL* isSuccessful);
	STDMETHODDECL clearStep();
	STDMETHODDECL Verify(/*[out, retval]*/ VARIANT * stringsafearray);
	STDMETHODDECL CreateNode(/*[in]*/ BSTR clasname, /*[out, retval]*/ INode ** ppNode);
	STDMETHODDECL IsASimpleType(/*[in]*/ BSTR bstrClassname, /*[out, retval]*/  VARIANT_BOOL* flag);
	STDMETHODDECL IsASimpleListType(/*[in]*/ BSTR bstrVal, /*[out, retval]*/  VARIANT_BOOL* flag);
	STDMETHODDECL GetClassSupertypeHierarchy(/*[in]*/  BSTR bstrClassname, /*[out, retval]*/  VARIANT * stringsafearray);
	STDMETHODDECL GetRoot(INode ** ppNode);
	STDMETHODDECL GetRootAttribute(/*[out,retval]*/  IAttribute ** ppAttribute);
	STDMETHODDECL GetRootAttributeList(/*[out,retval]*/  IAttributeList ** ppAttributeList);
	STDMETHODDECL GetP21Header(INode ** ppNode);
	STDMETHODDECL GetP21HeaderAttribute(/*[out,retval]*/  IAttribute ** ppAttribute);
	STDMETHODDECL GetP21HeaderAttributeList(/*[out, retval]*/  IAttributeList ** ppAttributeList);
	STDMETHODDECL saveFile(/*[in]*/  BSTR bstrFilename, /*[out, retval]*/ VARIANT_BOOL* isSuccessful);
	STDMETHODDECL CreateNewProject(/*[out, retval]*/ INode ** ppNode);
	STDMETHODDECL TranslateP21ToHtml(/*[in]*/ BSTR bstrFilename, /*[out, retval]*/ BSTR * bstrHtml);

};

OBJECT_ENTRY_AUTO(__uuidof(StepPath), CStepPath)
