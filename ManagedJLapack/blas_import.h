#ifndef __BLAS_H
#define __BLAS_H

#include "fpc.h"
#include "fpc_types.h"
using namespace fpc;

//using fpc::complex128;

//#include "common.h"



//---------------------------------------------------------------------------------------------
//--- Array copy functions --------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

extern "C" void __cdecl scopy_(
    int* n,
    float* sx,
    int* incx,
    float* sy,
    int* incy
);

extern "C" void __cdecl dcopy_(
    int* n,
    double* dx,
    int* incx,
    double* dy,
    int* incy
);

extern "C" void __cdecl zcopy_(
    int* n,
    complex* zx,
    int* incx,
    complex* zy,
    int* incy
);

template<typename _t>
inline void xcopy_(
    int* n,
    _t* x,
    int* incx,
    _t* y,
    int* incy
);

template<>
inline void xcopy_(
    int* n,
    float* x,
    int* incx,
    float* y,
    int* incy
){ scopy_(n,x,incx,y,incy); }

template<>
inline void xcopy_(
    int* n,
    double* x,
    int* incx,
    double* y,
    int* incy
){ dcopy_(n,x,incx,y,incy); }

template<>
inline void xcopy_(
    int* n,
    complex* x,
    int* incx,
    complex* y,
    int* incy
){ zcopy_(n,x,incx,y,incy); }


//---------------------------------------------------------------------------------------------
//--- Multiplications functions ---------------------------------------------------------------
//---------------------------------------------------------------------------------------------

