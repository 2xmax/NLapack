/* 
 * File:   jmatrix_ops.h
 * Author: morse
 *
 * In-place transposition of Non-Square matrix.
 * Input:
 *  _T* A - matrix to transpose
 *  int c - num of cols
 *  int r - num of rows
 *
 * Created on 17 Сентябрь 2009 г., 23:31
 */

#ifndef _TRANSP_H
#define	_TRANSP_H
#include "fpc.h"
NS_FPC_USE;

template<typename _T>
static inline void transp_NSQ(_T* A, int c, int r)
{
    // if matrix is one-dimentional - nothing to make
    if ((c==1) || (r==1)) return;

    int cr = c*r;
    int last = cr-1;
    // working bufer - speeds up calculations, but not necessary
    int bufl = (r+c)/2;
	
    bool* moved = new bool[bufl];
    for(int i=0;i<bufl;moved[i++]=0);
    // number of moved elements. is equal 2 because top-left and bottom-right are not needed to be moved
    int ncount = 2;
	
    //euqlid algorothm. GCD-1 equals to the number of elements that are not needed to be moved
    if ((r>3) && (c>3))
    {
            int ir2 = r-1;
            int ir1 = c-1;
            int ir0;
            do {
                    ir0= ir2 % ir1;
                    ir2= ir1;
                    ir1= ir0;
            } while (ir0 != 0);
            ncount += ir2 - 1;
    }

    int i = 0;
    int ic = last;
    int im = 0;

    int i1, i1c;
    int i2, i2c;
    _T S;
    _T SC;
	
    /* main loop. the idea is: we search for a not-rearranged chain
     * and rearrange it in loop to the moment when the number of rearranged
     * units is more or equal to m*n-1
     */
    do {
        // new chain search loop
        do {
            ic--;
            i++;
            if (i > ic) return; //error! should never occur
            im += r;
            if (im > last) im-=last;
            if (i == im) continue;
            if (i<bufl) {
                if (moved[i]==1) {
                    i2=0; //moved
                }
                else {
                    i2=i; //not moved
                }
            }
            else {
                i2 = im;
                while ((i2 > i)&&(i2<ic))
                {
                    i1=i2;
                    i2 = r*i1 % last;
                }
            }
        } while ( i2!=i && i2!=ic);

        i2 = i;
        S = A[i2];
        i2c = ic;
        SC = A[i2c];

        //chain rearrange loop
        do {
            i1 = i2;
            i1c = i2c;
            i2 = r*i1 % last;
            i2c = last - i2;
            if (i1 < bufl) moved[i1] = 1;
            if (i1c < bufl) moved[i1c] = 1;
            ncount+=2;

            A[i1] = A[i2];
            A[i1c] = A[i2c];
        } while ((i2!=i)&&(i2!=ic));

        if (i2==ic)
        {
            _T D = S;
            S = SC;
            SC = D;
        }
        A[i1] = S;
        A[i1c] = SC;
    } while (ncount < cr);
}

template <typename _t, typename _ct>
inline void xreal(int n, _ct* a, _t* re)
{ for (int i = 0;i < n;i++,a++,re++) *re = a->re; };

template <typename _t, typename _ct>
inline void ximag(int n, _ct* a, _t* im)
{ for (int i = 0;i < n;i++,a++,im++) *im = a->im; };

template <typename _t, typename _ct>
inline void xsplit(int n, _ct* a, _t* re, _t* im)
{ for (int i = 0;i < n;i++,a++,re++,im++){*re = a->re; *im = a->im;} };

template <typename _t, typename _ct>
inline void xcombine(int n, _t* re, _t* im, _ct* a)
{ for (int i = 0;i < n;i++,a++,re++,im++){a->re = *re; a->im = *im;} };

template <typename _t>
inline void xconj(int n, _t* a);

template <>
inline void xconj(int n, complex128fpc* a)
{ for (int i = 0;i < n;i++,a++){a->im.sign = ~a->im.sign;} };

template <>
inline void xconj(int n, complex64* a)
{ for (int i = 0;i < n;i++,a++){a->im = -a->im;} };

#endif	/* _TRANSP_H */

