//===-- POSIX header statvfs.h --------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SYS_STATVFS_H
#define LLVM_LIBC_SYS_STATVFS_H

#include <__llvm-libc-common.h>


#include <llvm-libc-types/StructStatvfs.h>
__BEGIN_C_DECLS

int statvfs(const char *__restrict, struct statvfs *__restrict);

int fstatvfs(int, struct statvfs *);

__END_C_DECLS


#endif // LLVM_LIBC_SYS_STATVFS_H
