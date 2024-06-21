class Macro:
    def __init__(self, name, value = None):
        self.name = name
        self.value = value

    def __str__(self):
        if self.name.endswith("-macros") or self.name.endswith("-macro"):
            return f'#include "llvm-libc-macros/{self.name}.h"'
        elif self.value != self.name:
            return f'#define {self.name} {self.value}'
        else:
            return f"#define {self.name}"
