# function_test.py

import unittest
from function import Function

class TestFunction(unittest.TestCase):
    def test_function_without_guard(self):
        func = Function("int", "myFunction", ["int a", "float b"])
        expected_output = "int myFunction(int a, float b);\n"
        self.assertEqual(str(func), expected_output)

    def test_function_with_guard(self):
        func = Function("void", "guardedFunction", ["int x"], guard="GUARD_MACRO")
        expected_output = "#ifdef GUARD_MACRO\nvoid guardedFunction(int x);\n#endif // GUARD_MACRO\n"
        self.assertEqual(str(func), expected_output)

    def test_function_with_attributes(self):
        func = Function("int", "attributedFunction", ["int a"], attributes=["__attribute__((const))"])
        expected_output = "int attributedFunction(int a) __attribute__((const));\n"
        self.assertEqual(str(func), expected_output)

if __name__ == '__main__':
    unittest.main()
