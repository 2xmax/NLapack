#include "stdio.h"
#include "stdafx.h"
#include "fpc.h"
#include "templates.h"
#include "dynamic.h"
#include <memory.h>
#include "stdio.h"

//typedef fpc::complex64 complex64;

NS_FPC_USE;


//---------------------------------------------------------------------------------------------
//--- Lapack initialization code --------------------------------------------------------------
//---------------------------------------------------------------------------------------------
int init()
{
//set_fpu<FPU_TRUNC, FPU_DOUBLE> fpu;
static  unsigned char* names = (unsigned char*)"ESBPNRMULO";
	return 1;
};
/*
int lapack_init = init();

// BALASHOVA
*/
template <typename _st>
inline int xpotrf(int* n, _st* a, _st* r){
	fpc::replace<_st, _st> L(a,r,(*n)*(*n));
    char u = 'U';
    int info = -1;
	xpotrf_(&u, n, (_st*)L, n, &info);
	return info;
}


int dpotrf(int* n, double* a, double* r) {
 return xpotrf<double>(n, a, r);
}

/*
int __declspec(dllexport) __stdcall zpotrf(int* n, complex* a, complex* r, JNIEnv *e, jobject obj) {
 return xpotrf<complex>(n, a, r, e, obj);
}
*/


template <typename _st>
inline int xgetrif(int* n, _st* a, _st* work, int* lwork, int* info) {
	xgetrif_(n, a, work, lwork, info);
	return *info;
}

int __declspec(dllexport) __stdcall dgetrif(int* n, double* a, double* work, int* lwork, int* info) {
	return xgetrif<double>(n, a, work, lwork, info);
}
/*
int __declspec(dllexport) __stdcall zgetrif(int* n, complex* a, complex* work, int* lwork, int* info, JNIEnv *e, jobject obj) {
	return xgetrif<complex>(n, a, work, lwork, info, e, obj);
}

// --BALASHOVA

int __declspec(dllexport) __stdcall dlamch(float80* c, JNIEnv *e, jobject obj)
{
	//printf("dlamch");
set_fpu<FPU_TRUNC, FPU_DOUBLE> fpu;
static  unsigned char* names = (unsigned char*)"ESBPNRMULO";
create<float80, double> C(c, 10);
	for (int i = 0;i < 10;i++) C[i] = dlamch_(names+i, e, obj);
	return 0;
};

*/
void dlarnv(int idist, int* iseed, int n, double* x){
	create<int,int> ISEED(iseed, 4);
	create<double,double> X(x, n);
	dlarnv_(&idist, ISEED.ptr(), &n, X.ptr());
};

double dlange(char norm, int  m, int  n, double* a){
	int lda = m;
	protect<double,double> A(a,m*n);
	buffer<double> WORK(m);
	return dlange_(&norm, &m, &n, A.ptr(), &lda, WORK.ptr());
}

int dgecon(char norm, int n, double* a, double anorm, double* rcond){
	int lda = n;
	protect<double,double> A(a,n*n);
	buffer<double> WORK(4*n);
	buffer<int> IWORK(n);
	int info = -1;
	dgecon_(&norm, &n, A.ptr(), &lda, &anorm, rcond, WORK.ptr(), IWORK.ptr(), &info);     
	return info;
}

