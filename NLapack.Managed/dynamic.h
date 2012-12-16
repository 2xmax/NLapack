#include "fpc.h"
#include "fpc_types.h"


//typedef fpc::complex64 complex64;

using namespace fpc;
/*
void dpotrf_(char* uplo, int* n, double* a, int* lda, int* info);
void zpotrf_(char* uplo, int* n, complex* a, int* lda, int* info);
//----
//void dgetri_(int* n, double* a, int* lda, int* ipiv, double* work, int* lwork,  int* info);
void zgetri_(int* n, complex* a, int* lda, int* ipiv, complex* work, int* lwork, int* info);


 double dlamch_( unsigned char* cmach);

 void dlarnv_( int* idist, int* iseed, int* n, double* x);

 void dgecon_( char* norm, int*  n, double* a, int* lda, double* anorm, double* rcond, double* work, int* iwork, int* info);

 //double dlange_( char* norm, int*  m, int*  n, double* a, int* lda, double* work , JNIEnv *env, jobject obj);

 void dgbsv_( int* n, int* kl, int* ku, int* nrhs, double* ab, int* ldab, int* ipiv, double* b, int* ldb, int* info);

 void dgbsvx_( unsigned char* fact, unsigned char* trans, int* n, int* kl, int* ku, int* nrhs, double* ab, int* ldab, double* afb, int* ldafb, int* ipiv, unsigned char* equed, double* r, double* c, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* iwork, int* info);

 void dgbtrf_( int* m, int* n, int* kl, int* ku, double* ab, int* ldab, int* ipiv, int* info , JNIEnv *env, jobject obj);

 void dgeqp3_( int* m, int* n, double* a, int* lda, int* jpvt, double* tau, double* work, int* lwork, int* info , JNIEnv *env, jobject obj);

 void dgeqrf_( int* m, int* n, double* a, int* lda, double* tau, double* work, int* lwork, int* info , JNIEnv *env, jobject obj);



 void dgesvx_( unsigned char* fact, unsigned char* trans, int* n, int* nrhs, double* a, int* lda, double* af, int* ldaf, int* ipiv, unsigned char* equed, double* r, double* c, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* iwork, int* info , JNIEnv *env, jobject obj);


 void dggevx_( unsigned char* balanc, unsigned char* jobvl, unsigned char* jobvr, unsigned char* sense, int* n, double* a, int* lda, double* b, int* ldb, double* alphar, double* alphai, double* beta, double* vl, int* ldvl, double* vr, int* ldvr, int* ilo, int* ihi, double* lscale, double* rscale, double* abnrm, double* bbnrm, double* rconde, double* rcondv, double* work, int* lwork, int* iwork, int* bwork, int* info , JNIEnv *env, jobject obj);

 void dggsvd_( unsigned char* jobu, unsigned char* jobv, unsigned char* jobq, int* m, int* n, int* p, int* k, int* l, double* a, int* lda, double* b, int* ldb, double* alpha, double* beta, double* u, int* ldu, double* v, int* ldv, double* q, int* ldq, double* work, int* iwork, int* info , JNIEnv *env, jobject obj);

 void dgtsv_( int* n, int* nrhs, double* dl, double* d, double* du, double* b, int* ldb, int* info , JNIEnv *env, jobject obj);

 void dgtsvx_( unsigned char* fact, unsigned char* trans, int* n, int* nrhs, double* dl, double* d, double* du, double* dlf, double* df, double* duf, double* du2, int* ipiv, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* iwork, int* info , JNIEnv *env, jobject obj);

 void dgttrf_( int* n, double* dl, double* d, double* du, double* du2, int* ipiv, int* info , JNIEnv *env, jobject obj);

 void dpbsv_( unsigned char* uplo, int* n, int* kd, int* nrhs, double* ab, int* ldab, double* b, int* ldb, int* info , JNIEnv *env, jobject obj);

 void dpbsvx_( unsigned char* fact, unsigned char* uplo, int* n, int* kd, int* nrhs, double* ab, int* ldab, double* afb, int* ldafb, unsigned char* equed, double* s, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* iwork, int* info , JNIEnv *env, jobject obj);

 void dposv_( unsigned char* uplo, int* n, int* nrhs, double* a, int* lda, double* b, int* ldb, int* info , JNIEnv *env, jobject obj);

 void dposvx_( unsigned char* fact, unsigned char* uplo, int* n, int* nrhs, double* a, int* lda, double* af, int* ldaf, unsigned char* equed, double* s, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* iwork, int* info , JNIEnv *env, jobject obj);

 void dptsv_( int* n, int* nrhs, double* d, double* e, double* b, int* ldb, int* info , JNIEnv *env, jobject obj);

 void dptsvx_( unsigned char* fact, int* n, int* nrhs, double* d, double* e, double* df, double* ef, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* info , JNIEnv *env, jobject obj);

 void dsbev_( unsigned char* jobz, unsigned char* uplo, int* n, int* kd, double* ab, int* ldab, double* w, double* z, int* ldz, double* work, int* info , JNIEnv *env, jobject obj);

 void dsbevd_( unsigned char* jobz, unsigned char* uplo, int* n, int* kd, double* ab, int* ldab, double* w, double* z, int* ldz, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void dsbevx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, int* kd, double* ab, int* ldab, double* q, int* ldq, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, double* work, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj);

 void dsbgv_( unsigned char* jobz, unsigned char* uplo, int* n, int* ka, int* kb, double* ab, int* ldab, double* bb, int* ldbb, double* w, double* z, int* ldz, double* work, int* info , JNIEnv *env, jobject obj);

 void dsbgvd_( unsigned char* jobz, unsigned char* uplo, int* n, int* ka, int* kb, double* ab, int* ldab, double* bb, int* ldbb, double* w, double* z, int* ldz, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void dsbgvx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, int* ka, int* kb, double* ab, int* ldab, double* bb, int* ldbb, double* q, int* ldq, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, double* work, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj);

 void dstev_( unsigned char* jobz, int* n, double* d, double* e, double* z, int* ldz, double* work, int* info , JNIEnv *env, jobject obj);

 void dstevd_( unsigned char* jobz, int* n, double* d, double* e, double* z, int* ldz, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void dstevr_( unsigned char* jobz, unsigned char* range, int* n, double* d, double* e, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, int* isuppz, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void dstevx_( unsigned char* jobz, unsigned char* range, int* n, double* d, double* e, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, double* work, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj);

 void dsyev_( unsigned char* jobz, unsigned char* uplo, int* n, double* a, int* lda, double* w, double* work, int* lwork, int* info , JNIEnv *env, jobject obj);

 void dsyevd_( unsigned char* jobz, unsigned char* uplo, int* n, double* a, int* lda, double* w, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void dsyevr_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, double* a, int* lda, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, int* isuppz, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void dsyevx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, double* a, int* lda, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, double* work, int* lwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj);

 void dsygv_( int* itype, unsigned char* jobz, unsigned char* uplo, int* n, double* a, int* lda, double* b, int* ldb, double* w, double* work, int* lwork, int* info , JNIEnv *env, jobject obj);

 void dsygvd_( int* itype, unsigned char* jobz, unsigned char* uplo, int* n, double* a, int* lda, double* b, int* ldb, double* w, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void dsygvx_( int* itype, unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, double* a, int* lda, double* b, int* ldb, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, double* work, int* lwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj);

 void dsysv_( unsigned char* uplo, int* n, int* nrhs, double* a, int* lda, int* ipiv, double* b, int* ldb, double* work, int* lwork, int* info , JNIEnv *env, jobject obj);

 void dsysvx_( unsigned char* fact, unsigned char* uplo, int* n, int* nrhs, double* a, int* lda, double* af, int* ldaf, int* ipiv, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* lwork, int* iwork, int* info , JNIEnv *env, jobject obj);

 void zgbsv_( int* n, int* kl, int* ku, int* nrhs, complex* ab, int* ldab, int* ipiv, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj);

 void zgbsvx_( unsigned char* fact, unsigned char* trans, int* n, int* kl, int* ku, int* nrhs, complex* ab, int* ldab, complex* afb, int* ldafb, int* ipiv, unsigned char* equed, double* r, double* c, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj);

 void zgbtrf_( int* m, int* n, int* kl, int* ku, complex* ab, int* ldab, int* ipiv, int* info , JNIEnv *env, jobject obj);


 void zgeqp3_( int* m, int* n, complex* a, int* lda, int* jpvt, complex* tau, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj);

 void zgeqrf_( int* m, int* n, complex* a, int* lda, complex* tau, complex* work, int* lwork, int* info , JNIEnv *env, jobject obj);


 void zgesvx_( unsigned char* fact, unsigned char* trans, int* n, int* nrhs, complex* a, int* lda, complex* af, int* ldaf, int* ipiv, unsigned char* equed, double* r, double* c, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj);




 void zggevx_( unsigned char* balanc, unsigned char* jobvl, unsigned char* jobvr, unsigned char* sense, int* n, complex* a, int* lda, complex* b, int* ldb, complex* alpha, complex* beta, complex* vl, int* ldvl, complex* vr, int* ldvr, int* ilo, int* ihi, double* lscale, double* rscale, double* abnrm, double* bbnrm, double* rconde, double* rcondv, complex* work, int* lwork, double* rwork, int* iwork, int* bwork, int* info , JNIEnv *env, jobject obj);

 void zggsvd_( unsigned char* jobu, unsigned char* jobv, unsigned char* jobq, int* m, int* n, int* p, int* k, int* l, complex* a, int* lda, complex* b, int* ldb, double* alpha, double* beta, complex* u, int* ldu, complex* v, int* ldv, complex* q, int* ldq, complex* work, double* rwork, int* iwork, int* info , JNIEnv *env, jobject obj);

 void zgtsv_( int* n, int* nrhs, complex* dl, complex* d, complex* du, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj);

 void zgtsvx_( unsigned char* fact, unsigned char* trans, int* n, int* nrhs, complex* dl, complex* d, complex* du, complex* dlf, complex* df, complex* duf, complex* du2, int* ipiv, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj);

 void zgttrf_( int* n, complex* dl, complex* d, complex* du, complex* du2, int* ipiv, int* info , JNIEnv *env, jobject obj);

 void zhbev_( unsigned char* jobz, unsigned char* uplo, int* n, int* kd, complex* ab, int* ldab, double* w, complex* z, int* ldz, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj);

 void zhbevd_( unsigned char* jobz, unsigned char* uplo, int* n, int* kd, complex* ab, int* ldab, double* w, complex* z, int* ldz, complex* work, int* lwork, double* rwork, int* lrwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void zhbevx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, int* kd, complex* ab, int* ldab, complex* q, int* ldq, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, complex* z, int* ldz, complex* work, double* rwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj);

 void zhbgv_( unsigned char* jobz, unsigned char* uplo, int* n, int* ka, int* kb, complex* ab, int* ldab, complex* bb, int* ldbb, double* w, complex* z, int* ldz, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj);

 void zhbgvd_( unsigned char* jobz, unsigned char* uplo, int* n, int* ka, int* kb, complex* ab, int* ldab, complex* bb, int* ldbb, double* w, complex* z, int* ldz, complex* work, int* lwork, double* rwork, int* lrwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void zhbgvx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, int* ka, int* kb, complex* ab, int* ldab, complex* bb, int* ldbb, complex* q, int* ldq, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, complex* z, int* ldz, complex* work, double* rwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj);

 void zheev_( unsigned char* jobz, unsigned char* uplo, int* n, complex* a, int* lda, double* w, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj);

 void zheevd_( unsigned char* jobz, unsigned char* uplo, int* n, complex* a, int* lda, double* w, complex* work, int* lwork, double* rwork, int* lrwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void zheevr_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, complex* a, int* lda, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, complex* z, int* ldz, int* isuppz, complex* work, int* lwork, double* rwork, int* lrwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void zheevx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, complex* a, int* lda, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, complex* z, int* ldz, complex* work, int* lwork, double* rwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj);

 void zhegv_( int* itype, unsigned char* jobz, unsigned char* uplo, int* n, complex* a, int* lda, complex* b, int* ldb, double* w, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj);

 void zhegvd_( int* itype, unsigned char* jobz, unsigned char* uplo, int* n, complex* a, int* lda, complex* b, int* ldb, double* w, complex* work, int* lwork, double* rwork, int* lrwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj);

 void zhegvx_( int* itype, unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, complex* a, int* lda, complex* b, int* ldb, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, complex* z, int* ldz, complex* work, int* lwork, double* rwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj);

 void zhesv_( unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, int* ipiv, complex* b, int* ldb, complex* work, int* lwork, int* info , JNIEnv *env, jobject obj);

 void zhesvx_( unsigned char* fact, unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, complex* af, int* ldaf, int* ipiv, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj);

 void zpbsv_( unsigned char* uplo, int* n, int* kd, int* nrhs, complex* ab, int* ldab, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj);

 void zpbsvx_( unsigned char* fact, unsigned char* uplo, int* n, int* kd, int* nrhs, complex* ab, int* ldab, complex* afb, int* ldafb, unsigned char* equed, double* s, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj);

 void zposv_( unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj);

 void zposvx_( unsigned char* fact, unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, complex* af, int* ldaf, unsigned char* equed, double* s, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj);

 void zptsv_( int* n, int* nrhs, double* d, complex* e, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj);

 void zptsvx_( unsigned char* fact, int* n, int* nrhs, double* d, complex* e, double* df, complex* ef, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj);

 void zsysv_( unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, int* ipiv, complex* b, int* ldb, complex* work, int* lwork, int* info , JNIEnv *env, jobject obj);

 void zsysvx_( unsigned char* fact, unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, complex* af, int* ldaf, int* ipiv, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj);

//---------------------------------------------------------------------------------------------
//--- LU decomposition functions --------------------------------------------------------------
//---------------------------------------------------------------------------------------------

 //void dgetrf_( int* m, int* n, double* a, int* lda, int* ipiv, int* info);

 void zgetrf_( int* m, int* n, complex* a, int* lda, int* ipiv, int* info);


//---------------------------------------------------------------------------------------------
//--- SVD decomposition functions -------------------------------------------------------------
//---------------------------------------------------------------------------------------------

 void dgesvd_( const unsigned char* jobu, const unsigned char* jobvt, int* m, int* n, double* a, int* lda, double* s,  double* u, int* ldu, double* vt, int* ldvt, double* work, int* lwork, int* info , JNIEnv *env, jobject obj);

 void zgesvd_( const unsigned char* jobu, const unsigned char* jobvt, int* m, int* n, complex* a, int* lda, double* s, complex* u, int* ldu, complex* vt, int* ldvt, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj);

 void sgesvd_( const unsigned char* jobu, const unsigned char* jobvt, int* m, int* n, float* a, int* lda, float* s, float* u, int* ldu, float* vt, int* ldvt, float* work, int* lwork, int* info , JNIEnv *env, jobject obj);

 void cgesvd_( const unsigned char* jobu, const unsigned char* jobvt, int* m, int* n, complex64* a, int* lda, float* s, complex64* u, int* ldu, complex64* vt, int* ldvt, complex64* work, int* lwork, float* rwork, int* info , JNIEnv *env, jobject obj);


 void dgesdd_( const unsigned char* jobz, int* m, int* n, double* a, int* lda, double* s, double* u, int* ldu, double* vt, int* ldvt, double* work, int* lwork, int* iwork, int* info , JNIEnv *env, jobject obj);

 void zgesdd_( const unsigned char* jobz, int* m, int* n, complex* a, int* lda, double* s, complex* u, int* ldu, complex* vt, int* ldvt, complex* work, int* lwork, double* rwork, int* iwork, int* info , JNIEnv *env, jobject obj);




//---------------------------------------------------------------------------------------------
//--- Eigenproblem functions ------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

 //void dgeev_( const unsigned char* jobvl, const unsigned char* jobvr, int* n, double* a, int* lda, double* wr, double* wi, double* vl, int* ldvl, double* vr, int* ldvr, double* work, int* lwork, int* info , JNIEnv *env, jobject obj);

 void zgeev_( const unsigned char* jobvl, const unsigned char* jobvr, int* n, complex* a, int* lda, complex* w, complex* vl, int* ldvl, complex* vr, int* ldvr, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj);


// ZYKOVA

 void dgeevx_(  const unsigned char* balanc,  const unsigned char* jobvl,  const unsigned char* jobvr,  const unsigned char* sense, int* n, double* a, int* lda, double* wr, double* wi, double* vl, int* ldvl, double* vr, int* ldvr, int* ilo, int* ihi, double* scale, double* abnrm, double* rconde, double* rcondv, double* work, int* lwork, int* iwork, int* info , JNIEnv *env, jobject obj);

 void zgeevx_( const unsigned char* balanc, const unsigned char* jobvl, const unsigned char* jobvr, const unsigned char* sense, int* n, complex* a, int* lda, complex* w, complex* vl, int* ldvl, complex* vr, int* ldvr, int* ilo, int* ihi, double* scale, double* abnrm, double* rconde, double* rcondv, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj);



// --ZYKOVA

//---------------------------------------------------------------------------------------------
//--- Generalized eigenproblem functions ------------------------------------------------------
//---------------------------------------------------------------------------------------------
 void dggev_( const unsigned char* jobvl, const unsigned char* jobvr, int* n, double* a, int* lda, double* b, int* ldb, double* alphar, double* alphai, double* beta, double* vl, int* ldvl, double* vr, int* ldvr, double* work, int* lwork, int* info , JNIEnv *env, jobject obj);

 void zggev_( const unsigned char* jobvl, const unsigned char* jobvr, int* n, complex* a, int* lda, complex* b, int* ldb, complex* alpha, complex* beta, complex* vl, int* ldvl, complex* vr, int* ldvr, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj);

//---------------------------------------------------------------------------------------------
//--- System of linear equations functions ----------------------------------------------------
//---------------------------------------------------------------------------------------------
 //void dgesv_( int* n, int* nrhs, double* a, int* lda, int* ipiv, double* b, int* ldb, int* info , JNIEnv *env, jobject obj);

 void zgesv_( int* n, int* nrhs, complex* a, int* lda, int* ipiv, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj);

 */