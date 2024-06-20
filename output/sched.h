#ifndef LLVM_LIBC_SCHED_H
#define LLVM_LIBC_SCHED_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/sched-macros"
#include <llvm-libc-types/struct_timespec.h>
#include <llvm-libc-types/time_t.h>
#include <llvm-libc-types/struct_sched_param.h>
#include <llvm-libc-types/size_t.h>
#include <llvm-libc-types/cpu_set_t.h>
#include <llvm-libc-types/pid_t.h>
__BEGIN_C_DECLS

int sched_get_priority_max(int);

int sched_get_priority_min(int);

int sched_getaffinity(pid_t, size_t, cpu_set_t *);

int sched_getparam(pid_t, struct sched_param *);

int sched_getscheduler(pid_t, int, const struct sched_param *);

int sched_rr_get_interval(pid_t, struct timespec *);

int sched_setaffinity(pid_t, size_t, const cpu_set_t *);

int sched_setparam(pid_t, const struct sched_param *);

int sched_setscheduler(pid_t);

int sched_yield();

int __sched_getcpucount(size_t, const cpu_set_t *);

__END_C_DECLS

 #endif // LLVM_LIBC_SCHED_H