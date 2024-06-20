#ifndef LLVM_LIBC_INTTYPES_H
#define LLVM_LIBC_INTTYPES_H

#include "__llvm-libc-common.h"

#include <llvm-libc-types/imaxdiv_t.h>
#include <llvm-libc-types/inttypes-macros.h>
__BEGIN_C_DECLS

intmax_t imaxabs(intmax_t);

imaxdiv_t imaxdiv(intmax_t, intmax_t);

intmax_t strtoimax(const char *__restrict, char * *__restrict, int);

uintmax_t strtoumax(const char *__restrict, char * *__restrict, int);

__END_C_DECLS

 #endif // LLVM_LIBC_INTTYPES_H