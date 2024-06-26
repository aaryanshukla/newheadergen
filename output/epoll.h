//===-- Linux header epoll.h ----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SYS_EPOLL_H
#define LLVM_LIBC_SYS_EPOLL_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/sys-epoll-macros.h"


#include <llvm-libc-types/struct_epoll_event.h>
#include <llvm-libc-types/struct_epoll_data.h>
#include <llvm-libc-types/sigset_t.h>
#include <llvm-libc-types/struct_timespec.h>
__BEGIN_C_DECLS

int epoll_create(int);

int epoll_create1(int);

int epoll_ctl(int, int, int, struct epoll_event *);

int epoll_wait(int, struct epoll_event *, int, int);

int epoll_pwait(int, struct epoll_event *, int, int, const sigset_t *);

int epoll_pwait2(int, struct epoll_event *, int, const struct timespec *, const sigset_t *);

__END_C_DECLS


#endif // LLVM_LIBC_SYS_EPOLL_H
