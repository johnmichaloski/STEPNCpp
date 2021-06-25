//
// StepNCTreeView.cpp
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.


#include "StdAfx.h"
#include "StepNCTreeView.h"
#define _WTL_NO_CSTRING
#define _CSTRING_NS	ATL
#include "atlmisc.h"
#include "boost/lexical_cast.hpp"
#include "SymbolTable.h"
#include "HelpInfo.h"

#define ID_NOTIFY_INSERT 1
#define ID_NOTIFY_DELETE 2
#define ID_NOTIFY_COPY 3
#define ID_NOTIFY_PASTE 4
#define ID_NOTIFY_CUT 5
#define ID_EXPANDALL 6
#define ID_MOVEITEMUP 7
#define ID_MOVEITEMDOWN 8
#define ID_RENUMBER 9
#define ID_FILL 10
#define ID_PATHCLIPBOARD 11
#define ID_CLASSPATHCLIPBOARD 12 

#define ID_START_INSERT 20

#define HELPINFO
#ifdef HELPINFO
static CHelpInfo helpinfo;
#endif

// NOTE: the Ptr are not boost smart pointer, but COM smart pointers, which are ignored.
extern 	IStepPath * gpStepDom;

bool isSimpleType(_bstr_t classname)
{

	return false;
}

class CTreeNodeOperation
{
public:
	CTreeNodeOperation(){}
	CTreeItem &Parent() { return _parent; }
	int & Index() { return  _index; }
	
	int op;
	int _index;
	CTreeItem _parent;
	CTreeItem node;
	CTreeItem prevsibling;

	CVarDefPtr vardef; // save variable. What about saving IStepNodePtr?
};
static std::vector<CTreeNodeOperation> undo;
static std::vector<CTreeNodeOperation> redo;

static CTreeItem _copy;
static int nCopy = 0;
static CTreeItem _safe;

CStepNCTreeView::CStepNCTreeView(void)
{

}

CStepNCTreeView::~CStepNCTreeView(void)
{
}

int CStepNCTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{

	LRESULT lRet = DefWindowProc();

	SetFont(AtlGetDefaultGuiFont());
	if(!m_treeicon.Create( IDB_TREE_ICONS, 16, 1, RGB(255,0,255) ))
	{
		DebugBreak(); 

	}
	SetImageList( m_treeicon ); //
	menutable.FromInifile(GetExeDirectory() + "Menu.ini" );

	// register object for message filtering and idle updates
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->AddMessageFilter(this);
	//pLoop->AddIdleHandler(this);
	m_ToolTip.Create(this->m_hWnd);
	m_ToolTip.SetDelayTime(TTDT_INITIAL, 1);

	m_ToolTip.Activate(TRUE);
	m_ToolTip.SetMaxTipWidth(300);
#if 0
	m_ToolTip.UpdateTipText("Hello", m_hWnd);
#endif

	return lRet;
}

// Determine if moveup or movedown is enabled
bool  CStepNCTreeView::IsMoveUpEnabled()
{  
	CTreeItem ti = this->GetSelectedItem(); 
	if(ti.IsNull())
		return false;
	CVarDef *  vardef = (CVarDef *) ti.GetData();

	return vardef->Type == index_; 
}

bool  CStepNCTreeView::IsMoveDownEnabled(){  return IsMoveUpEnabled(); }
LRESULT CStepNCTreeView::OnMoveUp(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	return MoveUpDown(GetSelectedItem(), ID_MOVEITEMUP);
}
LRESULT CStepNCTreeView::OnMoveDown(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	return MoveUpDown(GetSelectedItem(), ID_MOVEITEMDOWN);
}


HRESULT CStepNCTreeView::BuildTree(CVarDefs * vars, CTreeItem parent)
{
	CTreeItem ti=TVI_LAST;
	for(int i=0; i<vars->length; i++)
	{
		CVarDef *  vardef = (CVarDef * ) vars->Getitem(i);
		if(FAILED(BuildTreeBranch(vardef, parent)))
			return E_FAIL;
	}
	return S_OK;

}

