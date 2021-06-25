//
// HtmlTable.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once

#include "Misc.h"
#include <map>
#include <algorithm>
 
typedef std::vector<CStringVector> CStringTable;

inline CString  PrintPageJavaScript()
{
	CString tmp;
	tmp+=_T("<script language=\"Javascript1.2\">\n");
	tmp+=_T("<!--\n");
	tmp+=_T("function printpage() {\n");
	tmp+=_T("window.print(); \n"); 
	tmp+=_T("}\n");
	tmp+=_T("</script>");
	return tmp;
}
inline CString  PrintPageButton(CString button=_T("Print"))
{	
	CString str;
	str.Format("<CENTER><form><input type=button value=\"%s\" onClick=\"printpage()\"></form></CENTER>", button);
	return str;
}
inline CString IncludeJavaScript(CString name)
{	
	return StrFormat("<script src=\"%s\" type=\"text/javascript\"></script>", name);
}

/*

	CString tmp;
	CLocationData locdata;
	HTMLParameterTable html;
	html.LoadTableHeader(_T("StockID"), _T("Loccode"), _T("Description"), _T("Quantity"),  _T("ReorderLevel"), NULL);
	for(int i=0; i<this->m_stockitems.size(); i++)
	{
		for(int j=0; j<this->m_stocklocs.size(); j++)
		{
			CInventoryMapIt it = m_inventory.find(StockKeys((LPCTSTR)m_stockitems[i], (LPCTSTR)m_stocklocs[j]));
			if(it!=m_inventory.end())
			{
				locdata=(*it).second;
				StringVector strs =locdata.m_ParameterTable.ToStringVector(_T("StockID"), _T("Loccode"), _T("Description"), _T("Quantity"),  _T("ReorderLevel"), NULL);
				html.AppendTableRow(strs);

			}
		}
	}
	tmp=html.ToHtmlTable();
	return tmp;

	*/
#define MAKEDWORD(l, h)      ((DWORD)MAKELONG(l, h))
#define Str2W(X) ((BSTR) _bstr_t(X)) 

class CHtmlTable
{
public:
	CHtmlTable(CString tablewidth=_T("800"))
	{
		this->tablewidth=tablewidth;
		tableborder=L"3" ;
		cellpadding=L"5"; 
		cellspacing=L"2";
		//tablebgcolor=_L"#FFFFCC");
		// style="background-color:yellow;border:3px dashed black;">
		//  text-align:left
		//tablestyle=_L"font-size: 12pt; color: fuchsia");
		tablebgcolor=L"#FFFFFF";
		tablestyle=L"font-size: 12pt; color: black";  
		headercolor= 0xFFFFCC;
		headercolor = 0x9999CC;
		headeralign=L"center";
		headerstyle=L"font-size: 12pt; font-weight: bold; font-style : italic; color: blue";

	}
	~CHtmlTable(void){};
	void Clear() {
		m_strTableData.clear(); 
		m_strTableHeader.clear();
	}
	void AppendTableRow(CStringVector data )
	{
		m_strTableData.push_back(data);
	}

	
	void AppendTableDelimitedRows(CStringVector rows, CString delimiter )
	{
		for(UINT i=0; i< rows.size(); i++) 
		{
			AppendTableRow(CStringVector::Tokenize(rows[i],delimiter));
		}
	}

	void LoadTableRow(UINT i, CStringVector data )
	{
		if(i< m_strTableData.size())
			m_strTableData[i]=data;
	}

