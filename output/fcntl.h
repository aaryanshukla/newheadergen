#ifndef LLVM_LIBC_FCNTL_H
#define LLVM_LIBC_FCNTL_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/macros/fcntl-macros"
#include <llvm-libc-types/off_t.h>
#include <llvm-libc-types/mode_t.h>
__BEGIN_C_DECLS

int creat(const char *, mode_t);

int fcntl(int, int, ...);

int open(const char *, int, ...);

int openat(int, const char *, int, ...);

__END_C_DECLS

 #endif // LLVM_LIBC_FCNTL_H