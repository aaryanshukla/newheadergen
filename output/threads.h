#ifndef THREADS_H
#define THREADS_H

#define ONCE_FLAG_INIT
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
VoidType ['OnceFlagTypePtr', 'CallOnceFuncType'](c, a, l, l, _, o, n, c, e);
IntType ['CndTTypePtr'](c, n, d, _, b, r, o, a, d, c, a, s, t);
VoidType ['CndTTypePtr'](c, n, d, _, d, e, s, t, r, o, y);
IntType ['CndTTypePtr'](c, n, d, _, i, n, i, t);
IntType ['CndTTypePtr'](c, n, d, _, s, i, g, n, a, l);
IntType ['CndTTypePtr', 'MtxTTypePtr'](c, n, d, _, w, a, i, t);
IntType ['MtxTTypePtr', 'IntType'](m, t, x, _, i, n, i, t);
IntType ['VoidType'](m, t, x, _, d, e, s, t, r, o, y);
IntType ['MtxTTypePtr'](m, t, x, _, l, o, c, k);
IntType ['MtxTTypePtr'](m, t, x, _, u, n, l, o, c, k);
IntType ['ThrdTTypePtr', 'ThrdStartTType', 'VoidPtr'](t, h, r, d, _, c, r, e, a, t, e);
IntType ['ThrdTType', 'IntPtr'](t, h, r, d, _, j, o, i, n);
IntType ['ThrdTType'](t, h, r, d, _, d, e, t, a, c, h);
ThrdTType ['VoidType'](t, h, r, d, _, c, u, r, r, e, n, t);
IntType ['ThrdTType', 'ThrdTType'](t, h, r, d, _, e, q, u, a, l);
VoidType ['IntType'](t, h, r, d, _, e, x, i, t);
IntType ['TssTPtr', 'TssDtorTType'](t, s, s, _, c, r, e, a, t, e);
IntType ['TssTType'](t, s, s, _, d, e, l, e, t, e);
#endif // THREADS_H