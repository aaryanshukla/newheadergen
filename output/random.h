#ifndef LLVM_LIBC_RANDOM_H
#define LLVM_LIBC_RANDOM_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/sys-random-macros.h"
#include <llvm-libc-types/ssize_t.h>
#include <llvm-libc-types/size_t.h>
__BEGIN_C_DECLS

ssize_t getrandom(void *, size_t, unsigned int);

__END_C_DECLS

 #endif // LLVM_LIBC_RANDOM_H