	void LoadTableHeader(CStringVector & m_strVector, const TCHAR* col1, va_list argList)
	{
		CStringVector cols;
		m_strVector.clear();
		if (col1) {
			const TCHAR* ptr = col1;

			while (ptr) {
				cols.push_back(ptr);
				m_strVector.push_back(ptr);
				ptr = va_arg(argList, TCHAR*);
			}
			va_end(argList);
		}
	}
	void LoadTableHeader(const TCHAR* col1,...)
	{
		va_list argList;
		va_start(argList, col1);
		LoadTableHeader(m_strTableHeader, col1,  argList);
	}
	void LoadRowsStyle(const TCHAR* col1,...)
	{
		va_list argList;
		va_start(argList, col1);
		LoadTableHeader(m_strRowStyle, col1,  argList);
	}
	void LoadColumnsStyle(const TCHAR* col1,...)
	{
		va_list argList;
		va_start(argList, col1);
		LoadTableHeader(m_strColumnStyle, col1,  argList);
	}
	//void LoadTableCells(const TCHAR* col1, va_list argList)
	//{
	//	StringVector cols;
	//	m_strTableData.clear();
	//	LoadTableHeader(col1, argList);
	//	TypeInfoTable::iterator it;
	//	StringVector strs;
	//	for(int i=0; i< cols.size(); i++)
	//	{
	//		it=entries.find(cols[i]);
	//		if(it!=entries.end())
	//		{
	//			TypeInfo typeinfo = (*it).second;
	//			strs.push_back(CString(typeinfo.Retrieve()));

	//		}
	//	}
	//	m_strTableData.push_back(strs);
	//}
	CString TableFormat()
	{
		USES_CONVERSION;
		return StrFormat("<table bgcolor=\"%S\" width=\"%S\"  border=\"%S\" cellpadding=\"%S\" cellspacing=\"%S\" style=\"%S\">\n",
			T2W(tablebgcolor), T2W( tablewidth), T2W(tableborder), T2W(cellpadding), T2W(cellspacing),T2W(tablestyle));
	}
	CString TableHeaderRowFormat()
	{
		USES_CONVERSION;
		return StrFormat("<tr align=\"%S\" bgcolor=\"#%06X\" style=\"%S\">\n", T2W( headeralign), headercolor, T2W( headerstyle)); 
	} 
	CString TableRowFormat() {}

	/*CString ToHtmlTable(const TCHAR* col1, ...)
	{
		CString tmp;
		va_list argList;
		va_start(argList, col1);
		LoadTableCells(col1, argList);
		return  ToHtmlTable();
	}*/

	CString ToHtmlTable()
	{
		USES_CONVERSION;
		UINT i,j;
		CString tmp;
		tmp+=TableFormat();
		tmp+=TableHeaderRowFormat();
		for(i=0; i< m_strTableHeader.size(); i++)
		{
			tmp.AppendFormat("<TD>%S</TD>\n", T2W( m_strTableHeader[i]));
		}
		tmp+=_T("</TR>\n");

		for(i=0; i< m_strTableData.size(); i++)
		{
			_bstr_t bstrRowStyle = (m_strRowStyle.size()>i)?  Str2W(m_strColumnStyle[j]) : L"";
			tmp.AppendFormat("<TR %S>", (BSTR) bstrRowStyle);
			for(j=0; j< m_strTableData[i].size(); j++)
			{
				_bstr_t bstrColStyle= (m_strColumnStyle.size()>j)?  Str2W(m_strColumnStyle[j]) : L"";
				tmp.AppendFormat("<TD %S >", (BSTR) bstrColStyle);
				tmp+=m_strTableData[i][j];
				tmp+=_T("</TD>");
			}
			tmp+=_T("</TR>\n");

		}
		tmp+=_T("</TABLE>\n");

		return (const TCHAR *) tmp;		
	}
	/////////////////////////////////////////////////////////////////
	CString tablewidth;
	CString tableheight;
	CString tableborder ;
	CString tablebgcolor ;
	CString cellpadding;
	CString cellspacing;
	CString tablestyle;
	CString headeralign;
	CString headerstyle;
	long headercolor;

	CStringTable m_strTableData;
	CStringVector m_strTableHeader;
	CStringVector m_strColumnStyle;
	CStringVector m_strRowStyle;
};