//===-- POSIX header dirent.h ---------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_DIRENT_H
#define LLVM_LIBC_DIRENT_H

#include "__llvm-libc-common.h"


#include <llvm-libc-types/struct dirent.h>
#include <llvm-libc-types/DIR.h>
#include <llvm-libc-types/ino_t.h>
__BEGIN_C_DECLS

int alphasort(const struct dirent **, const struct dirent **);

int closedir(DIR *);

int dirfd(DIR *);

DIR * fdopendir(int);

DIR * opendir(const char *);

struct dirent * readdir(DIR *);

__END_C_DECLS


#endif // LLVM_LIBC_DIRENT_H
