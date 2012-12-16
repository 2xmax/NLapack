#ifndef JMATRIX_H_
#define JMATRIX_H_
#ifndef MIN
#define MIN(a,b) (((a) < (b))?(a):(b))
#endif

#ifndef MAX
#define MAX(a,b) (((a) > (b))?(a):(b))
#endif

#include <memory.h>
#include <stdexcept>
#include "fpc.h"
#include <stdio.h>

NS_FPC_USE;

#include "jmatrix_ops.h"

//#include <windows.h>

#define CHECK_BOTH 0
#define CHECK_COLS 1
#define CHECK_ROWS 2

template<typename _T>
struct SJMatrix
{
	int rows;
	int cols;
	_T* data;
};

template<typename _T>
class CJMatrix
{
	typedef SJMatrix<_T> TMatrix;
	static int _I1;
        //static void* lib_handle;

public:
	TMatrix* m;

        inline static void copyVector(int n, _T* s, int incs, _T* d, int incd)
        {
                for(int i=0;i < n;i++,s += incs,d += incd)
                    *d=*s;
        }

        static void _copyBlock(int i1, int i2, int s1, int s2, _T* s, int d1, int d2, _T* d)
	{
		for (int i = 0;i < i1;i++,s += s1,d += d1)
		{
			copyVector(i2, s, s2, d, d2);
		}
	}

        void boundsCheck(int r, int c, int ch)
        {
            if ((ch==0)||(ch==1)) { //COLS
		if (c < 0) {
                    char errMsg[50];
                    //sprintf(errMsg,"jmatrix: Incorrect value: cols = %d",c);
                    throw std::invalid_argument(errMsg);
                }
                if (c>=cols()) {
                    char errMsg[70];
                    //sprintf(errMsg,"jmatrix: Index value is out of bound: %d > %d",c,(cols())-1);
                    throw std::out_of_range(errMsg);
                }
            }
            if ((ch==0)||(ch==2)) { //ROWS
		if (r < 0) {
                    char errMsg[50];
                    //sprintf(errMsg,"jmatrix: Incorrect value: rows = %d",r);
                    throw std::invalid_argument(errMsg);
                }
                if (r>=rows()) {
                    char errMsg[70];
                    //sprintf(errMsg,"jmatrix: Index value is out of bound: %d > %d",r,(rows())-1);
                    throw std::out_of_range(errMsg);
                }
            }
        }

public:

	CJMatrix(int e, int obj) 
	{
            /*jclass cls = e->GetObjectClass(o);
            fid = e->GetFieldID(cls, "handle", "J");
            m = (TMatrix*) e->GetLongField(o, fid);*/
            /*
            if (CJMatrix::lib_handle == NULL) {
                printf("Try to load library!\n");
                //CJMatrix::lib_handle = LoadLibrary("C:\\katja\\javalapack_rep\\adapter_cula\\dist\\Release\\MinGW-Windows\\libadapter_cula.dll");
                CJMatrix::lib_handle = LoadLibrary("C:\\katja\\javalapack_rep\\lapack_netlib\\dist\\W\\F-Windows\\liblapack_netlib.dll");
                if (CJMatrix::lib_handle == NULL)
                    printf("Library not loaded! \n");
                else
                    printf("My Library loaded!! \n");
            }
             * */
            //printf("m=%d\n",m);
	}


	void takesString(const char *p)
	{
		printf("test\n");

	}

	void takesArray(int* p)
	{
		printf("test11\n");

	}

	void create(int rows, int cols)
	{
		destroy();
		if ((rows <= 0) || (cols <= 0)) {
                    char errMsg[50];
                    throw std::invalid_argument(errMsg);
                }
                    m = new TMatrix;
                    m->rows = rows;
                    m->cols = cols;
                    m->data = new _T[rows*cols];
	};

        void zero()
        {
	if (!m) return;
	memset(m->data, 0, rows() * cols() * sizeof(_T));
        };

        void diag(int n,_T* diag)
        {
            destroy();
            create(n,n);
            zero();
            _T* a=m->data;
            for (int i = 0;i < MIN(rows(),cols());i++,a+=cols()) a[i] = diag[i];

        }



        void transpose()
        {
            if(cols() == rows()) {
            int r=rows();
                for (int i=1;i<r;i++)
                    for (int j=0;j<i;j++) {
                        _T tmp = m->data[r*i+j];
                        m->data[r*i+j]=m->data[r*j+i];
                        m->data[r*j+i] = tmp;
                    }
            }
            else {
                transp_NSQ(m->data,cols(),rows());
                int i=cols();
                m->cols=rows();
                m->rows=i;
            }
        };

