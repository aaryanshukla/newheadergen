//===-- POSIX header wait.h -----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SYS_WAIT_H
#define LLVM_LIBC_SYS_WAIT_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/sys-wait-macros.h"


#include <llvm-libc-types/struct_rusage.h>
__BEGIN_C_DECLS

pid_t wait4(pid_t, int *, int, struct rusage *);

__END_C_DECLS


#endif // LLVM_LIBC_SYS_WAIT_H
