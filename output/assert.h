//===-- C standard library header assert.h --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "__llvm-libc-common.h"
#include "llvm-libc-macros/assert-macros.h"

// This file may be usefully included multiple times to change assert()'s
// definition based on NDEBUG.

#define static_assert
#define assert

__BEGIN_C_DECLS

[[noreturn]] __assert_fail(const char *, const char *, unsigned, const char *);

__END_C_DECLS

