#include "StdAfx.h"
#include "Express2Html.h"
#include "ExpressUtils.h"
#include "StepParser.h"
#include "Misc.h"
#include <iostream>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>


static CString tabs("");

typedef std::vector<parser_id> TreeNodes;
static	std::fstream outputfile;


CExpress2Html::CExpress2Html(CStepNCParser & parser) : _parser(parser)
{
}

CExpress2Html::~CExpress2Html(void)
{
}

template<typename TreeIter>
CString Express2Html(const TreeIter& i, CExpress2Html & html)
{
	CString tmp;
	TreeIter findit;
	TreeNodes nodes;
	tabs+="\t";
	int n =  i->value.id().to_long();
	{
		if(n==CExpressTokens::schema_blockID) 
		{
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				if(it->children.size() < 1)
				{
					tmp+=std::string(it->value.begin(), it->value.end()).c_str();
					tmp+=" ";
				}
				
				else if(findNode(it, findit, 0, Nodes(nodes, CExpressTokens::schema_idID, CExpressTokens::simple_idID, 0)))
				{
						TreeIter childit = findit->children.begin();           // characters
						html.schema = std::string(childit->value.begin(), childit->value.end()).c_str();
						tmp+=html.schema+" ";
				}
				else 
					tmp+=Express2Html(it, html); 
			}	
		}


		if(n==CExpressTokens::entity_headID) 
		{
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				CString str = std::string(it->value.begin(), it->value.end()).c_str();

				if(it->value.id().to_long() == CExpressTokens::entity_idID)
				{
					if(findNode(it, findit, 0, Nodes(nodes, CExpressTokens::entity_idID, CExpressTokens::simple_idID, 0)))\
					{
						TreeIter childit = findit->children.begin();           // characters
						CString szEntity = std::string(childit->value.begin(), childit->value.end()).c_str();
						szEntity=szEntity.Trim();
						tmp+=StrFormat("\nENTITY <A NAME=\"%s\">%s </A>", szEntity,szEntity);
					}
				
				}
				else
				{
					tmp+=Express2Html(it, html); 
				}
			}
			goto done;
		}

		if(n==CExpressTokens::derive_clauseID) {
			goto done;
		}	
		// This doesn't work..???
		//	type_decl =str_p("TYPE") >>  type_id >> ch_p('=') >> underlying_type >> 
		//	semicolon >> discard_node_d[*(anychar_p-str_p("END_TYPE"))]	>> str_p("END_TYPE") >> semicolon ;
		if(n==CExpressTokens::type_declID ) 
		{
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				CString str = std::string(it->value.begin(), it->value.end()).c_str();
				if(str=="TYPE")
				{
					tmp+="\nTYPE ";
				}
				else if(it->value.id().to_long()==CExpressTokens::type_idID)
				{
					str=Express2Html(it, html); 
					str=str.Trim();
					tmp+=StrFormat("<A NAME=\"%s\">%s </A>", str, str);
				}
				//else if(str=="END_TYPE")
				//{
				//	tmp+="\nEND_TYPE";
				//}
				else if(str.GetLength() > 0)
				{
					// do we need space?
					tmp+=str+" ";
				}
				else
				{
					tmp+=Express2Html(it, html); 
				}
			}
			goto done;
		}	
