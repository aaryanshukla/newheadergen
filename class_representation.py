class Macro:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return f"#define {self.name}"


class Type:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return f"typedef {self.name};"

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