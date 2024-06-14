import unittest
from enums import Enumeration

class TestEnums(unittest.TestCase):
    def test_macro_definition(self):
        macro = Enumeration("thrd_nomem")
        expected_output = "thrd_nomem,"
        self.assertEqual(str(macro), expected_output)

    def test_macro_with_value(self):
        macro = Enumeration("example_enum", 1)
        expected_output = "example_enum = 1,"
        self.assertEqual(str(macro), expected_output)

if __name__ == '__main__':
    unittest.main()