#if 1

		if(n==CExpressTokens::explicit_attrID) 
		{
			TreeIter it;

			//explicit_attr  = attribute_decl >> *(ch_p( ',') >>attribute_decl ) >> ch_p(':') 
			//				>> !( str_p("OPTIONAL")) >> base_type >> semicolon ;
			//	base_type  =  aggregation_types | simple_types |  named_types ;
			for(it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				CString str = std::string(it->value.begin(), it->value.end()).c_str();
				if(it->value.id().to_long()== CExpressTokens::attribute_declID)
				{
					// save this for table....
					if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CExpressTokens::attribute_declID, CExpressTokens::attribute_idID, CExpressTokens::simple_idID, 0)))
					{
						TreeIter childit = findit->children.begin();           // characters
						CString szAttr = std::string(childit->value.begin(), childit->value.end()).c_str();
						tmp+="<I>";
						tmp+=szAttr;
						tmp+=" </I>";

					}
				}
				else if(it->value.id().to_long()== CExpressTokens::base_typeID)
				{
					TreeIter childit = it->children.begin();           // characters

					if( childit->value.id().to_long() == CExpressTokens::named_typesID)
					{
						CString str =Express2Html(it, html);
						str=str.Trim();
						ISymbolPtr symbol = html._parser.symtable.FindSymbol(ExpMangle(str));
						if(symbol!=NULL && html.schema!=symbol->_sNamespace)
							tmp+=StrFormat("<A HREF=\"%s.html#%s\">%s </A>", symbol->_sNamespace, str, str);
						else
							tmp+=StrFormat("<A HREF=\"#%s\">%s</A>", str, str);
					}

					else 
						tmp+=Express2Html(it, html);
				}
				else if(str == "OPTIONAL")
				{
					tmp+=" OPTIONAL ";  
				}
				else if(str == ",")
				{
					tmp+=", ";  
				}
				else if(str == ":")
				{
					tmp+=": ";  
				}
				else if(it->value.id().to_long()== CExpressTokens::semicolonID)
				{
					tmp+=";\n";
				}
				else
				{
					//tmp+= std::string(it->value.begin(), it->value.end()).c_str();
					tmp+=Express2Html(it, html);  
				}
			}

			goto done;
		}	


		if(n==CExpressTokens::supertype_factorID) 
		{
			TreeIter it;
			for(it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				if(it->children.size() < 1)
				{
					CString szStr = std::string(it->value.begin(), it->value.end()).c_str();
					tmp+=szStr;
					continue;

				}
				if(i->children.size() > 0 && findNode(i->children.begin(), findit, 0, Nodes(nodes, CExpressTokens::entity_refID, CExpressTokens::entity_idID, CExpressTokens::simple_idID, 0)))
				{
					CString szEntity = std::string(findit->children.begin()->value.begin(), findit->children.begin()->value.end()).c_str();
					tmp+=StrFormat("<A HREF=\"#%s\">%s</A>", szEntity, szEntity);
					goto done;
				}
				else
				{
					tmp+=Express2Html(it, html);  
				}

			}
			goto done;
		}


		if(n==CExpressTokens::subtype_listID) 
		{
			TreeIter it;
			for(it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				if(it->children.size() < 1)
				{
					CString szStr = std::string(it->value.begin(), it->value.end()).c_str();
					tmp+=szStr;
					continue;

				}

				if(findNode(it, findit, 0, Nodes(nodes, CExpressTokens::entity_refID, CExpressTokens::entity_idID, CExpressTokens::simple_idID, 0)))
				{
					TreeIter childit = findit->children.begin();			// character set
					CString str = std::string(childit->value.begin(), childit->value.end()).c_str();
					ISymbolPtr symbol = html._parser.symtable.FindSymbol(ExpMangle(str));
					if(html.schema!=symbol->_sNamespace)
						tmp+=StrFormat("<A HREF=\"%s.html#%s\">%s </A>", symbol->_sNamespace, str, str);
					else
						tmp+=StrFormat("<A HREF=\"#%s\">%s</A>", str, str);

				}
				else
				{
					tmp+=Express2Html(it, html);  
				}

			}
			goto done;

		}

#endif

		if(n==CExpressTokens::semicolonID) 
		{
			tmp+=";\n";
			goto done;
		}	
		if(n==CExpressTokens::function_blockID) {
			goto done;
		}	

		if(n==CExpressTokens::where_clauseID) 
		{
			goto done;
		}	

		CString field = std::string(i->value.begin(), i->value.end()).c_str();
		tmp+=field;
		if(field.GetLength() > 0)
			tmp+=" ";
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
		{  
			std::string str(it->value.begin(),it->value.end());
			if(str=="SUBTYPE" ) 
			{
				tmp+="\nSUBTYPE ";
				continue;
			}
			if(str=="SUPERTYPE" ) 
			{
				tmp+="\nSUPERTYPE ";
				continue;
			}

			tmp+= Express2Html(it, html); 
		}

	}
done:
	tabs=tabs.Mid(1, tabs.GetLength()-1);

	return tmp;
}


void CExpress2Html::Express2Html()
{
	CString tmp;
	tmp="<HTML><BODY><PRE>\n";
	tmp += ::Express2Html(_parser.info.trees.begin(), *this);
	tmp +="</PRE></BODY></HTML>\n";
	std::fstream headerdeclfile;

	CString szFilename= StrFormat("%s.html", GetExeDirectory() + schema );

	headerdeclfile.open (szFilename, std::fstream::out );
	headerdeclfile<< tmp;
	headerdeclfile.close();


	OutputDebugString(tmp);


}


