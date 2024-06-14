import unittest
from arg_type import ArgType

class TestArgType(unittest.TestCase):
    def test_arg_type_definition(self):
        arg_type = ArgType("int", ["const"], ["*"])
        expected_output = "const int *"
        self.assertEqual(str(arg_type), expected_output)

    def test_arg_type_with_multiple_prefix_suffix(self):
        arg_type = ArgType("int", ["void", "const"], ["*", "*"])
        expected_output = "void const int * *"
        self.assertEqual(str(arg_type), expected_output)

    def test_arg_type_only_name(self):
        arg_type = ArgType("int")
        expected_output = "int"
        self.assertEqual(str(arg_type), expected_output)

    def test_arg_type_prefix(self):
        arg_type = ArgType("int", prefixes=["void", "const"])
        expected_output = "void const int"
        self.assertEqual(str(arg_type), expected_output)

    def test_arg_type_(self):
        arg_type = ArgType("int", suffixes=["*"])
        expected_output = "int *"
        self.assertEqual(str(arg_type), expected_output)


if __name__ == '__main__':
    unittest.main()