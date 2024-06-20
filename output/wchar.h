#ifndef LLVM_LIBC_WCHAR_H
#define LLVM_LIBC_WCHAR_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/wchar-macros"
#include <llvm-libc-types/size_t.h>
#include <llvm-libc-types/None.h>
#include <llvm-libc-types/None.h>
__BEGIN_C_DECLS

int wctob(wint_t);

__END_C_DECLS

 #endif // LLVM_LIBC_WCHAR_H