//
// ClassUtils.h
//
#pragma once
#include <stdarg.h>
#include "Misc.h"


#if 0
class CStringVector : public std::vector<CString> 
{
public:
	CString Merge() { CString tmp; for(UINT i=0; i< size(); i++) tmp+=at(i);  return tmp; }
	CString ToString() { CString tmp; for(UINT i=0; i< size(); i++) tmp+=at(i)+CString("\n");  return tmp; }
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
};
#endif
#include <sstream>
template< class T, class W=T >
struct Array1D  : public std::vector<T> 
{
	void Reserve(UINT size)
	{
		this->resize(size);
	}
	void Load(UINT n, ...)
	{
		clear();
		va_list ap;	
		va_start(ap,n); 
		for(int i=0; i< n; i++)
		{
			T t = va_arg ( ap, W );
			push_back(t);
		}
		va_end(ap);
	}
	CString ToString() 
	{
		USES_CONVERSION;
		std::stringstream str;
		for(UINT i=0; i< size(); i++)
			str<< at(i) << _T(",");
		str<< endl;
		std::string cstr;
		str>>cstr;

		return A2T((LPSTR) cstr.c_str());

	}

};

typedef Array1D<int>    CIntArray;
typedef	Array1D<float, double>  FloatList;

template< class T >
struct Array2D  : public std::vector<std::vector<T> >
{
	int rows, cols;
	void Reserve(UINT rows, UINT cols)
	{
		this->rows=rows; this->cols=cols;
		this->resize(rows);
		for(UINT i=0; i<rows; i++) 
			this->at(i).resize(cols);
	}
	Array2D<T>   Transpose()
	{
		Array2D<T>   tmp;
		int rows = this->size();
		int cols = (rows>0)? this->at(0).size() : 0;
		if(rows <1 && cols < 1)
			return tmp;
		tmp.resize(cols);
		for(UINT i=0; i<cols; i++) 
		{
			tmp.at(i).resize(rows);
			for(UINT j=0; j<rows; j++)
				tmp[i][j]=this->at(j).at(i);

		}
		return tmp;
	}
	CString ToString()
	{
		CString str;
		Array2D<T> & tmp(*this);
		for(UINT i=0; i<tmp.size(); i++) 
		{
			for(UINT j=0; j<tmp[i].size(); j++)
			{
				str.AppendFormat("[%d][%d]=%9.5f %9.5f %9.5f %9.5f\n", i,j, tmp[i][j].x, tmp[i][j].y, tmp[i][j].z, tmp[i][j].w);
			}

		}
		return str;
	}

};
typedef CStringVector::iterator CStringVectorIterator;
/* these are all orthogonal types */
#if 0
enum type_enum {
	unknown_ = 0,	/* 0 catches uninit. errors */
	special_,	/* placeholder, given meaning by it's owner, */
	/* such as Type_Dont_Care, Type_Bad, Type_User_Def */
	runtime_,	/* cannot be further determined until runtime */
	integer_,
	real_,
	string_,
	binary_,
	boolean_,
	logical_,

	/* formals-only */
	number_,
	generic_,

	/* aggregates */
	aggregate_,	/* as a formal */
	array_,
	bag_,
	set_,
	list_,
	last_aggregate_,/* not real, just for easier computation */

	oneof_,

	/* while they are really used for different */
	/* purposes, it might be worth considering */
	/* collapsing entity_ and entity_list_ */
	entity_,	/* single entity */
	entity_list_,	/* linked list of entities */
	enumeration_,
	select_,
	reference_,	/* something only defined by a base type, i.e., a */
	/* type reference */
	query_,
	op_,		/* something with an operand */
	inverse_,	/* is? an inverse */

	identifier_,	/* simple identifier in an expression */
	attribute_,	/* attribute reference (i.e., expr->u.variable) */
	derived_,/*?*/
	funcall_,	/* a function call and actual parameters */

	hollerith_,	/* quirky- a hollerith string */
	arrayint1D_,

	self_
};
#endif
class VarDef
{
public:
	VarDef(CString varname , int type, DWORD addr, CString classname)
	{
		_varname=varname;
		_type=type;
		_addr=addr;
		_classtype=classname;
	}
	CString _varname;
	int _type;
	DWORD _addr;
	CString _classtype;
};

typedef std::vector<VarDef> VarDefs;


