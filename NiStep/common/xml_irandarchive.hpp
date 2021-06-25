

#pragma once

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

#include "common/xml_irandarchive_impl.hpp"
#include "common/xml_irandarchive_impl.ipp"

template <char c>
struct concat : public unary_function<std::string, void>
{
	std::string sum;
	void operator()(std::string x) { sum = sum + c + x; }
	void operator()(MSXML2::IXMLDOMNodePtr x) { sum = sum + c + (LPCSTR) x->nodeName; }
	
	concat &  operator + (const char c) { sum+=c; return *this; }
	concat &  operator + (const char * s) { sum+=s; return *this; }
	LPCSTR c_str() { return sum.c_str(); }
};

struct IsXmlist : public unary_function<std::string, void>
{
	bool bFlag;
	bstr_t tag;
	IsXmlist() : bFlag(false)  {}
	void operator()(MSXML2::IXMLDOMNodePtr x) 
	{ 
		if(tag.length() < 1) 
		{ 
			bFlag=true;
			tag=   x->nodeName; 
			return ; 
		} 
		bFlag = bFlag && (tag == x->nodeName) ;
	}
	bool IsList() { return bFlag; }

};
namespace boost { 
namespace archive {
#if 1
class xml_irandarchive : 
    public xml_irandarchive_impl<xml_irandarchive>
{
	std::string &str;
	std::string _name;
	CQueryPath  xml;
	typedef std::vector<MSXML2::IXMLDOMNodePtr> NodeList;
	std::vector<NodeList> _nodes;
	std::vector<int> indexes;
	MSXML2::IXMLDOMElementPtr  _node;
	MSXML2::IXMLDOMElementPtr  subnode;
	unsigned int depth;
	std::vector<std::string> branch;
	std::vector<MSXML2::IXMLDOMNodePtr> subnodes;

public:
	xml_irandarchive(std::string &str_, unsigned int flags = 0) :
        xml_irandarchive_impl<xml_irandarchive>(flags),str(str_) , depth(0)
    {
		xml.Read(str.c_str());
		MSXML2::IXMLDOMNodeListPtr  nodes = xml.pXMLDom->GetchildNodes();
		NodeList nodelist=	Subset (nodes, MSXML2::DOMNodeType::NODE_ELEMENT);
		_nodes.push_back(nodelist);
		indexes.push_back(0);

	}
	NodeList Subset (MSXML2::IXMLDOMNodeListPtr nodes, MSXML2::DOMNodeType type)
	{
		NodeList nodelist;
		for(int i=0; i< nodes->length; i++)
		{
			MSXML2::IXMLDOMNodePtr item=nodes->item[i];
			if(item->GetnodeType() == type)
				nodelist.push_back(item);
		}
		return nodelist;
	}
    ~xml_irandarchive(){};
	void load_start(const char *name)
	{
		MSXML2::IXMLDOMNodePtr node;
		MSXML2::IXMLDOMNodeListPtr  nodes;

		OutputDebugString(StrFormat(L"load_start %s \n", (LPCTSTR) bstr_t(name)));
		depth++;
		_name=name;

		// assumes you can't have missing elements... must be blank
		// to be able to track <As> <A>...</A> <A>...</A> ... </As>

		bool bIsList = for_each(_nodes.back().begin(), _nodes.back().end(), IsXmlist()).IsList();
		int nIndex=indexes.back();;
		if(bIsList)
		{
			if(indexes.back() >= _nodes.back().size())
				throw std::exception("Bounds exceeded");

		}
		else
		{
			// may have more C++ tags than XML tags
			if(indexes.back()>= _nodes.back().size())
				nIndex=_nodes.back().size()-1;

		}
		node = _nodes.back().at(nIndex);
		indexes.back()++;

		nodes = node->GetchildNodes();
		//elem = node;

		OutputDebugString(StrFormat(L"List size = %d\n", nodes->length));
		NodeList nodelist=	Subset (nodes, MSXML2::DOMNodeType::NODE_ELEMENT);
		concat<'\n'> str = for_each(nodelist.begin(), nodelist.end(), concat<'\n'>());
		OutputDebugString((LPCTSTR) _bstr_t(str.c_str()));

		if(nodelist.size() > 0)
		{
			subnodes.push_back(NULL);
			indexes.push_back(0);
			_nodes.push_back(nodelist);
			branch.push_back(name);
		}
		else
		{
			// Problem ordered versus unordered list....
			if(node->nodeName != _bstr_t(name))
			{
				_node=node->parentNode;
				subnode= _node->selectSingleNode((LPCSTR) name);
				if(subnode==NULL)
				{
					DebugBreak();
					concat<'/'> str = for_each(branch.begin(), branch.end(), concat<'/'>())+ '/' + name;
					throw std::exception((LPCSTR) bstrFormat(L"Illegal XML tag %s\n", name));
				}
				subnodes.push_back(subnode);
			}
			else
			{
				subnode=node;
				subnodes.push_back(subnode);
			}
		}
	}
	void load_end(const char *name)
	{
		depth--;
		subnode=subnodes.back();
		subnodes.pop_back();
		if(subnode==NULL)
		{
			indexes.pop_back();
			_nodes.pop_back();
			branch.pop_back();
		}
	}
	template<class T>
	void load(T & t)
	{
		if(subnode==NULL)
		{
			throw std::exception((LPCSTR) bstrFormat(L"Illegal XML tag %s\n", _name));
		}		
		_bstr_t bstrText = subnode->text;
		try {
			t =  (T)  _variant_t(bstrText);
		}catch(...)
		{
			return ;
		}
	}
	void load(std::string & t){
		_bstr_t bstrText = subnode->text;
		t = (LPCSTR) bstrText;
    }
	void load(std::wstring & t){
		if(subnode==NULL)
		{
			throw std::exception((LPCSTR) bstrFormat(L"Illegal XML tag %s\n", _name));
		}	
		_bstr_t bstrText = subnode->text;
		t = (LPCWSTR) bstrText;
    }


};
#endif
} // namespace archive
} // namespace

