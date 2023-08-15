//
// _PROJ_VW.CPP
//
// Implementation of the CMDIAPPView class
//
// Copyright (c) XYZ Corporation, 2023. All Rights Reserved.
//

#include "stdafx.h"
#include "MDIAPP.h"

#include "mdiapdoc.h"
#include "mdiappvw.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//
// CMDIAPPView
//

IMPLEMENT_DYNCREATE(CMDIAPPView, CView)

BEGIN_MESSAGE_MAP(CMDIAPPView, CView)
	//{{AFX_MSG_MAP(CMDIAPPView)
	// Handlers within the section marked by {{AFX_MSG_MAP and }}AFX_MSG_MAP
	// are maintained by ClassExpress.
	//}}AFX_MSG_MAP

	// Use superclass for File/Print and File/Print Preview
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

//
// CMDIAPPView constructor
//

CMDIAPPView::CMDIAPPView()
{
	// to do: add construction code here
}

//
// CMDIAPPView destructor
//

CMDIAPPView::~CMDIAPPView()
{
}
int round(float v)
{
 return(v+0.5);
}

void CMDIAPPView::Circle (float x,float y, float r,CDC *pDC,CMDIAPPDoc* pDoc)
{
 pDC->Ellipse(round((x-r-pDoc->GetminX)*pDoc->rangeX),
              round((pDoc->GetScY-(y-r)+pDoc->GetminY)*pDoc->rangeY),
              round((x+r-pDoc->GetminX)*pDoc->rangeX),
              round((pDoc->GetScY-(y+r)+pDoc->GetminY)*pDoc->rangeY));
}

void CMDIAPPView::Line(float x1,float y1,float x2,float y2,CDC *pDC,CMDIAPPDoc* pDoc)
{
  pDC->MoveTo(round((x1-pDoc->GetminX)*pDoc->rangeX),round((pDoc->GetScY-y1+pDoc->GetminY)*pDoc->rangeY));
  pDC->LineTo(round((x2-pDoc->GetminX)*pDoc->rangeX),round((pDoc->GetScY-y2+pDoc->GetminY)*pDoc->rangeY));
}
void CMDIAPPView::OnDraw(CDC *pDC)
{
CPen bluePen=CPen(PS_SOLID, 1, RGB(0,0,255)),
     redPen =CPen(PS_SOLID, 1, RGB(255,0,0)),
     magPen =CPen(PS_SOLID, 1, RGB(255,0,255));

CBrush redBrush=CBrush( RGB(255,0,0) ),
       blackBrush = CBrush( RGB(0,0,0) ),
       blueBrush = CBrush( RGB(0,0,255) ),
       magBrush = CBrush( RGB(255,0,255) );

    CRect r;
    GetClientRect( &r );

	CMDIAPPDoc *pDoc = GetDocument();
    pDoc->rangeX=r.right/pDoc->GetScX;
    pDoc->rangeY=r.bottom/pDoc->GetScY;
    pDoc->rangeR=sqrt(pow(pDoc->rangeX,2)+pow(pDoc->rangeY,2));

    pDC->FillRect( r, &blackBrush );
    pDC->SelectStockObject( BLACK_BRUSH );
    for(pDoc->Pi=pDoc->FirstPat;pDoc->Pi!=NULL;pDoc->Pi=pDoc->Pi->next)
    {
      if (pDoc->Pi->q!=0) pDC->SelectObject( pDoc->Pi->q>0 ? &redPen : &bluePen );
      else pDC->SelectObject( &magPen );
      Circle(pDoc->Pi->X, pDoc->Pi->Y, pDoc->Pi->R, pDC, pDoc);
    }

	// to do: add draw code here
}

BOOL CMDIAPPView::OnPreparePrinting(CPrintInfo *pInfo)
{
	return DoPreparePrinting(pInfo);
}

void CMDIAPPView::OnBeginPrinting(CDC */*pDC*/, CPrintInfo */*pInfo*/)
{
}

void CMDIAPPView::OnEndPrinting(CDC */*pDC*/, CPrintInfo */*pInfo*/)
{
}

//
// CMDIAPPView debug diagnostics
//

#ifdef _DEBUG
void CMDIAPPView::AssertValid() const
{
	CView::AssertValid();
}

void CMDIAPPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDIAPPDoc *CMDIAPPView::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDIAPPDoc)));
	return (CMDIAPPDoc *) m_pDocument;
}

#endif

//
// CMDIAPPView message handlers
//