CTreeItem  CStepNCTreeView::InsertTreeItem(CString text, UINT image, UINT selectedimage, CVarDef * vardef, HTREEITEM parent, HTREEITEM after)
{
	CTreeItem ti = InsertItem(TVIF_TEXT | TVIF_IMAGE |TVIF_SELECTEDIMAGE|TVIF_PARAM , 
		text, 
		image,  // image
		selectedimage,  // selected image
		0,  // state
		0,  // state mask
		(LPARAM) vardef,  
		parent,  
		after);  // insert after
	//vardef->Atom = (DWORD) ti.m_hTreeItem;
	return ti;

}
CTreeItem  CStepNCTreeView::InsertSimpleTypeTreeItem(CVarDef * vardef, CTreeItem parent, CTreeItem ti)
{
	CString value = (LPCWSTR) vardef->GetVarString();
	UINT image=6, selectedimage=6;
	if(!vardef->IsSimpleType())
	{
		return NULL;
	}

	if(vardef->Type== real_ ||  vardef->Type== integer_)
	{ 
		image=5; selectedimage=5; 
	}
	else if(vardef->Type== boolean_)
	{ 
		image=13; selectedimage=13; 
	}

	ti=InsertItem(TVIF_TEXT | TVIF_IMAGE |TVIF_SELECTEDIMAGE|TVIF_PARAM , 
		StrFormat(_T("%s"), value), 
		image,  // image
		selectedimage,  // selected image
		0,  // state
		0,  // state mask
		(LPARAM) vardef,  
		parent,  
		ti );  // insert after
	
//	vardef->Atom = (DWORD) ti.m_hTreeItem;

	return ti;

}

