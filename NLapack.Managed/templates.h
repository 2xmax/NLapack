#include "stdafx.h"
#include "fpc.h"
#include "fpc_types.h"
#include "constants.h"
#include "extra_func.h"
#include "dynamic.h"
#include "lapack.h"

#include "blas_import.h"
//#include "stdio.h"

using namespace fpc;

template <typename _t>
inline void xgesv_  (
    int* n,
    int* nrhs,
    _t* a,
    int* lda,
    int* ipiv,
    _t* b,
    int* ldb,
    int* info);

template <>
inline void xgesv_ (
    int* n,
    int* nrhs,
    double* a,
    int* lda,
    int* ipiv,
    double* b,
    int* ldb,
    int* info){ 
		dgesv_(n,nrhs,a,lda,ipiv,b,ldb,info); 
}

template <>
inline void xgesv_ (
    int* n,
    int* nrhs,
    complex* a,
    int* lda,
    int* ipiv,
    complex* b,
    int* ldb,
    int* info){
		zgesv_(n,nrhs,a,lda,ipiv,b,ldb,info); 
};


template<typename _t>
inline void xpotrf_ (
    	     char* uplo,
    	     int* n,
    	     _t* a,
    	     int* lda,
    	     int* info
 );

template<>
inline void xpotrf_<double> (
	     char* uplo,
	     int* n,
	     double* a,
	     int* lda,
         int* info
 ) {	 
	 dpotrf_(uplo, n, a, lda,info);
}
/*
template<>
inline void xpotrf_<complex> (
	     char* uplo,
	     int* n,
	     complex* a,
	     int* lda,
	     int* info,
             JNIEnv *e,
             jobject obj
 ) {zpotrf_(uplo, n, a, lda, info, e, obj);}
 */
template<typename _t>
inline void xgetrif_  (int* n, _t* a, _t* work, int* lwork, int* info);

template<>
inline void xgetrif_<double>  (int* n, double* a, double* work, int* lwork, int* info)
{
	int* ipiv = new int[*n];
	dgetrf_(n, n, a, n, ipiv,info);
	if (*info==0)
		dgetri_(n, a, n, ipiv, work, lwork,info);
	else
	    *info=-99;
}


template<>
inline void xgetrif_<complex>  (int* n, complex* a, complex* work, int* lwork, int* info)
{
	/*int* ipiv = new int[*n];
	zgetrf_(n, n, a, n, ipiv,info);
	if (*info==0)
		zgetri_(n, a, n, ipiv, work, lwork,info);
	else
	    *info=-99;*/
}


template<typename _t>
inline void xgetrf_ (
	int* m,
    int* n,
    _t* a,
    int* lda,
    int* ipiv,
    int* info
 );

template<>
inline void xgetrf_<double> (
	int* m,
    int* n,
    double* a,
    int* lda,
    int* ipiv,
    int* info
 ){ dgetrf_(m,n,a,lda,ipiv,info); }

template<>
inline void xgetrf_<complex> (
	int* m,
    int* n,
    complex* a,
    int* lda,
    int* ipiv,
    int* info
 ){ //todo:zgetrf_(m,n,a,lda,ipiv,info);
}

template<typename _t, typename _st>
inline void xgesvd_ (
	const unsigned char* jobu,
    const unsigned char* jobvt,
    int* m,
    int* n,
    _t* a,
    int* lda,
    _st* s,
    _t* u,
    int* ldu,
    _t* vt,
    int* ldvt,
    int* info
 );

template<>
inline void xgesvd_ (
	const unsigned char* jobu,
    const unsigned char* jobvt,
    int* m,
    int* n,
    double* a,
    int* lda,
    double* s,
    double* u,
    int* ldu,
    double* vt,
    int* ldvt,
    int* info
 )
{
	double query = fpc::constants<double>::_0;
	int lwork = -1;

	dgesvd_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, &query, &lwork,info);
	if (*info) return;
	fpc::buffer<double> work(lwork = (int)query);
	
	dgesvd_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, work, &lwork, info);
}

