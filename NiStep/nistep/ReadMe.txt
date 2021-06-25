

// invoke serialization of the base class 
    ar & boost::serialization::base_object<base_class_of_T>(*this);




>	StepAnnotator.exe!boost::archive::load<boost::archive::xml_iarchive,MastercamTool>(boost::archive::xml_iarchive & ar={...}, MastercamTool & t={...})  Line 532	C++
 	StepAnnotator.exe!boost::archive::detail::common_iarchive<boost::archive::xml_iarchive>::load_override<MastercamTool>(MastercamTool & t={...}, int __formal=0)  Line 59 + 0x15 bytes	C++
 	StepAnnotator.exe!boost::archive::basic_xml_iarchive<boost::archive::xml_iarchive>::load_override<MastercamTool>(const boost::serialization::nvp<MastercamTool> & t={...}, int __formal=0)  Line 82	C++
 	StepAnnotator.exe!boost::archive::xml_iarchive_impl<boost::archive::xml_iarchive>::load_override<boost::serialization::nvp<MastercamTool> const >(const boost::serialization::nvp<MastercamTool> & t={...}, int __formal=0)  Line 75	C++
 	StepAnnotator.exe!boost::archive::detail::interface_iarchive<boost::archive::xml_iarchive>::operator>><boost::serialization::nvp<MastercamTool> const >(const boost::serialization::nvp<MastercamTool> & t={...})  Line 62	C++
 	StepAnnotator.exe!boost::archive::detail::interface_iarchive<boost::archive::xml_iarchive>::operator&<boost::serialization::nvp<MastercamTool> const >(const boost::serialization::nvp<MastercamTool> & t={...})  Line 69	C++


>	StepAnnotator.exe!boost::archive::basic_xml_iarchive<boost::archive::xml_iarchive>::load_override<MastercamTool>(const boost::serialization::nvp<MastercamTool> & t={...}, int __formal=0)  Line 80	C++
 	StepAnnotator.exe!boost::archive::xml_iarchive_impl<boost::archive::xml_iarchive>::load_override<boost::serialization::nvp<MastercamTool> const >(const boost::serialization::nvp<MastercamTool> & t={...}, int __formal=0)  Line 75	C++
 	StepAnnotator.exe!boost::archive::detail::interface_iarchive<boost::archive::xml_iarchive>::operator>><boost::serialization::nvp<MastercamTool> const >(const boost::serialization::nvp<MastercamTool> & t={...})  Line 62	C++
 	StepAnnotator.exe!boost::archive::detail::interface_iarchive<boost::archive::xml_iarchive>::operator&<boost::serialization::nvp<MastercamTool> const >(const boost::serialization::nvp<MastercamTool> & t={...})  Line 69	C++

>	StepAnnotator.exe!boost::archive::basic_xml_iarchive<boost::archive::xml_iarchive>::load_override<MastercamTool>(const boost::serialization::nvp<MastercamTool> & t={...}, int __formal=0)  Line 80	C++
   template<class T>
    void load_override(
        #ifndef BOOST_NO_FUNCTION_TEMPLATE_ORDERING
        const
        #endif
        boost::serialization::nvp<T> & t,
        int
    ){
        this->This()->load_start(t.name());
        this->detail_common_iarchive::load_override(t.value(), 0);
        this->This()->load_end(t.name());
    }



$(ProjectDir)../../../bin.v2/libs/serialization/build/msvc-7.1/debug/threading-multi


<Line>
<Start>2.804167 13.854445 2.110000</Start>
<End>1.595834 13.854445 2.110000</End>
</Line>

<Arc>
<Start>1.595834 13.854445 2.110000</Start>
<End> 1.543334 13.906945 2.110000</End>
<Center>1.595834 13.906945 2.110000</Center>
<Radius>0.052500 </Radius>
<StartAngle>3.141593 </StartAngle>
<SweepAngle>1.570796 </SweepAngle>
</Arc>
G70 Dimension in inches (lengths)
G71 Metric dimension (lengths)
G94 Linear feedrate F in mm/min or inch/min and °/min 
G95 Revolutional feedrate F in mm/rev or inches/rev
N20 $TC_DP1[1,1]=120 Definition of an end mill
N30 $TC_DP3[1,1]=20 with length 20 mm
N40 $TC_DP6[1,1]=5 and with radius 5 mm

http://www.stack.nl/~dimitri/doxygen/formulas.html

int pmCartCartProj(PmCartesian v1, PmCartesian v2,
                   PmCartesian * vout)
{
  int r1, r2, r3;
  double d;

  r1 = pmCartUnit(v2, &v2);
  r2 = pmCartCartDot(v1, v2, &d);
  r3 = pmCartScalMult(v2, d, vout);

  ========> return pmErrno = r1 || r2 || r3 ? PM_NORM_ERR : 0;
}

