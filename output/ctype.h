#ifndef LLVM_LIBC_CTYPE_H
#define LLVM_LIBC_CTYPE_H

#include "__llvm-libc-common.h"

__BEGIN_C_DECLS

int isalnum(int);

int isalpha(int);

int isblank(int);

int iscntrl(int);

int isdigit(int);

int isgraph(int);

int islower(int);

int isprint(int);

int ispunct(int);

int isspace(int);

int isupper(int);

int isxdigit(int);

int tolower(int);

int toupper(int);

int isascii(int);

__END_C_DECLS

 #endif // LLVM_LIBC_CTYPE_H