static CString gszEntity;
static CString gszAttr;
static CString type;
template<typename TreeIter>
CString Express2XmlHelp(const TreeIter& i)
{
	CString tmp;
	TreeIter findit;
	TreeNodes nodes;
	int n =  i->value.id().to_long();
	{
		if(n==CExpressTokens::entity_headID) 
		{
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
			{  

				if(it->value.id().to_long() == CExpressTokens::entity_idID)
				{
					if(findNode(it, findit, 0, Nodes(nodes, CExpressTokens::entity_idID, CExpressTokens::simple_idID, 0)))\
					{
						TreeIter childit = findit->children.begin();           // characters
						CString szEntity = std::string(childit->value.begin(), childit->value.end()).c_str();
						gszEntity=szEntity=szEntity.Trim();

						tmp+=StrFormat("<%s>\n", szEntity);
						tmp+=StrFormat("\t<description>\n\n\t</description>\n");
					}
				
				}
				else
				{
					tmp+=Express2XmlHelp(it); 
				}
			}
			goto done;
		}

		if(n==CExpressTokens::explicit_attrID) 
		{
			TreeIter it;

			//explicit_attr  = attribute_decl >> *(ch_p( ',') >>attribute_decl ) >> ch_p(':') 
			//				>> !( str_p("OPTIONAL")) >> base_type >> semicolon ;

			for(it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				CString str = std::string(it->value.begin(), it->value.end()).c_str();
				if(it->value.id().to_long()== CExpressTokens::attribute_declID)
				{
					// save this for table....
					if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CExpressTokens::attribute_declID, CExpressTokens::attribute_idID, CExpressTokens::simple_idID, 0)))
					{
						TreeIter childit = findit->children.begin();           // characters
						gszAttr = std::string(childit->value.begin(), childit->value.end()).c_str();
						tmp+=StrFormat("\t<%s>\n", gszAttr);


					}
				}
				else if(it->value.id().to_long()== CExpressTokens::base_typeID)
				{
					TreeIter childit = it->children.begin();           // characters
					CString str;

					if( childit->value.id().to_long() == CExpressTokens::named_typesID)
					{
						if(findANode(it->children.begin(), findit, CExpressTokens::simple_idID))
						{
							TreeIter childit = findit->children.begin();           // characters
							str = std::string(childit->value.begin(), childit->value.end()).c_str();
						}
					}
					else if( childit->value.id().to_long() == CExpressTokens::simple_typesID)
					{
						str=getText(childit, " ").c_str();
					}
					else str=getText(childit, " ").c_str();


					tmp+=StrFormat("\t\t<type>%s</type>\n", str);
				}
				else if(str.GetLength()>0)
				{
					  
				}
				else
				{
					//tmp+= std::string(it->value.begin(), it->value.end()).c_str();
					Express2XmlHelp(it);  
				}
			}
			tmp+=StrFormat("\t\t<description>\n\n\t\t</description>\n");

			tmp+=StrFormat("\t</%s>\n", gszAttr);
			goto done;
		}	


		if(n==CExpressTokens::supertype_factorID) 
		{
			goto done;
			TreeIter it;
			for(it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				if(it->children.size() < 1)
				{
					CString szStr = std::string(it->value.begin(), it->value.end()).c_str();
					tmp+=szStr;
					continue;

				}
				if(i->children.size() > 0 && findNode(i->children.begin(), findit, 0, Nodes(nodes, CExpressTokens::entity_refID, CExpressTokens::entity_idID, CExpressTokens::simple_idID, 0)))
				{
					CString szEntity = std::string(findit->children.begin()->value.begin(), findit->children.begin()->value.end()).c_str();
					tmp+=StrFormat("<A HREF=\"%s.html\">%s</A>", szEntity, szEntity);
					goto done;
				}
				else
				{
					tmp+=Express2XmlHelp(it);  
				}

			}
			goto done;
		}


		if(n==CExpressTokens::subtype_listID) 
		{
			goto done;
			TreeIter it;
			for(it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				if(it->children.size() < 1)
				{
					CString szStr = std::string(it->value.begin(), it->value.end()).c_str();
					tmp+=szStr;
					continue;

				}

				if(findNode(it, findit, 0, Nodes(nodes, CExpressTokens::entity_refID, CExpressTokens::entity_idID, CExpressTokens::simple_idID, 0)))
				{
					TreeIter childit = findit->children.begin();			// character set
					CString szEntity = std::string(childit->value.begin(), childit->value.end()).c_str();
					tmp+=StrFormat("<A HREF=\"%s.html\">%s</A>", szEntity, szEntity);
				}
				else
				{
					tmp+=Express2XmlHelp(it);  
				}

			}
			goto done;

		}

		if(n==CExpressTokens::semicolonID) 
		{
			tmp+="\n";
			goto done;
		}	
		if(n==CExpressTokens::function_blockID) {
			goto done;
		}	

		if(n==CExpressTokens::where_clauseID) 
		{
			goto done;
		}	
		if(n==CExpressTokens::derive_clauseID) {
			goto done;
		}	

		//CString field = std::string(i->value.begin(), i->value.end()).c_str();
		//tmp+=field;
		//if(field.GetLength() > 0)
		//	tmp+=" ";
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
		{  
			std::string str(it->value.begin(),it->value.end());
			if(str=="END_ENTITY" ) 
			{
				tmp+=StrFormat("</%s>\n", gszEntity);
				continue;
			}
			tmp+= Express2XmlHelp(it); 
		}

	}
