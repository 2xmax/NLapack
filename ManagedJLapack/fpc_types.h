#ifndef FPC_TYPES_H_
#define FPC_TYPES_H_

namespace fpc{

//---------------------------------------------------------------------------------------
//--- Floating point types definitions --------------------------------------------------
//---------------------------------------------------------------------------------------

#pragma pack(push, 1)
struct float80
{
	unsigned long manl : 32;
	unsigned long manh : 32;
	unsigned long exp : 15;
	unsigned long sign : 1; 
};

struct complex160 
{
	float80 re;
	float80 im;
};

struct float64
{	
	unsigned long manl : 20;
	unsigned long manh : 32;
	unsigned long exp : 11;	
	unsigned long sign : 1;	
};

struct complex64
{
	float re;
	float im;
};

struct complex128
{
	double re;
	double im;
};

typedef complex128 complex;

struct complex128fpc
{
	float64 re;
	float64 im;
};

struct float32
{
	unsigned long man : 23;	
	unsigned long exp : 8;
	unsigned long sign : 1;
};

#pragma pack(pop)

}; //namespace fpc

#endif