extern "C" void  sgemm_(
    const unsigned char* transa,
    const unsigned char* transb,
    int* m,
    int* n,
    int* k,
    const float* alpha,
    float* a,
    int* lda,
    float* b,
    int* ldb,
    const float* beta,
    float* c,
    int* ldc
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

extern "C" void __cdecl zgemm_(
    const unsigned char* transa,
    const unsigned char* transb,
    int* m,
    int* n,
    int* k,
    const complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    const complex* beta,
    complex* c,
    int* ldc
);

template<typename _t>
inline void xgemm_(
    const unsigned char* transa,
    const unsigned char* transb,
    int* m,
    int* n,
    int* k,
    const _t* alpha,
    _t* a,
    int* lda,
    _t* b,
    int* ldb,
    const _t* beta,
    _t* c,
    int* ldc
);

template<>
inline void xgemm_(
    const unsigned char* transa,
    const unsigned char* transb,
    int* m,
    int* n,
    int* k,
    const float* alpha,
    float* a,
    int* lda,
    float* b,
    int* ldb,
    const float* beta,
    float* c,
    int* ldc
){ sgemm_(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc); }

template<>
inline void xgemm_(
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
){ dgemm_(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc); }

template<>
inline void xgemm_(
    const unsigned char* transa,
    const unsigned char* transb,
    int* m,
    int* n,
    int* k,
    const complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    const complex* beta,
    complex* c,
    int* ldc
){ zgemm_(transa,transb,m,n,k,alpha,a,lda,b,ldb,beta,c,ldc); }



//---------------------------------------------------------------------------------------------


extern "C" void __cdecl caxpy_(
    int* n,
    complex* ca,
    complex* cx,
    int* incx,
    complex* cy,
    int* incy
);

extern "C" void __cdecl ccopy_(
    int* n,
    complex* cx,
    int* incx,
    complex* cy,
    int* incy
);

extern "C" void __cdecl cdotc_(
    complex* __g77_result,
    int* n,
    complex* cx,
    int* incx,
    complex* cy,
    int* incy
);

extern "C" void __cdecl cdotu_(
    complex* __g77_result,
    int* n,
    complex* cx,
    int* incx,
    complex* cy,
    int* incy
);

extern "C" void __cdecl cgbmv_(
    const unsigned char* trans,
    int* m,
    int* n,
    int* kl,
    int* ku,
    complex* alpha,
    complex* a,
    int* lda,
    complex* x,
    int* incx,
    complex* beta,
    complex* y,
    int* incy
);

extern "C" void __cdecl cgemm_(
    const unsigned char* transa,
    const unsigned char* transb,
    int* m,
    int* n,
    int* k,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    complex* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl cgemv_(
    const unsigned char* trans,
    int* m,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* x,
    int* incx,
    complex* beta,
    complex* y,
    int* incy
);

extern "C" void __cdecl cgerc_(
    int* m,
    int* n,
    complex* alpha,
    complex* x,
    int* incx,
    complex* y,
    int* incy,
    complex* a,
    int* lda
);

extern "C" void __cdecl cgeru_(
    int* m,
    int* n,
    complex* alpha,
    complex* x,
    int* incx,
    complex* y,
    int* incy,
    complex* a,
    int* lda
);

extern "C" void __cdecl chbmv_(
    const unsigned char* uplo,
    int* n,
    int* k,
    complex* alpha,
    complex* a,
    int* lda,
    complex* x,
    int* incx,
    complex* beta,
    complex* y,
    int* incy
);

extern "C" void __cdecl chemm_(
    const unsigned char* side,
    const unsigned char* uplo,
    int* m,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    complex* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl chemv_(
    const unsigned char* uplo,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* x,
    int* incx,
    complex* beta,
    complex* y,
    int* incy
);

extern "C" void __cdecl cher_(
    const unsigned char* uplo,
    int* n,
    float* alpha,
    complex* x,
    int* incx,
    complex* a,
    int* lda
);

extern "C" void __cdecl cher2_(
    const unsigned char* uplo,
    int* n,
    complex* alpha,
    complex* x,
    int* incx,
    complex* y,
    int* incy,
    complex* a,
    int* lda
);

extern "C" void __cdecl cher2k_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    float* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl cherk_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    float* alpha,
    complex* a,
    int* lda,
    float* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl chpmv_(
    const unsigned char* uplo,
    int* n,
    complex* alpha,
    complex* ap,
    complex* x,
    int* incx,
    complex* beta,
    complex* y,
    int* incy
);

extern "C" void __cdecl chpr_(
    const unsigned char* uplo,
    int* n,
    float* alpha,
    complex* x,
    int* incx,
    complex* ap
);

extern "C" void __cdecl chpr2_(
    const unsigned char* uplo,
    int* n,
    complex* alpha,
    complex* x,
    int* incx,
    complex* y,
    int* incy,
    complex* ap
);

extern "C" void __cdecl crotg_(
    complex* ca,
    complex* cb,
    float* c,
    complex* s
);

extern "C" void __cdecl cscal_(
    int* n,
    complex* ca,
    complex* cx,
    int* incx
);

extern "C" void __cdecl csscal_(
    int* n,
    float* sa,
    complex* cx,
    int* incx
);

extern "C" void __cdecl cswap_(
    int* n,
    complex* cx,
    int* incx,
    complex* cy,
    int* incy
);

extern "C" void __cdecl csymm_(
    const unsigned char* side,
    const unsigned char* uplo,
    int* m,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    complex* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl csyr2k_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    complex* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl csyrk_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    complex* alpha,
    complex* a,
    int* lda,
    complex* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl ctbmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    int* k,
    complex* a,
    int* lda,
    complex* x,
    int* incx
);

extern "C" void __cdecl ctbsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    int* k,
    complex* a,
    int* lda,
    complex* x,
    int* incx
);

extern "C" void __cdecl ctpmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    complex* ap,
    complex* x,
    int* incx
);

extern "C" void __cdecl ctpsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    complex* ap,
    complex* x,
    int* incx
);

extern "C" void __cdecl ctrmm_(
    const unsigned char* side,
    const unsigned char* uplo,
    const unsigned char* transa,
    const unsigned char* diag,
    int* m,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb
);

extern "C" void __cdecl ctrmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    complex* a,
    int* lda,
    complex* x,
    int* incx
);

extern "C" void __cdecl ctrsm_(
    const unsigned char* side,
    const unsigned char* uplo,
    const unsigned char* transa,
    const unsigned char* diag,
    int* m,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb
);

extern "C" void __cdecl ctrsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    complex* a,
    int* lda,
    complex* x,
    int* incx
);

extern "C" double __cdecl dasum_(
    int* n,
    double* dx,
    int* incx
);

