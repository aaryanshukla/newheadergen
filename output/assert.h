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


#define None 
#ifndef __cplusplus
#undef static_assert
#define static_assert _Static_assert
#endif

#undef assert
#ifdef NDEBUG
#define assert(e) (void)0
#else
#ifdef __cplusplus
extern "C"
#endif
_Noreturn void __assert_fail(const char *, const char *, unsigned, const char *) __NOEXCEPT;
#define assert(e)  \
((e) ? (void)0 : __assert_fail(#e, __FILE__, __LINE__, __PRETTY_FUNCTION__))
#endif

__BEGIN_C_DECLS

#ifdef __cplusplus
[[noreturn]] void __assert_fail(const char *, const char *, unsigned, const char *)__NOEXCEPT;
#endif // __cplusplus

__END_C_DECLS

