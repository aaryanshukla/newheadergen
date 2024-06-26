//===-- C standard library header fenv.h ----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_FENV_H
#define LLVM_LIBC_FENV_H

#include "__llvm-libc-common.h"
#include "llvm-libc-macros/fenv-macros.h"


#include <llvm-libc-types/fenv_t.h>
#include <llvm-libc-types/fexcept_t.h>
__BEGIN_C_DECLS

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

int fedisableexcept(int);

int feenableexcept(int);

int fegetexcept();

__END_C_DECLS


#endif // LLVM_LIBC_FENV_H