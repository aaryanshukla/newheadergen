#ifndef LLVM_LIBC_SOCKET_H
#define LLVM_LIBC_SOCKET_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/sys-socket-macros"
#include <llvm-libc-types/struct_sockaddr_un.h>
#include <llvm-libc-types/struct_sockaddr.h>
#include <llvm-libc-types/socklen_t.h>
#include <llvm-libc-types/sa_family_t.h>
__BEGIN_C_DECLS

int socket(int, int, int);

int bind(int, const struct sockaddr *, socklen_t);

__END_C_DECLS

 #endif // LLVM_LIBC_SOCKET_H