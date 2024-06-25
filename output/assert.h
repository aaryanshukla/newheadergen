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


#define static_assert None
#define assert None
__BEGIN_C_DECLS

__END_C_DECLS