/*
//---------------------------------------------------------------------------------------------
//--- QR decomposition functions --------------------------------------------------------------
//---------------------------------------------------------------------------------------------
void __declspec(dllexport) __stdcall _dgeqp3_(int* m, int* n, double* a, int* lda, int* jpvt, double* tau, double* work, int* lwork, int* info, JNIEnv *e, jobject obj)
{
  dgeqp3_(m, n, a, lda, jpvt, tau, work, lwork, info, e, obj);
};

void __declspec(dllexport) __stdcall _dgeqrf_(int* m, int* n, double* a, int* lda, double* tau, double* work, int* lwork, int* info, JNIEnv *e, jobject obj)
{
  dgeqrf_(m, n, a, lda, tau, work, lwork, info, e, obj);
};

//---------------------------------------------------------------------------------------------
//--- Generalized SVD decomposition functions -------------------------------------------------
//---------------------------------------------------------------------------------------------
void __declspec(dllexport) __stdcall _dggsvd_(unsigned char* jobu, unsigned char* jobv, unsigned char* jobq, int* m, int* n, int* p, int* k, int* l, double* a, int* lda, double* b, int* ldb, double* alpha, double* beta, double* u, int* ldu, double* v, int* ldv, double* q, int* ldq, double* work, int* iwork, int* info, JNIEnv *e, jobject obj)
{
  dggsvd_(jobu, jobv, jobq, m, n, p, k, l, a, lda, b, ldb, alpha, beta, u, ldu, v, ldv, q, ldq, work, iwork, info, e, obj);
};



//---------------------------------------------------------------------------------------------
//--- Eigenproblem functions - symmetric ------------------------------------------------------
//---------------------------------------------------------------------------------------------
void __declspec(dllexport) __stdcall _dsyev_(unsigned char* jobz, unsigned char* uplo, int* n, double* a, int* lda, double* w, double* work, int* lwork, int* info, JNIEnv *e, jobject obj)
{
  dsyev_(jobz, uplo, n, a, lda, w, work, lwork, info, e, obj);
};

void __declspec(dllexport) __stdcall _dsyevd_(unsigned char* jobz, unsigned char* uplo, int* n, double* a, int* lda, double* w, double* work, int* lwork, int* iwork, int* liwork, int* info, JNIEnv *e, jobject obj)
{
  dsyevd_(jobz, uplo, n, a, lda, w, work, lwork, iwork, liwork, info, e, obj);
};

void __declspec(dllexport) __stdcall _dsyevr_(unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, double* a, int* lda, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, int* isuppz, double* work, int* lwork, int* iwork, int* liwork, int* info, JNIEnv *e, jobject obj)
{
  dsyevr_(jobz, range, uplo, n, a, lda, vl, vu, il, iu, abstol, m, w, z, ldz, isuppz, work, lwork, iwork, liwork, info, e, obj);
};

void __declspec(dllexport) __stdcall _dsyevx_(unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, double* a, int* lda, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, double* work, int* lwork, int* iwork, int* ifail, int* info, JNIEnv *e, jobject obj)
{
  dsyevx_(jobz, range, uplo, n, a, lda, vl, vu, il, iu, abstol, m, w, z, ldz, work, lwork, iwork, ifail, info, e, obj);
};

//---------------------------------------------------------------------------------------------
//--- Generalized eigenproblem functions ------------------------------------------------------
//---------------------------------------------------------------------------------------------
void __declspec(dllexport) __stdcall _dggev_(unsigned char* jobvl, unsigned char* jobvr, int* n, double* a, int* lda, double* b, int* ldb, double* alphar, double* alphai, double* beta, double* vl, int* ldvl, double* vr, int* ldvr, double* work, int* lwork, int* info, JNIEnv *e, jobject obj)
{
  dggev_(jobvl, jobvr, n, a, lda, b, ldb, alphar, alphai, beta, vl, ldvl, vr, ldvr, work, lwork,info,e,obj);
};

void __declspec(dllexport) __stdcall _dggevx_(unsigned char* balanc, unsigned char* jobvl, unsigned char* jobvr, unsigned char* sense, int* n, double* a, int* lda, double* b, int* ldb, double* alphar, double* alphai, double* beta, double* vl, int* ldvl, double* vr, int* ldvr, int* ilo, int* ihi, double* lscale, double* rscale, double* abnrm, double* bbnrm, double* rconde, double* rcondv, double* work, int* lwork, int* iwork, int* bwork, int* info, JNIEnv *e, jobject obj)
{
  dggevx_(balanc, jobvl, jobvr, sense, n, a, lda, b, ldb, alphar, alphai, beta, vl, ldvl, vr, ldvr, ilo, ihi, lscale, rscale, abnrm, bbnrm, rconde, rcondv, work, lwork, iwork, bwork,info,e,obj);
};






void __declspec(dllexport) __stdcall _zggev_(unsigned char* jobvl, unsigned char* jobvr, int* n, complex* a, int* lda, complex* b, int* ldb, complex* alpha, complex* beta, complex* vl, int* ldvl, complex* vr, int* ldvr, complex* work, int* lwork, double* rwork, int* info, JNIEnv *e, jobject obj)
{
  zggev_(jobvl, jobvr, n, a, lda, b, ldb, alpha, beta, vl, ldvl, vr, ldvr, work, lwork, rwork,info,e,obj);
};

void __declspec(dllexport) __stdcall _zggevx_(unsigned char* balanc, unsigned char* jobvl, unsigned char* jobvr, unsigned char* sense, int* n, complex* a, int* lda, complex* b, int* ldb, complex* alpha, complex* beta, complex* vl, int* ldvl, complex* vr, int* ldvr, int* ilo, int* ihi, double* lscale, double* rscale, double* abnrm, double* bbnrm, double* rconde, double* rcondv, complex* work, int* lwork, double* rwork, int* iwork, int* bwork, int* info, JNIEnv *e, jobject obj)
{
  zggevx_(balanc, jobvl, jobvr, sense, n, a, lda, b, ldb, alpha, beta, vl, ldvl, vr, ldvr, ilo, ihi, lscale, rscale, abnrm, bbnrm, rconde, rcondv, work, lwork, rwork, iwork, bwork,info,e,obj);
};
//---------------------------------------------------------------------------------------------
//--- LU decomposition functions --------------------------------------------------------------
//---------------------------------------------------------------------------------------------
template<typename _st, typename _dt>
inline int xgetrf(int ra, int ca, _st* a, SUB_TYPE(_st)* p, _st* r, JNIEnv *e, jobject obj)
{
int info = -1;
fpc::buffer<int> _P(MIN(ra,ca)) ;
fpc::create<SUB_TYPE(_st), int> P(p, ra);
fpc::replace<_st, _dt> L(a,r,ra*ca);
	xgetrf_(&ra, &ca, (_dt*)L, &ra, _P,&info,e,obj);

	if (info>=0)
	{
	int x;
		for (int i = 0; i < ra; i++) P[i] = i;
  		for (int i = 0;i < MIN(ra,ca);i++)
  			{x = P[i];P[i] = P[_P[i]-1];P[_P[i]-1] = x;};
	};
  return info;
};
int __declspec(dllexport) __stdcall dgetrf(int ra, int ca, double* a, double* p, double* r, JNIEnv *e, jobject obj)
{ return xgetrf<double,double>(ra,ca,a,p,r,e,obj); };
int __declspec(dllexport) __stdcall dxgetrf(int ra, int ca, float80* a, float80* p, float80* r, JNIEnv *e, jobject obj)
{ return xgetrf<float80,double>(ra,ca,a,p,r,e,obj); };
int __declspec(dllexport) __stdcall zgetrf(int ra, int ca, complex* a, double* p, complex* r, JNIEnv *e, jobject obj)
{ return xgetrf<complex, complex>(ra,ca,a,p,r,e,obj); };
int __declspec(dllexport) __stdcall zxgetrf(int ra, int ca, complex160* a, float80* p, complex160* r, JNIEnv *e, jobject obj)
{ return xgetrf<complex160, complex128>(ra,ca,a,p,r,e,obj); };

*/
template<typename _st, typename _dt>
inline int xgetrf_simple(int ra, int ca, _st* a, _st* p, _st* l, _st* u)
{
	
	int info = -1;

	int lu = (ra >= ca);
	int n = MIN(ra,ca);
	fpc::buffer<int> PV(n + ra);
	int* P = PV + n;
	replace<_st, _dt> R(a,lu?l:u,ra*ca);
	xgetrf_(&ra, &ca, (_dt*)R, &ra, PV,&info);

	if (info>=0)
	{
		R.release();
		for (int i = 0; i < ra; i++){P[i] = i;};

		if (lu)
		{
			for (int i = 0;i < n;i++)
			{
			int j = P[i];P[i] = P[PV[i]-1];P[PV[i]-1] = j;
				for (j = 0;j <= i;j++)
				{
					u[j] = l[j];
					l[j] = constants<_st>::_0;
				};
				l[i] = constants<_st>::_1;
				for (;j < n;j++) u[j] = constants<_st>::_0;
				u += n;
				l += ra;
			};
		}
		else
		{
			for (int i = 0;i < n;i++)
			{
			int j = P[i];P[i] = P[PV[i]-1];P[PV[i]-1] = j;
				for (j = 0;j <= i;j++) l[j] = constants<_st>::_0;
				l[i] = constants<_st>::_1;
				for (;j < n;j++)
				{
					l[j] = u[j];
					u[j] = constants<_st>::_0;
				};
				l += n;
				u += ra;
			};
		};

  		memset(p, 0, sizeof(_st)*ra*ra);
  		for (int i = 0; i < ra;i++) p[P[i]+ra*i] = constants<_st>::_1;
	};

  return info;
};
int dgetrf_simple(int ra, int ca, double* a, double* p, double* l, double* u)
{ return xgetrf_simple<double, double>(ra, ca, a, p, l, u); };

