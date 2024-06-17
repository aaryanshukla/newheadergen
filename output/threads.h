#ifndef THREADS_H
#define THREADS_H

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
VoidType call_once(OnceFlagTypePtr, CallOnceFuncType);
IntType cnd_broadcast(CndTTypePtr);
VoidType cnd_destroy(CndTTypePtr);
IntType cnd_init(CndTTypePtr);
IntType cnd_signal(CndTTypePtr);
IntType cnd_wait(CndTTypePtr, MtxTTypePtr);
IntType mtx_init(MtxTTypePtr, IntType);
IntType mtx_destroy(VoidType);
IntType mtx_lock(MtxTTypePtr);
IntType mtx_unlock(MtxTTypePtr);
IntType thrd_create(ThrdTTypePtr, ThrdStartTType, VoidPtr);
IntType thrd_join(ThrdTType, IntPtr);
IntType thrd_detach(ThrdTType);
ThrdTType thrd_current(VoidType);
IntType thrd_equal(ThrdTType, ThrdTType);
VoidType thrd_exit(IntType);
IntType tss_create(TssTPtr, TssDtorTType);
IntType tss_delete(TssTType);
#endif // THREADS_H