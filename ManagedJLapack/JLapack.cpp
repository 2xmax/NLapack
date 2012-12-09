#include "Stdafx.h"
#include "JMatrix.h"
#include "lapack.h"
#include "blas.h"


#ifndef MIN
#define MIN(a,b) (((a) < (b))?(a):(b))
#endif

#if OS == 1
#include <windows.h>
#include "dynamic.h"
#include "io.h"
#else
//todo: #include <dlfcn.h>
#endif

/*int* conv_jint(jint* arr, int ilen) {
    int* iarr = (int*)malloc(ilen*sizeof(int));
    int i = 0;
    for(i=0;i<ilen;i++)
        iarr[i] = (int) arr[i];
    return iarr;
}*/

//  BALASHOVA

/*
void get_java_fields(JNIEnv *e, jobject obj, void** dllptr, int* libflag) {
    *libflag = e->GetIntField(obj, e->GetFieldID(e->GetObjectClass(obj),"libflag","I"));
    *dllptr = (void*) e->GetIntField(obj, e->GetFieldID(e->GetObjectClass(obj),"dllprt","L"));
}
*/
/*

JNIEXPORT void JNICALL Java_spbu_linalg_lapack_JLapack_freelibs(JNIEnv *env, jobject obj) {
long ldllptr = (long) env->GetLongField(obj, env->GetFieldID(env->GetObjectClass(obj),"dllptr","J"));
if (ldllptr == 0)
    return;
#if OS == 1
    HINSTANCE w_dllptr = (HINSTANCE) ldllptr;
    FreeLibrary(w_dllptr);
#else
    void* w_dllptr = (void*) ldllptr;
    dlclose(w_dllptr);
#endif
}*/

int lapack_CholD(CJRMatrix a, CJRMatrix & r)
{
	r.create(a.rows(), a.cols());
	int rows = a.rows();
    return dpotrf(&rows, a.data(), r.data());
}
/*
JNIEXPORT jint JNICALL Java_spbu_linalg_lapack_JLapack__1CholZ
 (JNIEnv *e, jobject obj, jobject a, jobject r)
{
	CJCMatrix A(e, a);
        CJCMatrix R(e, r);
        R.create(A.rows(), A.cols());
	int rows = A.rows();
	return zpotrf(&rows, A.data(), R.data(), e, obj);
}*/

/*JNIEXPORT jint JNICALL Java_spbu_linalg_lapack_JLapack__1invD
(JNIEnv *e, jobject obj, jobject a, jobject r)*/

void lapack_invD(CJRMatrix A, CJRMatrix & b)
{
	//CJRMatrix A(e, a);
	//CJRMatrix R(e, r);
	int n = A.cols();
	
	b.create(n, n);

	A.copyBlock(A.rows(),A.cols(),0,0,0,0,b);

	int lw = n;
	double* work = new double[lw];
	int ierr = 0;
	dgetrif(&n, b.data(), work, &lw, &ierr);
    delete work;
    /*return ierr;*/
}
/*
JNIEXPORT jint JNICALL Java_spbu_linalg_lapack_JLapack__1invZ
(JNIEnv *e, jobject obj, jobject a, jobject r)
{
	CJCMatrix A(e, a);
	CJCMatrix R(e, r);
	int n = A.cols();
	R.create(n,n);
        A.copyBlock(A.rows(),A.cols(),0,0,0,0,R);
	//R.copyBlock(n,n,n,1,A.data(),n,1,R.data());


	int	lw = n;
	complex* work = new complex[lw];
	int ierr = 0;
	zgetrif(&n, R.data(), work, &lw, &ierr, e, obj);
	delete work;
    return ierr;
}

// -- BALASHOVA

// ZYKOVA
*/
long lapack_geevxD(int balanc, CJRMatrix a, CJCMatrix & w, CJCMatrix & vl, CJCMatrix & vr, CJRMatrix & rconde, CJRMatrix & rcondv)
{
  w.create(a.rows(), 1);
  vl.create(a.rows(), a.cols());
  vr.create(a.rows(), a.cols());
  
  rconde.create(a.rows() ,1);  
  rcondv.create(a.rows(), 1);
  return dgeevx(balanc, a.cols(), a.data(), w.data(), vl.data(), vr.data(), rconde.data(), rcondv.data());
}
/*

JNIEXPORT jlong JNICALL Java_spbu_linalg_lapack_JLapack__1geevxZ
  (JNIEnv *e, jobject obj, jint balanc, jobject a, jobject w, jobject vl, jobject vr, jobject rconde, jobject rcondv)
{
  CJCMatrix A(e,a);
  CJCMatrix W(e,w);
  W.create(A.rows(),1);
  CJCMatrix VL(e,vl);
  VL.create(A.rows(),A.cols());
  CJCMatrix VR(e,vr);
  VR.create(A.rows(),A.cols());
  CJRMatrix RE (e,rconde);
  RE.create(A.rows(),1);
  CJRMatrix RV (e,rcondv);
  RV.create(A.rows(),1);
  return zgeevx(balanc, A.cols(), A.data(), W.data(), VL.data(), VR.data(), RE.data(), RV.data(), e, obj);
}
*/
long lapack_geevD(CJRMatrix a, CJCMatrix & w,  CJCMatrix & vl, CJCMatrix & vr)
{
	  w.create(a.rows(),1);
	  vl.create(a.rows(),a.cols());
	  vr.create(a.rows(),a.cols());
	  return dgeev(a.cols(), a.data(), w.data(), vl.data(), vr.data());	  
}

