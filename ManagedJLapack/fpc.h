#ifndef FPC_H_
#define FPC_H_

#include "fpc_types.h"
#include "stdio.h"

#define NS_FPC_BEGIN  namespace fpc{
#define NS_FPC_END };
#define NS_FPC_USE using namespace fpc


//Short summary of routine list of FPC
//convert(ps,pd) - template for convertion of fp number or one type at ps to other type at pd
//struct convert_array - contains methods for forward and backward array conversions
//smart_conver_array(ps,pd,size) - allows to make conversion, when source and destination
//		overlap, using appropriate combination of forward and backward conversion
//align(pt,size,delta) - returns pointer to memory, aligned to boundary, defined by template
//		parameter if alignment is possible, otherwise leaves pointer intact

//Data conversion classes to be used in calls 
//class create - used when algorithm produces some new data to buffer
//class replace - used when source data is replaced by result at same memory location
//class protect - used when some input data is destroyed by the algorithm (makes copy)
//class constant - used when data is guaranteed to be left intact
//class buffer - used for auxilary data buffer allocations


NS_FPC_BEGIN

template<typename _t>
struct constants
{
typedef _t _st;
static const _t _0;
static const _t _1;
static const _t _m1;
};

template<typename _t>
const _t constants<_t>::_0 = 0.;
template<typename _t>
const _t constants<_t>::_1 = 1.;
template<typename _t>
const _t constants<_t>::_m1 = -1.;

template<>
struct constants<int>
{	
typedef int _st;
static const int _0;
static const int _1;
static const int _m1;
};

template<>
struct constants<float80>
{	
typedef float80 _st;
static const float80 _0;
static const float80 _1;
static const float80 _m1;
};

template<>
struct constants<complex128>
{	
typedef double _st;
static const complex128 _0;
static const complex128 _1;
static const complex128 _m1;
};

template<>
struct constants<complex64>
{
typedef float _st;
static const complex64 _0;
static const complex64 _1;
static const complex64 _m1;
};

template<>
struct constants<complex160>
{	
typedef float80 _st;
static const complex160 _0;
static const complex160 _1;
static const complex160 _m1;
};

 
//---------------------------------------------------------------------------------------
//--- FPU control methods, needed for some algorithms, float to int conversion ----------
//---------------------------------------------------------------------------------------
 
inline int get_fpu_cw()
{
//int cw;
//	asm("fnstcw %0\n" : "=m" (cw) :  : "memory");
//	return cw;
	return -1;
};

inline void set_fpu_cw(int cw)
{
	//asm("fldcw %0\n" : : "m" (cw) : );
};

enum fpu_rnd {
	FPU_ROUND = 0, 
	FPU_FLOOR = 1, 
	FPU_CEIL = 2, 
	FPU_TRUNC = 3};

enum fpu_prec {
	FPU_SINGLE = 0, 
	FPU_DOUBLE = 2, 
	FPU_EXTENDED = 3};

template<fpu_rnd rnd = FPU_ROUND, fpu_prec prec = FPU_DOUBLE>
class set_fpu
{
static const int mask = ((prec&3)<<8)|((rnd&3)<<10);
public:
	set_fpu() 
	{
		cw = get_fpu_cw();
		set_fpu_cw( (cw&0xF0FF)|mask );
	};

	~set_fpu()
	{
		if (cw) set_fpu_cw(cw);
	};	

	void release() 
	{
		set_fpu_cw(cw); cw = 0;
	};

private:
	int cw;
};

template<typename _t>
inline void fpu_load(_t* x);

template<>
inline void fpu_load<float80>(float80* x)
{ 
	//asm("fldt (%0)\n": : "r"(x): "st(7)");
};

template<>
inline void fpu_load<float64>(float64* x)
{ 
	//asm("fldl (%0)\n": : "r"(x): "st(7)"); 
};

template<>
inline void fpu_load<double>(double* x)
{ 
	//asm("fldl (%0)\n": : "r"(x): "st(7)");
};

template<>
inline void fpu_load<float32>(float32* x)
{ 
	//asm("flds (%0)\n": : "r"(x): "st(7)"); 
};

template<>
inline void fpu_load<float>(float* x)
{ //asm("flds (%0)\n": : "r"(x): "st(7)"); 
};

template<typename _t>
inline void fpu_save(_t* x);

template<>
inline void fpu_save<float80>(float80* x)
{ //asm("fstpt (%0)\n": : "r"(x): "memory", "st"); 
};

template<>
inline void fpu_save<float64>(float64* x)
{ //asm("fstpl (%0)\n": : "r"(x): "memory", "st"); 
};

