//===-- C standard library header strings.h -------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_STRINGS_H
#define LLVM_LIBC_STRINGS_H

#include "__llvm-libc-common.h"


__BEGIN_C_DECLS

void bcopy(const void *, void *, size_t);

void bzero(void *, size_t);

int bcmp(const void *, const void *, size_t);

int strcasecmp(const char *, const char *);

int strncasecmp(const char *, const char *, size_t);

char * index(const char *, int);

char * rindex(const char *, int);

__END_C_DECLS


#endif // LLVM_LIBC_STRINGS_H
