//
// MDIAPP.h
//
// main header file for the application
//
// Copyright (c) XYZ Corporation, 2023. All Rights Reserved.
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

//
// CMDIAPPApp
//

class CFRDlg : public CDialog
{
public:
	int m_Npat;
	float m_dt;
	CFRDlg();

	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_DIALOG2 };
	//}}AFX_DATA

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()

	virtual void DoDataExchange(CDataExchange *pDX);
	void FrOnEdit1();
	void FrOnEdit2();
	//{{AFX_MSG(CFRDlg)
	//}}AFX_MSG
};

class CMDIAPPApp : public CWinApp
{
public:
	CMDIAPPApp();
	BOOL OnIdle( LONG lCount );

// Overrides
	virtual BOOL InitInstance();

// Implementation
	DECLARE_MESSAGE_MAP()

	//{{AFX_MSG(CMDIAPPApp)
	// Handlers within the section marked by {{AFX_MSG and }}AFX_MSG
	// are maintained by ClassExpress.
	afx_msg void OnAbout();
	afx_msg void OnFrMod_InCnd();
	//}}AFX_MSG
};

extern CFRDlg FrDlg;
extern CMDIAPPApp NEAR theApp;

// VB-Event extern declarations

//{{AFX_VBX_REGISTER()
//}}AFX_VBX_REGISTER


