from macro import Macro
from type import Type
from function import Function
from include import Include

class HeaderFile:
    def __init__(self, name):
        self.name = name
        self.macros = []
        self.types = []
        self.enumerations = []
        self.functions = []
        self.includes = []

    def add_macro(self, macro):
        self.macros.append(macro)

    def add_type(self, type_):
        self.types.append(type_)

    def add_enumeration(self, enumeration):
        self.enumerations.append(enumeration)

    def add_function(self, function):
        self.functions.append(function)

    def add_include(self, include):
        self.includes.append(include)

    def __str__(self):
        header_guard = self.name.replace('.', '_').upper()
        content = [f"#ifndef {header_guard}", f"#define {header_guard}", ""]

        for include in self.includes:
            content.append(str(include))

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