//
// MDIAPP.cpp
//
// Defines the class behaviors for the application.
//
// Copyright (c) XYZ Corporation, 2023. All Rights Reserved.
//

#include "stdafx.h"
#include "MDIAPP.h"

#include "mainfrm.h"
#include "mdiapdoc.h"
#include "mdiappvw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//
// CMDIAPPApp
//

CFRDlg FrDlg;

BEGIN_MESSAGE_MAP(CMDIAPPApp, CWinApp)
	//{{AFX_MSG_MAP(CMDIAPPApp)
	ON_COMMAND(ID_APP_ABOUT, OnAbout)
	ON_COMMAND(IDM_ITEM2, OnFrMod_InCnd)

	// Handlers within the section marked by {{AFX_MSG_MAP
	// and }}AFX_MSG_MAP are maintained by ClassExpress.
	//}}AFX_MSG_MAP

	// Use inherited for File/New and File/Open
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)

	// Use inherited for File/Print Setup
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)

	// Use inherited for help
	ON_COMMAND(ID_HELP_INDEX, CWinApp::OnHelpIndex)
	ON_COMMAND(ID_HELP_USING, CWinApp::OnHelpUsing)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CWinApp::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CWinApp::OnHelpIndex)
END_MESSAGE_MAP()

//
// CMDIAPPApp construction
//

CMDIAPPApp::CMDIAPPApp()
{
	// You can initialize member variables here.
	// Most of the initialization code, however,
	// should go into CMDIAPPApp::InitInstance().
}

// There is only one instance of the CMDIAPPApp object
CMDIAPPApp NEAR theApp;

//
// CMDIAPPApp initialization
//
CObList m_templateList;
BOOL CMDIAPPApp::InitInstance()
{
#if (_MFC_VER >= 0x0300)
	Enable3dControls();
#else
	EnableVBX();			// Initialize VBX support
	SetDialogBkColor();		// Set dialog background color to gray
#endif

	LoadStdProfileSettings();	// Load information from the .INI

	// Register our document templates
	CMultiDocTemplate *pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_MDIDOCTYPE,
			RUNTIME_CLASS(CMDIAPPDoc),
			RUNTIME_CLASS(CMDIChildWnd),
			RUNTIME_CLASS(CMDIAPPView));
    if (!pDocTemplate)
		return FALSE;
	else
		m_templateList.AddHead(pDocTemplate);
	AddDocTemplate(pDocTemplate);
	// Create an MDI frame window
	CMainFrame *pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

        // simple command-line handling
        if (! m_lpCmdLine[0]) {
                OnFileNew();
        } else {
                OpenDocumentFile(m_lpCmdLine);
        }

	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

//
// CAboutDlg dialog used for App About
//

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()

	virtual void DoDataExchange(CDataExchange *pDX);
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	// Handlers within the section marked by {{AFX_MSG_MAP and }}AFX_MSG_MAP
	// are maintained by ClassExpress.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CMDIAPPApp::OnAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


CFRDlg::CFRDlg() : CDialog(CFRDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
	m_Npat=60;
	m_dt=1e-5;

}

void CFRDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, m_Npat);
    DDV_MinMaxInt(pDX, m_Npat, 2, 10000);
    DDX_Text(pDX, IDC_EDIT2, m_dt);
    DDV_MinMaxFloat(pDX, m_dt, 0, 1);

	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFRDlg, CDialog)

    ON_COMMAND(IDC_EDIT1, FrOnEdit1)
	ON_COMMAND(IDC_EDIT2, FrOnEdit2)

	//{{AFX_MSG_MAP(CAboutDlg)
	// Handlers within the section marked by {{AFX_MSG_MAP and }}AFX_MSG_MAP
	// are maintained by ClassExpress.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void CFRDlg::FrOnEdit1()
{
}

void CFRDlg::FrOnEdit2()
{
}


void CMDIAPPApp::OnFrMod_InCnd()
{
	FrDlg.DoModal();
}
// VBX handling
//{{AFX_VBX_REGISTER_MAP()
//}}AFX_VBX_REGISTER_MAP

//
// CMDIAPPApp commands
//
BOOL CMDIAPPApp::OnIdle( LONG lCount )
{
    CWinApp::OnIdle( lCount );

    int i = 5;

    while( i-- )
    {
       POSITION pos = m_templateList.GetHeadPosition();
       while (pos != NULL)
       {  CMultiDocTemplate* pTemplate = (CMultiDocTemplate*)m_templateList.GetNext(pos);

          POSITION dPos = pTemplate->GetFirstDocPosition();
          while( dPos != NULL )
          {
             CDocument* doc = (CDocument*)pTemplate->GetNextDoc(dPos);
             doc->OnIdle();

             if( i ) continue;

                POSITION vPos = doc->GetFirstViewPosition();
                while( vPos != NULL )
                {
                    CView* view = (CView*)doc->GetNextView( vPos );
                    view->Invalidate( FALSE );
                    view->UpdateWindow();
                }
          }
      }
  }
  return TRUE;
}