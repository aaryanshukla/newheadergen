#ifndef LLVM_LIBC_WAIT_H
#define LLVM_LIBC_WAIT_H

#include "__llvm-libc-common.h"

#include <llvm-libc-types/siginfo_t.h>
#include <llvm-libc-types/struct rusage.h>
#include <llvm-libc-types/pid_t.h>
__BEGIN_C_DECLS

pid_t wait(int *);

pid_t wait4(pid_t, int *, int, struct rusage *);

pid_t waitpid(pid_t, int *, int);

__END_C_DECLS

 #endif // LLVM_LIBC_WAIT_H