/*int __declspec(dllexport) __stdcall dxgetrf_simple(int ra, int ca, float80* a, float80* p, float80* l, float80* u, JNIEnv *e, jobject obj)
{ return xgetrf_simple<float80, double>(ra, ca, a, p, l, u, e, obj); };
int __declspec(dllexport) __stdcall zgetrf_simple(int ra, int ca, complex* a, complex* p, complex* l, complex* u, JNIEnv *e, jobject obj)
{ return xgetrf_simple<complex, complex>(ra, ca, a, p, l, u, e, obj); };
int __declspec(dllexport) __stdcall zxgetrf_simple(int ra, int ca, complex160* a, complex160* p, complex160* l, complex160* u, JNIEnv *e, jobject obj)
{ return xgetrf_simple<complex160, complex128>(ra, ca, a, p, l, u, e, obj); };
*/
//---------------------------------------------------------------------------------------------
//--- SVD decomposition functions -------------------------------------------------------------
//---------------------------------------------------------------------------------------------
template<typename _st, typename _dt>
inline int xgesvd(int r, int c, _st* a, SUB_TYPE(_st)* s, _st* u, _st* vt)
{
	int info = -1;
	protect<_st,_dt> A(a,r*c);
	create<_st,_dt,false> U(u,r*r);
	create<_st,_dt,false> Vt(vt,c*c);
	create<SUB_TYPE(_st),SUB_TYPE(_dt)> S(s,MIN(r,c));
	xgesvd_(&_NA[u?1:0], &_NA[vt?1:0], &r, &c, A.ptr(), &r, S.ptr(), U.ptr(), &r, Vt.ptr(), &c,&info);
	return info;
};

