class Type:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return f"#include <llvm-libc-types/{self.name}.h>"
    
# type_dict = {
#     # spec.td
#     # Builtin types, don't have to be a NamedType
#     # not in type files: build/projects/libc/include/llvm-libc-types
#     "VarArgType": "...",
#     "VaListType": "va_list",
#     "VoidType": "void",
#     "IntType": "int",
#     "UnsignedIntType": "unsigned int",
#     "LongType": "long",
#     "UnsignedLongType": "unsigned long",
#     "LongLongType": "long long",
#     "UnsignedLongLongType": "unsigned long long",
#     "FloatType": "float",
#     "DoubleType": "double",
#     "LongDoubleType": "long double",
#     "CharType": "char",
#     "UnsignedCharType": "unsigned char",
#     "UnsignedShortType": "unsigned short",
#     "BoolType": "bool",

#     "Float16Type": "_Float16",
#     "Float128Type": "float128",

#     # math.h but can't find the NamedType anywhere
#     "float_t": "float_t",
#     "double_t": "double_t",
#     "float128": "float128",

#     "SizeTType": "size_t",
#     "Char8TType": "char8_t",
#     "Char16TType": "char16_t",
#     "Char32TType": "char32_t",
#     "WCharType": "wchar_t",
#     "WIntType": "wint_t",
#     "IntMaxTType": "intmax_t",
#     "UIntMaxTType": "uintmax_t",
#     "UInt16Type": "uint16_t",
#     "UInt32Type": "uint32_t",
#     "OffTType": "off_t",
#     "SSizeTType": "ssize_t",
#     # no return not really a type but convenient to treat as such
#     "NoReturn": "_Noreturn void",
#     "OnceFlagType": "once_flag",
#     "CallOnceFuncType": "__call_once_func_t",
#     "MtxTType": "mtx_t",
#     "CndTType": "cnd_t",
#     "ThrdStartTType": "thrd_start_t",
#     "ThrdTType": "thrd_t",
#     "SigHandlerT": "__sighandler_t",
#     "TimeTType": "time_t",
#     "StructTimeSpec": "struct timespec",
#     "BSearchCompareT": "__bsearchcompare_t",
#     "QSortCompareT": "__qsortcompare_t",
#     "AtexitHandlerT": "__atexithandler_t",
#     "FILE": "FILE",
#     "PThreadTType": "pthread_t",
#     "PidT": "pid_t",
#     "StructRUsage": "struct_usage",
#     "StructTimevalType": "struct_timeval",
#     "SuSecondsT": "suseconds_t",
#     "UnsignedType": "unsigned",
#     "ActionType": "ACTION",
#     "EntryType": "ENTRY",
#     "MBStateTType": "mbstate_t",
    
#     # stdc.td
#     "StructTmType": "struct_tm",
#     "ClockT": "clock_t",
#     "DivTType": "div_t",
#     "LDivTType": "ldiv_t",
#     "LLDivTType": "lldiv_t",
#     "JmpBuf": "jmp_buf",
#     "TssTType": "tss_t",
#     "TssDtorTType": "tss_dtor_t",
#     "fenv_t": "FEnvT",
#     "fexcept_t": "FExceptT",
#     "IMaxDivTType": "imaxdiv_t",
#     "SigAtomicT": "sig_atomic_t",

#     # stdc_ext.td
#     # not in type files: build/projects/libc/include/llvm-libc-types
#     "ShortFractType": "short fract",
#     "FractType": "fract",
#     "LongFractType": "long fract",
#     "UnsignedShortFractType": "unsigned short fract",
#     "UnsignedFractType": "unsigned fract",
#     "UnsignedLongFractType": "unsigned long fract",
#     "ShortAccumType": "short accum",
#     "AccumType": "accum",
#     "LongAccumType": "long accum",
#     "UnsignedShortAccumType": "unsigned short accum",
#     "UnsignedAccumType": "unsigned accum",
#     "UnsignedLongAccumType": "unsigned long accum",

#     # posix.td
#     "SigSetType": "sigset_t",
#     "SigInfoType": "siginfo_t",
#     # named type didn't have underscore
#     "UnionSigVal": "union_sigval",
#     "StructSigaction": "struct_sigaction",
#     "PThreadStartT": "__pthread_start_t",
#     "PThreadTSSDtorT": "__pthread_tss_dtor_t",
#     "PThreadKeyT": "pthread_key_t",
#     "PThreadOnceT": "pthread_once_t",
#     "PThreadOnceCallback": "__pthread_once_func_t",
#     "InoT": "ino_t",
#     "UidT": "uid_t",
#     "GidT": "gid_t",
#     "DevT": "dev_t",
#     "ClockIdT": "clockid_t",
#     "BlkSizeT": "blksize_t",
#     "BlkCntT": "blkcnt_t",
#     "NLinkT": "nlink_t",
#     # named type didn't have underscore
#     "StatType": "struct_stat",
#     "DIR": "DIR",
#     # named type didn't have underscore
#     "StructDirent": "struct_dirent",
#     # named type didn't have underscore
#     "StructSchedParam": "struct_sched_param",
#     "ExecArgvT": "__exec_argv_t",
#     "ExecEnvpT": "__exec_envp_t",
#     "AtForkCallbackT": "__atfork_callback_t",
#     "PosixSpawnFileActionsT": "posix_spawn_file_actions_t",
#     "PosixSpawnAttrT": "posix_spawnattr_t",
#     "CcT": "cc_t",
#     "SpeedT": "speed_t",
#     # named type didn't have underscore
#     "StructTermios": "struct_termios",
#     "TcFlagT": "tcflag_t",
#     "StackT": "stack_t",
#     "FdSet": "fd_set",
#     "GetoptArgvT": "__getoptargv_t",
#     "SAFamilyType": "sa_family_t",
#     "SocklenType": "socklen_t",
#     # named type didn't have underscore
#     "StructSockAddr": "struct_sockaddr",
#     # named type didn't have underscore
#     "StructSockAddrUn": "struct_sockaddr_un",
#     # named type didn't have underscore
#     "StructStatvfs": "struct_statvfs",
#     "ModeTType": "mode_t",
#     "PThreadAttrTType": "pthread_attr_t",
#     "PThreadCondAttrTType": "pthread_condattr_t",
#     "PThreadRWLockAttrTType": "pthread_rwlockattr_t",
#     "PThreadMutexAttrTType": "pthread_mutexattr_t",
#     "PThreadMutexTType": "pthread_mutex_t",
#     "RLimTType": "rlim_t",
#     # named type didn't have underscore
#     "StructRLimitType": "struct_rlimit",
#     # named type didn't have underscore
#     "StructUtsName": "struct_utsname",

#     # linux.td
#     "StructEpollEvent": "struct_epoll_event",
#     "StructEpollData": "struct_epoll_data",

#     #gnu_ext.td
#     "CpuSetT": "cpu_set_t",
#     "QSortRCompareT": "__qsortrcompare_t",
#     "StructHsearchData": "struct_hsearch_data",
#     "CookieIOFunctionsT": "cookie_io_functions_t"
# }