class Macro:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        if self.name.endswith("-macros"):
            return f'#include "llvm-libc-macros/{self.name}.h"'
        return f"#define {self.name}"