HRESULT CStepNCTreeView::BuildTreeBranch(CVarDef * vardef, CTreeItem parent, CTreeItem ti)
{
	CString value = (LPCTSTR) vardef->GetVarString();
	CTreeItem vectortreeitem=TVI_LAST;

	UINT image=2, selectedimage=2;
	if(vardef->Type == 	special_) 
	{
		BuildTree(vardef->GetInheritedAttributeList(), parent);
		return S_OK;
	}

	if(vardef->IsSimpleType())
	{
		CTreeItem parentitem=parent;
		CVarDef *  pvardef = (CVarDef *) parentitem.GetData();

		ti = InsertSimpleTypeTreeItem(vardef, parent,  ti);

		if(ti!=NULL)
			return S_OK;

		return E_FAIL;
	}

	if(vardef->Type == 	index_)
	{
		CVarDef * parentvardef = (CVarDef *) parent.GetData();
		IStepNodePtr list =   parentvardef->GetStepNode();
		int j = list->GetIndex(vardef);
		IStepNodePtr step = list->GetListItem(j); 
		vectortreeitem=	InsertTreeItem(StrFormat(_T("%d %s "), j, (LPCTSTR) step->Classname), 1, 4, vardef, parent, ti);
		vardef->Atom = (DWORD) vectortreeitem.m_hTreeItem;
		return BuildTree(step->GetVarDefs(), vectortreeitem);		
	}

	if(value.GetLength()>0)
		value= "  = " + value;

	if(vardef->Type == 	entity_  || (vardef->Type == 	reference_) )
	{
		ti=InsertTreeItem(StrFormat(_T("%s::%s"), (LPCTSTR) vardef->Name, (LPCTSTR) vardef->Classname, value), image, selectedimage, vardef, parent, ti);
		vardef->Atom = (DWORD) ti.m_hTreeItem;
		IStepNodePtr step=   vardef->GetStepNode();
		if(CString((LPCTSTR) vardef->Classname).Find(_T("feature"))>=0) ti.SetImage(6,6);
		if(CString((LPCTSTR) vardef->Classname).Find(_T("operation"))>=0) ti.SetImage(0,0);
		// FIMXE: repair classname to supertype.
		if(step!=NULL) 
		{
			BuildTree(step->GetVarDefs(), ti);
		}
	}
	else if(vardef->Type == 	bag_)
	{
		image=selectedimage=7;
		if(vardef->Dimension==1)
		{
			ti=InsertTreeItem(StrFormat(_T("%s::%s"), (LPCTSTR) vardef->Name, (LPCTSTR) vardef->Classname, value), image, selectedimage, vardef, parent, ti);
			vardef->Atom = (DWORD) ti.m_hTreeItem;
			IStepNodePtr list =   vardef->GetStepNode();

			//if(vardef->Name() == "coordinates")
			//	DebugBreak();

			if(list->GetSize()<1)
				return S_OK;
			if(list->IsASimpleListType(vardef->ListClassname))
			{
				value = (LPCTSTR) list->GetListVarString(_T(","));
				image=selectedimage=12;
				ti=InsertTreeItem(value, image,selectedimage, vardef, ti, TVI_LAST);
			}
			else
			{
				for (int j = 0; j<list->GetSize(); j++)
				{
					IStepNodePtr step = list->GetListItem(j); 
					vectortreeitem=	InsertTreeItem(StrFormat(_T("%d %s "), j, (LPCTSTR) step->Classname), 1, 4, list->GetAttributeList()->Getitem(j), ti, vectortreeitem);
					//list->GetItem(j)->Atom = (DWORD) vectortreeitem.m_hTreeItem;
					BuildTree(step->GetVarDefs(), vectortreeitem);			
				}
			}
		}
		else if(vardef->Dimension==2)
		{
#if FIXME
			ti=InsertTreeItem(StrFormat("%s::%s", vardef->Name(), vardef->Classname, value), image, selectedimage, vardef, parent, ti);
			vardef->Atom = (DWORD) ti.m_hTreeItem;

			EStepArray &outerlist = * (EStepArray *) vardef->m_ref;

			for (int j = 0; j<outerlist.size(); j++)
			{
				EStepNodeListPtr innerlist=  outerlist.at(j);

				IStepNodePtr step = innerlist->at(j) ;
				vectortreeitem=	InsertTreeItem(StrFormat("%d %s ", j, innerlist->Classname), 1, 4, outerlist.m_vars[j].get(), ti, vectortreeitem);
				innerlist->m_vars[j]->Atom = (DWORD) vectortreeitem.m_hTreeItem;
				BuildTree(innerlist->GetVarDefs(), vectortreeitem);			
			}
#endif
		}

		return S_OK;
	}
#if 0
	else if(vardef->Type() == 	set_ || vardef->Type() ==  list_)
	{
		ti=InsertTreeItem(StrFormat("%s::%s", vardef->Name(), vardef->Classname(), value), image, selectedimage, vardef, parent, ti);
		if(vardef->_nDimension!=1)
			return S_OK;
		std::vector<IStepNodePtr > &list= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
		CString szClassname = ExpDemangle(vardef->_sListClassname);
		if(list.size()<1)
			return S_OK;
		CString sz;
		CTreeItem vectortreeitem=TVI_LAST;
		if(vardef->m_eListType  == 	entity_  || (vardef->m_eListType == reference_))
		{
			for (int j = 0; j<list.size(); j++)
			{
				IStepNodePtr step = list[j] ;
				vectortreeitem=	InsertTreeItem(StrFormat("%d %s ", j, step->Classname()), 1, 4,  vardef, ti, vectortreeitem);
				// fixme: potential typedef problem...
				BuildTree(step->GetVarDefs(), vectortreeitem);			
			}
		}
		else
		{
			CString text("=(");
			for (int j = 0; j<list.size(); j++)
			{
				IStepNodePtr step = list[j] ;
				if(j>0)
					text+=",";
				if(step->IsSimpleType())
					text+=step->GetVarString();
			}
			text+=")";
			TCHAR label[128];
			ti.GetText(label, 128);
			ti.SetText( CString((LPTSTR) label) +  text);


		}
	}
#endif
	return S_OK;
}

void CStepNCTreeView::RebuildTree(CTreeItem ti, IStepNodePtr newstep,  CVarDefPtr vardef)
{			
	DeleteBranchChildren(ti);
	BuildTree( newstep->GetVarDefs(), ti);
	ti.SetText(StrFormat(_T("%s::%s"), (LPCTSTR) vardef->Name, (LPCTSTR) vardef->Classname));
}


LRESULT CStepNCTreeView::OnTreeDblClick(LPNMHDR pnmh)
{
	CTreeItem ti = GetSelectedItem(); 
	CVarDef *  vardef = (CVarDef *) ti.GetData();
	int nImage, nSelectedImage;
	ti.GetImage(nImage, nSelectedImage);
	if(vardef!=NULL && (vardef->IsSimpleType() || (vardef->Type == 	bag_ && nImage==simplelistitem)))
	{
		ti.EditLabel();
		return 0;
	}
	return 1;

}


//It then says to send TVM_ENDEDITLABELNOW to the Tree View in response to WM_CHAR messages for VK_RETURN and VK_CANCEL.