template<>
inline void xgesvd_ (
	const unsigned char* jobu,
    const unsigned char* jobvt,
    int* m,
    int* n,
    complex* a,
    int* lda,
    double* s,
    complex* u,
    int* ldu,
    complex* vt,
    int* ldvt,
    int* info
 )
{	
	complex query = fpc::constants<complex>::_0;
	int lwork = -1;
	zgesvd_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, &query, &lwork, 0,info);
	if (*info) return;
	fpc::buffer<complex> work(lwork = (int)query.re);
	fpc::buffer<double> rwork(5*MIN(*m,*n));
	zgesvd_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, work, &lwork, rwork,info);
}
/*
template<>
inline void xgesvd_ (
    const unsigned char* jobu,
    const unsigned char* jobvt,
    int* m,
    int* n,
    float* a,
    int* lda,
    float* s,
    float* u,
    int* ldu,
    float* vt,
    int* ldvt,
    int* info
 , JNIEnv *e,
 jobject obj
 )
{
float query = 0;
int lwork = -1;
printf("lapack-import.h: xgesvd_\n");

	sgesvd_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, &query, &lwork,info,e,obj);
	if (*info) return;
fpc::buffer<float> work(lwork = (int)query);
	sgesvd_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, work, &lwork,info,e,obj);
}
template<>
inline void xgesvd_ (
	const unsigned char* jobu,
    const unsigned char* jobvt,
    int* m,
    int* n,
    complex64* a,
    int* lda,
    float* s,
    complex64* u,
    int* ldu,
    complex64* vt,
    int* ldvt,
    int* info
 , JNIEnv *e,
 jobject obj
 )
{

complex64 query = fpc::constants<complex64>::_0;
int lwork = -1;
	cgesvd_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, &query, &lwork, 0,info,e,obj);
	if (*info) return;
fpc::buffer<complex64> work(lwork = (int)query.re);
fpc::buffer<float> rwork(5*MIN(*m,*n));
	cgesvd_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, work, &lwork, rwork,info,e,obj);
}


template<typename _t>
inline void xgesdd_ (
    const unsigned char* jobz,
    int* m,
    int* n,
    _t* a,
    int* lda,
    double* s,
    _t* u,
    int* ldu,
    _t* vt,
    int* ldvt,
    int* info
 , JNIEnv *e,
 jobject obj
 );

template<>
inline void xgesdd_ (
	const unsigned char* jobz,
    int* m,
    int* n,
    double* a,
    int* lda,
    double* s,
    double* u,
    int* ldu,
    double* vt,
    int* ldvt,
    int* info
 , JNIEnv *e,
 jobject obj
 )
{
double query = fpc::constants<double>::_0;
int lwork = -1;
	dgesdd_(jobz, m, n, a, lda, s, u, ldu, vt, ldvt, &query, &lwork, 0,info,e,obj);
	if (*info) return;
fpc::buffer<double> work(lwork = (int)query);
fpc::buffer<int> iwork(8*MIN(*m,*n));
	dgesdd_(jobz, m, n, a, lda, s, u, ldu, vt, ldvt, work, &lwork, iwork,info,e,obj);
}

template<>
inline void xgesdd_ (
	const unsigned char* jobz,
    int* m,
    int* n,
    complex* a,
    int* lda,
    double* s,
    complex* u,
    int* ldu,
    complex* vt,
    int* ldvt,
    int* info
 , JNIEnv *e,
 jobject obj
 )
{
complex query = fpc::constants<complex>::_0;
int lwork = -1;
	zgesdd_(jobz, m, n, a, lda, s, u, ldu, vt, ldvt, &query, &lwork, 0, 0,info,e,obj);
	if (*info) return;
fpc::buffer<complex> work(lwork = (int)query.re);
fpc::buffer<double> rwork((*jobz==_N)?( 5*MIN(*m,*n) ):( (5*MIN(*m,*n) + 7)*MIN(*m,*n) ) );
fpc::buffer<int> iwork(8*MIN(*m,*n));
	zgesdd_(jobz, m, n, a, lda, s, u, ldu, vt, ldvt, work, &lwork, rwork, iwork,info,e,obj);
}*/
template<typename _t>
inline void __cdecl xgeev_ (
    const unsigned char* jobvl,
    const unsigned char* jobvr,
    int* n,
    _t* a,
    int* lda,
    complex* w,
    complex* vl,
    int* ldvl,
    complex* vr,
    int* ldvr,
    int* info
 );
