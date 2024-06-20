#ifndef LLVM_LIBC_LINUX-TIME_H
#define LLVM_LIBC_LINUX-TIME_H

#include "__llvm-libc-common.h"

#define timeradd
#define timersub
#define timerclear
#define timerisset
#define timercmp
#include <llvm-libc-types/struct timeval.h>
__BEGIN_C_DECLS

__END_C_DECLS

 #endif // LLVM_LIBC_LINUX-TIME_H