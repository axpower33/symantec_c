//
// MAINFRM.CPP
//
// Code for the application frame window
//
// Copyright (c) XYZ Corporation, 2023. All Rights Reserved.
//
//

#include "stdafx.h"
#include "MDIAPP.h"

#include "mainfrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//
// class CMainFrame
//

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	// Handlers within the section marked by {{AFX_MSG_MAP and }}AFX_MSG_MAP
	// are maintained by ClassExpress.
	ON_WM_CREATE()
	//}}AFX_MSG_MAP

	ON_COMMAND(ID_HELP_INDEX, CFrameWnd::OnHelpIndex)
	ON_COMMAND(ID_HELP_USING, CFrameWnd::OnHelpUsing)
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpIndex)
END_MESSAGE_MAP()

// The following array contains a list of command IDs for the toolbar.
// They correspond to the order of the buttons in the IDR_MAINFRAME bitmap.

static UINT BASED_CODE buttons[] =
{
	ID_FILE_NEW,
	ID_FILE_OPEN,
	ID_FILE_SAVE,
	ID_SEPARATOR,
	ID_EDIT_CUT,
	ID_EDIT_COPY,
	ID_EDIT_PASTE,
	ID_SEPARATOR,
	ID_FILE_PRINT,
	ID_APP_ABOUT,
	ID_CONTEXT_HELP,
};

// The following array contains a list of indicators for the status bar.
// See AFXRES.H for a complete list.

static UINT BASED_CODE indicators[] =
{
	ID_SEPARATOR,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

//
// CMainFrame constructor
//

CMainFrame::CMainFrame()
{
}

//
// CMainFrame destructor.
//

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1) return -1;

	if (!m_StatusBar.Create(this) ||
		!m_StatusBar.SetIndicators(indicators,
		sizeof(indicators)/sizeof(indicators[0]))) {
		TRACE("Failed to create status bar in CMainFrame::OnCreate()\n");
		return -1;
	}

#if (_MFC_VER >= 0x0300)
	if (!m_ToolBar.Create(this,
		WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_TOOLTIPS | CBRS_FLYBY) ||
#else
	if (!m_ToolBar.Create(this) ||
#endif
		!m_ToolBar.LoadBitmap(IDR_MAINFRAME) ||
		!m_ToolBar.SetButtons(buttons, sizeof(buttons)/sizeof(buttons[0]))) {
		TRACE("Failed to create toolbar in CMainFrame::OnCreate()\n");
		return -1;
	}

#if (_MFC_VER >= 0x0300)
	m_ToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_ToolBar);
#endif

	return 0;
}

//
// CMainFrame debug diagnostics
//

#ifdef _DEBUG
void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

#endif

//
// CMainFrame message handlers
//
