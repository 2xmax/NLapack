/* 
 * File:   constants.h
 * Author: morse
 *
 * Created on 30 Ноябрь 2009 г., 17:35
 */

#ifndef _CONSTANTS_H
#define	_CONSTANTS_H

#ifndef MIN
#define MIN(a,b) (((a) < (b))?(a):(b))
#endif

#ifndef MAX
#define MAX(a,b) (((a) > (b))?(a):(b))
#endif

#ifndef SUB_TYPE
#define SUB_TYPE(x) typename constants<x>::_st
#endif

static const unsigned char _NA[] = {'N','A'};
static const unsigned char _NV[] = {'N','V'};
static const unsigned char _BC[] = {'N','P','S','B'};

static const unsigned char _A = 'A';
static const unsigned char _E = 'E';
static const unsigned char _S = 'S';
static const unsigned char _B = 'B';
static const unsigned char _P = 'P';
static const unsigned char _N = 'N';
static const unsigned char _R = 'R';
static const unsigned char _M = 'M';
static const unsigned char _U = 'U';
static const unsigned char _L = 'L';
static const unsigned char _O = 'O';
static const unsigned char _T = 'T';

#endif	/* _CONSTANTS_H */

