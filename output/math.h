#ifndef LLVM_LIBC_MATH_H
#define LLVM_LIBC_MATH_H

#include "__llvm-libc-common.h"

#define MATH_ERRNO
#define MATH_ERREXCEPT
#define math_errhandling
#define HUGE_VAL
#define INFINITY
#define NAN
#define FP_INT_UPWARD
#define FP_INT_DOWNWARD
#define FP_INT_TOWARDZERO
#define FP_INT_TONEARESTFROMZERO
#define FP_INT_TONEAREST
#define FP_ILOGB0
#define FP_ILOGBNAN
#define isfinite
#define isinf
#define isnan
__BEGIN_C_DECLS

DoubleType copysign(DoubleType, DoubleType);

FloatType copysignf(FloatType, FloatType);

LongDoubleType copysignl(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type copysignf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type copysignf128(Float128Type, Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType ceil(DoubleType);

FloatType ceilf(FloatType);

LongDoubleType ceill(LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type ceilf16(Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type ceilf128(Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType fabs(DoubleType)__LIBC_CONST_ATTR;

FloatType fabsf(FloatType);

LongDoubleType fabsl(LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fabsf16(Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fabsf128(Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType fdim(DoubleType, DoubleType);

FloatType fdimf(FloatType, FloatType);

LongDoubleType fdiml(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fdimf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fdimf128(Float128Type, Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType floor(DoubleType);

FloatType floorf(FloatType);

LongDoubleType floorl(LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type floorf16(Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type floorf128(Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType fmin(DoubleType, DoubleType);

FloatType fminf(FloatType, FloatType);

LongDoubleType fminl(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fminf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

Float128Type fminf128(Float128Type, Float128Type);

DoubleType fmax(DoubleType, DoubleType);

FloatType fmaxf(FloatType, FloatType);

LongDoubleType fmaxl(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fmaxf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

Float128Type fmaxf128(Float128Type, Float128Type);

DoubleType fmaximum(DoubleType, DoubleType);

FloatType fmaximumf(FloatType, FloatType);

LongDoubleType fmaximuml(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fmaximumf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fmaximumf128(Float128Type, Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType fmaximum_num(DoubleType, DoubleType);

FloatType fmaximum_numf(FloatType, FloatType);

LongDoubleType fmaximum_numl(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fmaximum_numf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fmaximum_numf128(Float128Type, Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType fmaximum_mag(DoubleType, DoubleType);

FloatType fmaximum_magf(FloatType, FloatType);

LongDoubleType fmaximum_magl(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fmaximum_magf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fmaximum_magf128(Float128Type, Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType fmaximum_mag_num(DoubleType, DoubleType);

FloatType fmaximum_mag_numf(FloatType, FloatType);

LongDoubleType fmaximum_mag_numl(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fmaximum_mag_numf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fmaximum_mag_numf128(Float128Type, Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType fminimum(DoubleType, DoubleType);

FloatType fminimumf(FloatType, FloatType);

LongDoubleType fminimuml(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fminimumf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fminimumf128(Float128Type, Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType fminimum_num(DoubleType, DoubleType);

FloatType fminimum_numf(FloatType, FloatType);

LongDoubleType fmaximum_numl(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fminimum_numf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fminimum_numf128(Float128Type, Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType fminimum_mag(DoubleType, DoubleType);

FloatType fminimum_magf(FloatType, FloatType);

LongDoubleType fminimum_magl(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fminimum_magf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fminimum_magf128(Float128Type, Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType fminimum_mag_num(DoubleType, DoubleType);

FloatType fminimum_mag_numf(FloatType, FloatType);

LongDoubleType fminimum_mag_numl(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT16
Float16Type fminimum_mag_numf16(Float16Type, Float16Type);
#endif // LIBC_TYPES_HAS_FLOAT16

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fminimum_mag_numf128(Float128Type, Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

DoubleType fma(DoubleType, DoubleType, DoubleType);

FloatType fmaf(FloatType, FloatType, FloatType);

DoubleType fmod(DoubleType, DoubleType);

FloatType fmodf(FloatType, FloatType);

LongDoubleType fmodl(LongDoubleType, LongDoubleType);

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fmodf128(Float128Type, Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

__END_C_DECLS

#endif // MATH_H