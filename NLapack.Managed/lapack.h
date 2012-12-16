#include "fpc_types.h"
#include <memory.h>
#include <stdexcept>
#include "fpc.h"
#include <stdio.h>


using namespace fpc;
using fpc::float80;
using fpc::complex160;
using fpc::complex64;


NS_FPC_USE;

// void __stdcall putString(char* str);


//  BALASHOVA
int dpotrf(
     int* n,
     double* a,
     double* r
);
int __declspec(dllexport) __stdcall zpotrf(
     int* n,
     complex* a,
     complex* r
);
int __declspec(dllexport) __stdcall  dgetrif(int* n, double* a, double* work, int* lwork, int* info);

int __declspec(dllexport) __stdcall  zgetrif(int* n, complex* a, complex* work, int* lwork, int* info  );

// --BALASHOVA
int __declspec(dllexport) __stdcall  dlamch(float80* c  );
void dlarnv(
    int idist,
    int* iseed,
    int n,
    double* x
);
int dgecon(
		char norm,
		int  n,
		double* a,
		double anorm,
		double* rcond
);
double  dlange(
		char norm,
		int  m,
		int  n,
		double* a
);

//---------------------------------------------------------------------------------------------
//--- LU decomposition functions --------------------------------------------------------------
//---------------------------------------------------------------------------------------------
int __declspec(dllexport) __stdcall   dgetrf(int ra, int ca, double* a, double* p, double* r  );
int __declspec(dllexport) __stdcall   dxgetrf(int ra, int ca, float80* a, float80* p, float80* r  );
int __declspec(dllexport) __stdcall   zgetrf(int ra, int ca, complex* a, double* p, complex* r  );
int __declspec(dllexport) __stdcall   zxgetrf(int ra, int ca, complex160* a, float80* p, complex160* r  );
int dgetrf_simple(int ra, int ca, double* a, double* p, double* l, double* u);
int dxgetrf_simple(int ra, int ca, float80* a, float80* p, float80* l, float80* u);
int __declspec(dllexport) __stdcall   zgetrf_simple(int ra, int ca, complex* a, complex* p, complex* l, complex* u  );
int __declspec(dllexport) __stdcall   zxgetrf_simple(int ra, int ca, complex160* a, complex160* p, complex160* l, complex160* u  );

//---------------------------------------------------------------------------------------------
//--- SVD decomposition functions -------------------------------------------------------------
//---------------------------------------------------------------------------------------------
int dgesvd(int r, int c, double* a, double* s, double* u, double* vt);
int __declspec(dllexport) __stdcall   dxgesvd(int r, int c, float80* a, float80* s, float80* u, float80* vt  );
int zgesvd(int r, int c, complex* a, double* s, complex* u, complex* vt);
int __declspec(dllexport) __stdcall   zxgesvd(int r, int c, complex160* a, float80* s, complex160* u, complex160* vt  );
int __declspec(dllexport) __stdcall   sgesvd(int r, int c, float* a, float* s, float* u, float* vt  );
int __declspec(dllexport) __stdcall   cgesvd(int r, int c, complex64* a, float* s, complex64* u, complex64* vt  );
int __declspec(dllexport) __stdcall   dgesdd(int r, int c, double* a, double* s, double* u, double* vt  );
int __declspec(dllexport) __stdcall   dxgesdd(int r, int c, float80* a, float80* s, float80* u, float80* vt  );
int __declspec(dllexport) __stdcall   zgesdd(int r, int c, complex* a, double* s, complex* u, complex* vt  );
int __declspec(dllexport) __stdcall   zxgesdd(int r, int c, complex160* a, float80* s, complex160* u, complex160* vt  );