LRESULT CStepNCTreeView::OnEndLabelEditnotify(WPARAM wParam, LPNMHDR pNMHDR, BOOL& bHandled)
{
	HRESULT hr;
	CTreeItem ti = GetSelectedItem(); 
	CEdit edit = this->GetEditControl(); 
	CString str;
	edit.GetWindowText(str);
	ti.SetText(str);

	CVarDef *  vardef = (CVarDef *) ti.GetData();
	if(vardef!=NULL && (vardef->IsSimpleType() || vardef->Type == 	bag_))
	{
		try {
			if(vardef->Type == real_ || vardef->Type == integer_)
			{
				vardef->Owner()->SetVarString(_bstr_t(str));
			}
			else if(vardef->Type == 	bag_ )
			{
				IStepNodePtr list = vardef->GetStepNode();
				// should not have anything but a simple list, but...

				if(!list->IsASimpleListType(vardef->ListClassname))
					return 1;
				if(FAILED(hr=list->SetVarString(_bstr_t(str))))
				{
					MessageBox(_T("Invalid Entry"));
				}
			}
			else if(vardef->Type == string_)
			{

				str.Replace(_T("'"), _T(""));
				vardef->Owner()->SetVarString(_bstr_t(str));
				OutputDebugString(StrFormat(_T("String is %s\n"), (LPCTSTR) vardef->Owner()->GetVarString()));
			}
		}
		catch(...)
		{
			return 0;
		}
		return 1;


	}
	return 1;
}


LRESULT CStepNCTreeView::OnBeginLabelEditnotify( WPARAM /*wParam*/, LPNMHDR /*lParam*/, BOOL& bHandled)
{
	CTreeItem ti = GetSelectedItem();
	CVarDef *  vardef = (CVarDef *) ti.GetData();
	int nImage, nSelectedImage;
	if(vardef==NULL)
		return 1;
	ti.GetImage(nImage, nSelectedImage);
	if(vardef->IsSimpleType())
	{
		return 0;
	}
	else if(vardef->Type == bag_ && nImage==simplelistitem)
	{
		IStepNodePtr list=  vardef->GetStepNode();
		// should not have anything but a simple list, but...
		if(list->IsASimpleListType(vardef->ListClassname))
			return 0;
		return 1;
	}
	return 1;
}



class CMenuTree
{
public:
	int _nMenuId, _nMenuId0;
	std::vector<HMENU> typemenus;
	std::map<int, CString> menustrings;

	CMenuTree(int nStartId=1) : _nMenuId0(nStartId) {}
	~CMenuTree(){ DestroyHandle();	}
	void Reset()
	{
		_nMenuId=_nMenuId0;
		for(int i=0; i<typemenus.size(); i++)
			::DestroyMenu(typemenus[i]);
	}
	void  DestroyHandle()
	{
		for(int i=0; i<typemenus.size(); i++)
			::DestroyMenu(typemenus[i]);
	}
	CString GetMenuString(int i) { return menustrings[i]; }
	void CreateTypeHierarchySubmenu(CMenu & menu, CString classname)
	{

#ifdef FIXME
		//if(IsSimpleType(classname))
		//{
		//	menustrings[_nMenuId]=classname;
		//	menu.AppendMenu(MF_STRING, _nMenuId++, classname);
		//	return ;
		//}
		CStringVector supertypes = ClassSupertypeHierarchy(classname);
		if(supertypes.size()<1)
		{
			menustrings[_nMenuId]=classname;
			menu.AppendMenu(MF_STRING, _nMenuId++, classname );
			return ;
		}

		CMenu submenu;
		submenu.CreatePopupMenu();

		menu.AppendMenu(MF_POPUP | MF_STRING, submenu.m_hMenu, classname);
		menustrings[_nMenuId]=classname;
		submenu.AppendMenu(MF_STRING, _nMenuId++, classname );
		submenu.AppendMenu(MF_SEPARATOR );
		for(int i=0; i< supertypes.size(); i++)
		{
			CreateTypeHierarchySubmenu(submenu, supertypes[i]);
		}

		typemenus.push_back(submenu.Detach());
#endif
		return;

	}

	void CreateTypeHierarchyMenu(CMenu & menu, CString classname)
	{
		Reset();
		return CreateTypeHierarchySubmenu(menu,  classname);
	}
};

void CStepNCTreeView::DeleteBranchChildren(CTreeItem ti)
{
	CTreeItem child;
	for(CTreeItem child= this->GetChildItem(ti); !child.IsNull(); child= this->GetChildItem(ti))
		this->DeleteItem(child);

}

