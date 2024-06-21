#ifndef LLVM_LIBC_STDFIX_H
#define LLVM_LIBC_STDFIX_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/macros/stdfix-macros"
__BEGIN_C_DECLS

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
short accum abshk(short accum);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
short fract abshr(short fract);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
accum absk(accum);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
fract absr(fract);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
long accum abslk(long accum);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
long fract abslr(long fract);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
short accum exphk(short accum);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
accum expk(accum);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
short accum roundhk(short accum, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
short fract roundhr(short fract, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
accum roundk(accum, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
fract roundr(fract, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
long accum roundlk(long accum, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
long fract roundlr(long fract, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned short accum rounduhk(unsigned short accum, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned short fract rounduhr(unsigned short fract, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned accum rounduk(unsigned accum, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned fract roundur(unsigned fract, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned long accum roundulk(unsigned long accum, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned long fract roundulr(unsigned long fract, int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned short accum sqrtuhk(unsigned short accum);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned short fract sqrtuhr(unsigned short fract);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned accum sqrtuk(unsigned accum);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned fract sqrtur(unsigned fract);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned long fract sqrtulr(unsigned long fract);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned short accum uhksqrtus(unsigned short);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

#ifdef LIBC_COMPILER_HAS_FIXED_POINT
unsigned accum uksqrtui(unsigned int);
#endif // LIBC_COMPILER_HAS_FIXED_POINT

__END_C_DECLS

 #endif // LLVM_LIBC_STDFIX_H