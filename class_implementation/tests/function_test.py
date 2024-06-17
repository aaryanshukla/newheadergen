import unittest
from class_implementation.classes.function import Function

class TestFunction(unittest.TestCase):
    def test_function_without_guard(self):
        func = Function(return_type="int", name="myFunction", arguments=["int a", "float b"])
        expected_output = "int myFunction(int a, float b);\n"
        self.assertEqual(str(func), expected_output)

    def test_function_with_guard(self):
        func = Function(return_type="void", name="guardedFunction", arguments=["int x"], guard="GUARD_MACRO")
        expected_output = "#ifdef GUARD_MACRO\nvoid guardedFunction(int x);\n#endif // GUARD_MACRO\n"
        self.assertEqual(str(func), expected_output)

    def test_function_with_attributes(self):
        func = Function(return_type="int", name="attributedFunction", arguments=["int a"], attributes=["__attribute__((const))"])
        expected_output = "int attributedFunction(int a) __attribute__((const));\n"
        self.assertEqual(str(func), expected_output)

    def test_function_with_multiple_arguments(self):
        func = Function(return_type="char *", name="strstr", arguments=["const char *", "const char *"])
        expected_output = "char * strstr(const char *, const char *);\n"
        self.assertEqual(str(func), expected_output)

if __name__ == '__main__':
    unittest.main()