LRESULT CStepNCTreeView::DeleteTreeItem(CTreeItem ti)
{
	if(ti.IsNull())
		return 0;

	CVarDefPtr vardef = (CVarDef *) ti.GetData();


	if(vardef->Type == entity_ || vardef->Type == reference_)
	{
		vardef->Clear();
		DeleteBranchChildren(ti);
		ti.SetText(StrFormat(_T("%s::%s"), (LPCTSTR) vardef->Name, (LPCTSTR) vardef->Classname));
		this->UpdateWindow();
	}
	else if(vardef->IsSimpleListType())  // fixme: if not simple list, clear list when delete
	{
		vardef->Clear();
		CTreeItem child = ti.GetChild();
		CVarDef * childvardef = (CVarDef *) child.GetData();
		if(childvardef!=NULL)
			child.SetText(childvardef->GetVarString());
	}
	else if(vardef->IsListType())  // fixme: if not simple list, clear list when delete
	{
		if(vardef->Dimension==1)
		{
			vardef->Clear();
			DeleteBranchChildren(ti);
		}
	}
	else if(vardef->Type == index_ )
	{
		CTreeItem parent = ti.GetParent();
		CVarDefPtr parentvardef = (CVarDef *)  parent.GetData();
		IStepNodePtr step=  parentvardef->GetStepNode();
		step->DeleteChild((IStepNode *) vardef->GetStepNode());
		this->DeleteItem(ti);

	}
	else return 0;
	return 1;
	// fyi, cannot delete simple type
}
void CStepNCTreeView::InvalidateTreeItem(CTreeItem ti)
{
	TCHAR label[256];
	ti.GetText(label, 256);
	ti.SetText(label);
}

