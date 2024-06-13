type_dict = {
    # Builtin types
    "VarArgType": "...",
    "VaListType": "va_list",
    "VoidType": "void",
    "IntType": "int",
    "UnsignedIntType": "unsigned int",
    "LongType": "long",
    "UnsignedLongType": "unsigned long",
    "LongLongType": "long long",
    "UnsignedLongLongType": "unsigned long long",
    "FloatType": "float",
    "DoubleType": "double",
    "LongDoubleType": "long double",
    "CharType": "char",
    "UnsignedCharType": "unsigned char",
    "UnsignedShortType": "unsigned short",
    "BoolType": "bool",

    "Float16Type": "_Float16",
    "Float128Type": "float128",

    "SizeTType": "size_t",
    "Char8TType": "char8_t",
    "Char16TType": "char16_t",
    "Char32TType": "char32_t",
    "WCharType": "wchar_t",
    "WIntType": "wint_t",
    "IntMaxTType": "intmax_t",
    "UIntMaxTType": "uintmax_t",
    "UInt16Type": "uint16_t",
    "UInt32Type": "uint32_t",
    "OffTType": "off_t",
    "SSizeTType": "ssize_t",
    # no return not really a type but convenient to treat as such
    "NoReturn": "_Noreturn void",
    "OnceFlagType": "once_flag",
    "CallOnceFuncType": "__call_once_func_t",
    "MtxTType": "mtx_t",
    "CndTType": "cnd_t",
    "ThrdStartTType": "thrd_start_t",
    "ThrdTType": "thrd_t",
    "SigHandlerT": "__sighandler_t",
    "TimeTType": "time_t",
    "StructTimeSpec": "struct timespec",
    "BSearchCompareT": "__bsearchcompare_t",
    "QSortCompareT": "__qsortcompare_t",
    "AtexitHandlerT": "__atexithandler_t",
    "FILE": "FILE",
    "PThreadTType": "pthread_t",
    "PidT": "pid_t",
    "StructRUsage": "struct rusage",
    "StructTimevalType": "struct timeval",
    "SuSecondsT": "suseconds_t",
    "UnsignedType": "unsigned",
    "ActionType": "ACTION",
    "EntryType": "ENTRY",
    "MBStateTType": "mbstate_t"
}
class Type:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return f"#include <llvm-libc-types/{type_dict[self.name]}.h>"