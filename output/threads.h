#ifndef LLVM_LIBC_THREADS_H
#define LLVM_LIBC_THREADS_H

#include "__llvm-libc-common.h"

#define ONCE_FLAG_INIT {0}
#include <llvm-libc-types/once_flag.h>
#include <llvm-libc-types/__call_once_func_t.h>
#include <llvm-libc-types/cnd_t.h>
#include <llvm-libc-types/mtx_t.h>
#include <llvm-libc-types/thrd_start_t.h>
#include <llvm-libc-types/thrd_t.h>
#include <llvm-libc-types/tss_t.h>
#include <llvm-libc-types/tss_dtor_t.h>
enum {
	mtx_plain,
	mtx_recursive,
	mtx_timed,
	thrd_timedout,
	thrd_success,
	thrd_busy,
	thrd_error,
	thrd_nomem,
};
__BEGIN_C_DECLS

void call_once(once_flag *, __call_once_func_t);

int cnd_broadcast(cnd_t *);

void cnd_destroy(cnd_t *);

int cnd_init(cnd_t *);

int cnd_signal(cnd_t *);

int cnd_wait(cnd_t *, mtx_t *);

int mtx_init(mtx_t *, int);

int mtx_destroy(void);

int mtx_lock(mtx_t *);

int mtx_unlock(mtx_t *);

int thrd_create(thrd_t *, thrd_start_t, void *);

int thrd_join(thrd_t, int *);

int thrd_detach(thrd_t);

thrd_t thrd_current(void);

int thrd_equal(thrd_t, thrd_t);

void thrd_exit(int);

int tss_create(tss_t *, tss_dtor_t);

int tss_delete(tss_t);

__END_C_DECLS

 #endif // LLVM_LIBC_THREADS_H