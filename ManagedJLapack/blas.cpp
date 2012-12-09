#include "stdafx.h"
#include "blas_import.h"
#include "fpc.h"
#include "fpc_types.h"
#include "blas_import.h"
#include "blas.h"
#include "constants.h"
#include "templates.h"



/*
template<typename _st, typename _dt>
long __stdcall xcopy(int* n, _st* x, int* incx, _dt* y, int* incy)
{
	xcopy_(n,x,incx,y,incy);
	return 0;
}

long __stdcall scopy(int* n, float* x, int* incx, float* y, int* incy)
{ return xcopy<float,float>(n,x,incx,y,incy); }

long __stdcall dcopy(int* n, double* x, int* incx, double* y, int* incy)
{ return xcopy<double,double>(n,x,incx,y,incy); }
long __stdcall zcopy(int* n, complex* x, int* incx, complex* y, int* incy)
{ return xcopy<complex,complex>(n,x,incx,y,incy); }


template<typename _st, typename _dt>
long __stdcall xgemm(int ra, int ca, _st* a, int rb, int cb, _st* b, int trans, _st* c)
{
unsigned char const* opa = &_N;
unsigned char const* opb = &_N;
int tra = ra;
int tcb = cb;
int tcarb = ca;

 	if (trans&1)
	{
		tra = ca;
		tcarb = ra;
		opa = &_T;
	}

 	if (trans&2)
	{
		tcb = rb;
		opb = &_T;
	}

constant<_st, _dt>A(a, ra*ca);
constant<_st, _dt>B(b, rb*cb);
create<_st, _dt>C(c, tra*tcb);
	xgemm_(opa, opb, &tra, &tcb, &tcarb, &constants<_dt>::_1,
		(_dt*)A, &ra, (_dt*)B, &rb, &constants<_dt>::_0, (_dt*)C, &tra);

	return 0;
}
long __stdcall dgemm(int ra, int ca, double* a, int rb, int cb, double* b, int trans, double* c)
{ return xgemm<double,double>(ra,ca,a,rb,cb,b,trans,c); }
long __stdcall dxgemm(int ra, int ca, float80* a, int rb, int cb, float80* b, int trans, float80* c)
{ return xgemm<float80,double>(ra,ca,a,rb,cb,b,trans,c); }
long __stdcall zgemm(int ra, int ca, complex* a, int rb, int cb, complex* b, int trans, complex* c)
{ return xgemm<complex,complex>(ra,ca,a,rb,cb,b,trans,c); }
long __stdcall zxgemm(int ra, int ca, complex160* a, int rb, int cb, complex160* b, int trans, complex160* c)
{ return xgemm<complex160,complex>(ra,ca,a,rb,cb,b,trans,c); }

*/

void sgemm_test()
{
	sgemm_(NULL,NULL, NULL,NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}



template<typename _st, typename _dt>
long __stdcall xgemm_simple(int ra, int ca, _st* a, int rb, int cb, _st* b, _st* c)
{
	constant<_st, _dt>A(a, ra*ca);
	constant<_st, _dt>B(b, rb*cb);
	create<_st, _dt>C(c, ra*cb);
	xgemm_(&_N, &_N, &ra, &cb, &ca, &constants<_dt>::_1,
		(_dt*)A, &ra, (_dt*)B, &rb, &constants<_dt>::_0, (_dt*)C, &ra);
	return 0;
}

/*
long __stdcall sgemm_simple(int ra, int ca, float* a, int rb, int cb, float* b, float* c)
{ return xgemm_simple<float,float>(ra,ca,a,rb,cb,b,c); }
*/
long __stdcall dgemm_simple(int ra, int ca, double* a, int rb, int cb, double* b, double* c)
{	
	return xgemm_simple<double,double>(ra,ca,a,rb,cb,b,c);
}



//xgemm_simple<double,double>(ra,ca,a,rb,cb,b,c); }
/*long __stdcall dxgemm_simple(int ra, int ca, float80* a, int rb, int cb, float80* b, float80* c)
{ return xgemm_simple<float80,double>(ra,ca,a,rb,cb,b,c); }*/
long __stdcall zgemm_simple(int ra, int ca, complex* a, int rb, int cb, complex* b, complex* c)
{ 
	return xgemm_simple<complex,complex>(ra,ca,a,rb,cb,b,c); 
}

/*
long __stdcall zxgemm_simple(int ra, int ca, complex160* a, int rb, int cb, complex160* b, complex160* c)
{ return xgemm_simple<complex160,complex>(ra,ca,a,rb,cb,b,c); }

*/