done:
	tabs=tabs.Mid(1, tabs.GetLength()-1);

	return tmp;
}

void CExpress2Html::Express2XmlHelp()
{
	std::fstream headerdeclfile;
	CString tmp;
	tmp += ::Express2XmlHelp(_parser.info.trees.begin());

	CString szFilename= StrFormat("%s.txt", GetExeDirectory() + "Machining" );

	headerdeclfile.open (szFilename, std::fstream::out );
	headerdeclfile<< tmp;
	headerdeclfile.close();


	OutputDebugString(tmp);


}
///////////////////////////////////////////////////////////////
template<typename TreeIter>
CString Express2HtmlHelp(const TreeIter& i, CExpress2Html & html)
{
	CString tmp;
	TreeIter findit;
	TreeNodes nodes;
	tabs+="\t";
	int n =  i->value.id().to_long();
	{
		if(n==CExpressTokens::schema_blockID) 
		{
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				if(it->children.size() < 1)
				{
				}
				else if(findNode(it, findit, 0, Nodes(nodes, CExpressTokens::schema_idID, CExpressTokens::simple_idID, 0)))
				{
						TreeIter childit = findit->children.begin();           // characters
						html.schema = std::string(childit->value.begin(), childit->value.end()).c_str();
				}
				else 
					tmp+=Express2HtmlHelp(it, html); 
			}	
		}

		if(n==CExpressTokens::entity_blockID) 
		{
			CString szEntity;  // source for the entity
			CString szStr = std::string(i->value.begin(), i->value.end()).c_str();
			if(szStr.GetLength() > 0)
			{
				tmp+=szStr;
				goto done;
			}
			tmp.Empty();

			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				tmp+=Express2HtmlHelp(it, html); 
			}

			CString szTestReportStyle = "../Styles/EntityReport.css";
			CString szFilename= StrFormat("%s%s.html", html._helppath.c_str(),  html._szEntityName);

			//html.htmlfile.open (szFilename, std::fstream::out );
			szEntity= StrFormat("<HTML><HEAD><TITLE> %s </TITLE>", html._szEntityName);
			szEntity.AppendFormat("<LINK href=\"%s\" rel=\"stylesheet\" type=\"text/css\">\n</HEAD><BODY>\n", szTestReportStyle);

			szEntity+= StrFormat("\n<H1>ENTITY <A NAME=\"%s\">%s </A></H1><P>", html._szEntityName,html._szEntityName);
			CString szDesc = html.xmldescriptions[StrFormat("%s.description", html._szEntityName)];
			szEntity+= szDesc;


			////////////////////////////////////////
			szEntity+=StrFormat("<H2>Schema</H2>\n");
			ISymbolPtr symbol = html._parser.symtable.FindSymbol(ExpMangle(html._szEntityName));
			if(symbol!=NULL)
				szEntity+=StrFormat("<A HREF=\"../../Schemas/%s.html#%s\">%s</A>", symbol->_sNamespace, html._szEntityName, symbol->_sNamespace);
			else szEntity+="&nbsp;<P>";


			////////////////////////////////////////
			szEntity+=StrFormat("<H2>Attributes</H2>\n");
			szEntity+=StrFormat("<TABLE>\n");


			

			for(int i=0; i< html._szEntityAttr.size(); i++)
			{
				if(i==0)
				{
					szEntity+= StrFormat("<TH>%s </TH>\n<TH>%s </TH>\n<TH>%s </TH>\n", 
						"Attribute", "Type", "Description");

				}
				szDesc= html.xmldescriptions[StrFormat("%s.%s.description", html._szEntityName, html._szEntityAttr[i])];
				if(szDesc.IsEmpty())
					szDesc="&nbsp;";


				szEntity+= StrFormat("<TR><TD>%s </TD>\n<TD>%s </TD>\n<TD>%s </TD></TR>\n", 
					html._szEntityAttr[i], html._szEntityAttrType[i], szDesc);
			}
			szEntity+=StrFormat("</TABLE>\n");
			SYSTEMTIME st;
			GetSystemTime(&st);
			szEntity+=StrFormat("<H2>Express Definition</H2>\n<pre>\n");
			szEntity+=tmp;
			szEntity+=StrFormat("<P>Last Edited - %s\n"  , NowString());
			szEntity+=StrFormat("</BODY></HTML>\n");
			OutputDebugString(tmp);
			//html.htmlfile<<tmp;
			//html.htmlfile.close();
			SaveDocument(szFilename, szEntity);

			goto done;
		}

		if(n==CExpressTokens::entity_headID) 
		{


			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				CString str = std::string(it->value.begin(), it->value.end()).c_str();

				if(it->value.id().to_long() == CExpressTokens::entity_idID)
				{
					if(findNode(it, findit, 0, Nodes(nodes, CExpressTokens::entity_idID, CExpressTokens::simple_idID, 0)))\
					{
						html._szEntityAttr.clear();
						html._szEntityAttrType.clear();
						TreeIter childit = findit->children.begin();           // characters
						html._szEntityName = std::string(childit->value.begin(), childit->value.end()).c_str();
						html._szEntityName=html._szEntityName.Trim();
						tmp+="ENTITY ";
						tmp+=html._szEntityName;
						tmp+=" ";
					}
				
				}
				else
				{
					tmp+=Express2HtmlHelp(it, html); 
				}
			}
			goto done;
		}

		if(n==CExpressTokens::derive_clauseID) {
			goto done;
		}	
		// This doesn't work..???
		//	type_decl =str_p("TYPE") >>  type_id >> ch_p('=') >> underlying_type >> 
		//	semicolon >> discard_node_d[*(anychar_p-str_p("END_TYPE"))]	>> str_p("END_TYPE") >> semicolon ;
		if(n==CExpressTokens::type_declID ) 
		{

			CString szTypeId;
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				CString str = std::string(it->value.begin(), it->value.end()).c_str();
				if(str=="TYPE")
				{
					tmp+="\nTYPE ";
				}
				else if(it->value.id().to_long()==CExpressTokens::type_idID)
				{
					str=Express2HtmlHelp(it, html); 
					szTypeId=str.Trim();
					tmp+=szTypeId;
				}
				else if(str.GetLength() > 0)
				{
					// do we need space?
					tmp+=str+" ";
				}
				else
				{
					tmp+=Express2HtmlHelp(it, html); 
				}
			}

			CString szTestReportStyle = "../Styles/EntityReport.css";
			CString szFilename= StrFormat("%s%s.html", html._helppath.c_str(),  szTypeId);

			//html.htmlfile.open (szFilename, std::fstream::out );
			CString szType = StrFormat("<HTML><HEAD><TITLE> %s </TITLE>", szTypeId);
			szType.AppendFormat("<LINK href=\"%s\" rel=\"stylesheet\" type=\"text/css\">\n</HEAD><BODY>\n", szTestReportStyle);

			szType+= StrFormat("\n<H1>TYPE <A NAME=\"%s\">%s </A></H1><P>", szTypeId,szTypeId);
			CString szDesc = html.xmldescriptions[StrFormat("%s.description", szTypeId)];
			szType+= szDesc;
			szType+=StrFormat("<H2>Express Definition</H2>\n<pre>\n");
			szType+=tmp;
			szType+=StrFormat("</pre><P>Last Edited - %s\n</BODY></HTML>\n" , NowString());

			SaveDocument(szFilename, szType);
			goto done;
		}	