template<>
inline void fpu_save<double>(double* x)
{ //asm("fstpl (%0)\n": : "r"(x): "memory", "st"); 
};

template<>
inline void fpu_save<float32>(float32* x)
{ //asm("fstps (%0)\n": : "r"(x): "memory", "st"); 
};

template<>
inline void fpu_save<float>(float* x)
{ //asm("fstps (%0)\n": : "r"(x): "memory", "st"); 
};

//---------------------------------------------------------------------------------------
//--- Arbitrary floating point datatype conversion templates ----------------------------
//---------------------------------------------------------------------------------------

template<typename t_src, typename t_dst>
inline void convert(t_src* ps, t_dst* pd) 
{ 
	*pd = *ps; 
};

template<>
inline void convert(float80* ps, double* pd)
{
	/*asm
	(	
		"fldt (%0)\n"
		"fstpl (%1)\n"
		: 
		: "r" (ps), "r" (pd)  
		: "memory", "st(7)"
	);*/
};

template<>
inline void convert(double* ps, float80* pd)
{
	/*asm
	(	
		"fldl (%0)\n"
		"fstpt (%1)\n"
		: 
		: "r" (ps), "r" (pd)  
		: "memory", "st(7)"
	);*/
};

template<>
inline void convert(float80* ps, float* pd)
{
	/*asm
	(	
		"fldt (%0)\n"
		"fstps (%1)\n"
		: 
		: "r" (ps), "r" (pd)  
		: "memory", "st(7)"
	);*/
};

template<>
inline void convert(float* ps, float80* pd)
{
	/*asm
	(	
		"flds (%0)\n"
		"fstpt (%1)\n"
		: 
		: "r" (ps), "r" (pd)  
		: "memory", "st(7)"
	);*/
};
 
template<>
inline void convert(float80* ps, float64* pd)
{ convert(ps, reinterpret_cast<double*>(pd)); };
 
template<>
inline void convert(float80* ps, float32* pd)
{ convert(ps, reinterpret_cast<float*>(pd)); };

template<>
inline void convert(float64* ps, float80* pd)
{ convert(reinterpret_cast<double*>(ps), pd); };

template<>
inline void convert(float32* ps, float80* pd)
{ convert(reinterpret_cast<float*>(ps), pd); };

template<>
inline void convert(complex160* ps, complex128* pd)
{ 
	/*asm
	(	
		"fldt (%0)\n"
		"fldt 10(%0)\n"
		"fstpl 8(%1)\n"
		"fstpl (%1)\n"					
		: 
		: "r" (ps), "r" (pd)  
		: "memory", "st(7)", "st(6)"
	);*/
};

template<>
inline void convert(complex128* ps, complex160* pd)
{ 
	/*asm
	(	
		"fldl (%0)\n"
		"fldl 8(%0)\n"
		"fstpt 10(%1)\n"
		"fstpt (%1)\n"					
		: 
		: "r" (ps), "r" (pd)  
		: "memory", "st(7)", "st(6)"
	);	*/
};

template<typename t_src, typename t_dst>
struct convert_array
{
	static inline void forward(t_src* ps, t_dst* pd, unsigned long size)
	{		
		for (unsigned int i = 0;i < size;i++) convert(ps+i, pd+i);				
	};

	static inline void backward(t_src* ps, t_dst* pd, unsigned long size)
	{		
		for (unsigned int i = size;i > 0;i--) convert(ps+i-1, pd+i-1);
	};
};

template<typename _t>
struct convert_array<_t, _t>
{
	static inline void forward(_t* ps, _t* pd, unsigned long size)
	{		
		if (ps == pd) return;
		for (unsigned int i = 0;i < size;i++) convert(ps+i, pd+i);		
	};

	static inline void backward(_t* ps, _t* pd, unsigned long size)
	{		
		if (ps == pd) return;
		for (unsigned int i = size;i > 0;i--) convert(ps+i-1, pd+i-1);
	};
};

template<typename t_src, typename t_dst>
inline void smart_convert_array(t_src* ps, t_dst* pd, unsigned long size)
{	
static const int m = sizeof(t_src);
static const int n = sizeof(t_dst);
int h = (unsigned char*)(pd) - (unsigned char*)(ps);

	if (m == n)
	{
		if (h <= 0) convert_array<t_src, t_dst>::forward(ps, pd, size);		
		else convert_array<t_src, t_dst>::backward(ps, pd, size);		
		return;
	};
	
	if (m > n) 
	{
	int i = (h-1)/((m-n)?(m-n):1) ;
		if (i < 0) i = 0;
		if (i > (int)size) i = size;
		convert_array<t_src, t_dst>::forward(ps + i, pd + i, size - i);
		convert_array<t_src, t_dst>::backward(ps, pd, i);
	} 
	else
	{
	int i = (-h-1)/((n-m)?(n-m):1);
		if (i < 0) i = 0;
		if (i > (int)size) i = size;		
		convert_array<t_src, t_dst>::forward(ps, pd, i);			
		convert_array<t_src, t_dst>::backward(ps + i, pd + i, size - i);			
	};
}; 

