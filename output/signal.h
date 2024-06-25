//===-- C standard library header signal.h --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SIGNAL_H
#define LLVM_LIBC_SIGNAL_H

#include "__llvm-libc-common.h"

#define __need_size_t
#include <stddef.h>

#include "llvm-libc-macros/signal-macros.h"


#define __need_size_t
#define signal-macros
#include <llvm-libc-types/pid_t.h>
#include <llvm-libc-types/stack_t.h>
#include <llvm-libc-types/siginfo_t.h>
#include <llvm-libc-types/struct_sigaction.h>
#include <llvm-libc-types/sigset_t.h>
#include <llvm-libc-types/union_sigval.h>
#include <llvm-libc-types/sig_atomic_t.h>
__BEGIN_C_DECLS

int raise(int);

int kill(pid_t, int);

int sigaction(int, const struct sigaction * __restrict, struct sigaction * __restrict);

int sigaltstack(const stack_t * __restrict, stack_t * __restrict);

int sigdelset(sigset_t *, int);

int sigaddset(sigset_t *, int);

int sigemptyset(sigset_t *);

int sigprocmask(int, const sigset_t * __restrict, sigset_t * __restrict);

int sigfillset(sigset_t *);

__sighandler_t signal(int, __sighandler_t);

__END_C_DECLS


#endif // LLVM_LIBC_SIGNAL_H
