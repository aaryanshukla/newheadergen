#ifndef LLVM_LIBC_SETJMP_H
#define LLVM_LIBC_SETJMP_H

#include "__llvm-libc-common.h"

#include <llvm-libc-types/JmpBuf.h>

__BEGIN_C_DECLS

void longjmp(_jmp_buf, int);

int setjmp(_jmp_buf);

__END_C_DECLS

 #endif // LLVM_LIBC_SETJMP_H