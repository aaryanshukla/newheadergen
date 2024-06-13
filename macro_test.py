import unittest
from macro import Macro

class TestMacro(unittest.TestCase):
    def test_macro_definition(self):
        macro = Macro("FE_DIVBYZERO")
        expected_output = "#define FE_DIVBYZERO"
        self.assertEqual(str(macro), expected_output)

    def test_macro_with_special_characters(self):
        macro = Macro("FE_INEXACT_1")
        expected_output = "#define FE_INEXACT_1"
        self.assertEqual(str(macro), expected_output)

if __name__ == '__main__':
    unittest.main()