int dgesvd(int r, int c, double* a, double* s, double* u, double* vt)
{    
    return xgesvd<double, double>(r,c,a,s,u,vt); 
};

/*int __declspec(dllexport) __stdcall dxgesvd(int r, int c, float80* a, float80* s, float80* u, float80* vt, JNIEnv *e, jobject obj)
{ return xgesvd<float80, double>(r,c,a,s,u,vt,e,obj); };*/
int zgesvd(int r, int c, complex* a, double* s, complex* u, complex* vt)
{ 
	return xgesvd<complex, complex>(r,c,a,s,u,vt); 
};


/*
int __declspec(dllexport) __stdcall zxgesvd(int r, int c, complex160* a, float80* s, complex160* u, complex160* vt, JNIEnv *e, jobject obj)
{ return xgesvd<complex160, complex>(r,c,a,s,u,vt,e,obj); };
int __declspec(dllexport) __stdcall sgesvd(int r, int c, float* a, float* s, float* u, float* vt, JNIEnv *e, jobject obj)
{ return xgesvd<float, float>(r,c,a,s,u,vt,e,obj); };
int __declspec(dllexport) __stdcall cgesvd(int r, int c, complex64* a, float* s, complex64* u, complex64* vt, JNIEnv *e, jobject obj)
{ return xgesvd<complex64, complex64>(r,c,a,s,u,vt,e,obj); };

template<typename _st, typename _dt>
inline int xgesdd(int r, int c, _st* a, SUB_TYPE(_st)* s, _st* u, _st* vt, JNIEnv *e, jobject obj)
{
int info = -1;
protect<_st,_dt> A(a,r*c);
create<_st,_dt,false> U(u,r*r);
create<_st,_dt,false> Vt(vt,c*c);
create<SUB_TYPE(_st),SUB_TYPE(_dt)> S(s,MIN(r,c));
	xgesdd_(&_NA[(u&&vt)?1:0], &r, &c, A.ptr(), &r, S.ptr(), U.ptr(), &r, Vt.ptr(), &c,&info,e,obj);
	return info;
};
int __declspec(dllexport) __stdcall dgesdd(int r, int c, double* a, double* s, double* u, double* vt, JNIEnv *e, jobject obj)
{ return xgesdd<double, double>(r,c,a,s,u,vt,e,obj); };
int __declspec(dllexport) __stdcall dxgesdd(int r, int c, float80* a, float80* s, float80* u, float80* vt, JNIEnv *e, jobject obj)
{ return xgesdd<float80, double>(r,c,a,s,u,vt,e,obj); };
int __declspec(dllexport) __stdcall zgesdd(int r, int c, complex* a, double* s, complex* u, complex* vt, JNIEnv *e, jobject obj)
{ return xgesdd<complex, complex>(r,c,a,s,u,vt,e,obj); };
int __declspec(dllexport) __stdcall zxgesdd(int r, int c, complex160* a, float80* s, complex160* u, complex160* vt, JNIEnv *e, jobject obj)
{ return xgesdd<complex160, complex>(r,c,a,s,u,vt,e,obj); };
*/
//---------------------------------------------------------------------------------------------
//--- Eigenproblem functions ------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
template<typename _st, typename _sst, typename _dt, typename _dst>
inline int xgeev(int n, _sst* a, _st* w, _st* vl, _st* vr)
{
	int info = -1;
	protect<_sst,_dst> A(a,n*n);
	create<_st,_dt> W(w,n);
	create<_st,_dt,false> VL(vl,n*n);
	create<_st,_dt,false> VR(vr,n*n);
	xgeev_(&_NV[(vl)?1:0], &_NV[(vr)?1:0], &n, A.ptr(), &n, W.ptr(), VL.ptr(), &n, VR.ptr(), &n,&info);
	return info;
};