LRESULT CStepNCTreeView::MoveUpDown(CTreeItem ti, int id)
{
	CVarDef *  vardef = (CVarDef *) ti.GetData();
	if(vardef==NULL)
		return 1;
	if(vardef->Type != index_ )
	{
		// shouldn't happen
		return 1;
	}
	// note: you can only move list items up/down in the same list. 
	// Attribute positions are fixed.
	// FIXME: check that we aren't at root - slim to none chances of course.
	CTreeItem parent = ti.GetParent();
	CVarDefPtr parentvardef = (CVarDef *)  parent.GetData();
	IStepNodePtr list=   parentvardef->GetStepNode();
	IStepNodePtr step=  (IStepNode *) vardef->GetStepNode();
	int n = list->GetIndex(vardef);
	if(id==ID_MOVEITEMUP && n > 0 )
	{
		// fixme: exchange indexes in StepNode part - maybe not use index after all...
		list->Swap(n, n+1);
		CTreeItem prev = ti.GetPrevSibling();
		CVarDef * pVarDef = (CVarDef *) prev.GetData();
		BuildTreeBranch(pVarDef, parent, ti);
		DeleteItem(prev);
	}
	else  if(id==ID_MOVEITEMDOWN && n <(list->GetSize()-1))
	{
		list->Swap(n, n-1);
		CTreeItem next = ti.GetNextSibling();
		BuildTreeBranch(vardef, parent, next);
		DeleteItem(ti);
	}
	return 0;

}
LRESULT CStepNCTreeView::OnMouseRightClick(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& bHandled)
{
	HRESULT hr;
	UINT	Flags =  TPM_CENTERALIGN | TPM_RIGHTBUTTON |TPM_RETURNCMD ; //| TPM_NONOTIFY;
	UINT id;
	DWORD dwPos = GetMessagePos();
	/* Convert the co-ords into a CPoint structure */
	CPoint pt( GET_X_LPARAM( dwPos ), GET_Y_LPARAM( dwPos ) ), spt;
	spt = pt;

	::ScreenToClient(m_hWnd, &spt ); /* Convert to screen co-ords for hittesting */

	UINT nFlags;
	CTreeItem ti = this->HitTest(spt,&nFlags);
	CVarDef *  vardef = (CVarDef *) ti.GetData();
	CVarDef *  copyvardef = (!_copy.IsNull())? (CVarDef *) _copy.GetData() : NULL;
	if(vardef==NULL)
	{
		OutputDebugString(_T("Error menu hit test found class without LPARAM\n"));
		return 0;

	}

	// Create Menu
	//
	CMenu m_menu;
	CMenu m_submenu;
	CMenu m_fillsubmenu;
	CMenuTree menutree(ID_START_INSERT);


	m_menu.CreatePopupMenu();
	m_submenu.CreatePopupMenu();

	if(vardef->IsListType() && !vardef->IsSimpleListType())
	{
		m_menu.AppendMenu(MF_POPUP | MF_STRING, m_submenu.m_hMenu, _T("Insert") );
		menutree.CreateTypeHierarchyMenu( m_submenu,  (LPCTSTR) vardef->ListClassname);
	}
	else if(vardef->Type == entity_ || vardef->Type == reference_)
	{
		m_menu.AppendMenu(MF_POPUP | MF_STRING, m_submenu.m_hMenu, _T("Insert") );
		menutree.CreateTypeHierarchyMenu( m_submenu, (LPCTSTR) vardef->Classname);
	}
	else if(vardef->Type == index_ )
	{
		m_menu.AppendMenu(MF_POPUP | MF_STRING, m_submenu.m_hMenu, _T("Insert") );
		menutree.CreateTypeHierarchyMenu( m_submenu, (LPCTSTR) vardef->Classname);
	}
	else
	{
		m_menu.AppendMenu(MF_GRAYED | MF_STRING, ID_NOTIFY_INSERT, _T("Insert") );

	}

	m_menu.AppendMenu(MF_STRING, ID_NOTIFY_DELETE, _T("Delete") );
	m_menu.AppendMenu(MF_SEPARATOR);
	
	m_menu.AppendMenu(MF_STRING, ID_PATHCLIPBOARD, _T("Copy Path Clipboard") );
	m_menu.AppendMenu(MF_STRING, ID_CLASSPATHCLIPBOARD, _T("Copy Class Path Clipboard") );
	m_menu.AppendMenu(MF_STRING, ID_NOTIFY_COPY, _T("Copy") );
	m_menu.AppendMenu(MF_STRING, ID_NOTIFY_CUT, _T("Cut") );

	UINT nDeleteFlag = MF_STRING | MF_GRAYED;
	if(_copy!=NULL) 
	{
		// Has to be an exact copy. Too complicated otherwise.
		if(vardef->IsSimpleType() && vardef->Type == copyvardef->Type)
			nDeleteFlag =MF_STRING ;  
		else if(vardef->IsSimpleListType() && vardef->Classname == copyvardef->Classname)
			nDeleteFlag =MF_STRING ;  
		else if(vardef->IsListType() && !IsSimpleType(vardef->ListClassname) && 
			copyvardef->IsListType() && vardef->Classname == copyvardef->Classname)
			nDeleteFlag =MF_STRING ;  
		// fix - can be is-kind-of copy/paste not just exact match...?  
		else if(vardef->IsListType() && !IsSimpleType(vardef->ListClassname) && 
			copyvardef->Type == index_ && vardef->ListClassname == copyvardef->ListClassname)
			nDeleteFlag =MF_STRING ;  

	}
	m_menu.AppendMenu(nDeleteFlag, ID_NOTIFY_PASTE, _T("Paste") );
	if(vardef->Type == index_ ) // fixme only move if more than 1
	{
		// consider assigning method based variables once at beginning based on type...
		m_menu.AppendMenu(MF_SEPARATOR);
		m_menu.AppendMenu(MF_STRING, ID_MOVEITEMUP, _T("Move Up") );
		m_menu.AppendMenu(MF_STRING, ID_MOVEITEMDOWN, _T("Move Down") );
	}
	if(vardef->IsListType() && !vardef->IsSimpleListType()) // fixme only move if more than 1
	{
		m_menu.AppendMenu(MF_SEPARATOR);
		m_menu.AppendMenu(MF_STRING, ID_RENUMBER, _T("Renumber") );
	}
	
	CSymbolPtr symbol;
	if((symbol=menutable.GetSymbol((LPCTSTR) vardef->Name ))!=NULL )// fixme only move if more than 1
	{
		m_fillsubmenu.CreatePopupMenu();
		m_menu.AppendMenu(MF_POPUP | MF_STRING, m_fillsubmenu.m_hMenu, _T("Fill") );
		CStringVector items = menutable.GetSectionSymbols((LPCTSTR) vardef->Name);
		for(int i=0; i<items.size(); i++)
		{
			m_fillsubmenu.AppendMenu(MF_STRING, ID_FILL+i, items[i] );

		}
		
	}
	
	// Show menu
	CMenuHandle menu  = m_menu; 
	id=menu.TrackPopupMenu(Flags,pt.x,pt.y, m_hWnd);

	// Handle menu selection
	if(id==ID_EXPANDALL)
	{
		this->Expand(ti);
	}
	else if(id==ID_MOVEITEMUP || id==ID_MOVEITEMDOWN)
	{
		MoveUpDown(ti,id);
	}
	else if(id==ID_NOTIFY_DELETE)
	{
		DeleteTreeItem(ti);
	}
	else if(id==ID_NOTIFY_COPY || id==ID_NOTIFY_CUT)
	{
		_copy=ti; nCopy=id;
	}
	else if(id==ID_PATHCLIPBOARD || id==ID_CLASSPATHCLIPBOARD)
	{
		CVarDefPtr parentvardef=vardef;
		CTreeItem parent=ti;
		CString szPath;
#if 0
		IStepNodePtr step = vardef->GetStepNodePtr();
		CString tmp;
		if(step!=NULL)
			tmp = step->QueryAttributePaths(vardef);
#endif
		while (parent!=NULL)
		{
			CString separator;
			parentvardef = (CVarDef *)  parent.GetData();
			if(! szPath.Find(_T("["))==0)
				separator="/";
			if(id==ID_PATHCLIPBOARD)
				szPath=parentvardef->Name + separator + szPath;
			if(id==ID_CLASSPATHCLIPBOARD)
				szPath=_T("{") + parentvardef->Classname + _T("}") + parentvardef->Name+ separator + szPath;
			parent  = parent.GetParent();

		}
		CopyClipboard(szPath);

	}
	else if(id==ID_RENUMBER)
	{
		// FIMXE: should be pointer and check if null?
		//EListT<IStepNodePtr> & list=  *(EListT<IStepNodePtr> *) vardef->m_ref;
		IStepNodePtr list=  vardef->GetStepNode();
		CTreeItem child;
		int j;
		for ( j = 0, child=	ti.GetChild(); j<list->GetSize(); j++, child=child.GetNextSibling())
		{
			IStepNodePtr step = list->GetListItem(j) ;
			child.SetText(StrFormat(_T("%d %s "), j, (LPCTSTR) step->Classname));
		}

	}

	else if(id==ID_NOTIFY_PASTE)
	{
		if(copyvardef==NULL)
			return 1;
		if(vardef->IsSimpleType() && vardef->Type == copyvardef->Type)
		{
			CString str = (LPCTSTR) copyvardef->Owner()->GetVarString();
			vardef->Owner()->SetVarString(_bstr_t(str));
			ti.SetText(str);

		}
		else if(vardef->IsListType() && IsSimpleType(vardef->ListClassname) && vardef->Classname == copyvardef->Classname)
		{
			
			// Under construction...
			//EListT<IStepNodePtr> & list =  *(EListT<IStepNodePtr> *) vardef->m_ref;
			//CString str = list.GetVarString(",");
			//vardef->SetVarString(str);
			//ti.SetText(str);
		}
		else if(vardef->IsListType() && !IsSimpleType(vardef->ListClassname) && copyvardef->IsListType() && vardef->Classname == copyvardef->Classname)
		{

		}
		else if(vardef->IsListType() && !IsSimpleType(vardef->ListClassname) && copyvardef->Type == index_ && vardef->ListClassname == copyvardef->ListClassname)
		{
			IStepNode * list=  vardef->GetStepNode();

			IStepNode * indexstep = (IStepNode *)  copyvardef->GetStepNode();
			CString classname = (LPCTSTR) indexstep->Classname;

			IStepNodePtr newstep = gpStepDom->CreateNode(_bstr_t(classname)); //CClassGenerators::gClassGenerators.CreateClass(classname,_T(""));
			list->push_back(newstep, vardef->Name);
			CVarDef * newvardef = list->GetVarDefs()->back();
			newvardef->SetStepNode( (IStepNode *)  newstep);
			copyvardef->Clone(newvardef);

			IStepNode *  node =  (IStepNode *) newvardef->GetStepNode();

			CTreeItem vectortreeitem = InsertTreeItem(StrFormat(_T("%d %s"), list->GetSize()-1, classname), 1, 4, newvardef, ti, TVI_LAST);
			BuildTree(newstep->GetVarDefs(), vectortreeitem);	
			if(nCopy==ID_NOTIFY_CUT)
				DeleteTreeItem(_copy);

		}

	}
	else if(id>=ID_FILL && id<ID_START_INSERT)
	{
		CStringVector	tags =  menutable.GetSectionSymbols((LPCTSTR) vardef->Name);
		CString value ;
		_variant_t var = menutable.GetItemValue(vardef->Name + tags[id-ID_FILL]);
		try{ value = (LPCTSTR)(_bstr_t) var; } catch(...){ return 1; }
		//if(!menutable.GetValue(vardef->Name(), tags[id-ID_FILL], value))
		//	return 1;

		if(vardef->IsSimpleListType())
		{
			IStepNode * list =  vardef->GetStepNode();
			if(FAILED(list->SetVarString(_bstr_t(value))))
			{
				// should never get here...
				return 1;
			}
			CTreeItem child = ti.GetChild();
			child.SetText(value);

		}	 
	}

	else if(id>=ID_START_INSERT)
	{
		if(vardef->Type == entity_ || vardef->Type == reference_ )
		{
			IStepNodePtr step=  vardef->GetStepNode();
			CString classname = menutree.GetMenuString(id);
			IStepNodePtr newstep = gpStepDom->CreateNode(_bstr_t(classname)); // CClassGenerators::gClassGenerators.CreateClass(ExpDemangle(classname),"");
			vardef->SetStepNode(newstep); // step= newstep;
			DeleteBranchChildren(ti);
			BuildTree( newstep->GetVarDefs(), ti);
			ti.SetText(StrFormat(_T("%s::%s"), (LPCTSTR) vardef->Name, (LPCTSTR) vardef->Classname));
		}
		// fixme iskind of simple list
		else if(vardef->Type == index_)
		{
			// FIXME get parent , get index, store new into index position - no just replacing?
			CTreeItem parent = ti.GetParent();
			CVarDefPtr parentvardef = (CVarDef *)  parent.GetData();
			IStepNode * list=  vardef->GetStepNode();
			int n = list->GetIndex(vardef);
			if(n<0 || n> list->GetSize())
			{
				// problem 
				return 0;
			}
		
			CString classname = menutree.GetMenuString(id);
			IStepNodePtr newstep = gpStepDom->CreateNode(_bstr_t(classname));
			if(newstep==NULL)
			{
				// problem 
				return 0;		
			}

			list->SetListItem(n, newstep);  // replace , old one should be deleted.

			DeleteBranchChildren(ti);
			BuildTree( newstep->GetVarDefs(), ti);
			this->InvalidateTreeItem(ti);

		}
		else if(!vardef->IsSimpleListType())
		{
			//EListT<IStepNodePtr> * step=  (EListT<IStepNodePtr> *) vardef->m_ref;
			IStepNode * list=  vardef->GetStepNode();
			CString classname = menutree.GetMenuString(id);

			IStepNodePtr newstep = gpStepDom->CreateNode(_bstr_t(classname));
			list->push_back(newstep, vardef->Name);
			CVarDef * newvardef = list->GetVarDefs()->back();

			CTreeItem vectortreeitem = InsertTreeItem(StrFormat(_T("%d %s"), list->GetSize()-1, classname), 1, 4, newvardef, ti, TVI_LAST);
			BuildTree(newstep->GetVarDefs(), vectortreeitem);	

		}

	}
	return  0;
}

LRESULT CStepNCTreeView::OnSelectChangeTree(WPARAM /*wParam*/, LPNMHDR /*lParam*/, BOOL& bHandled)
{
	CTreeItem ti = GetSelectedItem();
	CVarDef *  vardef = (CVarDef *) ti.GetData();
	if(vardef==NULL)
		return 0; // should NEVER happen
	if(vardef->IsSimpleType() || vardef->IsSimpleListType())
		return 0;
#ifdef HELPINFO
	CVarDef * parent = (CVarDef *) ti.GetParent().GetData();
	CString szHelp;
	if(parent)
		szHelp+= helpinfo.description[StrFormat(_T("%s.%s.description"), (LPCTSTR) parent->Classname, (LPCTSTR) vardef->Name)];
	szHelp+= helpinfo.description[StrFormat(_T("%s.description"), (LPCTSTR) vardef->Classname)];
	if(szHelp.GetLength() < 1)
		return 0;
	m_ToolTip.AddTool(m_hWnd, (LPCTSTR) szHelp);
	m_ToolTip.Pop();
#endif
	return  0;

}
