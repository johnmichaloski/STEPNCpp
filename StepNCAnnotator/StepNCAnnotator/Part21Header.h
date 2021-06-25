//
// Part21Header.h: interface for the CPart21Header class.
//


#pragma once
#include "atlstr.h"
#include "ExpressUtils.h"

class CPart21Header  
{
public:
	CPart21Header()
	{
		m_sImplementation_level="1";
		m_sPreprocessor_version="$";
		m_sAuthorisation="$";
		m_sOriginating_system="Nist Splash";
		TCHAR lpBuffer[256];
		DWORD dwSize=256;
		GetUserName( lpBuffer, &dwSize);
		m_sAuthors.push_back(lpBuffer);
		m_sFile_description.push_back("ISO 14649-11 EXAMPLE 1, THE SOMEWHAT MODIFIED");
		m_sFile_description.push_back("ISO14649 EQUIVALENT OF test238.stp");
		m_sOrganizations.push_back("NIST");
		n=1;
	}
	virtual ~CPart21Header(){}
	CString & Name() { return m_sName; }
	CStringVector & Authors() { return m_sAuthors; }
	CStringVector & Organizations() { return m_sOrganizations; }
	CString GenerateList(CString comment, CStringVector & items)
	{
		CString tmp;
		tmp.AppendFormat("%-40s", StrFormat("/*%s*/", comment));
		for(int i=0; i< items.size(); i++)
		{
			if(i==0) tmp.AppendFormat("(");
			if(i>0) tmp.AppendFormat(", ");
			if(i>0 ) tmp.AppendFormat("%s%-40s", (items[i-1].GetLength()>40 )? "\n": "", " ");
			tmp.AppendFormat("'%s'", items[i]);
		}
 		tmp.AppendFormat(" ),\n");
		return tmp;
	}

	CString GenerateString(CString s)
	{
		if(s=="$") 
			return s;
		return StrFormat("'%s'", s);
	}

	CString GenerateHeader()
	{
		CString tmp;
		tmp.AppendFormat("ISO-10303-21;\n\nHEADER;\n");
		tmp.AppendFormat("FILE_DESCRIPTION(\n");
		tmp.Append(GenerateList("description", m_sFile_description));
		tmp.AppendFormat("%-40s '%s');\n\n", "/*implementation*/", m_sImplementation_level);
		tmp.AppendFormat("FILE_NAME(\n");
		tmp.AppendFormat("%-40s '%s',\n", "/* name */", m_sName);
		tmp.AppendFormat("%-40s '%s',\n", "/* time_stamp */", m_sTimeStamp);
		///* author */ ('TOM KRAMER', 'YONG TAK HYUN','JOCHEN WOLF'),
		tmp.AppendFormat(GenerateList("authors", m_sAuthors) );
		tmp.AppendFormat(GenerateList("organizations", m_sOrganizations) );
		tmp.AppendFormat("%-40s %s,\n", "/* preprocessor_version */", GenerateString(m_sPreprocessor_version));
		tmp.AppendFormat("%-40s %s,\n", "/* originating_system */", GenerateString(m_sOriginating_system));
		tmp.AppendFormat("%-40s %s);\n", "/* authorisation */",  GenerateString(m_sAuthorisation));

		return tmp;
	}

	void Init()
	{
		n=1;
		lines.clear();
	}
	CString AddEntity(CString szEntity, CString szData) 
	{ 
		szData.Trim();
		szData=szData.Mid(0, szData.GetLength()-1); // remove last comma

		// FIXME check to see if existing entry exists.
		lines[n]= StrFormat("#%d=%s(%s);\n", n, szEntity.MakeUpper(), szData);
		return StrFormat("#%d", n++);
	}

	void SaveP21(CVarDefs &vars, CString szFilename)
	{
		DumpCVarDefs(vars);

		outputfile.open (szFilename, std::fstream::out );
		outputfile <<  GenerateHeader();
		outputfile << StrFormat("FILE_SCHEMA(( ");
		// add schemas
		for(int i=0; i<m_sSchemas.size(); i++)
		{
			if(i>0)
				outputfile << ", ";
			outputfile << StrFormat("'%s'", m_sSchemas[i]);

		}
		outputfile << StrFormat("));\nENDSEC;\n\n");

		// Data section header
		outputfile << StrFormat("DATA;\n");
		for(std::map<int, CString>::iterator it= lines.begin(); it !=lines.end(); it++)
		{
			outputfile << (*it).second;
		}
		outputfile << StrFormat("ENDSEC;\n");
		outputfile << StrFormat("END-ISO-10303-21;\n");
		// Data section trailer
		outputfile.close();
	}
	CString DumpCVarDefs(CVarDefs &vars)
	{
		CString tmp;
		for(int i=0; i<vars.size(); i++)
		{
			CVarDefPtr  vardef = vars[i];
			tmp+=Generate(vardef);
		}
		return tmp;

	}