extern "C" void __cdecl daxpy_(
    int* n,
    double* da,
    double* dx,
    int* incx,
    double* dy,
    int* incy
);

extern "C" double __cdecl dcabs1_(
    complex* z
);


extern "C" double __cdecl ddot_(
    int* n,
    double* dx,
    int* incx,
    double* dy,
    int* incy
);

extern "C" void __cdecl dgbmv_(
    const unsigned char* trans,
    int* m,
    int* n,
    int* kl,
    int* ku,
    double* alpha,
    double* a,
    int* lda,
    double* x,
    int* incx,
    double* beta,
    double* y,
    int* incy
);


extern "C" void __cdecl dgemv_(
    const unsigned char* trans,
    int* m,
    int* n,
    double* alpha,
    double* a,
    int* lda,
    double* x,
    int* incx,
    double* beta,
    double* y,
    int* incy
);

extern "C" void __cdecl dger_(
    int* m,
    int* n,
    double* alpha,
    double* x,
    int* incx,
    double* y,
    int* incy,
    double* a,
    int* lda
);

extern "C" double __cdecl dnrm2_(
    int* n,
    double* x,
    int* incx
);

extern "C" void __cdecl drot_(
    int* n,
    double* dx,
    int* incx,
    double* dy,
    int* incy,
    double* c,
    double* s
);

extern "C" void __cdecl drotg_(
    double* da,
    double* db,
    double* c,
    double* s
);

extern "C" void __cdecl dsbmv_(
    const unsigned char* uplo,
    int* n,
    int* k,
    double* alpha,
    double* a,
    int* lda,
    double* x,
    int* incx,
    double* beta,
    double* y,
    int* incy
);

extern "C" void __cdecl dscal_(
    int* n,
    double* da,
    double* dx,
    int* incx
);

extern "C" void __cdecl dspmv_(
    const unsigned char* uplo,
    int* n,
    double* alpha,
    double* ap,
    double* x,
    int* incx,
    double* beta,
    double* y,
    int* incy
);

extern "C" void __cdecl dspr_(
    const unsigned char* uplo,
    int* n,
    double* alpha,
    double* x,
    int* incx,
    double* ap
);

extern "C" void __cdecl dspr2_(
    const unsigned char* uplo,
    int* n,
    double* alpha,
    double* x,
    int* incx,
    double* y,
    int* incy,
    double* ap
);

extern "C" void __cdecl dswap_(
    int* n,
    double* dx,
    int* incx,
    double* dy,
    int* incy
);

extern "C" void __cdecl dsymm_(
    const unsigned char* side,
    const unsigned char* uplo,
    int* m,
    int* n,
    double* alpha,
    double* a,
    int* lda,
    double* b,
    int* ldb,
    double* beta,
    double* c,
    int* ldc
);

extern "C" void __cdecl dsymv_(
    const unsigned char* uplo,
    int* n,
    double* alpha,
    double* a,
    int* lda,
    double* x,
    int* incx,
    double* beta,
    double* y,
    int* incy
);

extern "C" void __cdecl dsyr_(
    const unsigned char* uplo,
    int* n,
    double* alpha,
    double* x,
    int* incx,
    double* a,
    int* lda
);

extern "C" void __cdecl dsyr2_(
    const unsigned char* uplo,
    int* n,
    double* alpha,
    double* x,
    int* incx,
    double* y,
    int* incy,
    double* a,
    int* lda
);

extern "C" void __cdecl dsyr2k_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    double* alpha,
    double* a,
    int* lda,
    double* b,
    int* ldb,
    double* beta,
    double* c,
    int* ldc
);

extern "C" void __cdecl dsyrk_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    double* alpha,
    double* a,
    int* lda,
    double* beta,
    double* c,
    int* ldc
);

extern "C" void __cdecl dtbmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    int* k,
    double* a,
    int* lda,
    double* x,
    int* incx
);

extern "C" void __cdecl dtbsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    int* k,
    double* a,
    int* lda,
    double* x,
    int* incx
);

extern "C" void __cdecl dtpmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    double* ap,
    double* x,
    int* incx
);

extern "C" void __cdecl dtpsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    double* ap,
    double* x,
    int* incx
);

