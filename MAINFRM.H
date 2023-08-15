//
// MAINFRM.H
//
// Interface for the application frame window
//
// Copyright (c) XYZ Corporation, 2023. All Rights Reserved.
//
//

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
			
public:
	CMainFrame();				
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Implementation 
protected:

	// Member variables
	CStatusBar	m_StatusBar;
	CToolBar		m_ToolBar;

	// Message maps
protected:
	DECLARE_MESSAGE_MAP()
			
	//{{AFX_MSG(CMainFrame)
	// Handlers within the section marked by {{AFX_MSG and }}AFX_MSG
	// are maintained by ClassExpress.	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
};