	CString Generate(CVarDefPtr  vardef)
	{
		CString tmp;
		OutputDebugString(StrFormat("ENTER: Item = %s Class = %s Type=%d\n",   vardef->Name(),   vardef->m_sClassname, vardef->Type()));
		if(vardef==NULL)
		{
			OutputDebugString("!!!!!!!Bad vardef\n");
		}

		if(vardef->Type() == 	integer_)
		{
			EInteger * nVal=  * (EInteger **) vardef->m_ref;
			if(nVal==NULL)
			{
				if(!vardef->m_bOptional)
					OutputDebugString(StrFormat("PROBLEM with %s logical or boolean\n", vardef->Name()));
				tmp.AppendFormat("$, ");
				goto done;
			}	
			tmp.AppendFormat("%d, ",  nVal->val);
		}
		else if(vardef->Type() == 	logical_ ||  vardef->Type() == 	boolean_)
		{
			EInteger * iVal= * (EInteger **) vardef->m_ref;
			if(iVal==NULL)
			{
				if( !vardef->m_bOptional)
					OutputDebugString(StrFormat("PROBLEM with %s logical or boolean\n", vardef->Name()));
				tmp.AppendFormat("$, ");
				goto done;
			}	

			long val = iVal->val;
			CString str = (val==0) ? "FALSE" : (val==1) ? "TRUE" : "UNKOWN"; 
			tmp.AppendFormat(".%s., ",  str);
			//tmp.AppendFormat("%s", str);
		}
		else if(vardef->Type() == 	typereference_)
		{
			IStepClassPtr step=  *(IStepClass **) vardef->m_ref;
			if(step!=NULL) 
			{
				CString sz = DumpCVarDefs(step->GetVarDefs());
				tmp.AppendFormat("%s ", sz);

			}
			else
				tmp.AppendFormat("$ ");
		}
		else if(vardef->Type() == 	enumeration_)
		{
			EEnum * eVal=  (EEnum *) vardef->m_ref;
			if(eVal==NULL )
			{
				if( !vardef->m_bOptional)
					OutputDebugString(StrFormat("PROBLEM with %s empty non-optional logical or boolean\n", vardef->Name()));
				tmp.AppendFormat("$, ");
				goto done;
			}	
			tmp.AppendFormat(".%s., ",  eVal->GetEnum2String(eVal->_nSelection).MakeUpper());
		}
		else if(vardef->Type() == 	real_)
		{
			// optional real not handled properly yet.
			double  rVal= *(double *) vardef->m_ref;
			tmp.AppendFormat("%.3f, ",  rVal);
		}
		else if(vardef->Type() == 	select_)
		{
			ESelection * sVal= *(ESelection **) vardef->m_ref;
			IStepClassPtr pSel =sVal-> GetSelection();
			CString szenum = DumpCVarDefs(pSel->GetVarDefs());
			tmp.AppendFormat("%s, ", szenum);
		}
		else if(vardef->Type() == 	string_)
		{
			CString * s= (CString *)vardef->m_ref;
			if(s==NULL)
			{
				if(!vardef->m_bOptional)
					OutputDebugString(StrFormat("PROBLEM with %s empty non-optional string\n", vardef->Name()));
				tmp.AppendFormat("$, ");
				goto done;
			}
			tmp.AppendFormat("\'%s\', ", *s);
		}
		else if(vardef->Type() == 	entity_  || (vardef->Type() == 	reference_) )
		{
			IStepClassPtr step=  *(IStepClass **) vardef->m_ref;
			if(step!=NULL) 
			{
				int n;
				CString sz = DumpCVarDefs(step->GetVarDefs());
				if(n=StrCount(sz,',') >=0)
				{
					CString szClassname = step->m_sClassname;
					if(szClassname.GetLength()< 1) // typedef's don't have classnames for now...
						szClassname= vardef->m_sClassname;
					CString szNumId = AddEntity(szClassname, sz) ;
					tmp.AppendFormat("%s, ", szNumId);
				}
				else
				{
					tmp.AppendFormat("%s", sz);

				}

			}
			else
				tmp.AppendFormat("$, ");

		}
		else if(vardef->Type() == 	special_)
		{
			tmp.AppendFormat("%s", DumpCVarDefs((CVarDefs) *(CVarDefs*)vardef->m_ref));
		}
		else if(vardef->Type() == 	set_ || vardef->Type() ==  list_)
		{
			//		std::vector<IStepNC *> * items=(std::vector<IStepNC *> *)  vars[i].m_ref;
			tmp.AppendFormat("(");
			if(vardef->_nDimension==1)
			{

				std::vector<IStepClassPtr > &list= *(std::vector<IStepClassPtr> *)  vardef->m_ref;
				for (int i = 0; i<list.size(); i++)
				{
					IStepClassPtr step = list[i] ;
					tmp.AppendFormat("%s", DumpCVarDefs(step->GetVarDefs()));
				}

			}
			else  if(vardef->_nDimension==2)
			{
				std::vector< std::vector<IStepClassPtr > > &list = *( std::vector< std::vector<IStepClassPtr > > *) vardef->m_ref;
				for (int i = 0; i<list.size(); i++)
				{
					// how to distinguish  new row/col items
					for (int j = 0; j<list[i].size(); j++) 
					{
						IStepClassPtr step = list[i][j] ;
						tmp.AppendFormat("%s", DumpCVarDefs(step->GetVarDefs()));
					}
				}
			}
			else if(vardef->_nDimension>2)
			{
				OutputDebugString("Too many list dimensions\n");
				::DebugBreak();
			}
			tmp.Trim();
			tmp=tmp.Mid(0,tmp.GetLength()-1); // remove last ,
			tmp.AppendFormat("), ");


		}
		else
		{
			::DebugBreak();
		}
		OutputDebugString(StrFormat("EXIT: Item = %s Class = %s\n",   vardef->Name(),   vardef->m_sClassname));
done:
		return tmp;

	}
	////////////////////////////////////////////////////////////////
	int n;
	std::map<int, CString> lines;
	std::fstream outputfile;

	//FILE_DESCRIPTION
	CStringVector m_sSchemas;
	CStringVector m_sFile_description;
	CString m_sImplementation_level;

	//FILE_NAME
	CString m_sName;
	CString m_sTimeStamp;
	CStringVector m_sAuthors;
	CStringVector m_sOrganizations;
	CString m_sPreprocessor_version;
	CString m_sOriginating_system;
	CString m_sAuthorisation;

};