extern "C" void __cdecl dtrmm_(
    const unsigned char* side,
    const unsigned char* uplo,
    const unsigned char* transa,
    const unsigned char* diag,
    int* m,
    int* n,
    double* alpha,
    double* a,
    int* lda,
    double* b,
    int* ldb
);

extern "C" void __cdecl dtrmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    double* a,
    int* lda,
    double* x,
    int* incx
);

extern "C" void __cdecl dtrsm_(
    const unsigned char* side,
    const unsigned char* uplo,
    const unsigned char* transa,
    const unsigned char* diag,
    int* m,
    int* n,
    double* alpha,
    double* a,
    int* lda,
    double* b,
    int* ldb
);

extern "C" void __cdecl dtrsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    double* a,
    int* lda,
    double* x,
    int* incx
);

extern "C" double __cdecl dzasum_(
    int* n,
    complex* zx,
    int* incx
);

extern "C" double __cdecl dznrm2_(
    int* n,
    complex* x,
    int* incx
);

extern "C" int __cdecl icamax_(
    int* n,
    complex* cx,
    int* incx
);

extern "C" int __cdecl idamax_(
    int* n,
    double* dx,
    int* incx
);

extern "C" int __cdecl isamax_(
    int* n,
    float* sx,
    int* incx
);

extern "C" int __cdecl izamax_(
    int* n,
    complex* zx,
    int* incx
);

extern "C" int __cdecl lsame_(
    const unsigned char* ca,
    const unsigned char* cb
);

extern "C" double __cdecl sasum_(
    int* n,
    float* sx,
    int* incx
);

extern "C" void __cdecl saxpy_(
    int* n,
    float* sa,
    float* sx,
    int* incx,
    float* sy,
    int* incy
);

extern "C" double __cdecl scabs1_(
    complex* z
);

extern "C" double __cdecl scasum_(
    int* n,
    complex* cx,
    int* incx
);

extern "C" double __cdecl scnrm2_(
    int* n,
    complex* x,
    int* incx
);

extern "C" double __cdecl sdot_(
    int* n,
    float* sx,
    int* incx,
    float* sy,
    int* incy
);

extern "C" void __cdecl sgbmv_(
    const unsigned char* trans,
    int* m,
    int* n,
    int* kl,
    int* ku,
    float* alpha,
    float* a,
    int* lda,
    float* x,
    int* incx,
    float* beta,
    float* y,
    int* incy
);



extern "C" void __cdecl sgemv_(
    const unsigned char* trans,
    int* m,
    int* n,
    float* alpha,
    float* a,
    int* lda,
    float* x,
    int* incx,
    float* beta,
    float* y,
    int* incy
);

extern "C" void __cdecl sger_(
    int* m,
    int* n,
    float* alpha,
    float* x,
    int* incx,
    float* y,
    int* incy,
    float* a,
    int* lda
);

extern "C" double __cdecl snrm2_(
    int* n,
    float* x,
    int* incx
);

extern "C" void __cdecl srot_(
    int* n,
    float* sx,
    int* incx,
    float* sy,
    int* incy,
    float* c,
    float* s
);

extern "C" void __cdecl srotg_(
    float* sa,
    float* sb,
    float* c,
    float* s
);

extern "C" void __cdecl ssbmv_(
    const unsigned char* uplo,
    int* n,
    int* k,
    float* alpha,
    float* a,
    int* lda,
    float* x,
    int* incx,
    float* beta,
    float* y,
    int* incy
);

extern "C" void __cdecl sscal_(
    int* n,
    float* sa,
    float* sx,
    int* incx
);

extern "C" void __cdecl sspmv_(
    const unsigned char* uplo,
    int* n,
    float* alpha,
    float* ap,
    float* x,
    int* incx,
    float* beta,
    float* y,
    int* incy
);

extern "C" void __cdecl sspr_(
    const unsigned char* uplo,
    int* n,
    float* alpha,
    float* x,
    int* incx,
    float* ap
);

extern "C" void __cdecl sspr2_(
    const unsigned char* uplo,
    int* n,
    float* alpha,
    float* x,
    int* incx,
    float* y,
    int* incy,
    float* ap
);

