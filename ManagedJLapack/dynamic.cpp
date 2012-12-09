#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "stringfwd.h"
#include "fpc.h"
#include "fpc_types.h"
using namespace std;
#if OS == 1
#include <windows.h>
#include "dynamic.h"
#include "io.h"
#include "Stdafx.h"
#include "math.h"


//using namespace fpc;
/*
#define fcall1 \
    long ldllptr = (long) env->GetLongField(obj, env->GetFieldID(env->GetObjectClass(obj),"dllptr","J"));\
    HINSTANCE w_dllptr = (HINSTANCE) ldllptr;\
    printf("point1, ldllptr=%d\n",ldllptr);\
    if (ldllptr == 0)\
        w_dllptr = loadLib(env, obj);\
    t_fptr_ p_fptr_;\
    int tried_twice = 0;\
    try_start:\
    try {\
        p_fptr_ = (t_fptr_) GetProcAddress(w_dllptr,func_name);

#define fcall2 \
      tried_twice++;\
    } catch (int ex) {\
        if (tried_twice<2)\
            goto try_start;\
        else\
            throw;\
    }\


HINSTANCE loadLib() {
    int libflag = e->GetIntField(obj, e->GetFieldID(e->GetObjectClass(obj),"libflag","I"));
    printf("point2, libflag=%d\n",libflag);
    const char* cpath = getcwd(NULL, 1000);
    string path;
    path.assign(cpath);
    path = path.substr(0,path.find_last_of("\\"));
    switch (libflag) {
        case 0:
            path += "\\lapack_netlib\\dist\\W\\F-Windows\\liblapack_netlib.dll";
        break;
        case 1:
            path += "\\adapter_cula\\dist\\Release\\MinGW-Windows\\libadapter_cula.dll";
        break;
    }
    char* file = new char[path.size()+1];
    strcpy(file, path.c_str());
    printf("dir: %s\n",file);
    HINSTANCE ptr = LoadLibrary(file);
    printf("ptr: %d\n",ptr);
    e->SetLongField(obj,e->GetFieldID(e->GetObjectClass(obj),"dllptr","J"), (long) ptr);

	int m = 0;
	int j = 4/m;
    return ptr;
}


#else
#include <dlfcn.h>
#define fcall1 \
    long ldllptr = (long) env->GetLongField(obj, env->GetFieldID(env->GetObjectClass(obj),"dllptr","J"));\
    void* w_dllptr = (void*) ldllptr;\
    printf("point1, ldllptr=%d\n",ldllptr);\
    if (ldllptr == 0)\
        w_dllptr = loadLib(env, obj);\
    t_fptr_ p_fptr_;\
    int tried_twice = 0;\
    try_start:\
    try {\
        p_fptr_ = dlsym(w_dllptr, func_name); \
        if (dlerror()!=NULL) {\
            tried_twice++; \
            goto try_start\
        }\

#define fcall2 \
      tried_twice++;\
    } catch (int ex) {\
        if (tried_twice<2)\
            goto try_start;\
        else\
            throw;\
    }\

void* loadLib(JNIEnv *e, jobject obj) {
    int libflag = e->GetIntField(obj, e->GetFieldID(e->GetObjectClass(obj),"libflag","I"));
    printf("point2, libflag=%d\n",libflag);
    const char* cpath = getcwd(NULL, 1000);
    string path;
    path.assign(cpath);
    path = path.substr(0,path.find_last_of("\\"));
    switch (libflag) {
        case 0:
            path += "\\lapack_netlib\\dist\\Release_Linux_x86\\GNU-Linux-x86\\liblapack_netlib.so";
        break;
        case 1:
            path += "\\adapter_cula\\dist\\Release_Linux_x86\\GNU-Linux-x86\\libadapter_cula.so";
        break;
    }
    char* file = new char[path.size()+1];
    strcpy(file, path.c_str());
    printf("dir: %s\n",file);
    void* ptr = dlopen(file, RTLD_LAZY);
    if (!ptr) {
        printf("failed to load library!");
        exit(1);
    }
    e->SetLongField(obj,e->GetFieldID(e->GetObjectClass(obj),"dllptr","J"), (long) ptr);
    dlerror();
    return ptr;
}
#endif
*/



