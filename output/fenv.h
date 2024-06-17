#ifndef FENV_H
#define FENV_H

#define FE_DIVBYZERO
#define FE_INEXACT
#define FE_INVALID
#define FE_OVERFLOW
#define FE_UNDERFLOW
#define FE_ALL_EXCEPT
#define FE_DOWNWARD
#define FE_TONEAREST
#define FE_TOWARDZERO
#define FE_DFL_ENV
#include <llvm-libc-types/FEnvT.h>
#include <llvm-libc-types/FExceptT.h>
int feclearexcept(int);
int fetestexcept(int);
int fetestexceptflag(const fexcept_t *, int);
int feraiseexcept(int);
int fesetround(int);
int fegetround();
int fegetenv(fenv_t *);
int fesetenv(const fenv_t *);
int fegetexceptflag(fexcept_t *, int);
int fesetexcept(int);
int fesetexceptflag(const fexcept_t *, int);
int feholdexcept(fenv_t *);
int feupdateenv(const fenv_t *);
#endif // FENV_H