extern "C" void __cdecl sswap_(
    int* n,
    float* sx,
    int* incx,
    float* sy,
    int* incy
);

extern "C" void __cdecl ssymm_(
    const unsigned char* side,
    const unsigned char* uplo,
    int* m,
    int* n,
    float* alpha,
    float* a,
    int* lda,
    float* b,
    int* ldb,
    float* beta,
    float* c,
    int* ldc
);

extern "C" void __cdecl ssymv_(
    const unsigned char* uplo,
    int* n,
    float* alpha,
    float* a,
    int* lda,
    float* x,
    int* incx,
    float* beta,
    float* y,
    int* incy
);

extern "C" void __cdecl ssyr_(
    const unsigned char* uplo,
    int* n,
    float* alpha,
    float* x,
    int* incx,
    float* a,
    int* lda
);

extern "C" void __cdecl ssyr2_(
    const unsigned char* uplo,
    int* n,
    float* alpha,
    float* x,
    int* incx,
    float* y,
    int* incy,
    float* a,
    int* lda
);

extern "C" void __cdecl ssyr2k_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    float* alpha,
    float* a,
    int* lda,
    float* b,
    int* ldb,
    float* beta,
    float* c,
    int* ldc
);

extern "C" void __cdecl ssyrk_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    float* alpha,
    float* a,
    int* lda,
    float* beta,
    float* c,
    int* ldc
);

extern "C" void __cdecl stbmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    int* k,
    float* a,
    int* lda,
    float* x,
    int* incx
);

extern "C" void __cdecl stbsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    int* k,
    float* a,
    int* lda,
    float* x,
    int* incx
);

extern "C" void __cdecl stpmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    float* ap,
    float* x,
    int* incx
);

extern "C" void __cdecl stpsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    float* ap,
    float* x,
    int* incx
);

extern "C" void __cdecl strmm_(
    const unsigned char* side,
    const unsigned char* uplo,
    const unsigned char* transa,
    const unsigned char* diag,
    int* m,
    int* n,
    float* alpha,
    float* a,
    int* lda,
    float* b,
    int* ldb
);

extern "C" void __cdecl strmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    float* a,
    int* lda,
    float* x,
    int* incx
);

extern "C" void __cdecl strsm_(
    const unsigned char* side,
    const unsigned char* uplo,
    const unsigned char* transa,
    const unsigned char* diag,
    int* m,
    int* n,
    float* alpha,
    float* a,
    int* lda,
    float* b,
    int* ldb
);

extern "C" void __cdecl strsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    float* a,
    int* lda,
    float* x,
    int* incx
);

extern "C" void __cdecl xerbla_(
    const unsigned char* srname,
    int* info
);

extern "C" void __cdecl zaxpy_(
    int* n,
    complex* za,
    complex* zx,
    int* incx,
    complex* zy,
    int* incy
);

extern "C" void __cdecl zdotc_(
    complex* __g77_result,
    int* n,
    complex* zx,
    int* incx,
    complex* zy,
    int* incy
);

extern "C" void __cdecl zdotu_(
    complex* __g77_result,
    int* n,
    complex* zx,
    int* incx,
    complex* zy,
    int* incy
);

extern "C" void __cdecl zdscal_(
    int* n,
    double* da,
    complex* zx,
    int* incx
);

extern "C" void __cdecl zgbmv_(
    const unsigned char* trans,
    int* m,
    int* n,
    int* kl,
    int* ku,
    complex* alpha,
    complex* a,
    int* lda,
    complex* x,
    int* incx,
    complex* beta,
    complex* y,
    int* incy
);


extern "C" void __cdecl zgemv_(
    const unsigned char* trans,
    int* m,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* x,
    int* incx,
    complex* beta,
    complex* y,
    int* incy
);

extern "C" void __cdecl zgerc_(
    int* m,
    int* n,
    complex* alpha,
    complex* x,
    int* incx,
    complex* y,
    int* incy,
    complex* a,
    int* lda
);

extern "C" void __cdecl zgeru_(
    int* m,
    int* n,
    complex* alpha,
    complex* x,
    int* incx,
    complex* y,
    int* incy,
    complex* a,
    int* lda
);

