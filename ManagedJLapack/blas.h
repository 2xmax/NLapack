#ifndef BLAS_H_
#define BLAS_H_

#ifndef __declspec
#define __declspec(dllexport) 
#endif

#include "fpc_types.h"
using fpc::float80;
using fpc::complex160;

extern "C" long __declspec(dllexport) __stdcall scopy(int* n, float* x, int* incx, float* y, int* incy);
extern "C" long __declspec(dllexport) __stdcall dcopy(int* n, double* x, int* incx, double* y, int* incy);
extern "C" long __declspec(dllexport) __stdcall zcopy(int* n, complex* x, int* incx, complex* y, int* incy);

extern "C" long __declspec(dllexport) __stdcall dgemm(int ra, int ca, double* a, int rb, int cb, double* b, int trans, double* c);
extern "C" long __declspec(dllexport) __stdcall dxgemm(int ra, int ca, float80* a, int rb, int cb, float80* b, int trans, float80* c);
extern "C" long __declspec(dllexport) __stdcall zgemm(int ra, int ca, complex* a, int rb, int cb, complex* b, int trans, complex* c);
extern "C" long __declspec(dllexport) __stdcall zxgemm(int ra, int ca, complex160* a, int rb, int cb, complex160* b, int trans, complex160* c);

extern "C" long __declspec(dllexport) __stdcall sgemm_simple(int ra, int ca, float* a, int rb, int cb, float* b, float* c);
long __stdcall dgemm_simple(int ra, int ca, double* a, int rb, int cb, double* b, double* c);

extern "C" long __declspec(dllexport) __stdcall dxgemm_simple(int ra, int ca, float80* a, int rb, int cb, float80* b, float80* c);
long __stdcall zgemm_simple(int ra, int ca, complex* a, int rb, int cb, complex* b, complex* c);
extern "C" long __declspec(dllexport) __stdcall zxgemm_simple(int ra, int ca, complex160* a, int rb, int cb, complex160* b, complex160* c);

#endif /*BLAS_H_*/
