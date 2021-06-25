// 
// StepNCTreeView.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "Resource.h"
#include <time.h>
#include "atlstr.h"
#include "atlcrack.h"
#include "OutDebug.h"
#include "SymbolTable.h"

typedef CWinTraitsOR<WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_SHOWSELALWAYS | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_EDITLABELS >      CNCTreeViewTraits;
#if 1
typedef CComPtr<NiStepLib::IAttribute> CVarDefPtr;
typedef NiStepLib::IAttribute CVarDef;
typedef CComPtr<NiStepLib::INode> IStepNodePtr;
typedef NiStepLib::INode IStepNode;
typedef NiStepLib::IAttributeList CVarDefs;
using namespace NiStepLib;

#else

typedef CComPtr<IAttribute> CVarDefPtr;
typedef IAttribute CVarDef;
typedef CComPtr<INode> IStepNodePtr;
typedef INode IStepNode;
typedef IAttributeList CVarDefs;
#endif
#define GetVarDefs   GetAttributeList
#define IsSimpleType isSimpleType
#define  ExpressClassname Classname
#define IsListType isListType
#define IsASimpleListType isASimpleListType
#define IsSimpleListType  isSimpleListType
#define Swap SwapListItems
class CStepNCTreeView :
	public CWindowImpl<CStepNCTreeView, WTL::CTreeViewCtrlEx, CNCTreeViewTraits>,
	public CMessageFilter
{
public:
	DECLARE_WND_SUPERCLASS(NULL, CTreeViewCtrl::GetWndClassName());	
	CStepNCTreeView(void);
	~CStepNCTreeView(void);
	CToolTipCtrl m_ToolTip;
	enum { alpha=6, numeric=5, simplelistitem=12, list=7, entity=2 };
	
	HRESULT			BuildTree(CVarDefs *vars, CTreeItem parent=NULL);
	HRESULT			BuildTreeBranch(CVarDef * vardef, CTreeItem parent=NULL, CTreeItem prev=TVI_LAST);
	CTreeItem		InsertTreeItem(CString text, UINT image, UINT selectedimage, CVarDef * vardef, HTREEITEM parent, HTREEITEM after);
	CTreeItem		InsertSimpleTypeTreeItem(CVarDef * vardef, CTreeItem parent, CTreeItem ti);
	LRESULT			DeleteTreeItem(CTreeItem ti);
	void			InvalidateTreeItem(CTreeItem ti);
	LRESULT			MoveUpDown(CTreeItem ti, int id);
	void			RebuildTree(CTreeItem ti, IStepNodePtr newstep,  CVarDefPtr vardef);

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		if(m_ToolTip.IsWindow())
			 m_ToolTip.RelayEvent(pMsg);
		 return false;
	}
	
	BEGIN_MSG_MAP(CStepNCTreeView)
		MSG_WM_CREATE(OnCreate)
		MESSAGE_HANDLER(WM_RBUTTONDOWN, OnMouseRightClick)

		REFLECTED_NOTIFY_CODE_HANDLER(TVN_SELCHANGED, OnSelectChangeTree)

		REFLECTED_NOTIFY_CODE_HANDLER_EX(NM_DBLCLK, OnTreeDblClick)
		REFLECTED_NOTIFY_CODE_HANDLER(TVN_BEGINLABELEDIT, OnBeginLabelEditnotify)
		REFLECTED_NOTIFY_CODE_HANDLER(TVN_ENDLABELEDIT, OnEndLabelEditnotify)

		

		FORWARD_NOTIFICATIONS()
		DEFAULT_REFLECTION_HANDLER()

	END_MSG_MAP()


	bool IsMoveUpEnabled();
	bool IsMoveDownEnabled();
	bool IsDeleteEnabled(){ CTreeItem ti=GetSelectedItem(); return !ti.IsNull(); }
	LRESULT OnMoveUp(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnMoveDown(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnDeleteItem(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{ CTreeItem ti=GetSelectedItem(); return DeleteTreeItem(ti); }


	int OnCreate(LPCREATESTRUCT lpCreateStruct);

	LRESULT OnTreeDblClick(LPNMHDR pnmh);
	LRESULT OnKeydownnotify(WPARAM /*wParam*/, LPNMHDR /*lParam*/, BOOL& bHandled);

	
	LRESULT OnSelectChangeTree(WPARAM /*wParam*/, LPNMHDR /*lParam*/, BOOL& bHandled);
	LRESULT OnEndLabelEditnotify(WPARAM /*wParam*/, LPNMHDR /*lParam*/, BOOL& bHandled);
	LRESULT OnBeginLabelEditnotify( WPARAM /*wParam*/, LPNMHDR /*lParam*/, BOOL& bHandled);
	LRESULT OnSelectChangeTree(NMHDR* phdr)
	{
		return 0;
	}
	void DeleteBranchChildren(CTreeItem it);

	LRESULT OnMouseRightClick(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	///////////////////////////////////////////////////////
	CImageList m_treeicon;
	HWND Bug_Handle;
	CSymbolTable menutable;

};
