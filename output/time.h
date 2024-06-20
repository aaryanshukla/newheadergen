#ifndef LLVM_LIBC_TIME_H
#define LLVM_LIBC_TIME_H

#include "__llvm-libc-common.h"

#include <llvm-libc-types/struct timeval.h>
#include <llvm-libc-types/clockid_t.h>
#include <llvm-libc-types/struct timespec.h>
#include <llvm-libc-types/struct tm.h>
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

 #endif // LLVM_LIBC_TIME_H