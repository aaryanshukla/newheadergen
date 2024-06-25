//===-- GPU header rpc.h --------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_GPU_RPC_H
#define LLVM_LIBC_GPU_RPC_H

#include "__llvm-libc-common.h"

#include "llvm-libc-types/rpc_opcodes_t.h"


__BEGIN_C_DECLS

void rpc_host_call(void *, void *, size_t);

int rpc_fprintf(::FILE *__restrict, const char *__restrict, void *, size_t);

__END_C_DECLS


#endif // LLVM_LIBC_GPU_RPC_H
