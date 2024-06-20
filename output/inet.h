#ifndef LLVM_LIBC_INET_H
#define LLVM_LIBC_INET_H

#include "__llvm-libc-common.h"

#include <llvm-libc-types/uint32_t.h>
#include <llvm-libc-types/uint16_t.h>
#include <llvm-libc-types/inttypes.h.h>
__BEGIN_C_DECLS

uint32_t htonl(uint32_t);

uint16_t htons(uint16_t);

uint32_t ntohl(uint32_t);

uint16_t ntohs(uint16_t);

__END_C_DECLS

 #endif // LLVM_LIBC_INET_H