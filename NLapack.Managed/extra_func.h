#include "fpc.h"
#include "fpc_types.h"
using namespace fpc;

inline void _buildevconj(int n, double* &ra, complex* &r)
{
double* rb = ra + n;
complex* rc = r + n;
	for (int k = 0;k < n;k++,r++,rc++,ra++,rb++)
	{
		r->re = *ra;
		r->im = *rb;
		rc->re = *ra;
		rc->im = -*rb;
	};
	ra = rb;
	r = rc;
};

inline void _buildevsafe(int n, double* &ra, complex* &r)
{
double* rb = ra + n;
complex* rc = r;
	for (int k = 0;k < n;k++,r++,ra++,rb++)
	{
		r->re = *ra;
		r->im = *rb;
	};
	ra = rb;
	for (int k = 0;k < n;k++,r++,rc++)
	{
		r->re = rc->re;
		r->im = -rc->im;
	};
};

inline void _buildev(int n, double* re, double* im, complex* v, complex* r, complex* l)
{
double* ra = (double*)(r) + n*n;
double* la = (double*)(l) + n*n;
	for (int i = 0;i < n;i++,re++,im++,v++)
	{
		v->re = *re;
		v->im = *im;
		if (v->im == 0.)
		{
			if (r) for (int k = 0;k < n;k++,r++,ra++) { r->re = *ra;r->im = 0; };
			if (l) for (int k = 0;k < n;k++,l++,la++) { l->re = *la;l->im = 0; };
		}
		else
		{
			if (i != (n-2))
			{
				if (r) _buildevconj(n, ra, r);
				if (l) _buildevconj(n, la, l);
			}
			else
			{
				if (r) _buildevsafe(n, ra, r);
				if (l) _buildevsafe(n, la, l);
			};

			i++;v++;re++;im++;
			v->re = *re;
			v->im = *im;
		};
	};
};
