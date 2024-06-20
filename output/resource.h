#ifndef LLVM_LIBC_RESOURCE_H
#define LLVM_LIBC_RESOURCE_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/sys-resource-macros"
#include <llvm-libc-types/struct_rlimit.h>
#include <llvm-libc-types/rlim_t.h>
__BEGIN_C_DECLS

int getrlimit(struct rlimit *);

int setrlimit(const struct rlimit);

__END_C_DECLS

 #endif // LLVM_LIBC_RESOURCE_H