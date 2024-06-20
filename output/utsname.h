#ifndef LLVM_LIBC_UTSNAME_H
#define LLVM_LIBC_UTSNAME_H

#include "__llvm-libc-common.h"

#include <llvm-libc-types/struct utsname.h>
__BEGIN_C_DECLS

int uname(struct utsname *);

__END_C_DECLS

 #endif // LLVM_LIBC_UTSNAME_H