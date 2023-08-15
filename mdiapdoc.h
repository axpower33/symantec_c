//
// mdiapdoc.h
//
// Interface of the CMDIAPPDoc class
//
// Copyright (c) XYZ Corporation, 2023. All Rights Reserved.
//
enum bool {false=0, true=1};

struct RPoint
         { float X;
           float Y;
           float Z;
         };
struct  Particle
          {
            float X,Y,Z;
            float Vx,Vy,Vz;
            float Fx,Fy,Fz;
            float VanX,VanY,VanZ;
            float mass;
            float q;
            float R;
            int   N;
            int   agr;
            bool  stop;
            Particle* next;
            Particle* pred;
          };

struct Agregat
          {
            float X,Y,Z;
            float Vx,Vy,Vz;
            float Jx,Jy,Jz;
            float Mx,My,Mz;
          };

class CMDIAPPDoc : public CDocument
{
public:
	virtual ~CMDIAPPDoc();
	void OnIdle();
	virtual void Serialize(CArchive& ar);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CMDIAPPDoc();
	DECLARE_DYNCREATE(CMDIAPPDoc)

	virtual BOOL	OnNewDocument();

	// Message maps
protected:
	DECLARE_MESSAGE_MAP()

	//{{AFX_MSG(CMDIAPPDoc)
	// Handlers within the section marked by {{AFX_MSG and }}AFX_MSG
	// are maintained by ClassExpress.
	//}}AFX_MSG
protected:
    void MakeArray(int N);
    void DistroyArray();
    Particle* Npat(int Np);
    void MxwDstr();
    void InitParticle();
    void InitAgr();
    void CulonForces();
    bool IsPatInAgr (Particle* Pi,Particle* Pj);
    void MovePart();
    void AngleSpeed (int kk, RPoint &W);
    void ChangeCMass(int Nagr);
    float GetMass (int i);
    void SetAgrSpeed(Particle* Pi);
    void AddPattoAgr (Particle* Pi,Particle* Pj);
    void PushAway (Particle*Pi,Particle* Pj);
    void UnitPaticle (Particle* Pi, Particle* Pj);
    void AgrForces();
    char* PathToDat();
public:
    int N;
    float dt;
    float Rmax;
    float Rmin;
    float Rmid;
    float Tmshft;
    float DensAg;
    int Tk;
    int MaxQ;
    float Xmax;
    float Ymax;
    float Zmax;
    Particle* FirstPat;
    Particle* PNp;
    Agregat* dF;
    int* Pagregat;
    Agregat* CMass;
    int* ConPat;
    int s;
    float t;
    Particle* LastPat;
    Particle* TempP;
    Particle* Pi;
    Particle* Pj;
    bool needCharge;
    float GetScX,GetScY;
    float GetmaxX,GetmaxY;
    float GetminX,GetminY;
    float rangeX;
    float rangeY;
    float rangeR;
};