/*
void dpotrf_(char* uplo, int* n, double* a, int* lda, int* info, JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(char*, int*, double*, int*, int*);
char* func_name = "dpotrf_";
fcall1;
p_fptr_(uplo, n, a, lda, info);
fcall2;
}

void zpotrf_(char* uplo, int* n, complex* a, int* lda, int* info, JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(char*, int*, complex*, int*, int*);
char* func_name = "zpotrf_";
fcall1;
p_fptr_(uplo, n, a, lda, info);
fcall2;
}*/
/*
void dgetri_(int* n, double* a, int* lda, int* ipiv, double* work, int* lwork,  int* info, JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, double*, int*, int*, double*, int*, int*);
char* func_name = "dgetri_";
fcall1;
p_fptr_(n, a, lda, ipiv, work, lwork, info);
fcall2;
}


void zgetri_(int* n, complex* a, int* lda, int* ipiv, complex* work, int* lwork, int* info, JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, complex*, int*, int*, complex*, int*, int*);
char* func_name = "zgetri_";
fcall1;
p_fptr_(n, a, lda, ipiv, work, lwork, info);
fcall2;
}

double dlamch_( unsigned char* cmach, JNIEnv *env, jobject obj) {
typedef double(*t_fptr_)(unsigned char*);
char* func_name = "dlamch_";
double res;
fcall1;
res = p_fptr_(cmach);
fcall2;
return res;
}

void dlarnv_( int* idist, int* iseed, int* n, double* x, JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, int*, double*);
char* func_name = "dlarnv_";
fcall1;
p_fptr_(idist, iseed, n, x);
fcall2;
}

void dgecon_( char* norm, int*  n, double* a, int* lda, double* anorm, double* rcond, double* work, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(char*, int*, double*, int*, double*, double*, double*, int*, int*);
char* func_name = "dgecon_";
fcall1;
p_fptr_(norm, n, a, lda, anorm, rcond, work, iwork, info);
fcall2;
}

double dlange_( char* norm, int*  m, int*  n, double* a, int* lda, double* work , JNIEnv *env, jobject obj) {
typedef double(*t_fptr_)(char*, int*, int*, double*, int*, double*);
char* func_name = "dlange_";
double res;
fcall1;
res = p_fptr_(norm, m, n, a, lda, work);
fcall2;
return res;
}

void dgbsv_( int* n, int* kl, int* ku, int* nrhs, double* ab, int* ldab, int* ipiv, double* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, int*, int*, double*, int*, int*, double*, int*, int*);
char* func_name = "dgbsv_";
fcall1;
p_fptr_(n, kl, ku, nrhs, ab, ldab, ipiv, b, ldb, info);
fcall2;
}

void dgbsvx_( unsigned char* fact, unsigned char* trans, int* n, int* kl, int* ku, int* nrhs, double* ab, int* ldab, double* afb, int* ldafb, int* ipiv, unsigned char* equed, double* r, double* c, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, int*, int*, double*, int*, double*, int*, int*, unsigned char*, double*, double*, double*, int*, double*, int*, double*, double*, double*, double*, int*, int*);
char* func_name = "dgbsvx_";
fcall1;
p_fptr_(fact, trans, n, kl, ku, nrhs, ab, ldab, afb, ldafb, ipiv, equed, r, c, b, ldb, x, ldx, rcond, ferr, berr, work, iwork, info);
fcall2;
}

void dgbtrf_( int* m, int* n, int* kl, int* ku, double* ab, int* ldab, int* ipiv, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, int*, int*, double*, int*, int*, int*);
char* func_name = "dgbtrf_";
fcall1;
p_fptr_(m, n, kl, ku, ab, ldab, ipiv, info);
fcall2;
}

void dgeqp3_( int* m, int* n, double* a, int* lda, int* jpvt, double* tau, double* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, double*, int*, int*, double*, double*, int*, int*);
char* func_name = "dgeqp3_";
fcall1;
p_fptr_(m, n, a, lda, jpvt, tau, work, lwork, info);
fcall2;
}

void dgeqrf_( int* m, int* n, double* a, int* lda, double* tau, double* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, double*, int*, double*, double*, int*, int*);
char* func_name = "dgeqrf_";
fcall1;
p_fptr_(m, n, a, lda, tau, work, lwork, info);
fcall2;
}

void dgesvx_( unsigned char* fact, unsigned char* trans, int* n, int* nrhs, double* a, int* lda, double* af, int* ldaf, int* ipiv, unsigned char* equed, double* r, double* c, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, double*, int*, double*, int*, int*, unsigned char*, double*, double*, double*, int*, double*, int*, double*, double*, double*, double*, int*, int*);
char* func_name = "dgesvx_";
fcall1;
p_fptr_(fact, trans, n, nrhs, a, lda, af, ldaf, ipiv, equed, r, c, b, ldb, x, ldx, rcond, ferr, berr, work, iwork, info);
fcall2;
}

void dggevx_( unsigned char* balanc, unsigned char* jobvl, unsigned char* jobvr, unsigned char* sense, int* n, double* a, int* lda, double* b, int* ldb, double* alphar, double* alphai, double* beta, double* vl, int* ldvl, double* vr, int* ldvr, int* ilo, int* ihi, double* lscale, double* rscale, double* abnrm, double* bbnrm, double* rconde, double* rcondv, double* work, int* lwork, int* iwork, int* bwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, unsigned char*, int*, double*, int*, double*, int*, double*, double*, double*, double*, int*, double*, int*, int*, int*, double*, double*, double*, double*, double*, double*, double*, int*, int*, int*, int*);
char* func_name = "dggevx_";
fcall1;
p_fptr_(balanc, jobvl, jobvr, sense, n, a, lda, b, ldb, alphar, alphai, beta, vl, ldvl, vr, ldvr, ilo, ihi, lscale, rscale, abnrm, bbnrm, rconde, rcondv, work, lwork, iwork, bwork, info);
fcall2;
}

void dggsvd_( unsigned char* jobu, unsigned char* jobv, unsigned char* jobq, int* m, int* n, int* p, int* k, int* l, double* a, int* lda, double* b, int* ldb, double* alpha, double* beta, double* u, int* ldu, double* v, int* ldv, double* q, int* ldq, double* work, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, int*, int*, int*, int*, int*, double*, int*, double*, int*, double*, double*, double*, int*, double*, int*, double*, int*, double*, int*, int*);
char* func_name = "dggsvd_";
fcall1;
p_fptr_(jobu, jobv, jobq, m, n, p, k, l, a, lda, b, ldb, alpha, beta, u, ldu, v, ldv, q, ldq, work, iwork, info);
fcall2;
}

void dgtsv_( int* n, int* nrhs, double* dl, double* d, double* du, double* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, double*, double*, double*, double*, int*, int*);
char* func_name = "dgtsv_";
fcall1;
p_fptr_(n, nrhs, dl, d, du, b, ldb, info);
fcall2;
}

void dgtsvx_( unsigned char* fact, unsigned char* trans, int* n, int* nrhs, double* dl, double* d, double* du, double* dlf, double* df, double* duf, double* du2, int* ipiv, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, double*, double*, double*, double*, double*, double*, double*, int*, double*, int*, double*, int*, double*, double*, double*, double*, int*, int*);
char* func_name = "dgtsvx_";
fcall1;
p_fptr_(fact, trans, n, nrhs, dl, d, du, dlf, df, duf, du2, ipiv, b, ldb, x, ldx, rcond, ferr, berr, work, iwork, info);
fcall2;
}

void dgttrf_( int* n, double* dl, double* d, double* du, double* du2, int* ipiv, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, double*, double*, double*, double*, int*, int*);
char* func_name = "dgttrf_";
fcall1;
p_fptr_(n, dl, d, du, du2, ipiv, info);
fcall2;
}

void dpbsv_( unsigned char* uplo, int* n, int* kd, int* nrhs, double* ab, int* ldab, double* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, int*, int*, int*, double*, int*, double*, int*, int*);
char* func_name = "dpbsv_";
fcall1;
p_fptr_(uplo, n, kd, nrhs, ab, ldab, b, ldb, info);
fcall2;
}

void dpbsvx_( unsigned char* fact, unsigned char* uplo, int* n, int* kd, int* nrhs, double* ab, int* ldab, double* afb, int* ldafb, unsigned char* equed, double* s, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, int*, double*, int*, double*, int*, unsigned char*, double*, double*, int*, double*, int*, double*, double*, double*, double*, int*, int*);
char* func_name = "dpbsvx_";
fcall1;
p_fptr_(fact, uplo, n, kd, nrhs, ab, ldab, afb, ldafb, equed, s, b, ldb, x, ldx, rcond, ferr, berr, work, iwork, info);
fcall2;
}

void dposv_( unsigned char* uplo, int* n, int* nrhs, double* a, int* lda, double* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, int*, int*, double*, int*, double*, int*, int*);
char* func_name = "dposv_";
fcall1;
p_fptr_(uplo, n, nrhs, a, lda, b, ldb, info);
fcall2;
}

void dposvx_( unsigned char* fact, unsigned char* uplo, int* n, int* nrhs, double* a, int* lda, double* af, int* ldaf, unsigned char* equed, double* s, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, double*, int*, double*, int*, unsigned char*, double*, double*, int*, double*, int*, double*, double*, double*, double*, int*, int*);
char* func_name = "dposvx_";
fcall1;
p_fptr_(fact, uplo, n, nrhs, a, lda, af, ldaf, equed, s, b, ldb, x, ldx, rcond, ferr, berr, work, iwork, info);
fcall2;
}

void dptsv_( int* n, int* nrhs, double* d, double* e, double* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, double*, double*, double*, int*, int*);
char* func_name = "dptsv_";
fcall1;
p_fptr_(n, nrhs, d, e, b, ldb, info);
fcall2;
}

void dptsvx_( unsigned char* fact, int* n, int* nrhs, double* d, double* e, double* df, double* ef, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, int*, int*, double*, double*, double*, double*, double*, int*, double*, int*, double*, double*, double*, double*, int*);
char* func_name = "dptsvx_";
fcall1;
p_fptr_(fact, n, nrhs, d, e, df, ef, b, ldb, x, ldx, rcond, ferr, berr, work, info);
fcall2;
}

void dsbev_( unsigned char* jobz, unsigned char* uplo, int* n, int* kd, double* ab, int* ldab, double* w, double* z, int* ldz, double* work, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, double*, int*, double*, double*, int*, double*, int*);
char* func_name = "dsbev_";
fcall1;
p_fptr_(jobz, uplo, n, kd, ab, ldab, w, z, ldz, work, info);
fcall2;
}

void dsbevd_( unsigned char* jobz, unsigned char* uplo, int* n, int* kd, double* ab, int* ldab, double* w, double* z, int* ldz, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, double*, int*, double*, double*, int*, double*, int*, int*, int*, int*);
char* func_name = "dsbevd_";
fcall1;
p_fptr_(jobz, uplo, n, kd, ab, ldab, w, z, ldz, work, lwork, iwork, liwork, info);
fcall2;
}

void dsbevx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, int* kd, double* ab, int* ldab, double* q, int* ldq, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, double* work, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, int*, int*, double*, int*, double*, int*, double*, double*, int*, int*, double*, int*, double*, double*, int*, double*, int*, int*, int*);
char* func_name = "dsbevx_";
fcall1;
p_fptr_(jobz, range, uplo, n, kd, ab, ldab, q, ldq, vl, vu, il, iu, abstol, m, w, z, ldz, work, iwork, ifail, info);
fcall2;
}

void dsbgv_( unsigned char* jobz, unsigned char* uplo, int* n, int* ka, int* kb, double* ab, int* ldab, double* bb, int* ldbb, double* w, double* z, int* ldz, double* work, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, int*, double*, int*, double*, int*, double*, double*, int*, double*, int*);
char* func_name = "dsbgv_";
fcall1;
p_fptr_(jobz, uplo, n, ka, kb, ab, ldab, bb, ldbb, w, z, ldz, work, info);
fcall2;
}

void dsbgvd_( unsigned char* jobz, unsigned char* uplo, int* n, int* ka, int* kb, double* ab, int* ldab, double* bb, int* ldbb, double* w, double* z, int* ldz, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, int*, double*, int*, double*, int*, double*, double*, int*, double*, int*, int*, int*, int*);
char* func_name = "dsbgvd_";
fcall1;
p_fptr_(jobz, uplo, n, ka, kb, ab, ldab, bb, ldbb, w, z, ldz, work, lwork, iwork, liwork, info);
fcall2;
}

void dsbgvx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, int* ka, int* kb, double* ab, int* ldab, double* bb, int* ldbb, double* q, int* ldq, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, double* work, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, int*, int*, int*, double*, int*, double*, int*, double*, int*, double*, double*, int*, int*, double*, int*, double*, double*, int*, double*, int*, int*, int*);
char* func_name = "dsbgvx_";
fcall1;
p_fptr_(jobz, range, uplo, n, ka, kb, ab, ldab, bb, ldbb, q, ldq, vl, vu, il, iu, abstol, m, w, z, ldz, work, iwork, ifail, info);
fcall2;
}

void dstev_( unsigned char* jobz, int* n, double* d, double* e, double* z, int* ldz, double* work, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, int*, double*, double*, double*, int*, double*, int*);
char* func_name = "dstev_";
fcall1;
p_fptr_(jobz, n, d, e, z, ldz, work, info);
fcall2;
}

void dstevd_( unsigned char* jobz, int* n, double* d, double* e, double* z, int* ldz, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, int*, double*, double*, double*, int*, double*, int*, int*, int*, int*);
char* func_name = "dstevd_";
fcall1;
p_fptr_(jobz, n, d, e, z, ldz, work, lwork, iwork, liwork, info);
fcall2;
}

void dstevr_( unsigned char* jobz, unsigned char* range, int* n, double* d, double* e, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, int* isuppz, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, double*, double*, double*, double*, int*, int*, double*, int*, double*, double*, int*, int*, double*, int*, int*, int*, int*);
char* func_name = "dstevr_";
fcall1;
p_fptr_(jobz, range, n, d, e, vl, vu, il, iu, abstol, m, w, z, ldz, isuppz, work, lwork, iwork, liwork, info);
fcall2;
}

void dstevx_( unsigned char* jobz, unsigned char* range, int* n, double* d, double* e, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, double* work, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, double*, double*, double*, double*, int*, int*, double*, int*, double*, double*, int*, double*, int*, int*, int*);
char* func_name = "dstevx_";
fcall1;
p_fptr_(jobz, range, n, d, e, vl, vu, il, iu, abstol, m, w, z, ldz, work, iwork, ifail, info);
fcall2;
}

void dsyev_( unsigned char* jobz, unsigned char* uplo, int* n, double* a, int* lda, double* w, double* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, double*, int*, double*, double*, int*, int*);
char* func_name = "dsyev_";
fcall1;
p_fptr_(jobz, uplo, n, a, lda, w, work, lwork, info);
fcall2;
}

void dsyevd_( unsigned char* jobz, unsigned char* uplo, int* n, double* a, int* lda, double* w, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, double*, int*, double*, double*, int*, int*, int*, int*);
char* func_name = "dsyevd_";
fcall1;
p_fptr_(jobz, uplo, n, a, lda, w, work, lwork, iwork, liwork, info);
fcall2;
}

void dsyevr_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, double* a, int* lda, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, int* isuppz, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, int*, double*, int*, double*, double*, int*, int*, double*, int*, double*, double*, int*, int*, double*, int*, int*, int*, int*);
char* func_name = "dsyevr_";
fcall1;
p_fptr_(jobz, range, uplo, n, a, lda, vl, vu, il, iu, abstol, m, w, z, ldz, isuppz, work, lwork, iwork, liwork, info);
fcall2;
}

void dsyevx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, double* a, int* lda, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, double* work, int* lwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, int*, double*, int*, double*, double*, int*, int*, double*, int*, double*, double*, int*, double*, int*, int*, int*, int*);
char* func_name = "dsyevx_";
fcall1;
p_fptr_(jobz, range, uplo, n, a, lda, vl, vu, il, iu, abstol, m, w, z, ldz, work, lwork, iwork, ifail, info);
fcall2;
}

void dsygv_( int* itype, unsigned char* jobz, unsigned char* uplo, int* n, double* a, int* lda, double* b, int* ldb, double* w, double* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, unsigned char*, unsigned char*, int*, double*, int*, double*, int*, double*, double*, int*, int*);
char* func_name = "dsygv_";
fcall1;
p_fptr_(itype, jobz, uplo, n, a, lda, b, ldb, w, work, lwork, info);
fcall2;
}

void dsygvd_( int* itype, unsigned char* jobz, unsigned char* uplo, int* n, double* a, int* lda, double* b, int* ldb, double* w, double* work, int* lwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, unsigned char*, unsigned char*, int*, double*, int*, double*, int*, double*, double*, int*, int*, int*, int*);
char* func_name = "dsygvd_";
fcall1;
p_fptr_(itype, jobz, uplo, n, a, lda, b, ldb, w, work, lwork, iwork, liwork, info);
fcall2;
}

void dsygvx_( int* itype, unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, double* a, int* lda, double* b, int* ldb, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, double* z, int* ldz, double* work, int* lwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, unsigned char*, unsigned char*, unsigned char*, int*, double*, int*, double*, int*, double*, double*, int*, int*, double*, int*, double*, double*, int*, double*, int*, int*, int*, int*);
char* func_name = "dsygvx_";
fcall1;
p_fptr_(itype, jobz, range, uplo, n, a, lda, b, ldb, vl, vu, il, iu, abstol, m, w, z, ldz, work, lwork, iwork, ifail, info);
fcall2;
}

void dsysv_( unsigned char* uplo, int* n, int* nrhs, double* a, int* lda, int* ipiv, double* b, int* ldb, double* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, int*, int*, double*, int*, int*, double*, int*, double*, int*, int*);
char* func_name = "dsysv_";
fcall1;
p_fptr_(uplo, n, nrhs, a, lda, ipiv, b, ldb, work, lwork, info);
fcall2;
}

void dsysvx_( unsigned char* fact, unsigned char* uplo, int* n, int* nrhs, double* a, int* lda, double* af, int* ldaf, int* ipiv, double* b, int* ldb, double* x, int* ldx, double* rcond, double* ferr, double* berr, double* work, int* lwork, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, double*, int*, double*, int*, int*, double*, int*, double*, int*, double*, double*, double*, double*, int*, int*, int*);
char* func_name = "dsysvx_";
fcall1;
p_fptr_(fact, uplo, n, nrhs, a, lda, af, ldaf, ipiv, b, ldb, x, ldx, rcond, ferr, berr, work, lwork, iwork, info);
fcall2;
}

void zgbsv_( int* n, int* kl, int* ku, int* nrhs, complex* ab, int* ldab, int* ipiv, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, int*, int*, complex*, int*, int*, complex*, int*, int*);
char* func_name = "zgbsv_";
fcall1;
p_fptr_(n, kl, ku, nrhs, ab, ldab, ipiv, b, ldb, info);
fcall2;
}

void zgbsvx_( unsigned char* fact, unsigned char* trans, int* n, int* kl, int* ku, int* nrhs, complex* ab, int* ldab, complex* afb, int* ldafb, int* ipiv, unsigned char* equed, double* r, double* c, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, int*, int*, complex*, int*, complex*, int*, int*, unsigned char*, double*, double*, complex*, int*, complex*, int*, double*, double*, double*, complex*, double*, int*);
char* func_name = "zgbsvx_";
fcall1;
p_fptr_(fact, trans, n, kl, ku, nrhs, ab, ldab, afb, ldafb, ipiv, equed, r, c, b, ldb, x, ldx, rcond, ferr, berr, work, rwork, info);
fcall2;
}

void zgbtrf_( int* m, int* n, int* kl, int* ku, complex* ab, int* ldab, int* ipiv, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, int*, int*, complex*, int*, int*, int*);
char* func_name = "zgbtrf_";
fcall1;
p_fptr_(m, n, kl, ku, ab, ldab, ipiv, info);
fcall2;
}

void zgeqp3_( int* m, int* n, complex* a, int* lda, int* jpvt, complex* tau, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, complex*, int*, int*, complex*, complex*, int*, double*, int*);
char* func_name = "zgeqp3_";
fcall1;
p_fptr_(m, n, a, lda, jpvt, tau, work, lwork, rwork, info);
fcall2;
}

void zgeqrf_( int* m, int* n, complex* a, int* lda, complex* tau, complex* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, complex*, int*, complex*, complex*, int*, int*);
char* func_name = "zgeqrf_";
fcall1;
p_fptr_(m, n, a, lda, tau, work, lwork, info);
fcall2;
}

void zgesvx_( unsigned char* fact, unsigned char* trans, int* n, int* nrhs, complex* a, int* lda, complex* af, int* ldaf, int* ipiv, unsigned char* equed, double* r, double* c, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, complex*, int*, complex*, int*, int*, unsigned char*, double*, double*, complex*, int*, complex*, int*, double*, double*, double*, complex*, double*, int*);
char* func_name = "zgesvx_";
fcall1;
p_fptr_(fact, trans, n, nrhs, a, lda, af, ldaf, ipiv, equed, r, c, b, ldb, x, ldx, rcond, ferr, berr, work, rwork, info);
fcall2;
}

void zggevx_( unsigned char* balanc, unsigned char* jobvl, unsigned char* jobvr, unsigned char* sense, int* n, complex* a, int* lda, complex* b, int* ldb, complex* alpha, complex* beta, complex* vl, int* ldvl, complex* vr, int* ldvr, int* ilo, int* ihi, double* lscale, double* rscale, double* abnrm, double* bbnrm, double* rconde, double* rcondv, complex* work, int* lwork, double* rwork, int* iwork, int* bwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, unsigned char*, int*, complex*, int*, complex*, int*, complex*, complex*, complex*, int*, complex*, int*, int*, int*, double*, double*, double*, double*, double*, double*, complex*, int*, double*, int*, int*, int*);
char* func_name = "zggevx_";
fcall1;
p_fptr_(balanc, jobvl, jobvr, sense, n, a, lda, b, ldb, alpha, beta, vl, ldvl, vr, ldvr, ilo, ihi, lscale, rscale, abnrm, bbnrm, rconde, rcondv, work, lwork, rwork, iwork, bwork, info);
fcall2;
}

void zggsvd_( unsigned char* jobu, unsigned char* jobv, unsigned char* jobq, int* m, int* n, int* p, int* k, int* l, complex* a, int* lda, complex* b, int* ldb, double* alpha, double* beta, complex* u, int* ldu, complex* v, int* ldv, complex* q, int* ldq, complex* work, double* rwork, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, int*, int*, int*, int*, int*, complex*, int*, complex*, int*, double*, double*, complex*, int*, complex*, int*, complex*, int*, complex*, double*, int*, int*);
char* func_name = "zggsvd_";
fcall1;
p_fptr_(jobu, jobv, jobq, m, n, p, k, l, a, lda, b, ldb, alpha, beta, u, ldu, v, ldv, q, ldq, work, rwork, iwork, info);
fcall2;
}

void zgtsv_( int* n, int* nrhs, complex* dl, complex* d, complex* du, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, complex*, complex*, complex*, complex*, int*, int*);
char* func_name = "zgtsv_";
fcall1;
p_fptr_(n, nrhs, dl, d, du, b, ldb, info);
fcall2;
}

void zgtsvx_( unsigned char* fact, unsigned char* trans, int* n, int* nrhs, complex* dl, complex* d, complex* du, complex* dlf, complex* df, complex* duf, complex* du2, int* ipiv, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, complex*, complex*, complex*, complex*, complex*, complex*, complex*, int*, complex*, int*, complex*, int*, double*, double*, double*, complex*, double*, int*);
char* func_name = "zgtsvx_";
fcall1;
p_fptr_(fact, trans, n, nrhs, dl, d, du, dlf, df, duf, du2, ipiv, b, ldb, x, ldx, rcond, ferr, berr, work, rwork, info);
fcall2;
}

void zgttrf_( int* n, complex* dl, complex* d, complex* du, complex* du2, int* ipiv, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, complex*, complex*, complex*, complex*, int*, int*);
char* func_name = "zgttrf_";
fcall1;
p_fptr_(n, dl, d, du, du2, ipiv, info);
fcall2;
}

void zhbev_( unsigned char* jobz, unsigned char* uplo, int* n, int* kd, complex* ab, int* ldab, double* w, complex* z, int* ldz, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, complex*, int*, double*, complex*, int*, complex*, double*, int*);
char* func_name = "zhbev_";
fcall1;
p_fptr_(jobz, uplo, n, kd, ab, ldab, w, z, ldz, work, rwork, info);
fcall2;
}

void zhbevd_( unsigned char* jobz, unsigned char* uplo, int* n, int* kd, complex* ab, int* ldab, double* w, complex* z, int* ldz, complex* work, int* lwork, double* rwork, int* lrwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, complex*, int*, double*, complex*, int*, complex*, int*, double*, int*, int*, int*, int*);
char* func_name = "zhbevd_";
fcall1;
p_fptr_(jobz, uplo, n, kd, ab, ldab, w, z, ldz, work, lwork, rwork, lrwork, iwork, liwork, info);
fcall2;
}

void zhbevx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, int* kd, complex* ab, int* ldab, complex* q, int* ldq, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, complex* z, int* ldz, complex* work, double* rwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, int*, int*, complex*, int*, complex*, int*, double*, double*, int*, int*, double*, int*, double*, complex*, int*, complex*, double*, int*, int*, int*);
char* func_name = "zhbevx_";
fcall1;
p_fptr_(jobz, range, uplo, n, kd, ab, ldab, q, ldq, vl, vu, il, iu, abstol, m, w, z, ldz, work, rwork, iwork, ifail, info);
fcall2;
}

void zhbgv_( unsigned char* jobz, unsigned char* uplo, int* n, int* ka, int* kb, complex* ab, int* ldab, complex* bb, int* ldbb, double* w, complex* z, int* ldz, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, int*, complex*, int*, complex*, int*, double*, complex*, int*, complex*, double*, int*);
char* func_name = "zhbgv_";
fcall1;
p_fptr_(jobz, uplo, n, ka, kb, ab, ldab, bb, ldbb, w, z, ldz, work, rwork, info);
fcall2;
}

void zhbgvd_( unsigned char* jobz, unsigned char* uplo, int* n, int* ka, int* kb, complex* ab, int* ldab, complex* bb, int* ldbb, double* w, complex* z, int* ldz, complex* work, int* lwork, double* rwork, int* lrwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, int*, complex*, int*, complex*, int*, double*, complex*, int*, complex*, int*, double*, int*, int*, int*, int*);
char* func_name = "zhbgvd_";
fcall1;
p_fptr_(jobz, uplo, n, ka, kb, ab, ldab, bb, ldbb, w, z, ldz, work, lwork, rwork, lrwork, iwork, liwork, info);
fcall2;
}

void zhbgvx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, int* ka, int* kb, complex* ab, int* ldab, complex* bb, int* ldbb, complex* q, int* ldq, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, complex* z, int* ldz, complex* work, double* rwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, int*, int*, int*, complex*, int*, complex*, int*, complex*, int*, double*, double*, int*, int*, double*, int*, double*, complex*, int*, complex*, double*, int*, int*, int*);
char* func_name = "zhbgvx_";
fcall1;
p_fptr_(jobz, range, uplo, n, ka, kb, ab, ldab, bb, ldbb, q, ldq, vl, vu, il, iu, abstol, m, w, z, ldz, work, rwork, iwork, ifail, info);
fcall2;
}

void zheev_( unsigned char* jobz, unsigned char* uplo, int* n, complex* a, int* lda, double* w, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, complex*, int*, double*, complex*, int*, double*, int*);
char* func_name = "zheev_";
fcall1;
p_fptr_(jobz, uplo, n, a, lda, w, work, lwork, rwork, info);
fcall2;
}

void zheevd_( unsigned char* jobz, unsigned char* uplo, int* n, complex* a, int* lda, double* w, complex* work, int* lwork, double* rwork, int* lrwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, complex*, int*, double*, complex*, int*, double*, int*, int*, int*, int*);
char* func_name = "zheevd_";
fcall1;
p_fptr_(jobz, uplo, n, a, lda, w, work, lwork, rwork, lrwork, iwork, liwork, info);
fcall2;
}

void zheevr_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, complex* a, int* lda, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, complex* z, int* ldz, int* isuppz, complex* work, int* lwork, double* rwork, int* lrwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, int*, complex*, int*, double*, double*, int*, int*, double*, int*, double*, complex*, int*, int*, complex*, int*, double*, int*, int*, int*, int*);
char* func_name = "zheevr_";
fcall1;
p_fptr_(jobz, range, uplo, n, a, lda, vl, vu, il, iu, abstol, m, w, z, ldz, isuppz, work, lwork, rwork, lrwork, iwork, liwork, info);
fcall2;
}

void zheevx_( unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, complex* a, int* lda, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, complex* z, int* ldz, complex* work, int* lwork, double* rwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, unsigned char*, int*, complex*, int*, double*, double*, int*, int*, double*, int*, double*, complex*, int*, complex*, int*, double*, int*, int*, int*);
char* func_name = "zheevx_";
fcall1;
p_fptr_(jobz, range, uplo, n, a, lda, vl, vu, il, iu, abstol, m, w, z, ldz, work, lwork, rwork, iwork, ifail, info);
fcall2;
}

void zhegv_( int* itype, unsigned char* jobz, unsigned char* uplo, int* n, complex* a, int* lda, complex* b, int* ldb, double* w, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, unsigned char*, unsigned char*, int*, complex*, int*, complex*, int*, double*, complex*, int*, double*, int*);
char* func_name = "zhegv_";
fcall1;
p_fptr_(itype, jobz, uplo, n, a, lda, b, ldb, w, work, lwork, rwork, info);
fcall2;
}

void zhegvd_( int* itype, unsigned char* jobz, unsigned char* uplo, int* n, complex* a, int* lda, complex* b, int* ldb, double* w, complex* work, int* lwork, double* rwork, int* lrwork, int* iwork, int* liwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, unsigned char*, unsigned char*, int*, complex*, int*, complex*, int*, double*, complex*, int*, double*, int*, int*, int*, int*);
char* func_name = "zhegvd_";
fcall1;
p_fptr_(itype, jobz, uplo, n, a, lda, b, ldb, w, work, lwork, rwork, lrwork, iwork, liwork, info);
fcall2;
}

void zhegvx_( int* itype, unsigned char* jobz, unsigned char* range, unsigned char* uplo, int* n, complex* a, int* lda, complex* b, int* ldb, double* vl, double* vu, int* il, int* iu, double* abstol, int* m, double* w, complex* z, int* ldz, complex* work, int* lwork, double* rwork, int* iwork, int* ifail, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, unsigned char*, unsigned char*, unsigned char*, int*, complex*, int*, complex*, int*, double*, double*, int*, int*, double*, int*, double*, complex*, int*, complex*, int*, double*, int*, int*, int*);
char* func_name = "zhegvx_";
fcall1;
p_fptr_(itype, jobz, range, uplo, n, a, lda, b, ldb, vl, vu, il, iu, abstol, m, w, z, ldz, work, lwork, rwork, iwork, ifail, info);
fcall2;
}

void zhesv_( unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, int* ipiv, complex* b, int* ldb, complex* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, int*, int*, complex*, int*, int*, complex*, int*, complex*, int*, int*);
char* func_name = "zhesv_";
fcall1;
p_fptr_(uplo, n, nrhs, a, lda, ipiv, b, ldb, work, lwork, info);
fcall2;
}

void zhesvx_( unsigned char* fact, unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, complex* af, int* ldaf, int* ipiv, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, complex*, int*, complex*, int*, int*, complex*, int*, complex*, int*, double*, double*, double*, complex*, int*, double*, int*);
char* func_name = "zhesvx_";
fcall1;
p_fptr_(fact, uplo, n, nrhs, a, lda, af, ldaf, ipiv, b, ldb, x, ldx, rcond, ferr, berr, work, lwork, rwork, info);
fcall2;
}

void zpbsv_( unsigned char* uplo, int* n, int* kd, int* nrhs, complex* ab, int* ldab, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, int*, int*, int*, complex*, int*, complex*, int*, int*);
char* func_name = "zpbsv_";
fcall1;
p_fptr_(uplo, n, kd, nrhs, ab, ldab, b, ldb, info);
fcall2;
}

void zpbsvx_( unsigned char* fact, unsigned char* uplo, int* n, int* kd, int* nrhs, complex* ab, int* ldab, complex* afb, int* ldafb, unsigned char* equed, double* s, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, int*, complex*, int*, complex*, int*, unsigned char*, double*, complex*, int*, complex*, int*, double*, double*, double*, complex*, double*, int*);
char* func_name = "zpbsvx_";
fcall1;
p_fptr_(fact, uplo, n, kd, nrhs, ab, ldab, afb, ldafb, equed, s, b, ldb, x, ldx, rcond, ferr, berr, work, rwork, info);
fcall2;
}

void zposv_( unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, int*, int*, complex*, int*, complex*, int*, int*);
char* func_name = "zposv_";
fcall1;
p_fptr_(uplo, n, nrhs, a, lda, b, ldb, info);
fcall2;
}

void zposvx_( unsigned char* fact, unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, complex* af, int* ldaf, unsigned char* equed, double* s, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, complex*, int*, complex*, int*, unsigned char*, double*, complex*, int*, complex*, int*, double*, double*, double*, complex*, double*, int*);
char* func_name = "zposvx_";
fcall1;
p_fptr_(fact, uplo, n, nrhs, a, lda, af, ldaf, equed, s, b, ldb, x, ldx, rcond, ferr, berr, work, rwork, info);
fcall2;
}

void zptsv_( int* n, int* nrhs, double* d, complex* e, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, double*, complex*, complex*, int*, int*);
char* func_name = "zptsv_";
fcall1;
p_fptr_(n, nrhs, d, e, b, ldb, info);
fcall2;
}

void zptsvx_( unsigned char* fact, int* n, int* nrhs, double* d, complex* e, double* df, complex* ef, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, int*, int*, double*, complex*, double*, complex*, complex*, int*, complex*, int*, double*, double*, double*, complex*, double*, int*);
char* func_name = "zptsvx_";
fcall1;
p_fptr_(fact, n, nrhs, d, e, df, ef, b, ldb, x, ldx, rcond, ferr, berr, work, rwork, info);
fcall2;
}

void zsysv_( unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, int* ipiv, complex* b, int* ldb, complex* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, int*, int*, complex*, int*, int*, complex*, int*, complex*, int*, int*);
char* func_name = "zsysv_";
fcall1;
p_fptr_(uplo, n, nrhs, a, lda, ipiv, b, ldb, work, lwork, info);
fcall2;
}

void zsysvx_( unsigned char* fact, unsigned char* uplo, int* n, int* nrhs, complex* a, int* lda, complex* af, int* ldaf, int* ipiv, complex* b, int* ldb, complex* x, int* ldx, double* rcond, double* ferr, double* berr, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(unsigned char*, unsigned char*, int*, int*, complex*, int*, complex*, int*, int*, complex*, int*, complex*, int*, double*, double*, double*, complex*, int*, double*, int*);
char* func_name = "zsysvx_";
fcall1;
p_fptr_(fact, uplo, n, nrhs, a, lda, af, ldaf, ipiv, b, ldb, x, ldx, rcond, ferr, berr, work, lwork, rwork, info);
fcall2;
}
*/
/*void dgetrf_( int* m, int* n, double* a, int* lda, int* ipiv, int* info , double *env) {
//typedef void(*t_fptr_)(int*, int*, double*, int*, int*, int*);
//char* func_name = "dgetrf_";
//fcall1;
//p_fptr_(m, n, a, lda, ipiv, info);
//fcall2;
}*/
/*
void zgetrf_( int* m, int* n, complex* a, int* lda, int* ipiv, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, complex*, int*, int*, int*);
char* func_name = "zgetrf_";
fcall1;
p_fptr_(m, n, a, lda, ipiv, info);
fcall2;
}

void dgesvd_( const unsigned char* jobu, const unsigned char* jobvt, int* m, int* n, double* a, int* lda, double* s,  double* u, int* ldu, double* vt, int* ldvt, double* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, const unsigned char*, int*, int*, double*, int*, double*, double*, int*, double*, int*, double*, int*, int*);
char* func_name = "dgesvd_";
fcall1;
p_fptr_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, work, lwork, info);
fcall2;
}

void zgesvd_( const unsigned char* jobu, const unsigned char* jobvt, int* m, int* n, complex* a, int* lda, double* s, complex* u, int* ldu, complex* vt, int* ldvt, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, const unsigned char*, int*, int*, complex*, int*, double*, complex*, int*, complex*, int*, complex*, int*, double*, int*);
char* func_name = "zgesvd_";
fcall1;
p_fptr_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, work, lwork, rwork, info);
fcall2;
}

void sgesvd_( const unsigned char* jobu, const unsigned char* jobvt, int* m, int* n, float* a, int* lda, float* s, float* u, int* ldu, float* vt, int* ldvt, float* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, const unsigned char*, int*, int*, float*, int*, float*, float*, int*, float*, int*, float*, int*, int*);
char* func_name = "sgesvd_";
fcall1;
p_fptr_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, work, lwork, info);
fcall2;
}

void cgesvd_( const unsigned char* jobu, const unsigned char* jobvt, int* m, int* n, complex64* a, int* lda, float* s, complex64* u, int* ldu, complex64* vt, int* ldvt, complex64* work, int* lwork, float* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, const unsigned char*, int*, int*, complex64*, int*, float*, complex64*, int*, complex64*, int*, complex64*, int*, float*, int*);
char* func_name = "cgesvd_";
fcall1;
p_fptr_(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, work, lwork, rwork, info);
fcall2;
}

void dgesdd_( const unsigned char* jobz, int* m, int* n, double* a, int* lda, double* s, double* u, int* ldu, double* vt, int* ldvt, double* work, int* lwork, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, int*, int*, double*, int*, double*, double*, int*, double*, int*, double*, int*, int*, int*);
char* func_name = "dgesdd_";
fcall1;
p_fptr_(jobz, m, n, a, lda, s, u, ldu, vt, ldvt, work, lwork, iwork, info);
fcall2;
}

void zgesdd_( const unsigned char* jobz, int* m, int* n, complex* a, int* lda, double* s, complex* u, int* ldu, complex* vt, int* ldvt, complex* work, int* lwork, double* rwork, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, int*, int*, complex*, int*, double*, complex*, int*, complex*, int*, complex*, int*, double*, int*, int*);
char* func_name = "zgesdd_";
fcall1;
p_fptr_(jobz, m, n, a, lda, s, u, ldu, vt, ldvt, work, lwork, rwork, iwork, info);
fcall2;
}

void dgeev_( const unsigned char* jobvl, const unsigned char* jobvr, int* n, double* a, int* lda, double* wr, double* wi, double* vl, int* ldvl, double* vr, int* ldvr, double* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, const unsigned char*, int*, double*, int*, double*, double*, double*, int*, double*, int*, double*, int*, int*);
char* func_name = "dgeev_";
fcall1;
p_fptr_(jobvl, jobvr, n, a, lda, wr, wi, vl, ldvl, vr, ldvr, work, lwork, info);
fcall2;
}

void zgeev_( const unsigned char* jobvl, const unsigned char* jobvr, int* n, complex* a, int* lda, complex* w, complex* vl, int* ldvl, complex* vr, int* ldvr, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, const unsigned char*, int*, complex*, int*, complex*, complex*, int*, complex*, int*, complex*, int*, double*, int*);
char* func_name = "zgeev_";
fcall1;
p_fptr_(jobvl, jobvr, n, a, lda, w, vl, ldvl, vr, ldvr, work, lwork, rwork, info);
fcall2;
}

void dgeevx_(  const unsigned char* balanc,  const unsigned char* jobvl,  const unsigned char* jobvr,  const unsigned char* sense, int* n, double* a, int* lda, double* wr, double* wi, double* vl, int* ldvl, double* vr, int* ldvr, int* ilo, int* ihi, double* scale, double* abnrm, double* rconde, double* rcondv, double* work, int* lwork, int* iwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, const unsigned char*, const unsigned char*, const unsigned char*, int*, double*, int*, double*, double*, double*, int*, double*, int*, int*, int*, double*, double*, double*, double*, double*, int*, int*, int*);
char* func_name = "dgeevx_";
fcall1;
p_fptr_(balanc, jobvl, jobvr, sense, n, a, lda, wr, wi, vl, ldvl, vr, ldvr, ilo, ihi, scale, abnrm, rconde, rcondv, work, lwork, iwork, info);
fcall2;
}

void zgeevx_( const unsigned char* balanc, const unsigned char* jobvl, const unsigned char* jobvr, const unsigned char* sense, int* n, complex* a, int* lda, complex* w, complex* vl, int* ldvl, complex* vr, int* ldvr, int* ilo, int* ihi, double* scale, double* abnrm, double* rconde, double* rcondv, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, const unsigned char*, const unsigned char*, const unsigned char*, int*, complex*, int*, complex*, complex*, int*, complex*, int*, int*, int*, double*, double*, double*, double*, complex*, int*, double*, int*);
char* func_name = "zgeevx_";
fcall1;
p_fptr_(balanc, jobvl, jobvr, sense, n, a, lda, w, vl, ldvl, vr, ldvr, ilo, ihi, scale, abnrm, rconde, rcondv, work, lwork, rwork, info);
fcall2;
}

void dggev_( const unsigned char* jobvl, const unsigned char* jobvr, int* n, double* a, int* lda, double* b, int* ldb, double* alphar, double* alphai, double* beta, double* vl, int* ldvl, double* vr, int* ldvr, double* work, int* lwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, const unsigned char*, int*, double*, int*, double*, int*, double*, double*, double*, double*, int*, double*, int*, double*, int*, int*);
char* func_name = "dggev_";
fcall1;
p_fptr_(jobvl, jobvr, n, a, lda, b, ldb, alphar, alphai, beta, vl, ldvl, vr, ldvr, work, lwork, info);
fcall2;
}

void zggev_( const unsigned char* jobvl, const unsigned char* jobvr, int* n, complex* a, int* lda, complex* b, int* ldb, complex* alpha, complex* beta, complex* vl, int* ldvl, complex* vr, int* ldvr, complex* work, int* lwork, double* rwork, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(const unsigned char*, const unsigned char*, int*, complex*, int*, complex*, int*, complex*, complex*, complex*, int*, complex*, int*, complex*, int*, double*, int*);
char* func_name = "zggev_";
fcall1;
p_fptr_(jobvl, jobvr, n, a, lda, b, ldb, alpha, beta, vl, ldvl, vr, ldvr, work, lwork, rwork, info);
fcall2;
}

void dgesv_( int* n, int* nrhs, double* a, int* lda, int* ipiv, double* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, double*, int*, int*, double*, int*, int*);
char* func_name = "dgesv_";
fcall1;
p_fptr_(n, nrhs, a, lda, ipiv, b, ldb, info);
fcall2;
}

void zgesv_( int* n, int* nrhs, complex* a, int* lda, int* ipiv, complex* b, int* ldb, int* info , JNIEnv *env, jobject obj) {
typedef void(*t_fptr_)(int*, int*, complex*, int*, int*, complex*, int*, int*);
char* func_name = "zgesv_";
fcall1;
p_fptr_(n, nrhs, a, lda, ipiv, b, ldb, info);
fcall2;
}

*/