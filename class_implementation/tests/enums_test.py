import unittest
from class_implementation.classes.enums import Enumeration

class TestEnums(unittest.TestCase):
    def test_enum_definition(self):
        enumeration = Enumeration("thrd_nomem")
        expected_output = "thrd_nomem,"
        self.assertEqual(str(enumeration), expected_output)

    def test_enum_with_value(self):
        macro = Enumeration("example_enum", 1)
        expected_output = "example_enum = 1,"
        self.assertEqual(str(macro), expected_output)

if __name__ == '__main__':
    unittest.main()