template<typename t_src, typename t_dst, int log2_boundary>
inline t_dst* align(t_src* pt, unsigned int size, int delta)
{
static const int boundary = (1 << log2_boundary);
unsigned long npt = reinterpret_cast<unsigned long>(pt);
int need = ( (npt + boundary - 1) & (~(boundary - 1)) ) - npt;
	delta += (sizeof(t_src) - sizeof(t_dst)) * size;
	return reinterpret_cast<t_dst*>( (need > delta)?npt:(npt + need) );
};

//---------------------------------------------------------------------------------------
//--- Arbitrary float to integer and vice versa datatype conversion templates ----------------------------
//---------------------------------------------------------------------------------------

template<typename t_src, typename t_dst>
inline void _iconvert(t_src* ps, t_dst* pd)
{
	(*pd) = (*ps); 
};

template<>
inline void _iconvert(float80* ps, int* pd)
{
	/*asm
	(	
		"fldt (%0)\n"		
		"fistpl (%1)\n"		  
		: 
		: "r" (ps), "r" (pd)   
		: "memory", "st(7)"
	);	*/
};

template<>
inline void _iconvert(int* ps, float80* pd)
{
	/*asm
	(	
		"fildl (%0)\n"		
		"fstpt (%1)\n"		  
		: 
		: "r" (ps), "r" (pd)   
		: "memory", "st(7)"
	);	*/
};

template<>
inline void _iconvert(double* ps, int* pd)
{
	/*asm
	(	
		"fldl (%0)\n"		
		"fistpl (%1)\n"		  
		: 
		: "r" (ps), "r" (pd)   
		: "memory", "st(7)"
	);	*/
};

template<>
inline void _iconvert(int* ps, double* pd)
{
	/*asm
	(	
		"fildl (%0)\n"		
		"fstpl (%1)\n"		  
		: 
		: "r" (ps), "r" (pd)   
		: "memory", "st(7)"
	);	*/
};

template<>
inline void _iconvert(float* ps, int* pd)
{
	/*asm
	(	
		"flds (%0)\n"		
		"fistpl (%1)\n"		  
		: 
		: "r" (ps), "r" (pd)   
		: "memory", "st(7)"
	);	*/
};

template<>
inline void _iconvert(int* ps, float* pd)
{/*
	asm
	(	
		"fildl (%0)\n"		
		"fstps (%1)\n"		  
		: 
		: "r" (ps), "r" (pd)   
		: "memory", "st(7)"
	);	*/
};

template<typename t_src, typename t_dst>
inline void iconvert(t_src* ps, t_dst* pd)
{
int cw = get_fpu_cw();
	set_fpu_cw(cw | 0x0C00);
	_iconvert(ps, pd);
	set_fpu_cw(cw);
}; 

template<> inline void convert(float80* ps, int* pd){ iconvert(ps, pd); };
template<> inline void convert(int* ps, float80* pd){ iconvert(ps, pd); };
template<> inline void convert(double* ps, int* pd){ iconvert(ps, pd); };
template<> inline void convert(int* ps, double* pd){ iconvert(ps, pd); };
template<> inline void convert(float* ps, int* pd){ iconvert(ps, pd); };
template<> inline void convert(int* ps, float* pd){ iconvert(ps, pd); };
	

template<typename t_src, typename t_dst>
struct iconvert_array
{
	static inline void forward(t_src* ps, t_dst* pd, unsigned long size)
	{
	int cw = get_fpu_cw();
		set_fpu_cw(cw | 0x0C00);
		for (unsigned int i = 0;i < size;i++) _iconvert(ps+i, pd+i);
		set_fpu_cw(cw);		
	};

	static inline void backward(t_src* ps, t_dst* pd, unsigned long size)
	{		
	int cw = get_fpu_cw();
		set_fpu_cw(cw | 0x0C00);		
		for (unsigned int i = size;i > 0;i--) _iconvert(ps+i-1, pd+i-1);
		set_fpu_cw(cw);
	};
};