#if 1

		if(n==CExpressTokens::explicit_attrID) 
		{
			TreeIter it;

			//explicit_attr  = attribute_decl >> *(ch_p( ',') >>attribute_decl ) >> ch_p(':') 
			//				>> !( str_p("OPTIONAL")) >> base_type >> semicolon ;
			//	base_type  =  aggregation_types | simple_types |  named_types ;
			for(it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				CString str = std::string(it->value.begin(), it->value.end()).c_str();
				if(it->value.id().to_long()== CExpressTokens::attribute_declID)
				{
					// save this for table....
					if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CExpressTokens::attribute_declID, CExpressTokens::attribute_idID, CExpressTokens::simple_idID, 0)))
					{
						TreeIter childit = findit->children.begin();           // characters
						CString szAttr = std::string(childit->value.begin(), childit->value.end()).c_str();
						html._szEntityAttr.push_back(szAttr);
						tmp+=" " + szAttr;

					}
				}
				else if(it->value.id().to_long()== CExpressTokens::base_typeID)
				{
					CString szBasetype;
					TreeIter childit = it->children.begin();           // characters

					if( childit->value.id().to_long() == CExpressTokens::named_typesID)
					{
						CString str =Express2HtmlHelp(it, html);
						str=str.Trim();
						ISymbolPtr symbol = html._parser.symtable.FindSymbol(ExpMangle(str));
						if(symbol!=NULL)
							szBasetype=StrFormat("<A HREF=\"../%s/%s.html#%s\">%s</A>", symbol->_sNamespace, str, str, str);
						else szBasetype=str;
					}

					else 
					{
						szBasetype=Express2HtmlHelp(it, html);

					}
					html._szEntityAttrType.push_back(szBasetype);
					tmp+=" "+ szBasetype;
				}
				else if(str == "OPTIONAL")
				{
					tmp+=" OPTIONAL";  
				}
				else if(str == ",")
				{
					tmp+=", ";  
				}
				else if(str == ":")
				{
					tmp+=" :";  
				}
				else if(it->value.id().to_long()== CExpressTokens::semicolonID)
				{
					tmp+=";\n";
				}
				else
				{
					tmp+=Express2HtmlHelp(it, html);  
				}
			}

			goto done;
		}	


		if(n==CExpressTokens::supertype_factorID) 
		{
			TreeIter it;
			for(it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				if(it->children.size() < 1)
				{
					CString szStr = std::string(it->value.begin(), it->value.end()).c_str();
					tmp+=szStr;
					continue;

				}
				if(i->children.size() > 0 && findNode(i->children.begin(), findit, 0, Nodes(nodes, CExpressTokens::entity_refID, CExpressTokens::entity_idID, CExpressTokens::simple_idID, 0)))
				{
					CString szEntity = std::string(findit->children.begin()->value.begin(), findit->children.begin()->value.end()).c_str();
					tmp+=StrFormat("<A HREF=\"%s.html\">%s</A>", szEntity, szEntity);
					goto done;
				}
				else
				{
					tmp+=Express2HtmlHelp(it, html);  
				}

			}
			goto done;
		}


		if(n==CExpressTokens::subtype_listID) 
		{
			TreeIter it;
			for(it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				if(it->children.size() < 1)
				{
					CString szStr = std::string(it->value.begin(), it->value.end()).c_str();
					tmp+=szStr;
					continue;

				}

				if(findNode(it, findit, 0, Nodes(nodes, CExpressTokens::entity_refID, CExpressTokens::entity_idID, CExpressTokens::simple_idID, 0)))
				{
					TreeIter childit = findit->children.begin();			// character set
					CString str = std::string(childit->value.begin(), childit->value.end()).c_str();
					ISymbolPtr symbol = html._parser.symtable.FindSymbol(ExpMangle(str));
					if(html.schema!=symbol->_sNamespace)
						tmp+=StrFormat("<A HREF=\"../%s/%s.html\">%s </A>", symbol->_sNamespace, str, str);
					else
						tmp+=StrFormat("<A HREF=\"%s.html\">%s</A>", str, str);

				}
				else
				{
					tmp+=Express2HtmlHelp(it, html);  
				}

			}
			goto done;

		}

