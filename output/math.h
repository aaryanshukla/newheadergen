//===-- C standard library header math.h ----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_MATH_H
#define LLVM_LIBC_MATH_H

#include "__llvm-libc-common.h"
#include "llvm-libc-macros/float16-macros.h"
#include "llvm-libc-macros/math-macros.h"
#include "llvm-libc-types/float128.h"



#include <llvm-libc-types/float_t.h>
#include <llvm-libc-types/double_t.h>
#include <llvm-libc-types/float128.h>
__BEGIN_C_DECLS

double copysign(double, double);

float copysignf(float, float);

long double copysignl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 copysignf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 copysignf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double ceil(double);

float ceilf(float);

long double ceill(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 ceilf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 ceilf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double fabs(double)__LIBC_CONST_ATTR;

float fabsf(float);

long double fabsl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fabsf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fabsf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double fdim(double, double);

float fdimf(float, float);

long double fdiml(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fdimf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fdimf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double floor(double);

float floorf(float);

long double floorl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 floorf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 floorf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double fmin(double, double);

float fminf(float, float);

long double fminl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fminf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

float128 fminf128(float128, float128);

double fmax(double, double);

float fmaxf(float, float);

long double fmaxl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fmaxf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

float128 fmaxf128(float128, float128);

double fmaximum(double, double);

float fmaximumf(float, float);

long double fmaximuml(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fmaximumf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fmaximumf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double fmaximum_num(double, double);

float fmaximum_numf(float, float);

long double fmaximum_numl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fmaximum_numf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fmaximum_numf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double fmaximum_mag(double, double);

float fmaximum_magf(float, float);

long double fmaximum_magl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fmaximum_magf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fmaximum_magf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double fmaximum_mag_num(double, double);

float fmaximum_mag_numf(float, float);

long double fmaximum_mag_numl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fmaximum_mag_numf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fmaximum_mag_numf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double fminimum(double, double);

float fminimumf(float, float);

long double fminimuml(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fminimumf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fminimumf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double fminimum_num(double, double);

float fminimum_numf(float, float);

long double fminimum_numl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fminimum_numf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fminimum_numf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double fminimum_mag(double, double);

float fminimum_magf(float, float);

long double fminimum_magl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fminimum_magf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fminimum_magf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double fminimum_mag_num(double, double);

float fminimum_mag_numf(float, float);

long double fminimum_mag_numl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fminimum_mag_numf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fminimum_mag_numf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double fma(double, double, double);

float fmaf(float, float, float);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 f16fmaf(float, float, float);
#endif // LIBC_TYPES_HAS_FLOAT16

double fmod(double, double);

float fmodf(float, float);

long double fmodl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT128
_Float16 fmodf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT128

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fmodf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double frexp(double, int *);

float frexpf(float, int *);

long double frexpl(long double, int *);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 frexpf16(_Float16, int *);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 frexpf128(float128, int *);
#endif // LIBC_TYPES_HAS_FLOAT128

double fromfp(double, int, unsigned int);

float fromfpf(float, int, unsigned int);

long double fromfpl(long double, int, unsigned int);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fromfpf16(_Float16, int, unsigned int);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fromfpf128(float128, int, unsigned int);
#endif // LIBC_TYPES_HAS_FLOAT128

double fromfpx(double, int, unsigned int);

float fromfpxf(float, int, unsigned int);

long double fromfpxl(long double, int, unsigned int);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 fromfpxf16(_Float16, int, unsigned int);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 fromfpxf128(float128, int, unsigned int);
#endif // LIBC_TYPES_HAS_FLOAT128

double ufromfp(double, int, unsigned int);

float ufromfpf(float, int, unsigned int);

long double ufromfpl(long double, int, unsigned int);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 ufromfpf16(_Float16, int, unsigned int);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 ufromfpf128(float128, int, unsigned int);
#endif // LIBC_TYPES_HAS_FLOAT128

double ufromfpx(double, int, unsigned int);

float ufromfpxf(float, int, unsigned int);

long double ufromfpxl(long double, int, unsigned int);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 ufromfpxf16(_Float16, int, unsigned int);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 ufromfpxf128(float128, int, unsigned int);
#endif // LIBC_TYPES_HAS_FLOAT128

double hypot(double, double);

float hypotf(float, float);

int ilogb(double);

int ilogbf(float);

int ilogbl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
int ilogbf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
int ilogbf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

long llogb(double);

long llogbf(float);

long llogbl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
long llogbf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
long llogbf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double ldexp(double, int);

float ldexpf(float, int);

long double ldexpl(long double, int);

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 ldexpf128(float128, int);
#endif // LIBC_TYPES_HAS_FLOAT128

double log10(double);

float log10f(float);

double log1p(double);

float log1pf(float);

double log2(double);

float log2f(float);

double log(double);

float logf(float);

double log1p(double);

float log1pf(float);

double log2(double);

float log2f(float);

double logb(double);

float logbf(float);

long double logbl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 logbf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 logbf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double modf(double, double *);

float modff(float, float *);

long double modfl(long double, long double *);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 modff16(_Float16, _Float16 *);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 modff128(float128, float128 *);
#endif // LIBC_TYPES_HAS_FLOAT128

double cos(double);

float cosf(float);

double sin(double);

void sincosf(float, float *, float *);

float sinf(float);

double tan(double);

float tanf(float);

float erff(float);

double exp(double);

float expf(float);

double exp2(double);

float exp2f(float);

float exp2m1f(float);

double expm1(double);

float expm1f(float);

double exp10(double);

float exp10f(float);

double remainder(double, double);

float remainderf(float, float);

long double remainderl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 remainderf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

double remquo(double, double, int *);

float remquof(float, float, int *);

long double remquol(long double, long double, int *);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 remquof16(_Float16, _Float16, int *);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 remquof128(float128, float128, int *);
#endif // LIBC_TYPES_HAS_FLOAT128

double round(double);

float roundf(float);

long double roundl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 roundf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 roundf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double roundeven(double);

float roundevenf(float);

long double roundevenl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 roundevenf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 roundevenf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

long lround(double);

long lroundf(float);

long lroundl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
long lroundf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
long lroundf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

Longlong llround(double);

Longlong llroundf(float);

Longlong llroundl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
Longlong llroundf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Longlong llroundf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double rint(double);

float rintf(float);

long double rintl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 rintf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 rintf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

long lrint(double);

long lrintf(float);

long lrintl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
long lrintf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
long lrintf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

Longlong llrint(double);

Longlong llrintf(float);

Longlong llrintl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
Longlong llrintf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Longlong llrintf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double sqrt(double);

float sqrtf(float);

long double sqrtl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 sqrtf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double trunc(double);

float truncf(float);

long double truncl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 truncf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 truncf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double nearbyint(double);

float nearbyintf(float);

long double nearbyintl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 nearbyintf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 nearbyintf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

float nextafterf(float, float);

double nextafter(double, double);

long double nextafterl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 nextafterf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 nextafterf128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

float nexttowardf(float, long double);

double nexttoward(double, long double);

long double nexttowardl(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 nexttowardf16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

double nextdown(double);

float nextdownf(float);

long double nextdownl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 nextdownf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 nextdownf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

double nextup(double);

float nextupf(float);

long double nextupl(long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 nextupf16(_Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 nextupf128(float128);
#endif // LIBC_TYPES_HAS_FLOAT128

float powf(float, float);

double pow(double, double);

float coshf(float);

float sinhf(float);

float tanhf(float);

float acosf(float);

float asinf(float);

double asin(double);

float atanf(float);

float atan2f(float, float);

float acoshf(float);

float asinhf(float);

float atanhf(float);

double scalbn(double, int);

float scalbnf(float, int);

long double scalbnl(long double, int);

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 scalbnf128(float128, int);
#endif // LIBC_TYPES_HAS_FLOAT128

float nanf(const char *);

double nan(const char *);

long double nanl(const char *);

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 nanf16(const char *);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
float128 nanf128(const char *);
#endif // LIBC_TYPES_HAS_FLOAT128

int canonicalize(double, double);

int canonicalizef(float, float);

int canonicalizel(long double, long double);

#ifdef LIBC_TYPES_HAS_FLOAT16
int canonicalizef16(_Float16, _Float16);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
int canonicalizef128(float128, float128);
#endif // LIBC_TYPES_HAS_FLOAT128

#ifdef LIBC_TYPES_HAS_FLOAT16
int totalorderf16(_Float16 *, _Float16 *);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT16
int totalordermagf16(_Float16 *, _Float16 *);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT16
_Float16 f16sqrtf(float);
#endif // LIBC_TYPES_HAS_FLOAT16

__END_C_DECLS


#endif // LLVM_LIBC_MATH_H