template<>
inline void __cdecl xgeev_ (
    const unsigned char* jobvl,
    const unsigned char* jobvr,
    int* n,
    double* a,
    int* lda,
    complex* w,
    complex* vl,
    int* ldvl,
    complex* vr,
    int* ldvr,
    int* info
 )
{
	double query = fpc::constants<double>::_0;
	int lwork = -1;
		double* _vl = ((double*)(vl)) + (*n)*(*n);
		double* _vr = ((double*)(vr)) + (*n)*(*n);

		//dgeev_(jobvl, jobvr, n, a, lda, *wr, *wi,  *vl,  *ldvl,  *vr,  *ldvr,  *work, int *lwork, int *info);
		//todo:

		dgeev_(jobvl, jobvr, n, a, lda, 0, 0, _vl, ldvl, _vr, ldvr, &query, &lwork, info);
		if (*info) return;
	fpc::buffer<double> work( (lwork = (int)query) + 2*(*n));
	double* wr = work + lwork;
	double* wi = wr + *n;
		dgeev_(jobvl, jobvr, n, a, lda, wr, wi, _vl, ldvl, _vr, ldvr, work, &lwork, info);
		_buildev(*n, wr, wi, w, vr, vl);
};

template<>
inline void __cdecl xgeev_ (
    const unsigned char* jobvl,
    const unsigned char* jobvr,
    int* n,
    complex* a,
    int* lda,
    complex* w,
    complex* vl,
    int* ldvl,
    complex* vr,
    int* ldvr,
    int* info
 )
{
/*complex query = fpc::constants<complex>::_0;
int lwork = -1;
	zgeev_(jobvl, jobvr, n, a, lda, w, vl, ldvl, vr, ldvr, &query, &lwork, 0,info,e,obj);
	if (*info) return;
fpc::buffer<complex> work( (lwork = (int)query.re) + *n);
double* rwork = (double*)(work + lwork);
	zgeev_(jobvl, jobvr, n, a, lda, w, vl, ldvl, vr, ldvr, work, &lwork, rwork,info,e,obj);*/
};
template<typename _t>
inline void __cdecl xgeevx_ (
	const unsigned char* balanc,
    const unsigned char* jobvl,
    const unsigned char* jobvr,
    const unsigned char* sense,
    int* n,
    _t* a,
    int* lda,
    complex* w,
    complex* vl,
    int* ldvl,
    complex* vr,
    int* ldvr,
    int* ilo,
    int* ihi,
    double* abnrm,
    double* rconde,
    double* rcondv,
    int* info
 );

template<>
inline void __cdecl xgeevx_ (
	const unsigned char* balanc,
    const unsigned char* jobvl,
    const unsigned char* jobvr,
    const unsigned char* sense,
    int* n,
    double* a,
    int* lda,
    complex* w,
    complex* vl,
    int* ldvl,
    complex* vr,
    int* ldvr,
    int* ilo,
    int* ihi,
    double* abnrm,
    double* rconde,
    double* rcondv,
    int* info
 )
{
	 double query = fpc::constants<double>::_0;
	 int lwork=-1;
	 double* _vl=((double*)(vl))+(*n)*(*n);
	 double* _vr=((double*)(vr))+(*n)*(*n);
	 fpc::buffer<double> scale(*n);
	 fpc::buffer<int> iwork(2*(*n)-2);
	 dgeevx_(balanc,jobvl,jobvr,sense,n,a,lda,0,0,_vl,ldvl,_vr,ldvr,ilo,ihi,scale,abnrm,rconde,rcondv,&query,&lwork,iwork,info);
	 if (*info) return;
	 fpc::buffer<double> work( (lwork = (int)query) + 2*(*n));
	 double* wr = work + lwork;
	 double* wi = wr + *n;
	 dgeevx_(balanc,jobvl,jobvr,sense,n,a,lda,wr,wi,_vl,ldvl,_vr,ldvr,ilo,ihi,scale,abnrm,rconde,rcondv,work,&lwork,iwork,info);
	 _buildev(*n, wr, wi, w, vr, vl);
};