int __declspec(dllexport) __stdcall dgeev(int n, double* a, complex* w, complex* vl, complex* vr)
{ return xgeev<complex, double, complex, double>(n, a, w, vl, vr); };
/*int __declspec(dllexport) __stdcall dxgeev(int n, float80* a, complex160* w, complex160* vl, complex160* vr, JNIEnv *e, jobject obj)
{ return xgeev<complex160, float80, complex, double>(n, a, w, vl, vr,e,obj); };
int __declspec(dllexport) __stdcall zgeev(int n, complex* a, complex* w, complex* vl, complex* vr, JNIEnv *e, jobject obj)
{ return xgeev<complex, complex, complex, complex>(n, a, w, vl, vr,e,obj); };
int __declspec(dllexport) __stdcall zxgeev(int n, complex160* a, complex160* w, complex160* vl, complex160* vr, JNIEnv *e, jobject obj)
{ return xgeev<complex160, complex160, complex, complex>(n, a, w, vl, vr,e,obj); };

// ZYKOVA
*/
template<typename _st, typename _sst, typename _dt, typename _dst>
inline int xgeevx(int balanc, int n, _sst* a, _st* w, _st* vl, _st* vr, double* rconde, double* rcondv)
{
    int info = -1;
    int ihi=0;
    int ilo=0;
    double abnrm=0;
    protect<_sst,_dst> A(a,n*n);
    create<_st,_dt> W(w,n);
    create<_st,_dt,false> VL(vl,n*n);
    create<_st,_dt,false> VR(vr,n*n);
    create<double,double,false> RE(rconde,n);
    create<double,double,false> RV(rcondv,n);
    xgeevx_(&_BC[balanc], &_NV[(vl)?1:0], &_NV[(vr)?1:0], &_B, &n, A.ptr(), &n, W.ptr(), VL.ptr(), &n, VR.ptr(), &n, &ihi,&ilo,&abnrm, RE.ptr(), RV.ptr(),&info);
    return info;
};


/*
 BALANC  (input) CHARACTER*1   
            Indicates how the input matrix should be diagonally scaled   
            and/or permuted to improve the conditioning of its   
            eigenvalues.   
            = 'N': Do not diagonally scale or permute;   
            = 'P': Perform permutations to make the matrix more nearly   
                   upper triangular. Do not diagonally scale;   
            = 'S': Diagonally scale the matrix, i.e. replace A by   
                   D*A*D**(-1), where D is a diagonal matrix chosen   
                   to make the rows and columns of A more equal in   
                   norm. Do not permute;   
            = 'B': Both diagonally scale and permute A.  */
int dgeevx(int balanc,int n, double* a, complex* w, complex* vl, complex* vr, double* rconde, double* rcondv)
{ 
	return xgeevx<complex, double, complex, double>(balanc, n, a, w, vl, vr, rconde, rcondv); 
};