//---------------------------------------------------------------------------------------------
//--- Eigenproblem functions ------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
int __declspec(dllexport) __stdcall   dgeev(int n, double* a, complex* w, complex* vl, complex* vr);
int __declspec(dllexport) __stdcall   dxgeev(int n, float80* a, complex160* w, complex160* vl, complex160* vr  );
int __declspec(dllexport) __stdcall   zgeev(int n, complex* a, complex* w, complex* vl, complex* vr  );
int __declspec(dllexport) __stdcall   zxgeev(int n, complex160* a, complex160* w, complex160* vl, complex160* vr  );
int dgeevx(int balanc, int n, double* a, complex* w, complex* vl, complex* vr, double* rconde, double* rcondv);
int __declspec(dllexport) __stdcall   zgeevx(int balanc, int n, complex* a, complex* w, complex* vl, complex* vr, double* rconde, double* rcondv  );
//---------------------------------------------------------------------------------------------
//--- Generalized eigenproblem functions ------------------------------------------------------
//---------------------------------------------------------------------------------------------
int __declspec(dllexport) __stdcall   dggev(int n, double* a, double* b, complex* alpha, double* beta, complex* vl, complex* vr  );
int __declspec(dllexport) __stdcall   dxggev(int n, float80* a, float80* b, complex160* alpha, float80* beta, complex160* vl, complex160* vr  );
int __declspec(dllexport) __stdcall   zggev(int n, complex* a, complex* b, complex* alpha, complex* beta, complex* vl, complex* vr  );
int __declspec(dllexport) __stdcall   zxggev(int n, complex160* a, complex160* b, complex160* alpha, complex160* beta, complex160* vl, complex160* vr  );