/*

JNIEXPORT jlong JNICALL Java_spbu_linalg_lapack_JLapack__1geevZ
  (JNIEnv *e, jobject obj, jobject a, jobject w, jobject vl, jobject vr)
{
  CJCMatrix	A(e,a);
  CJCMatrix W(e,w);
  W.create(A.rows(),1);
  CJCMatrix VL(e,vl);
  VL.create(A.rows(),A.cols());
  CJCMatrix VR(e,vr);
  VR.create(A.rows(),A.cols());
  return zgeev(A.cols(),A.data(),W.data(),VL.data(),VR.data(), e, obj);
}*/


// -- ZYKOVA

/*
 * Class:     spbu_linalg_lapack_JLapack
 * Method:    _multiplyD
 * Signature: (Lspbu/lapack/JRealMatrix;Lspbu/lapack/JRealMatrix;Lspbu/lapack/JRealMatrix;)I
 */

/*
JNIEXPORT jint JNICALL Java_spbu_linalg_lapack_JLapack__1multiplyS
  (JNIEnv *e, jobject obj, jobject a, jobject b, jobject c)
{
	//printf("mult");
CJSMatrix A(e, a);
CJSMatrix B(e, b);
CJSMatrix C(e, c);
//printf("bef cr");
	C.create(A.rows(), B.cols());
	//printf("aft cr");
	sgemm_simple(A.rows(), A.cols(), A.data(), B.rows(), B.cols(), B.data(), C.data());
	return 0;
};*/


int lapack_multiplyD(CJRMatrix a, CJRMatrix b, CJRMatrix &c)
{
	//c.create(2, 2);
	dgemm_simple(a.rows(), a.cols(), a.data(), b.rows(), b.cols(), b.data(), c.data());
	return 0;
};

int lapack_multiplyZ(CJCMatrix a, CJCMatrix b, CJCMatrix &c)
{
	c.create(a.rows(), b.cols());
	zgemm_simple(a.rows(), a.cols(), a.data(), b.rows(), b.cols(), b.data(), c.data());
	return 0;
}

int lapack_LUPDecompositionD(CJRMatrix a, CJRMatrix p, CJRMatrix & l, CJRMatrix & u)
{	
	p.create(a.rows(), a.rows());
	l.create(a.rows(), MIN(a.rows(), a.cols()));
	u.create(MIN(a.rows(), a.cols()), a.cols());
	return dgetrf_simple(a.rows(), a.cols(), a.data(), p.data(), l.data(), u.data());
};
/*
JNIEXPORT jint JNICALL Java_spbu_linalg_lapack_JLapack__1LUPDecompositionZ
    (JNIEnv *e, jobject obj, jobject a, jobject p, jobject l, jobject u)
{
	CJCMatrix A(e, a);
	CJCMatrix P(e, p);
	CJCMatrix L(e, l);
	CJCMatrix U(e, u);
	P.create(A.rows(), A.rows());
	L.create(A.rows(), MIN(A.rows(), A.cols()));
	U.create(MIN(A.rows(), A.cols()), A.cols());
	return zgetrf_simple(A.rows(), A.cols(), A.data(), P.data(), L.data(), U.data(), e, obj);

}*/


