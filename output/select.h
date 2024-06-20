#ifndef LLVM_LIBC_SELECT_H
#define LLVM_LIBC_SELECT_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/sys-select-macros"
#include <llvm-libc-types/struct_timeval.h>
#include <llvm-libc-types/struct_timespec.h>
#include <llvm-libc-types/suseconds_t.h>
#include <llvm-libc-types/sigset_t.h>
#include <llvm-libc-types/time_t.h>
#include <llvm-libc-types/fd_set.h>
__BEGIN_C_DECLS

int select(int, fd_set *__restrict, fd_set *__restrict, fd_set *__restrict, struct timeval *__restrict);

__END_C_DECLS

 #endif // LLVM_LIBC_SELECT_H