//---------------------------------------------------------------------------------------------
//--- System of linear equations functions ----------------------------------------------------
//---------------------------------------------------------------------------------------------
int dgesv(int n, double* a, int nrhs, double* b, double* x);
int __declspec(dllexport) __stdcall   dxgesv(int n, float80* a, int nrhs, float80* b, float80* x  );
int zgesv(int n, complex* a, int nrhs, complex* b, complex* x  );
int __declspec(dllexport) __stdcall   zxgesv(int n, complex160* a, int nrhs, complex160* b, complex160* x  );
int __declspec(dllexport) __stdcall   dgesvx(int n, double* a, int nrhs, double* b, double* x, double* rcond  );
void __declspec(dllexport) __stdcall   _dgbsv_(
    int* n,
    int* kl,
    int* ku,
    int* nrhs,
    double* ab,
    int* ldab,
    int* ipiv,
    double* b,
    int* ldb,
    int* info
);
void __declspec(dllexport) __stdcall   _dgbsvx_(
    unsigned char* fact,
    unsigned char* trans,
    int* n,
    int* kl,
    int* ku,
    int* nrhs,
    double* ab,
    int* ldab,
    double* afb,
    int* ldafb,
    int* ipiv,
    unsigned char* equed,
    double* r,
    double* c,
    double* b,
    int* ldb,
    double* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    double* work,
    int* iwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dgbtrf_(
    int* m,
    int* n,
    int* kl,
    int* ku,
    double* ab,
    int* ldab,
    int* ipiv,
    int* info
);
void __declspec(dllexport) __stdcall   _dgeqp3_(
    int* m,
    int* n,
    double* a,
    int* lda,
    int* jpvt,
    double* tau,
    double* work,
    int* lwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dgeqrf_(
    int* m,
    int* n,
    double* a,
    int* lda,
    double* tau,
    double* work,
    int* lwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dgesvx_(
    unsigned char* fact,
    unsigned char* trans,
    int* n,
    int* nrhs,
    double* a,
    int* lda,
    double* af,
    int* ldaf,
    int* ipiv,
    unsigned char* equed,
    double* r,
    double* c,
    double* b,
    int* ldb,
    double* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    double* work,
    int* iwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dggev_(
    unsigned char* jobvl,
    unsigned char* jobvr,
    int* n,
    double* a,
    int* lda,
    double* b,
    int* ldb,
    double* alphar,
    double* alphai,
    double* beta,
    double* vl,
    int* ldvl,
    double* vr,
    int* ldvr,
    double* work,
    int* lwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dggevx_(
    unsigned char* balanc,
    unsigned char* jobvl,
    unsigned char* jobvr,
    unsigned char* sense,
    int* n,
    double* a,
    int* lda,
    double* b,
    int* ldb,
    double* alphar,
    double* alphai,
    double* beta,
    double* vl,
    int* ldvl,
    double* vr,
    int* ldvr,
    int* ilo,
    int* ihi,
    double* lscale,
    double* rscale,
    double* abnrm,
    double* bbnrm,
    double* rconde,
    double* rcondv,
    double* work,
    int* lwork,
    int* iwork,
    int* bwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dggsvd_(
    unsigned char* jobu,
    unsigned char* jobv,
    unsigned char* jobq,
    int* m,
    int* n,
    int* p,
    int* k,
    int* l,
    double* a,
    int* lda,
    double* b,
    int* ldb,
    double* alpha,
    double* beta,
    double* u,
    int* ldu,
    double* v,
    int* ldv,
    double* q,
    int* ldq,
    double* work,
    int* iwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dgtsv_(
    int* n,
    int* nrhs,
    double* dl,
    double* d,
    double* du,
    double* b,
    int* ldb,
    int* info
);
void __declspec(dllexport) __stdcall   _dgtsvx_(
    unsigned char* fact,
    unsigned char* trans,
    int* n,
    int* nrhs,
    double* dl,
    double* d,
    double* du,
    double* dlf,
    double* df,
    double* duf,
    double* du2,
    int* ipiv,
    double* b,
    int* ldb,
    double* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    double* work,
    int* iwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dgttrf_(
    int* n,
    double* dl,
    double* d,
    double* du,
    double* du2,
    int* ipiv,
    int* info
);
void __declspec(dllexport) __stdcall   _dpbsv_(
    unsigned char* uplo,
    int* n,
    int* kd,
    int* nrhs,
    double* ab,
    int* ldab,
    double* b,
    int* ldb,
    int* info
);
void __declspec(dllexport) __stdcall   _dpbsvx_(
    unsigned char* fact,
    unsigned char* uplo,
    int* n,
    int* kd,
    int* nrhs,
    double* ab,
    int* ldab,
    double* afb,
    int* ldafb,
    unsigned char* equed,
    double* s,
    double* b,
    int* ldb,
    double* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    double* work,
    int* iwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dposv_(
    unsigned char* uplo,
    int* n,
    int* nrhs,
    double* a,
    int* lda,
    double* b,
    int* ldb,
    int* info
);
void __declspec(dllexport) __stdcall   _dposvx_(
    unsigned char* fact,
    unsigned char* uplo,
    int* n,
    int* nrhs,
    double* a,
    int* lda,
    double* af,
    int* ldaf,
    unsigned char* equed,
    double* s,
    double* b,
    int* ldb,
    double* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    double* work,
    int* iwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dptsv_(
    int* n,
    int* nrhs,
    double* d,
    double* e,
    double* b,
    int* ldb,
    int* info
);
void __declspec(dllexport) __stdcall   _dptsvx_(
    unsigned char* fact,
    int* n,
    int* nrhs,
    double* d,
    double* e,
    double* df,
    double* ef,
    double* b,
    int* ldb,
    double* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    double* work,
    int* info
);
void __declspec(dllexport) __stdcall   _dsbev_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    int* kd,
    double* ab,
    int* ldab,
    double* w,
    double* z,
    int* ldz,
    double* work,
    int* info
);
void __declspec(dllexport) __stdcall   _dsbevd_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    int* kd,
    double* ab,
    int* ldab,
    double* w,
    double* z,
    int* ldz,
    double* work,
    int* lwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dsbevx_(
    unsigned char* jobz,
    unsigned char* range,
    unsigned char* uplo,
    int* n,
    int* kd,
    double* ab,
    int* ldab,
    double* q,
    int* ldq,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    double* z,
    int* ldz,
    double* work,
    int* iwork,
    int* ifail,
    int* info
);
void __declspec(dllexport) __stdcall   _dsbgv_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    int* ka,
    int* kb,
    double* ab,
    int* ldab,
    double* bb,
    int* ldbb,
    double* w,
    double* z,
    int* ldz,
    double* work,
    int* info
);
void __declspec(dllexport) __stdcall   _dsbgvd_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    int* ka,
    int* kb,
    double* ab,
    int* ldab,
    double* bb,
    int* ldbb,
    double* w,
    double* z,
    int* ldz,
    double* work,
    int* lwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dsbgvx_(
    unsigned char* jobz,
    unsigned char* range,
    unsigned char* uplo,
    int* n,
    int* ka,
    int* kb,
    double* ab,
    int* ldab,
    double* bb,
    int* ldbb,
    double* q,
    int* ldq,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    double* z,
    int* ldz,
    double* work,
    int* iwork,
    int* ifail,
    int* info
);
void __declspec(dllexport) __stdcall   _dstev_(
    unsigned char* jobz,
    int* n,
    double* d,
    double* e,
    double* z,
    int* ldz,
    double* work,
    int* info
);
void __declspec(dllexport) __stdcall   _dstevd_(
    unsigned char* jobz,
    int* n,
    double* d,
    double* e,
    double* z,
    int* ldz,
    double* work,
    int* lwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dstevr_(
    unsigned char* jobz,
    unsigned char* range,
    int* n,
    double* d,
    double* e,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    double* z,
    int* ldz,
    int* isuppz,
    double* work,
    int* lwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dstevx_(
    unsigned char* jobz,
    unsigned char* range,
    int* n,
    double* d,
    double* e,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    double* z,
    int* ldz,
    double* work,
    int* iwork,
    int* ifail,
    int* info
);
void __declspec(dllexport) __stdcall   _dsyev_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    double* a,
    int* lda,
    double* w,
    double* work,
    int* lwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dsyevd_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    double* a,
    int* lda,
    double* w,
    double* work,
    int* lwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dsyevr_(
    unsigned char* jobz,
    unsigned char* range,
    unsigned char* uplo,
    int* n,
    double* a,
    int* lda,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    double* z,
    int* ldz,
    int* isuppz,
    double* work,
    int* lwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dsyevx_(
    unsigned char* jobz,
    unsigned char* range,
    unsigned char* uplo,
    int* n,
    double* a,
    int* lda,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    double* z,
    int* ldz,
    double* work,
    int* lwork,
    int* iwork,
    int* ifail,
    int* info
);
void __declspec(dllexport) __stdcall   _dsygv_(
    int* itype,
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    double* a,
    int* lda,
    double* b,
    int* ldb,
    double* w,
    double* work,
    int* lwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dsygvd_(
    int* itype,
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    double* a,
    int* lda,
    double* b,
    int* ldb,
    double* w,
    double* work,
    int* lwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dsygvx_(
    int* itype,
    unsigned char* jobz,
    unsigned char* range,
    unsigned char* uplo,
    int* n,
    double* a,
    int* lda,
    double* b,
    int* ldb,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    double* z,
    int* ldz,
    double* work,
    int* lwork,
    int* iwork,
    int* ifail,
    int* info
);
void __declspec(dllexport) __stdcall   _dsysv_(
    unsigned char* uplo,
    int* n,
    int* nrhs,
    double* a,
    int* lda,
    int* ipiv,
    double* b,
    int* ldb,
    double* work,
    int* lwork,
    int* info
);
void __declspec(dllexport) __stdcall   _dsysvx_(
    unsigned char* fact,
    unsigned char* uplo,
    int* n,
    int* nrhs,
    double* a,
    int* lda,
    double* af,
    int* ldaf,
    int* ipiv,
    double* b,
    int* ldb,
    double* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    double* work,
    int* lwork,
    int* iwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zgbsv_(
    int* n,
    int* kl,
    int* ku,
    int* nrhs,
    complex* ab,
    int* ldab,
    int* ipiv,
    complex* b,
    int* ldb,
    int* info
);
void __declspec(dllexport) __stdcall   _zgbsvx_(
    unsigned char* fact,
    unsigned char* trans,
    int* n,
    int* kl,
    int* ku,
    int* nrhs,
    complex* ab,
    int* ldab,
    complex* afb,
    int* ldafb,
    int* ipiv,
    unsigned char* equed,
    double* r,
    double* c,
    complex* b,
    int* ldb,
    complex* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    complex* work,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zgbtrf_(
    int* m,
    int* n,
    int* kl,
    int* ku,
    complex* ab,
    int* ldab,
    int* ipiv,
    int* info
);
void __declspec(dllexport) __stdcall   _zgeqp3_(
    int* m,
    int* n,
    complex* a,
    int* lda,
    int* jpvt,
    complex* tau,
    complex* work,
    int* lwork,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zgeqrf_(
    int* m,
    int* n,
    complex* a,
    int* lda,
    complex* tau,
    complex* work,
    int* lwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zgesvx_(
    unsigned char* fact,
    unsigned char* trans,
    int* n,
    int* nrhs,
    complex* a,
    int* lda,
    complex* af,
    int* ldaf,
    int* ipiv,
    unsigned char* equed,
    double* r,
    double* c,
    complex* b,
    int* ldb,
    complex* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    complex* work,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zgetrf_(
    int* m,
    int* n,
    complex* a,
    int* lda,
    int* ipiv,
    int* info
);
void __declspec(dllexport) __stdcall   _zggev_(
    unsigned char* jobvl,
    unsigned char* jobvr,
    int* n,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    complex* alpha,
    complex* beta,
    complex* vl,
    int* ldvl,
    complex* vr,
    int* ldvr,
    complex* work,
    int* lwork,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zggevx_(
    unsigned char* balanc,
    unsigned char* jobvl,
    unsigned char* jobvr,
    unsigned char* sense,
    int* n,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    complex* alpha,
    complex* beta,
    complex* vl,
    int* ldvl,
    complex* vr,
    int* ldvr,
    int* ilo,
    int* ihi,
    double* lscale,
    double* rscale,
    double* abnrm,
    double* bbnrm,
    double* rconde,
    double* rcondv,
    complex* work,
    int* lwork,
    double* rwork,
    int* iwork,
    int* bwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zggsvd_(
    unsigned char* jobu,
    unsigned char* jobv,
    unsigned char* jobq,
    int* m,
    int* n,
    int* p,
    int* k,
    int* l,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    double* alpha,
    double* beta,
    complex* u,
    int* ldu,
    complex* v,
    int* ldv,
    complex* q,
    int* ldq,
    complex* work,
    double* rwork,
    int* iwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zgtsv_(
    int* n,
    int* nrhs,
    complex* dl,
    complex* d,
    complex* du,
    complex* b,
    int* ldb,
    int* info
);
void __declspec(dllexport) __stdcall   _zgtsvx_(
    unsigned char* fact,
    unsigned char* trans,
    int* n,
    int* nrhs,
    complex* dl,
    complex* d,
    complex* du,
    complex* dlf,
    complex* df,
    complex* duf,
    complex* du2,
    int* ipiv,
    complex* b,
    int* ldb,
    complex* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    complex* work,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zgttrf_(
    int* n,
    complex* dl,
    complex* d,
    complex* du,
    complex* du2,
    int* ipiv,
    int* info
);
void __declspec(dllexport) __stdcall   _zhbev_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    int* kd,
    complex* ab,
    int* ldab,
    double* w,
    complex* z,
    int* ldz,
    complex* work,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zhbevd_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    int* kd,
    complex* ab,
    int* ldab,
    double* w,
    complex* z,
    int* ldz,
    complex* work,
    int* lwork,
    double* rwork,
    int* lrwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zhbevx_(
    unsigned char* jobz,
    unsigned char* range,
    unsigned char* uplo,
    int* n,
    int* kd,
    complex* ab,
    int* ldab,
    complex* q,
    int* ldq,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    complex* z,
    int* ldz,
    complex* work,
    double* rwork,
    int* iwork,
    int* ifail,
    int* info
);
void __declspec(dllexport) __stdcall   _zhbgv_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    int* ka,
    int* kb,
    complex* ab,
    int* ldab,
    complex* bb,
    int* ldbb,
    double* w,
    complex* z,
    int* ldz,
    complex* work,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zhbgvd_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    int* ka,
    int* kb,
    complex* ab,
    int* ldab,
    complex* bb,
    int* ldbb,
    double* w,
    complex* z,
    int* ldz,
    complex* work,
    int* lwork,
    double* rwork,
    int* lrwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zhbgvx_(
    unsigned char* jobz,
    unsigned char* range,
    unsigned char* uplo,
    int* n,
    int* ka,
    int* kb,
    complex* ab,
    int* ldab,
    complex* bb,
    int* ldbb,
    complex* q,
    int* ldq,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    complex* z,
    int* ldz,
    complex* work,
    double* rwork,
    int* iwork,
    int* ifail,
    int* info
);
void __declspec(dllexport) __stdcall   _zheev_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    complex* a,
    int* lda,
    double* w,
    complex* work,
    int* lwork,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zheevd_(
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    complex* a,
    int* lda,
    double* w,
    complex* work,
    int* lwork,
    double* rwork,
    int* lrwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zheevr_(
    unsigned char* jobz,
    unsigned char* range,
    unsigned char* uplo,
    int* n,
    complex* a,
    int* lda,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    complex* z,
    int* ldz,
    int* isuppz,
    complex* work,
    int* lwork,
    double* rwork,
    int* lrwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zheevx_(
    unsigned char* jobz,
    unsigned char* range,
    unsigned char* uplo,
    int* n,
    complex* a,
    int* lda,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    complex* z,
    int* ldz,
    complex* work,
    int* lwork,
    double* rwork,
    int* iwork,
    int* ifail,
    int* info
);
void __declspec(dllexport) __stdcall   _zhegv_(
    int* itype,
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    double* w,
    complex* work,
    int* lwork,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zhegvd_(
    int* itype,
    unsigned char* jobz,
    unsigned char* uplo,
    int* n,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    double* w,
    complex* work,
    int* lwork,
    double* rwork,
    int* lrwork,
    int* iwork,
    int* liwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zhegvx_(
    int* itype,
    unsigned char* jobz,
    unsigned char* range,
    unsigned char* uplo,
    int* n,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    double* vl,
    double* vu,
    int* il,
    int* iu,
    double* abstol,
    int* m,
    double* w,
    complex* z,
    int* ldz,
    complex* work,
    int* lwork,
    double* rwork,
    int* iwork,
    int* ifail,
    int* info
);
void __declspec(dllexport) __stdcall   _zhesv_(
    unsigned char* uplo,
    int* n,
    int* nrhs,
    complex* a,
    int* lda,
    int* ipiv,
    complex* b,
    int* ldb,
    complex* work,
    int* lwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zhesvx_(
    unsigned char* fact,
    unsigned char* uplo,
    int* n,
    int* nrhs,
    complex* a,
    int* lda,
    complex* af,
    int* ldaf,
    int* ipiv,
    complex* b,
    int* ldb,
    complex* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    complex* work,
    int* lwork,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zpbsv_(
    unsigned char* uplo,
    int* n,
    int* kd,
    int* nrhs,
    complex* ab,
    int* ldab,
    complex* b,
    int* ldb,
    int* info
);
void __declspec(dllexport) __stdcall   _zpbsvx_(
    unsigned char* fact,
    unsigned char* uplo,
    int* n,
    int* kd,
    int* nrhs,
    complex* ab,
    int* ldab,
    complex* afb,
    int* ldafb,
    unsigned char* equed,
    double* s,
    complex* b,
    int* ldb,
    complex* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    complex* work,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zposv_(
    unsigned char* uplo,
    int* n,
    int* nrhs,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    int* info
);
void __declspec(dllexport) __stdcall   _zposvx_(
    unsigned char* fact,
    unsigned char* uplo,
    int* n,
    int* nrhs,
    complex* a,
    int* lda,
    complex* af,
    int* ldaf,
    unsigned char* equed,
    double* s,
    complex* b,
    int* ldb,
    complex* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    complex* work,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zptsv_(
    int* n,
    int* nrhs,
    double* d,
    complex* e,
    complex* b,
    int* ldb,
    int* info
);
void __declspec(dllexport) __stdcall   _zptsvx_(
    unsigned char* fact,
    int* n,
    int* nrhs,
    double* d,
    complex* e,
    double* df,
    complex* ef,
    complex* b,
    int* ldb,
    complex* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    complex* work,
    double* rwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zsysv_(
    unsigned char* uplo,
    int* n,
    int* nrhs,
    complex* a,
    int* lda,
    int* ipiv,
    complex* b,
    int* ldb,
    complex* work,
    int* lwork,
    int* info
);
void __declspec(dllexport) __stdcall   _zsysvx_(
    unsigned char* fact,
    unsigned char* uplo,
    int* n,
    int* nrhs,
    complex* a,
    int* lda,
    complex* af,
    int* ldaf,
    int* ipiv,
    complex* b,
    int* ldb,
    complex* x,
    int* ldx,
    double* rcond,
    double* ferr,
    double* berr,
    complex* work,
    int* lwork,
    double* rwork,
    int* info
);


extern "C" void __cdecl dgemm_(
    const unsigned char* transa,
    const unsigned char* transb,
    int* m,
    int* n,
    int* k,
    const double* alpha,
    double* a,
    int* lda,
    double* b,
    int* ldb,
    const double* beta,
    double* c,
    int* ldc
);


//from CLAPACK header(http://www.netlib.org/clapack/clapack.h)

extern "C" void __cdecl dgetrf_( int* m, int* n, double* a, int* lda, int* ipiv, int* info);
extern "C" void __cdecl dgetri_(int *n, double *a, int *lda, int *ipiv, double *work, int *lwork, int *info);//dgetri_(int* n, double* a, int* lda, int* ipiv, double* work, int* lwork,  int* info);

extern "C" double __cdecl  dlange_(char *norm, int *m, int *n, double *a, int *lda, double *work);

extern "C" int dgeev_( const unsigned char *jobvl,  const unsigned char *jobvr, int *n, double *a, int *lda, double *wr, double *wi, double *vl, int *ldvl, double *vr, int *ldvr, double *work, int *lwork, int *info);

extern "C" int dpotrf_(char *uplo, int *n, double *a, int *lda, int *info);

extern "C" int dgesvd_(const unsigned char *jobu, const unsigned char *jobvt, int *m, int *n, double *a, int *lda, double *s, double *u, int *ldu, double *vt, int *ldvt, double *work, int *lwork, int *info);

extern "C" int dgesvd_(const unsigned char *jobu, const unsigned char *jobvt, int *m, int *n, double *a, int *lda, double *s, double *u, int *ldu, double *vt, int *ldvt, double *work, int *lwork, int *info);

extern "C" int dgecon_(char *norm, int *n, double *a, int *lda, double *anorm, double *rcond, double *work, int *iwork, int *info);

extern "C" int dlarnv_(int *idist, int *iseed, int *n, double *x);

extern "C" int dgeevx_(const unsigned char *balanc, const unsigned char *jobvl, const unsigned char *jobvr, const unsigned char *sense, 
	int *n, double *a, int *lda, double *wr, 
	double *wi, double *vl, int *ldvl, double *vr, 
	int *ldvr, int *ilo, int *ihi, double *scale, 
	double *abnrm, double *rconde, double *rcondv, double *work, int *lwork, int *iwork, int *info);

/*
typedef double doublereal;
typedef struct { doublereal r, i; } doublecomplex;



typedef long int integer;
typedef double doublereal;
typedef struct { doublereal r, i; } doublecomplex1;*/



extern "C" int zgesvd_(const unsigned char *jobu, const unsigned char *jobvt, int *m, int *n, 
	complex *a, int *lda, double *s, complex *u, 
	int *ldu, complex *vt, int *ldvt, complex *work, 
	int *lwork, double *rwork, int *info);



//extern "C" int zgesvd_(char *jobu, char *jobvt, integer *m, integer *n, 
//	doublecomplex1 *a, integer *lda, doublereal *s, doublecomplex1 *u, 
//	integer *ldu, doublecomplex1 *vt, integer *ldvt, doublecomplex1 *work, 
//	integer *lwork, doublereal *rwork, integer *info);






