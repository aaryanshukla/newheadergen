import unittest
from class_implementation.classes.macro import Macro

class TestMacro(unittest.TestCase):
    def test_macro_definition(self):
        macro = Macro("FE_DIVBYZERO")
        expected_output = "#define FE_DIVBYZERO"
        self.assertEqual(str(macro), expected_output)

    def test_macro_with_value(self):
        macro = Macro("_IONBF", 2)
        expected_output = "#define _IONBF 2"
        self.assertEqual(str(macro), expected_output)

    def test_macro_include_macro(self):
        macro = Macro("null-macro")
        expected_output = f'#include "llvm-libc-macros/null-macro.h"'
        self.assertEqual(str(macro), expected_output)

    def test_macro_include_macros(self):
        macro = Macro("termios-macros")
        expected_output = f'#include "llvm-libc-macros/termios-macros.h"'
        self.assertEqual(str(macro), expected_output)

if __name__ == '__main__':
    unittest.main()