#define INT_C_A(s_type, r_type) \
template<> struct convert_array<s_type, r_type> { \
	static inline void forward(s_type* ps, r_type* pd, unsigned long size) \
	{ iconvert_array<s_type,r_type>::forward(ps, pd, size); }; \
	static inline void backward(s_type* ps, r_type* pd, unsigned long size) \
	{ iconvert_array<s_type,r_type>::backward(ps, pd, size); }; \
};
 
INT_C_A(float80, int)
INT_C_A(int, float80)
INT_C_A(double, int)
INT_C_A(int, double)
INT_C_A(float, int)
INT_C_A(int, float)	

//---------------------------------------------------------------------------------------
//--- Floating point datattype converstion classes --------------------------------------
//---------------------------------------------------------------------------------------

template<typename _t>
class helper
{
protected:
	static const int align_log = 3;
	static const int align_boundary = (1 << align_log);
	static const int align_extra = (align_boundary + sizeof(_t) - 1) / sizeof(_t);
	static const int align_delta = align_extra * sizeof(_t);
	
public:
	inline operator _t*() { return res; };
	inline _t* ptr() { return res; };	

protected:
	helper(){ released = false; };

	inline void alloc(unsigned long size)
	{
                //printf("fpc.h: helper() inline void alloc, size: %d\n",size + align_boundary);
		mem = new _t[size + align_boundary];
                res = align<_t, _t>(mem, size);
	};
	inline void free() { delete[] mem; };
	
	template<typename _t_src, typename _t_dst>
	inline _t_dst* align(_t_src* data, unsigned long size, unsigned long delta = align_delta)
	{ return fpc::align<_t_src, _t_dst, align_log>(data, size, delta); };

protected:
	_t* mem;
	_t* res;
	bool released;
};

template<typename t_src, typename t_res, bool safe = true>
class create : public helper<t_res>
{
public:
	static const bool expand = sizeof(t_src) < sizeof(t_res);

	inline create(t_src* buf, unsigned long size) throw()
	{

		this->res = 0;
		this->src = buf;
                this->size = size;

		if (src)  
		{
			if (expand) this->alloc(size);
                        else this->res = this->align<t_src, t_res>(src, size, 0);
		}
		else if (safe) {
                     this->alloc(size);
                }
	};
	
	inline ~create() throw() 
	{ release(); };

	inline void release() throw()
	{
		if (this->released) return;
		this->released = true;
		
		if (src)
		{		
			smart_convert_array(this->res, src, size);
			if (expand) this->free();
		}
		else if (safe) this->free();
	};

protected:
	t_src* src;
	unsigned long size;
};

template<typename t_src, typename t_res, bool safe = true>
class replace : public create<t_src, t_res, safe>
{
public:
	static const bool expand = sizeof(t_src) < sizeof(t_res);

	inline replace(t_src* data, t_src* buf, unsigned long size) 
		: create<t_src, t_res, safe>(buf, size)
	{
            //printf("fpc.h: class replace inline replace\n");
		if ((this->res) && (data)) smart_convert_array(data, this->res, size);				
	};
};

template<typename t_src, typename t_res, bool safe = true>
class protect : public replace<t_src, t_res, safe>
{
public:
	inline protect(t_src* data, unsigned long size) : 
	replace<t_src, t_res, safe>(data, 0, size){};
};
 
template<typename t_src, typename t_res, bool safe = true>
class constant : public helper<t_res>
{
public:
	inline constant(t_src* src, unsigned long size) throw()
	{						
		this->res = 0;
		if (src)
		{
			this->alloc(size); 
			smart_convert_array(src, this->res, size);
		}else if (safe) this->alloc(size);			
	};
	
	inline ~constant() throw()
	{ release(); };

	inline void release() throw()
	{
		if (this->released) return;
		this->released = true;
	 
		if (this->res) this->free(); 
	};
};

template<typename _t, bool safe>
class constant<_t, _t, safe> : public helper<_t>
{
public:
	inline constant(_t* src, unsigned long size) throw()
	{		
		this->src = src;		
		this->res = src;
		if ((!src) && (safe)) this->alloc(size);			
	};
	
	inline ~constant() throw()
	{ release(); };

	inline void release() throw()
	{
		if (this->released) return;
		this->released = true;
		 
		if ((!src) && (safe)) this->free(); 
	};

private:
	_t* src;
};

template<typename t_res>
class buffer : public constant<t_res, t_res, true>
{
public:
	inline buffer(unsigned long size) : constant<t_res,t_res,true>(0, size) {};
};


NS_FPC_END


#endif /*FPC_H_*/
