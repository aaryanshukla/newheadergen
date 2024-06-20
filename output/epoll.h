#ifndef LLVM_LIBC_EPOLL_H
#define LLVM_LIBC_EPOLL_H

#include "__llvm-libc-common.h"

#include <llvm-libc-types/struct epoll_event.h>
#include <llvm-libc-types/struct epoll_data.h>
#include <llvm-libc-types/sigset_t.h>
#include <llvm-libc-types/struct timespec.h>
__BEGIN_C_DECLS

int epoll_create(int);

int epoll_create1(int);

int epoll_ctl(int, int, int, struct epoll_event *);

int epoll_wait(int, struct epoll_event *, int, int);

int epoll_pwait(int, struct epoll_event *, int, int, sigset_t *);

int epoll_pwait2(int, struct epoll_event *, int, const struct timespec *, sigset_t *);

__END_C_DECLS

 #endif // LLVM_LIBC_EPOLL_H