span.highlighted { background-color: #161616; font-weight: bold; } 
span.term0 { background-color: #161633; } 
span.term1 { background-color: #331616;} 
span.term2 { background-color: #163316; }


C:/Program Files/NIST/proj/Tests/NiStep/NiStep/StepNode.cpp:150: Warning: argument `Index1' of command @param is not found in the argument list of IStepNode::SwapListItems(LONG index1, LONG index2)
C:/Program Files/NIST/proj/Tests/NiStep/NiStep/StepNode.cpp:150: Warning: argument `Index2' of command @param is not found in the argument list of IStepNode::SwapListItems(LONG index1, LONG index2)
C:/Program Files/NIST/proj/Tests/NiStep/NiStep/StepNode.cpp:150: Warning: The following parameters of IStepNode::SwapListItems(LONG index1, LONG index2) are not documented:
  parameter index1
  parameter index2


main_workplan/its_elements/its_elements[1]/its_secplane/
main_workplan/its_elements/its_elements[1]/its_secplane/

Run-Time Check Failure #0 - 
The value of ESP was not properly saved across a function call.  
This is usually a result of calling a function declared with one calling convention 
with a function pointer declared with a different calling convention.

============> CComObject base better be declared 1st!!!!!!!!!!
----


Never cast interface pointers. WebBrowser object doesn't in fact
implement IHTMLDocument3. The pointer you get out of the cast is bogus.

Get the document object by calling IWebBrowser2::get_Document, query -
don't cast - this object for IHTMLDocument3.

--
That's what I thought. You are effectively downcasting from IDispatch to
ICOMQueryResultSet. You cannot do that - you must use QueryInterface to
obtain one interface pointer from another. You need something like this:

CComPtr<IDispatch> resultsetDisp;
schema->Query(query, &resultsetDisp);
CComQIPtr<ICOMQueryResultSet> resultset = resultsetDisp;

---
Did you register the proxy-stub for interface B? Remember, it is not marked 
as automation-compliant

http://www.cs.odu.edu/~wild/cs477/spring02/automation.htm 

In case you didn't know, MIDL does not generate proxy/stub marshaling code for any
interfaces within the library block



interface ISearchCollection
  : IDispatch
{
   [propget, id(DISPID_NEWENUM), restricted, hidden] 
   HRESULT _NewEnum([out,retval] IUnknown** pVal);
};
http://www.ddj.com/cpp/184401803?pgno=8
struct dirparts_proxy_traits
{
  static CComVariant make_value(const recls_strptrs_t &ptr);
};
typedef stlsoft::proxy_sequence < const recls_strptrs_t, CComVariant
                      , dirparts_proxy_traits> directory_parts_type;
typedef CComEnumOnSTL           < IEnumVARIANT, &IID_IEnumVARIANT, VARIANT,
                                _Copy<VARIANT>, directory_parts_type>     
                                  Enumerator_t;
typedef ICollectionOnSTLImpl    < IDirectoryPartsCollection, 
                                directory_parts_type, VARIANT, _Copy<VARIANT>,
                                Enumerator_t>     
                                Collection_t;
class ATL_NO_VTABLE DirectoryPartsCollection
  : public CComObjectRootEx<CComMultiThreadModelNoCS>
  , public IDispatchImpl<Collection_t, 
           &IID_IDirectoryPartsCollection, &LIBID_RECLS_COMLib>
  , public atlstl::SupportErrorInfoImpl<&IID_IDirectoryPartsCollection>
{
public:
  DirectoryPartsCollection()
    : m_punkOwner(NULL)
  {}
  ~DirectoryPartsCollection();
  HRESULT Init(LPUNKNOWN punkOwner, directory_parts_type &parts)
  {
    m_punkOwner = punkOwner;
    if(NULL != m_punkOwner)
    {
      m_punkOwner->AddRef();
    }
    m_coll = parts; // Copy STL collection
    return S_OK;
  }
DECLARE_PROTECT_FINAL_CONSTRUCT()
BEGIN_COM_MAP(DirectoryPartsCollection)
  COM_INTERFACE_ENTRY(IDirectoryPartsCollection)
  COM_INTERFACE_ENTRY(IDispatch)
  COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
// Members
private:
  LPUNKNOWN m_punkOwner;
};




Parse 21 error message list - xml only the last one?





BSTR are marshalled differently than LPCWSTR used in OPC

      virtual HRESULT __stdcall raw_validateNode (
        /*[in]*/ struct IXMLDOMNode * node,
        /*[out,retval]*/ struct IXMLDOMParseError * * errorObj ) = 0;

