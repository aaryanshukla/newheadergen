#ifndef LLVM_LIBC_MMAN_H
#define LLVM_LIBC_MMAN_H

#include "__llvm-libc-common.h"

#include "llvm-libc-macros/sys-mman-macros"
#include <llvm-libc-types/mode_t.h>
#include <llvm-libc-types/size_t.h>
#include <llvm-libc-types/off_t.h>
__BEGIN_C_DECLS

int madvise(void *, size_t, int);

void * mmap(void *, size_t, int, int, int, off_t);

int mprotect(void *, size_t, int);

int munmap(void *, size_t);

int posix_madvise(void *, size_t, int);

int mincore(void *, size_t, unsigned char *);

int mlock(void *, size_t);

int mlock2(void *, size_t, unsigned int);

int munlock(void *, size_t);

int mlockall(int);

int munlockall();

int msync(void *, size_t, int);

int shm_open(const char *, int, mode_t);

int shm_unlink(const char *);

__END_C_DECLS

 #endif // LLVM_LIBC_MMAN_H