template<>
inline void __cdecl xgeevx_ (
	const unsigned char* balanc,
	const unsigned char* jobvl,
	const unsigned char* jobvr,
	const unsigned char* sense,
	int* n,
	complex* a,
	int* lda,
	complex* w,
	complex* vl,
	int* ldvl,
	complex* vr,
	int* ldvr,
	int* ilo,
	int* ihi,
	double* abnrm,
	double* rconde,
	double* rcondv,
	int* info
 )
{
/* complex query = fpc::constants<complex>::_0;
 int lwork = -1;
 fpc::buffer<double> scale(*n);
 fpc::buffer<double> rwork(2*(*n));
 zgeevx_(balanc,jobvl,jobvr,sense,n,a,lda,0,vl,ldvl,vr,ldvr,ilo,ihi,scale,abnrm,rconde,rcondv,&query,&lwork,rwork,info,e,obj);
 if (*info) return;
 fpc::buffer<complex> work( (lwork = (int)query.re));
 zgeevx_(balanc,jobvl,jobvr,sense,n,a,lda,w,vl,ldvl,vr,ldvr,ilo,ihi,scale,abnrm,rconde,rcondv,work,&lwork,rwork,info,e,obj);
 if (*info) return;*/
};
/*
template <typename _t>
inline void __cdecl xggev_ (
    const unsigned char* jobvl,
    const unsigned char* jobvr,
    int* n,
    _t* a,
    int* lda,
    _t* b,
    int* ldb,
    complex* alpha,
    _t* beta,
    complex* vl,
    int* ldvl,
    complex* vr,
    int* ldvr,
    int* info
 , JNIEnv *e,
 jobject obj
 );

template<>
inline void __cdecl xggev_ (
	const unsigned char* jobvl,
	const unsigned char* jobvr,
	int* n,
	double* a,
	int* lda,
	double* b,
	int* ldb,
	complex* alpha,
	double* beta,
	complex* vl,
	int* ldvl,
	complex* vr,
	int* ldvr,
    int* info
 , JNIEnv *e,
 jobject obj
 )
{
double query = fpc::constants<double>::_0;
int lwork = -1;
double* _vl = ((double*)(vl)) + (*n)*(*n);
double* _vr = ((double*)(vr)) + (*n)*(*n);
	dggev_(jobvl, jobvr, n, a, lda, b, ldb, 0, 0, 0, _vl, ldvl, _vr, ldvr, &query, &lwork,info,e,obj);
	if (*info) return;
fpc::buffer<double> work( (lwork = (int)query) + 2*(*n));
double* alphar = work + lwork;
double* alphai = alphar + *n;
	dggev_(jobvl, jobvr, n, a, lda, b, ldb, alphar, alphai, beta, _vl, ldvl, _vr, ldvr, work, &lwork,info,e,obj);
	_buildev(*n, alphar, alphai, alpha, vr, vl);
};

template<>
inline void __cdecl xggev_ (
	const unsigned char* jobvl,
	const unsigned char* jobvr,
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
    int* info
 , JNIEnv *e,
 jobject obj
 )
{
complex query = fpc::constants<complex>::_0;
int lwork = -1;
	zggev_(jobvl, jobvr, n, a, lda, b, ldb, alpha, beta, vl, ldvl, vr, ldvr, &query, &lwork, 0,info,e,obj);
	if (*info) return;
fpc::buffer<complex> work( (lwork = (int)query.re) + 4*(*n));
double* rwork = (double*)(work + lwork);
	zggev_(jobvl, jobvr, n, a, lda, b, ldb, alpha, beta, vl, ldvl, vr, ldvr, work, &lwork, rwork,info,e,obj);
};

*/
/*
void test456()
{
	
}*/