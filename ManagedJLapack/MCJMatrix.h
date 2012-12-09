// ManagedJLapack.h


#pragma once
#include "JMatrix.h"
#include "JLapack.h"
#include "lapack.h"

#include "stdafx.h"

using namespace System;


namespace MLapack {


	public __gc class MCJRMatrix 
	{
	public:

		MCJRMatrix::MCJRMatrix()
		{
			m_pCJRMatrix = new CJRMatrix(NULL, NULL);
		}

		MCJRMatrix::MCJRMatrix(int rows, int cols){
			allocate(rows, cols);
		}

		void allocate(int rows, int cols)
		{
			if(m_pCJRMatrix == NULL)
				m_pCJRMatrix = new CJRMatrix(NULL, NULL);

			m_pCJRMatrix->create(rows, cols);
		}

		void setAt(int row, int col, double v)
		{
			m_pCJRMatrix->setAt(row, col, v);			
		}

		double getAt(int row, int col)
		{
			double value;
			m_pCJRMatrix->getAt(row, col, value);
			return value;
		}

		//todo:remove
		double getRow(int r) __gc[]
		{
			double* value = new double;
			m_pCJRMatrix->getRow(r, value);

			//todo:
			int size = sizeof(value) - 1;
			Double ret[] = new Double[size];

			for(int i=0;i<size;i++)
				ret[i] = value[i];

			return ret;
		}

		int rows(){return m_pCJRMatrix->rows();}

		int cols(){return m_pCJRMatrix->cols();}

		void transpose()
		{
			m_pCJRMatrix->transpose();
		}

		
		void zero()
		{
			m_pCJRMatrix->zero();
		}

		void destory()
		{
			m_pCJRMatrix->destroy();
		}

	public:
		CJRMatrix __nogc* m_pCJRMatrix;
	};
	

	public __gc class MCJCMatrix 
	{
	public:
		MCJCMatrix::MCJCMatrix(){
			m_pCJRMatrix = new CJCMatrix(NULL, NULL);
		}

		MCJCMatrix::MCJCMatrix(int rows, int cols){
			allocate(rows, cols);
		}

		void allocate(int rows, int cols)
		{
			m_pCJRMatrix = new CJCMatrix(NULL, NULL);
			m_pCJRMatrix->create(rows, cols);
		}

		void setAt(int row, int col, double re, double im)
		{
			complex v;
			v.re = re;
			v.im = im;
			m_pCJRMatrix->setAt(row, col, v);			
		}
		
		double getAt(int row, int col)
		{
			complex value;
			m_pCJRMatrix->getAt(row, col, value);			
			return value.re;
		}

		//todo:
		double getAtIm(int row, int col)
		{
			complex value;
			m_pCJRMatrix->getAt(row, col, value);			
			return value.im;
		}

		__value struct ExampleValueType
		{
			double im;
		};

		//todo:remove
		double getRow(int r) __gc[]
		{
			/*double* value = new double;
			m_pCJRMatrix->getRow(r, value);

			//todo:
			int size = sizeof(value) - 1;
			Double ret[] = new Double[size];

			for(int i=0;i<size;i++)
				ret[i] = value[i];

			return ret;*/
			return 0;
		}

		int rows(){return m_pCJRMatrix->rows();}

		int cols(){return m_pCJRMatrix->cols();}

		void transpose()
		{
			m_pCJRMatrix->transpose();
		}

		void zero()
		{
			m_pCJRMatrix->zero();
		}

		void destory()
		{
			m_pCJRMatrix->destroy();
		}

	public://todo:make protected
		CJCMatrix __nogc* m_pCJRMatrix;
	};
	
	
	public __gc class MCJIMatrix 
	{
	public:
		MCJIMatrix::MCJIMatrix(){
			m_pCJRMatrix = new CJIMatrix(NULL, NULL);
		}

		MCJIMatrix::MCJIMatrix(int rows, int cols){
			allocate(rows, cols);
		}

		void allocate(int rows, int cols)
		{
			m_pCJRMatrix = new CJIMatrix(NULL, NULL);
			m_pCJRMatrix->create(rows, cols);
		}

		void setAt(int row, int col, int value)
		{
			m_pCJRMatrix->setAt(row, col, value);			
		}
		
		int getAt(int row, int col)
		{
			int value;
			m_pCJRMatrix->getAt(row, col, value);			
			return value;
		}

		//todo:remove
		double getRow(int r) __gc[]
		{
			/*double* value = new double;
			m_pCJRMatrix->getRow(r, value);

			//todo:
			int size = sizeof(value) - 1;
			Double ret[] = new Double[size];

			for(int i=0;i<size;i++)
				ret[i] = value[i];

			return ret;*/
			return 0;
		}

		int rows(){return m_pCJRMatrix->rows();}

		int cols(){return m_pCJRMatrix->cols();}

		void transpose()
		{
			m_pCJRMatrix->transpose();
		}

		void zero()
		{
			m_pCJRMatrix->zero();
		}

		void destory()
		{
			m_pCJRMatrix->destroy();
		}

	public://todo:make protected
		CJIMatrix __nogc* m_pCJRMatrix;
	};
	

	
	
