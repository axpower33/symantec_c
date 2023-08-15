//
// _PROJ_VW.H
//
// interface of the CMDIAPPView class
//
// Copyright (c) XYZ Corporation, 2023. All Rights Reserved.
//

class CMDIAPPView : public CView
{
public:
	CMDIAPPDoc *GetDocument();

	virtual ~CMDIAPPView();
	virtual void OnDraw(CDC *pDC);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CMDIAPPView();
	DECLARE_DYNCREATE(CMDIAPPView)
    virtual void Circle (float x,float y, float r,CDC *pDC,CMDIAPPDoc* pDoc);
    virtual void Line(float x1,float y1,float x2,float y2,CDC *pDC,CMDIAPPDoc* pDoc);

	virtual BOOL OnPreparePrinting(CPrintInfo *pInfo);
	virtual void OnBeginPrinting(CDC *pDC, CPrintInfo *pInfo);
	virtual void OnEndPrinting(CDC *pDC, CPrintInfo *pInfo);

	// Message maps
protected:
	DECLARE_MESSAGE_MAP()

	//{{AFX_MSG(CMDIAPPView)
	// Handlers within the section marked by {{AFX_MSG and }}AFX_MSG
	// are maintained by ClassExpress.
	//}}AFX_MSG
};

#ifndef _DEBUG	// debug version in mdiappvw.cpp
inline CMDIAPPDoc *CMDIAPPView::GetDocument()
	 { return (CMDIAPPDoc*) m_pDocument; }
#endif
