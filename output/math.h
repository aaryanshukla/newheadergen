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

#ifdef LIBC_TYPES_HAS_FLOAT128
Float128Type fabsf128(Float128Type);
#endif // LIBC_TYPES_HAS_FLOAT128

__END_C_DECLS

 #endif // LLVM_LIBC_MATH_H