	public __gc class MLapackLib 
	{
	public:
		
		/// <summary>
        /// a^-1 = c
        /// </summary>
		void inv(MCJRMatrix* a, MCJRMatrix* c)
		{
			CJRMatrix  A = *(a->m_pCJRMatrix);
			c->allocate((*(a->m_pCJRMatrix)).rows(), (*(a->m_pCJRMatrix)).cols());	
			
			lapack_invD(A, *(c->m_pCJRMatrix));
		}

		void inv(MCJCMatrix* a, MCJCMatrix* c)
		{
			
		}

		/// <summary>
        /// c = a * b
        /// </summary>
		void multiply(MCJRMatrix* a, MCJRMatrix* b, MCJRMatrix* c)
		{						
			c->allocate((*(a->m_pCJRMatrix)).rows(), (*(b->m_pCJRMatrix)).cols());			
			lapack_multiplyD(*(a->m_pCJRMatrix), *(b->m_pCJRMatrix), *(c->m_pCJRMatrix));
		}

		/// <summary>
        /// c = a * b
        /// </summary>
		void multiply(MCJCMatrix* a, MCJCMatrix* b, MCJCMatrix* c)
		{
			//not implemented yet
			//c->allocate((*(a->m_pCJRMatrix)).rows(), (*(b->m_pCJRMatrix)).cols());			
			lapack_multiplyZ(*(a->m_pCJRMatrix), *(b->m_pCJRMatrix), *(c->m_pCJRMatrix));
		}

		/// <summary>
        /// a * x = b, x=?
        /// </summary>
		void solveSLE(MCJRMatrix* a, MCJRMatrix* b, MCJRMatrix* x)
		{			
			int ret = lapack_solveSLED(*(a->m_pCJRMatrix), *(b->m_pCJRMatrix), *(x->m_pCJRMatrix));
		}


		/// <summary>
        /// a * x = b, x=?
        /// </summary>
		void solveSLE(MCJCMatrix* a, MCJCMatrix* b, MCJCMatrix* x)
		{			
			int ret = lapack_solveSLEZ(*(a->m_pCJRMatrix), *(b->m_pCJRMatrix), *(x->m_pCJRMatrix));
		}

		/*
		028: *     DLANGE = ( max(abs(A(i,j))), NORM = 'M' or 'm'
029: *              (
030: *              ( norm1(A),         NORM = '1', 'O' or 'o'
031: *              (
032: *              ( normI(A),         NORM = 'I' or 'i'
033: *              (
034: *              ( normF(A),         NORM = 'F', 'f', 'E' or 'e'
035: *
036: *  where  norm1  denotes the  one norm of a matrix (maximum column sum),
037: *  normI  denotes the  infinity norm  of a matrix  (maximum row sum) and
038: *  normF  denotes the  Frobenius norm of a matrix (square root of sum of
039: *  squares).  Note that  max(abs(A(i,j)))  is not a consistent matrix norm.*/
		double norm(char norm, MCJRMatrix* a)
		{
			return lapack_matrixNorm(norm, *(a->m_pCJRMatrix));
		}

		/// <summary>
        /// p - pivot matrix,
		/// p * a = l * u
        /// </summary>
		void LUPDecomposition(MCJRMatrix* a, MCJRMatrix* p, MCJRMatrix* l, MCJRMatrix* u)
		{
			lapack_LUPDecompositionD(*(a->m_pCJRMatrix), *(p->m_pCJRMatrix), *(l->m_pCJRMatrix), *(u->m_pCJRMatrix));
		}

		/// <summary>
		///
        /// </summary>
		void eigenVals(MCJRMatrix* a, MCJCMatrix* w, MCJCMatrix* vl, MCJCMatrix* vr)
		{
			lapack_geevD(*(a->m_pCJRMatrix), *(w->m_pCJRMatrix), *(vl->m_pCJRMatrix), *(vr->m_pCJRMatrix));
		}
		
		/// <summary>
		///
        /// </summary>
		void chol(MCJRMatrix* a, MCJRMatrix* r)
		{
			r->m_pCJRMatrix =  new CJRMatrix(NULL, NULL);
			lapack_CholD(*(a->m_pCJRMatrix), *(r->m_pCJRMatrix));
		}

		void SVDDecomposition(MCJRMatrix* a, MCJRMatrix* s, MCJRMatrix* u, MCJRMatrix* vt)
		{
			lapack_SVDDecompositionD(*(a->m_pCJRMatrix), *(s->m_pCJRMatrix), *(u->m_pCJRMatrix), *(vt->m_pCJRMatrix));
		}

		void SVDDecomposition(MCJCMatrix* a, MCJRMatrix* s, MCJCMatrix* u, MCJCMatrix* vt)
		{
			lapack_SVDDecompositionZ(*(a->m_pCJRMatrix), *(s->m_pCJRMatrix), *(u->m_pCJRMatrix), *(vt->m_pCJRMatrix));
		}

		double matrixRConditionNumber(char normType, MCJRMatrix* a)
		{
			double anorm = norm(normType, a);

			return lapack_matrixRConditionNumber(normType, *(a->m_pCJRMatrix), anorm);
		}

		/*
		025: *  IDIST   (input) INTEGER
026: *          Specifies the distribution of the random numbers:
027: *          = 1:  uniform (0,1)
028: *          = 2:  uniform (-1,1)
029: *          = 3:  normal (0,1)
030: *
031: *  ISEED   (input/output) INTEGER array, dimension (4)
032: *          On entry, the seed of the random number generator; the array
033: *          elements must be between 0 and 4095, and ISEED(4) must be
034: *          odd.
035: *          On exit, the seed is updated.
036: *
037: *  N       (input) INTEGER
038: *          The number of random numbers to be generated.
039: *
040: *  X       (output) DOUBLE PRECISION array, dimension (N)
041: *          The generated random numbers.
*/
		MCJRMatrix* randomMatrix(int idist, MCJIMatrix* iseed, int m, int n)
		{
			MCJRMatrix* result = new MCJRMatrix(m, n);		
			lapack_dlarnv(idist, *(iseed->m_pCJRMatrix), *(result->m_pCJRMatrix));			
			return result;
		}

		void eigenValsX(int balanc, MCJRMatrix* a, MCJCMatrix* w, MCJCMatrix* vl, MCJCMatrix* vr, MCJRMatrix* rconde, MCJRMatrix* rcondv)
		{
			lapack_geevxD(balanc, *(a->m_pCJRMatrix), *(w->m_pCJRMatrix), *(vl->m_pCJRMatrix), *(vr->m_pCJRMatrix), *(rconde->m_pCJRMatrix), *(rcondv->m_pCJRMatrix));

		}

	private:
		CJRMatrix __nogc* m_pCJRMatrix;
	};
	
}
