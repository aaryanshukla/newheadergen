class Macro:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return f"#define {self.name}"

# full dictionary in type.py
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

class Enumeration:
    def __init__(self, name, values):
        self.name = name
        self.values = values

    def __str__(self):
        values_str = ", ".join([f"{name} = {value}" for name, value in self.values.items()])
        return f"enum {self.name} {{{values_str}}};"
    
class Function: 
    def __init__(self, return_type, name, arguments, guard=None, attributes=None):
        self.return_type = return_type
        self.name = name
        self.arguments = arguments
        self.guard = guard
        self.attributes = attributes or []

    def __str__(self):
        args_str = ", ".join(self.arguments)
        attributes_str = " ".join(self.attributes)
        return f"{self.return_type} {self.name}({args_str}){attributes_str};"
    
class HeaderFile: 
    def __init__(self, name):
        self.name = name
        self.macros = []
        self.types = []
        self.enumerations = []
        self.functions = []

    def add_macro(self, macro):
        self.macros.append(macro)

    def add_type(self, type_):
        self.types.append(type_)

    def add_enumeration(self, enumeration):
        self.enumerations.append(enumeration)

    def add_function(self, function):
        self.functions.append(function)

    def __str__(self):
        header_guard = self.name.replace('.', '_').upper()
        content = [f"#ifndef {header_guard}", f"#define {header_guard}", ""]

        for macro in self.macros:
            content.append(str(macro))

        for type_ in self.types:
            content.append(str(type_))

        for enum in self.enumerations:
            content.append(str(enum))

        for function in self.functions:
            content.append(str(function))

        content.append(f"#endif // {header_guard}")
        return "\n".join(content)