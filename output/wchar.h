#ifndef LLVM_LIBC_WCHAR_H
#define LLVM_LIBC_WCHAR_H

#include "__llvm-libc-common.h"

#include <llvm-libc-types/wchar-macros.h>
#include <llvm-libc-types/size_t.h>
#include <llvm-libc-types/wint_t.h>
#include <llvm-libc-types/wchar_t.h>
__BEGIN_C_DECLS

int wctob(wint_t);

__END_C_DECLS

 #endif // LLVM_LIBC_WCHAR_H