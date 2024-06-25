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

asctime ['struct tm *']();

asctime_r ['struct tm *', 'char *']();

clock_gettime ['clockid_t', 'struct timespec *']();

clock []();

difftime ['time_t', 'time_t']();

gettimeofday ['struct timeval *', 'void *']();

gmtime ['time_t *']();

gmtime_r ['time_t *', 'struct tm *']();

mktime ['struct tm *']();

nanosleep ['const struct timespec *', 'struct timespec *']();

time ['time_t *']();

__END_C_DECLS


#endif // LLVM_LIBC_SYS_TIME_H
