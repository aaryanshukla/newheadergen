#ifndef LLVM_LIBC_STRING_H
#define LLVM_LIBC_STRING_H

#include "__llvm-libc-common.h"

#define NULL
#include <llvm-libc-types/size_t.h>
__BEGIN_C_DECLS

size_t strlen(const char *);

__END_C_DECLS

 #endif // LLVM_LIBC_STRING_H