#endif

		if(n==CExpressTokens::semicolonID) 
		{
			tmp+=";\n";
			goto done;
		}	
		if(n==CExpressTokens::function_blockID) {
			goto done;
		}	

		if(n==CExpressTokens::where_clauseID) 
		{
			goto done;
		}	

		CString field = std::string(i->value.begin(), i->value.end()).c_str();
		if(field.GetLength() > 0)
		{
			if(tmp!="(" || tmp!= ")"  ||  tmp!=";")
				tmp+=" ";
		}
		tmp+=field;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
		{  
			std::string str(it->value.begin(),it->value.end());
			if(str=="SUBTYPE" ) 
			{
				tmp+="\nSUBTYPE ";
				continue;
			}
			if(str=="SUPERTYPE" ) 
			{
				tmp+="\nSUPERTYPE ";
				continue;
			}

			tmp+= Express2HtmlHelp(it, html); 
		}

	}
done:
	tabs=tabs.Mid(1, tabs.GetLength()-1);

	return tmp;
}



HRESULT CExpress2Html::Express2HtmlHelp(std::string helppath)
{
	::CreateDirectory(helppath.c_str(),NULL);
	this->_helppath =helppath;

	::Express2HtmlHelp(_parser.info.trees.begin(), *this);
	return S_OK;

}
HRESULT CExpress2Html::Xml2StdMap(std::string schema, std::string xmlfilename )
{
	boost::property_tree::ptree helpme;
	boost::property_tree::ptree children;
	std::string filename = (LPCTSTR) ::GetExeDirectory();
	std::string tmp, szFilename;
	try{
		boost::property_tree::read_xml(xmlfilename, helpme);
	}
	catch(boost::property_tree::file_parser_error e)
	{

		OutputDebugString(StrFormat("Error at line = %d\n", e.line() 	));
	}

	try {
		boost::property_tree::ptree::iterator it, it2;
		std::string cppfilename = filename + schema + ".cpp";
		children = helpme.get_child(schema);
		for(it=children.begin(); it!=children.end(); it++)
		{
			boost::property_tree::ptree description;
			//std::string prop = StrFormat("%s.description", (*it).first.c_str());
			//description=children.get_child(prop);
			//CString szDesc = description.data().c_str();
			//szDesc.Replace("\"", "\\\"");
			//tmp+=StrFormat("description[\"%s\"]=\"%s\";\n\n", prop.c_str(), szDesc);

			// now go through each child's attributes...
			std::string childname = StrFormat("%s", (*it).first.c_str());
			description=children.get_child(childname);
			for(it2=description.begin(); it2!=description.end(); it2++)
			{
				CString szDesc;
				std::string prop;
				std::string attrname = (*it2).first.c_str();
				boost::property_tree::ptree attrdesc;
				if(attrname == "description")
				{
					prop = attrname;
					szDesc = (*it2).second.data().c_str();
					szDesc.Replace("\"", "\\\"");
					xmldescriptions[StrFormat("%s.description", childname.c_str())]=szDesc;
					tmp+=StrFormat("description[\"%s\"]=\"%s\";\n\n", StrFormat("%s.description", childname.c_str()), szDesc);
					continue;

				}
				//prop = StrFormat("description", attrname.c_str());
				CString dname = StrFormat("%s.description", attrname.c_str());
				attrdesc=description.get_child((LPCTSTR) dname);
				szDesc = attrdesc.data().c_str();
				szDesc.Replace("\"", "\\\"");
				xmldescriptions[StrFormat("%s.%s.description", childname.c_str(), attrname.c_str())]=szDesc;
				tmp+=StrFormat("description[\"%s\"]=\"%s\";\n\n",StrFormat("%s.%s.description", childname.c_str(), attrname.c_str()) , szDesc);


			}


		}
	}
	catch(boost::property_tree::ptree_bad_path e)
	{
		DebugBreak();
		OutputDebugString(StrFormat("Error bad path  = %s\n", e.what()	));
		return E_FAIL;

	}

	std::fstream cppfile;
	szFilename=filename;
	szFilename+=schema;
	szFilename+=".cpp";

	try {
	cppfile.open (szFilename.c_str(), std::fstream::out );
	cppfile<< tmp;
	cppfile.close();
	}
	catch(...)
	{
		DebugBreak();
		return E_FAIL;

	}
	return S_OK;
}