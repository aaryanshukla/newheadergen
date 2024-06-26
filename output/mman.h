//===-- POSIX header mman.h -----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SYS_MMAN_H
#define LLVM_LIBC_SYS_MMAN_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/sys-mman-macros.h"


#include <llvm-libc-types/mode_t.h>
#include <llvm-libc-types/size_t.h>
#include <llvm-libc-types/off_t.h>
__BEGIN_C_DECLS

int mincore(void *, size_t, unsigned char *);

int mlock2(void *, size_t, unsigned int);

__END_C_DECLS


#endif // LLVM_LIBC_SYS_MMAN_H