struct ColorMap
{
	ColorMap(float red=0, float green=0, float blue=0) { SetColor(red, green,  blue);}
	ColorMap(COLORREF rgb)  { SetColor(rgb); }
	void SetColor(float red, float green, float blue) { this->red=red; this->green=green; this->blue= blue;}
	void SetColor(COLORREF rgb)
	{
		red=float(GetRValue(rgb))/255.0;
		green=float(GetGValue(rgb))/255.0;
		blue=float(GetBValue(rgb))/255.0;
	}
	float * GetColor(){ return &this->red; }
	operator  COLORREF(){ COLORREF rgb = RGB ((short) (red*255) ,(short) (green*255),(short) (blue*255));	return rgb;}
	///////////////////
	float red, green, blue;

};


struct SPolygon : public	std::vector<Vector> 
{	
public:
	void Multiply(Matrix v);
	void Translate(Vector v);
	CString ToString();
};
typedef	SPolygon  VectorList;
#if 0
struct CClassDef;
struct CVarDef;
typedef std::vector<CVarDef> CVarDefs;

struct CVarDef
{
	CString m_sName;
	CString m_sClassname;
	type_enum m_eType;
	DWORD m_ref;
	CVarDefs * m_optBaseClassVars;
	type_enum m_eListType;
	bool m_bOptional;
	DWORD m_NRef;

	CVarDef(CString name=_T(""), type_enum type=unknown_, DWORD ref=0, CString sClassname=_T(""), bool bOptional=false)
	{ 
		Init(name,  type,  ref, sClassname,  bOptional);
	} 
	CVarDef(CString name,  DWORD ref, CString sClassname, type_enum type, ...)
	{ 
		Init(name,  type,  ref, sClassname,  false);
		va_list ap;
		va_start(ap, type);
		switch(type)
		{
		case arrayint1D_:
			{
				m_NRef=va_arg ( ap, DWORD );
			}
		}
		va_end(ap);
	} 
	void Init(CString name=_T(""), type_enum type=unknown_, DWORD ref=0, CString sClassname=_T(""), bool bOptional=false)
	{ 
		this->m_sName=name; 
		this->m_eType=type; 
		this->m_ref=ref; 
		this->m_optBaseClassVars=NULL;
		this->m_eListType=unknown_;
		this->m_sClassname=sClassname;
		m_bOptional=bOptional;
	} 

	static DWORD Find(std::vector<CVarDef> vars, CString name)
	{
		for(int i=0; i<vars.size(); i++)
			if(vars[i].m_sName==name) return vars[i].m_ref;

		return NULL;
	}
	static CString Hollerith(CString str) { return StrFormat("%dH%s", str.GetLength(), str); }
	static CString DeHollerith(CString str){ 
		return str.Mid(str.Find("H")+1); }


	HRESULT Store (CString str)
	{
		switch(m_eType)
		{
		case integer_ :
			{
				int * pInt = (int *) m_ref;
				*pInt= atoi(str);
			}
			break;
		case real_ :
			{
				float * pFloat = (float *) m_ref;
				*pFloat= atof(str);
				if(errno==EINVAL)
					return E_FAIL;
			}
			break;
		case string_ :
			{
				CString * pStr = (CString *) m_ref;
				*pStr= str;
			}
			break;
			break;
		case hollerith_ :
			{
				CString * pStr = (CString *) m_ref;
				*pStr= DeHollerith(str);
			}
			break;	
		}
		
		return S_OK;
	}
	CString Write ()
	{
		CString str;
		switch(m_eType)
		{
		case integer_ :
			{
				int * pInt = (int *) m_ref;
				return StrFormat("%d", *pInt); 
			}
			break;
		case real_ :
			{
				float * pFloat = (float *) m_ref;
				return StrFormat("%g", *pFloat); 
			}
			break;
		case string_ :
			{
				CString * pStr = (CString *) m_ref;
				return StrFormat("%s", *pStr); 
			}
			break;
		case hollerith_ :
			{
				CString * pStr = (CString *) m_ref;
				return Hollerith(StrFormat("%s", *pStr)); 
			}
		}
		return str;
	}
};

#endif
template<class T>
struct SetType
{
	int min;   // e.g., 0 or 1
	int max;  // -1 infinite
	CString m_sName;
	CString m_sType;
	CString m_sReferenceChain;
	bool m_bOptional;
	std::vector<T> items;
	SetType<T>(CString name, CString type, CString parent=_T(""), bool bOptional=true, int min=1, int max=-1)
	{
		this-> min=min;   // e.g., 0 or 1
		this->max=max;  // -1 infinite
		this->m_sName=name;
		this->m_sType=type;
		this->m_sReferenceChain=parent;
		this->m_bOptional=bOptional;
	}

};