extern "C" void __cdecl zhbmv_(
    const unsigned char* uplo,
    int* n,
    int* k,
    complex* alpha,
    complex* a,
    int* lda,
    complex* x,
    int* incx,
    complex* beta,
    complex* y,
    int* incy
);

extern "C" void __cdecl zhemm_(
    const unsigned char* side,
    const unsigned char* uplo,
    int* m,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    complex* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl zhemv_(
    const unsigned char* uplo,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* x,
    int* incx,
    complex* beta,
    complex* y,
    int* incy
);

extern "C" void __cdecl zher_(
    const unsigned char* uplo,
    int* n,
    double* alpha,
    complex* x,
    int* incx,
    complex* a,
    int* lda
);

extern "C" void __cdecl zher2_(
    const unsigned char* uplo,
    int* n,
    complex* alpha,
    complex* x,
    int* incx,
    complex* y,
    int* incy,
    complex* a,
    int* lda
);

extern "C" void __cdecl zher2k_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    double* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl zherk_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    double* alpha,
    complex* a,
    int* lda,
    double* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl zhpmv_(
    const unsigned char* uplo,
    int* n,
    complex* alpha,
    complex* ap,
    complex* x,
    int* incx,
    complex* beta,
    complex* y,
    int* incy
);

extern "C" void __cdecl zhpr_(
    const unsigned char* uplo,
    int* n,
    double* alpha,
    complex* x,
    int* incx,
    complex* ap
);

extern "C" void __cdecl zhpr2_(
    const unsigned char* uplo,
    int* n,
    complex* alpha,
    complex* x,
    int* incx,
    complex* y,
    int* incy,
    complex* ap
);

extern "C" void __cdecl zrotg_(
    complex* ca,
    complex* cb,
    double* c,
    complex* s
);

extern "C" void __cdecl zscal_(
    int* n,
    complex* za,
    complex* zx,
    int* incx
);

extern "C" void __cdecl zswap_(
    int* n,
    complex* zx,
    int* incx,
    complex* zy,
    int* incy
);

extern "C" void __cdecl zsymm_(
    const unsigned char* side,
    const unsigned char* uplo,
    int* m,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    complex* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl zsyr2k_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb,
    complex* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl zsyrk_(
    const unsigned char* uplo,
    const unsigned char* trans,
    int* n,
    int* k,
    complex* alpha,
    complex* a,
    int* lda,
    complex* beta,
    complex* c,
    int* ldc
);

extern "C" void __cdecl ztbmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    int* k,
    complex* a,
    int* lda,
    complex* x,
    int* incx
);

extern "C" void __cdecl ztbsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    int* k,
    complex* a,
    int* lda,
    complex* x,
    int* incx
);

extern "C" void __cdecl ztpmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    complex* ap,
    complex* x,
    int* incx
);

extern "C" void __cdecl ztpsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    complex* ap,
    complex* x,
    int* incx
);

extern "C" void __cdecl ztrmm_(
    const unsigned char* side,
    const unsigned char* uplo,
    const unsigned char* transa,
    const unsigned char* diag,
    int* m,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb
);

extern "C" void __cdecl ztrmv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    complex* a,
    int* lda,
    complex* x,
    int* incx
);

extern "C" void __cdecl ztrsm_(
    const unsigned char* side,
    const unsigned char* uplo,
    const unsigned char* transa,
    const unsigned char* diag,
    int* m,
    int* n,
    complex* alpha,
    complex* a,
    int* lda,
    complex* b,
    int* ldb
);

extern "C" void __cdecl ztrsv_(
    const unsigned char* uplo,
    const unsigned char* trans,
    const unsigned char* diag,
    int* n,
    complex* a,
    int* lda,
    complex* x,
    int* incx
);



extern "C" void __cdecl  dgesv_(int *n, int *nrhs, double *a, int 
	*lda, int *ipiv, double *b, int *ldb, int *info);

extern "C" void __cdecl zgesv_(int *n, int *nrhs, complex *a, 
	int *lda, int *ipiv, complex *b, int *ldb, int *
	info);

#endif