	void destroy()
	{
		/*if (!m) return;
		if (m->data) delete[] m->data;
		delete m;
                m=NULL;*/
		//jni e->SetLongField(o, fid, 0);
	};

	int rows(){ return m?m->rows:0; }
	int cols(){ return m?m->cols:0; }

	void getAt(int r, int c, _T& v)
        {
            boundsCheck(r,c,CHECK_BOTH);
            v = *(m->data + c*rows() + r);
	};

	void getRow(int r, _T* v)
        {
            boundsCheck(r,0,CHECK_ROWS);
            copyVector(cols(), m->data + r, rows(), v, 1);
	}

	bool getSubRow(int r, int c, int nc, _T* v)
	{
            boundsCheck(r,c,CHECK_BOTH);
            boundsCheck(r,c+nc-1,CHECK_COLS);
            copyVector(nc, m->data + c * rows() + r, rows(), v, 1);
	}

	void getColumn(int c, _T* v)
{
            boundsCheck(0,c,CHECK_COLS);
            copyVector(rows(), m->data + c*rows(), 1, v, 1);
	}

	void getSubColumn(int r, int c, int nr, _T* v)
	{
            boundsCheck(r,c,CHECK_BOTH);
            boundsCheck(r+nr-1,c,CHECK_ROWS);
            copyVector(nr, m->data + c*rows() + r, 1, v, 1);
	}

	void getSubMatrix(int r, int c, int nr, int nc, _T* v, int transp)
	{
            boundsCheck(r,c,CHECK_BOTH);
            boundsCheck(r+nr-1,c+nc-1,CHECK_BOTH);
            if (!transp) _copyBlock(nc, nr, rows(), 1, m->data + c*rows() + r, nr, 1, v);
            else _copyBlock(nc, nr, rows(), 1, m->data + c*rows() + r, 1, nc, v);
	}

	void setAt(int r, int c, _T& v)
	{
            boundsCheck(r,c,CHECK_BOTH);
            *(m->data + c*rows() + r) = v;
	};

	void setRow(int r, _T* v)
	{
            boundsCheck(r,0,CHECK_ROWS);
            copyVector(cols(), v, 1, m->data + r, rows());
	}

	void setSubRow(int r, int c, int nc, _T* v)
	{
            boundsCheck(r,c,CHECK_BOTH);
            boundsCheck(r,c+nc-1,CHECK_COLS);
            copyVector(nc, v, 1, m->data + c * rows() + r, rows());
	}

	bool setColumn(int c, _T* v)
	{
            boundsCheck(0,c,CHECK_COLS);
            copyVector(rows(), v, 1, m->data + c*rows(), 1);
            return true;
	}

	bool setSubColumn(int r, int c, int nr, _T* v)
	{
            boundsCheck(r,c,CHECK_BOTH);
            boundsCheck(r+nr-1,c,CHECK_ROWS);
            copyVector(nr, v, 1, m->data + c*rows() + r, 1);
            return true;
	}

	bool setSubMatrix(int r, int c, int nr, int nc, _T* v, int transp)
	{
            checkSubMatrix(r,c,nr,nc);
            if (!transp) _copyBlock(nc, nr, nr, 1, v, rows(), 1, m->data + c*rows() + r);
            else _copyBlock(nc, nr, 1, nc, v, rows(), 1, m->data + c*rows() + r);
            return true;
	}

        void copyBlock(int nr, int nc, int nrs, int ncs, int nrd, int ncd, CJMatrix<_T> dest)
        {
            checkSubMatrix(nrs,ncs,nr,nc);
            dest.checkSubMatrix(nrd,ncd,nr,nc);
            _copyBlock(nc,nr,rows(),1,m->data + ncs*rows() + nrs,dest.rows(),1,dest.data()+ncd*dest.rows()+nrd);
        }

        void checkSubMatrix(int r, int c, int nr, int nc)
        {
            boundsCheck(r,c,CHECK_BOTH);
            boundsCheck(r+nr-1,c+nc-1,CHECK_BOTH);
        }

	bool exist() { return m != NULL; }
	_T*& data() { return m->data; }
};

template<typename _T>
int CJMatrix<_T>::_I1 = 1;

//template<typename _T>
//void* CJMatrix<_T>::lib_handle = NULL;

typedef CJMatrix<double> CJRMatrix;
typedef CJMatrix<float> CJSMatrix;
typedef CJMatrix<int> CJIMatrix;
typedef CJMatrix<complex128> CJCMatrix;
typedef CJMatrix<complex64> CJC64Matrix;
#endif /*JMATRIX_H_*/