/*int __declspec(dllexport) __stdcall zgeevx(int balanc,int n, complex* a, complex* w, complex* vl, complex* vr, double* rconde, double* rcondv, JNIEnv *e, jobject obj)
{ return xgeevx<complex, complex, complex, complex>(balanc, n, a, w, vl, vr, rconde, rcondv,e,obj); };


// --ZYKOVA


//---------------------------------------------------------------------------------------------
//--- Generalized eigenproblem functions ------------------------------------------------------
//---------------------------------------------------------------------------------------------
template<typename _st, typename _sst, typename _dt, typename _dst>
inline int xggev(int n, _sst* a, _sst* b, _st* alpha, _sst* beta, _st* vl, _st* vr, JNIEnv *e, jobject obj)
{
int info = -1;
protect<_sst,_dst> A(a,n*n);
protect<_sst,_dst> B(b,n*n);
create<_st,_dt> Alpha(alpha,n);
create<_sst,_dst> Beta(beta,n);
create<_st,_dt,false> VL(vl,n*n);
create<_st,_dt,false> VR(vr,n*n);
	xggev_(&_NV[(vl)?1:0], &_NV[(vr)?1:0], &n, A.ptr(), &n, B.ptr(), &n,
			Alpha.ptr(), Beta.ptr(), VL.ptr(), &n, VR.ptr(), &n,&info,e,obj);
	return info;
};
int __declspec(dllexport) __stdcall dggev(int n, double* a, double* b, complex* alpha, double* beta, complex* vl, complex* vr, JNIEnv *e, jobject obj)
{ return xggev<complex, double, complex, double>(n, a, b, alpha, beta, vl, vr,e,obj); };
int __declspec(dllexport) __stdcall dxggev(int n, float80* a, float80* b, complex160* alpha, float80* beta, complex160* vl, complex160* vr, JNIEnv *e, jobject obj)
{ return xggev<complex160, float80, complex, double>(n, a, b, alpha, beta, vl, vr,e,obj); };
int __declspec(dllexport) __stdcall zggev(int n, complex* a, complex* b, complex* alpha, complex* beta, complex* vl, complex* vr, JNIEnv *e, jobject obj)
{ return xggev<complex, complex, complex, complex>(n, a, b, alpha, beta, vl, vr,e,obj); };
int __declspec(dllexport) __stdcall zxggev(int n, complex160* a, complex160* b, complex160* alpha, complex160* beta, complex160* vl, complex160* vr, JNIEnv *e, jobject obj)
{ return xggev<complex160, complex160, complex, complex>(n, a, b, alpha, beta, vl, vr,e,obj); };
*/
//---------------------------------------------------------------------------------------------
//--- System of linear equations functions ----------------------------------------------------
//---------------------------------------------------------------------------------------------
template<typename _st, typename _dt>
inline int xgesv(int n, _st* a, int nrhs, _st* b, _st* x)
{
	int info = -1;
	protect<_st,_dt> A(a,n*n);
	replace<_st,_dt> B(b,x,n*nrhs);
	buffer<int> P(n);
	xgesv_(&n, &nrhs, A.ptr(), &n, P.ptr(), B.ptr(), &n,&info);
	return info;
};

int dgesv(int n, double* a, int nrhs, double* b, double* x)
{
	return xgesv<double,double>(n,a,nrhs,b,x);
}
/*
int __declspec(dllexport) __stdcall dxgesv(int n, float80* a, int nrhs, float80* b, float80* x, JNIEnv *e, jobject obj)
{return xgesv<float80,double>(n,a,nrhs,b,x,e,obj);}*/
int zgesv(int n, complex* a, int nrhs, complex* b, complex* x)
{return xgesv<complex,complex>(n,a,nrhs,b,x);}
/*
int __declspec(dllexport) __stdcall zxgesv(int n, complex160* a, int nrhs, complex160* b, complex160* x, JNIEnv *e, jobject obj)
{return xgesv<complex160,complex>(n,a,nrhs,b,x,e,obj);}

int __declspec(dllexport) __stdcall dgesvx(int n, double* a, int nrhs, double* b, double* x, double* rcond, JNIEnv *e, jobject obj){
    unsigned char fact = 'N';
    unsigned char trans = 'N';
    protect<double,double> A(a,n*n);
    int lda = n;
    int ldaf=n;
    buffer<double> AF(ldaf*n);
    buffer<int> IPIV(n);
    unsigned char equed='N';
    double* r;
    double* c;
    int ldb=n;
    int ldx=n;
    buffer<double> FERR(nrhs);
    buffer<double> BERR(nrhs);
    buffer<double> WORK(4*n);
    buffer<int> IWORK(n);
    int info=-1;
	dgesvx_(&fact, &trans, &n, &nrhs, A.ptr(), &lda, AF.ptr(), &ldaf,
			IPIV.ptr(), &equed, r, c, b, &ldb, x, &ldx, rcond, FERR.ptr(),
			BERR.ptr(), WORK.ptr(), IWORK.ptr(),&info,e,obj);
}
*/