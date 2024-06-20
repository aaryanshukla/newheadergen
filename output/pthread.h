#ifndef LLVM_LIBC_PTHREAD_H
#define LLVM_LIBC_PTHREAD_H

#include "__llvm-libc-common.h"

#define PTHREAD_STACK_MIN (1 << 14)
#define PTHREAD_MUTEX_INITIALIZER {0}
#define PTHREAD_ONCE_INIT {0}
#define PTHREAD_PROCESS_PRIVATE 0
#define PTHREAD_PROCESS_SHARED 1
#define PTHREAD_RWLOCK_PREFER_READER_NP 0
#define PTHREAD_RWLOCK_PREFER_WRITER_NP 1
#define PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP 2
#include <llvm-libc-types/pthread_t.h>
#include <llvm-libc-types/pthread_once_t.h>
#include <llvm-libc-types/pthread_mutex_t.h>
#include <llvm-libc-types/pthread_mutexattr_t.h>
#include <llvm-libc-types/pthread_key_t.h>
#include <llvm-libc-types/pthread_condattr_t.h>
#include <llvm-libc-types/__pthread_tss_dtor_t.h>
#include <llvm-libc-types/pthread_rwlockattr_t.h>
#include <llvm-libc-types/pthread_attr_t.h>
#include <llvm-libc-types/__pthread_start_t.h>
#include <llvm-libc-types/__pthread_once_func_t.h>
#include <llvm-libc-types/__atfork_callback_t.h>
enum {
	PTHREAD_CREATE_JOINABLE = 0,
	PTHREAD_CREATE_DETACHED = 1,
	PTHREAD_MUTEX_NORMAL = 0,
	PTHREAD_MUTEX_ERRORCHECK = 1,
	PTHREAD_MUTEX_RECURSIVE = 2,
	PTHREAD_MUTEX_DEFAULT = 0,
	PTHREAD_PROCESS_PRIVATE = 0,
	PTHREAD_PROCESS_SHARED = 1,
	PTHREAD_MUTEX_STALLED = 0,
	PTHREAD_MUTEX_ROBUST = 1,
	PTHREAD_RWLOCK_PREFER_READER_NP = 0,
	PTHREAD_RWLOCK_PREFER_WRITER_NP = 1,
	PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP = 2,
};
__BEGIN_C_DECLS

int pthread_atfork(__atfork_callback_t, __atfork_callback_t, __atfork_callback_t);

int pthread_attr_destroy(pthread_attr_t *);

int pthread_attr_init(pthread_attr_t *);

int pthread_attr_getdetachstate(const pthread_attr_t *, int *);

int pthread_attr_getguardsize(const pthread_attr_t * __restrict, size_t * __restrict);

int pthread_attr_getstack(const pthread_attr_t * __restrict, void * * __restrict, size_t * __restrict);

int pthread_attr_getstacksize(const pthread_attr_t * __restrict, size_t * __restrict);

int pthread_attr_setdetachstate(pthread_attr_t *, int);

int pthread_attr_setguardsize(pthread_attr_t *, size_t);

int pthread_attr_setstack(pthread_attr_t *, void *, size_t);

int pthread_attr_setstacksize(pthread_attr_t *, size_t);

int pthread_condattr_destroy(pthread_condattr_t *);

int pthread_condattr_getclock(const pthread_condattr_t * __restrict, clockid_t * __restrict);

int pthread_condattr_getpshared(const pthread_condattr_t * __restrict, int * __restrict);

int pthread_condattr_init(pthread_condattr_t *);

int pthread_condattr_setclock(pthread_condattr_t *, clockid_t);

int pthread_condattr_setpshared(pthread_condattr_t *, int);

int pthread_create(pthread_t * __restrict, const pthread_attr_t * __restrict, __pthread_start_t, void *);

int pthread_detach(pthread_t);

int pthread_equal(pthread_t, pthread_t);

void pthread_exit(void *)noreturn;

int pthread_getname_np(pthread_t, char *, size_t);

void * pthread_getspecific(pthread_key_t);

int pthread_join(pthread_t, void * *);

int pthread_key_create(pthread_key_t *, __pthread_tss_dtor_t);

int pthread_key_delete(pthread_key_t);

pthread_t pthread_self();

int pthread_setname_np(pthread_t, const char *);

int pthread_mutex_destroy(pthread_mutex_t *);

int pthread_mutex_init(pthread_mutex_t * __restrict, const pthread_mutexattr_t * __restrict);

int pthread_mutex_lock(pthread_mutex_t *);

int pthread_mutex_unlock(pthread_mutex_t *);

int pthread_mutexattr_destroy(pthread_mutexattr_t *);

int pthread_mutexattr_init(pthread_mutexattr_t *);

int pthread_mutexattr_getpshared(const pthread_mutexattr_t * __restrict, int * __restrict);

int pthread_mutexattr_getrobust(const pthread_mutexattr_t * __restrict, int * __restrict);

int pthread_mutexattr_gettype(const pthread_mutexattr_t * __restrict, int * __restrict);

int pthread_mutexattr_setpshared(pthread_mutexattr_t * __restrict, int);

int pthread_mutexattr_setrobust(pthread_mutexattr_t * __restrict, int);

int pthread_mutexattr_settype(pthread_mutexattr_t * __restrict, int);

int pthread_once(pthread_once_t *, __pthread_once_func_t);

int pthread_rwlockattr_destroy(pthread_rwlockattr_t *);

int pthread_rwlockattr_getkind_np(pthread_rwlockattr_t *, int *);

int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *, int *);

int pthread_rwlockattr_init(pthread_rwlockattr_t *);

int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t *, int);

int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *, int);

void * pthread_setspecific(pthread_key_t, const void *);

__END_C_DECLS

 #endif // LLVM_LIBC_PTHREAD_H