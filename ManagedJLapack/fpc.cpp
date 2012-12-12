#include "stdafx.h"
#include "fpc.h"
using namespace fpc;

NS_FPC_BEGIN

const int constants<int>::_0 = 0;
const int constants<int>::_1 = 1;
const int constants<int>::_m1 = -1;

const float80 constants<float80>::_0 = {0,0,0,0};
const float80 constants<float80>::_1 = {0,0x80000000,0x3FFF,0};
const float80 constants<float80>::_m1 = {0,0x80000000,0x3FFF,1};

const complex128 constants<complex128>::_0 = {0.,0.};
const complex128 constants<complex128>::_1 = {1.,0.};
const complex128 constants<complex128>::_m1 = {-1.,0.};

const complex64 constants<complex64>::_0 = {0.f,0.f};
const complex64 constants<complex64>::_1 = {1.f,0.f};
const complex64 constants<complex64>::_m1 = {-1.f,0.f};

const complex160 constants<complex160>::_0 = {{0,0,0,0},{0,0,0,0}};
const complex160 constants<complex160>::_1 = {{0,0x80000000,0x3FFF,0},{0,0,0,0}};
const complex160 constants<complex160>::_m1 = {{0,0x80000000,0x3FFF,1},{0,0,0,0}};

NS_FPC_END


