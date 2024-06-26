//===-- Linux header time.h -----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SYS_TIME_H
#define LLVM_LIBC_SYS_TIME_H

#include "__llvm-libc-common.h"

#include "llvm-libc-types/struct_timeval.h"

#include "llvm-libc-macros/sys-time-macros.h"


#include <llvm-libc-types/struct_timeval.h>
#include <llvm-libc-types/clockid_t.h>
#include <llvm-libc-types/struct_timespec.h>
#include <llvm-libc-types/struct_tm.h>
#include <llvm-libc-types/time_t.h>
#include <llvm-libc-types/clock_t.h>
__BEGIN_C_DECLS

char * asctime(struct tm *);

char * asctime_r(struct tm *, char *);

int clock_gettime(clockid_t, struct timespec *);

clock_t clock();

double difftime(time_t, time_t);

int gettimeofday(struct timeval *, void *);

struct tm * gmtime(time_t *);

struct tm * gmtime_r(time_t *, struct tm *);

time_t mktime(struct tm *);

int nanosleep(const struct timespec *, struct timespec *);

time_t time(time_t *);

__END_C_DECLS


#endif // LLVM_LIBC_SYS_TIME_H