int lapack_SVDDecompositionD(CJRMatrix a, CJRMatrix & s, CJRMatrix & u, CJRMatrix & vt)
{
	u.create(a.rows(), a.rows());
	s.create(MIN(a.rows(), a.cols()), 1);
	vt.create(a.cols(), a.cols());
	return dgesvd(a.rows(), a.cols(), a.data(), s.data(), u.data(), vt.data());
};

/*
/*
JNIEXPORT jint JNICALL Java_spbu_linalg_lapack_JLapack__1SVDDecompositionS
  (JNIEnv *e, jobject obj, jobject a, jobject s , jobject u, jobject vt)
{
CJSMatrix A(e, a);
CJSMatrix U(e, u);
CJSMatrix S(e, s);
CJSMatrix Vt(e, vt);
	U.create(A.rows(), A.rows());
	S.create(MIN(A.rows(), A.cols()), 1);
	Vt.create(A.cols(), A.cols());
        printf("spbu_linalg_lapack_JLapack.cpp: Java_spbu_linalg_lapack_JLapack__1SVDDecompositionS\n");
        printf("A.rows()=%d A.cols()=%d\n",A.rows(),A.cols());
        int tmp_r=A.rows();
        int tmp_c=A.cols();
        printf("A.data[2]=%e\n", (A.data())[2]);
	return sgesvd(tmp_r, tmp_c, A.data(), S.data(), U.data(), Vt.data(), e, obj);
};

JNIEXPORT jint JNICALL Java_spbu_linalg_lapack_JLapack__1SVDDecompositionC
  (JNIEnv *e, jobject obj, jobject a, jobject s , jobject u, jobject vt)
{
CJC64Matrix A(e, a);
CJC64Matrix U(e, u);
CJSMatrix S(e, s);
CJC64Matrix Vt(e, vt);
	U.create(A.rows(), A.rows());
	S.create(MIN(A.rows(), A.cols()), 1);
	Vt.create(A.cols(), A.cols());
	return cgesvd(A.rows(), A.cols(), A.data(), S.data(), U.data(), Vt.data(), e, obj);
};

*/
int lapack_SVDDecompositionZ(CJCMatrix a, CJRMatrix & s, CJCMatrix & u, CJCMatrix & vt)
{
	u.create(a.rows(), a.rows());
	s.create(MIN(a.rows(), a.cols()), 1);
	vt.create(a.cols(), a.cols());
	return zgesvd(a.rows(), a.cols(), a.data(), s.data(), u.data(), vt.data());
};


int lapack_solveSLED(CJRMatrix A, CJRMatrix B, CJRMatrix & X)
{
	X.create(B.rows(), B.cols());
	return dgesv(A.rows(), A.data(), B.cols(), B.data(), X.data());
};

int lapack_solveSLEZ  (CJCMatrix A, CJCMatrix B, CJCMatrix & X)
{
	X.create(B.rows(), B.cols());
	return zgesv(A.rows(), A.data(), B.cols(), B.data(), X.data());
};

void lapack_dlarnv(int idist, CJIMatrix & iseed, CJRMatrix & x) {
	dlarnv(idist, iseed.data(), x.rows()*x.cols(), x.data());
}

double lapack_matrixNorm(char norm, CJRMatrix a){
	return dlange(norm, a.rows(), a.cols(), a.data());
}


double lapack_matrixRConditionNumber(char norm, CJRMatrix a, double anorm){
	int info = -1;
	double rcond = 0.0;
	info = dgecon(norm, a.rows(), a.data(), anorm, &rcond);
	return rcond;
}
