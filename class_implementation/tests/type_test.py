import unittest
from class_implementation.classes.type import Type

class TestType(unittest.TestCase):
    # def test_type_definition(self):
    #     thing = Type("float_t")
    #     expected_output = "#include <llvm-libc-types/float_t.h>"
    #     print("TYPE OF THING IS: ")
    #     print(type(thing.name))
    #     print(thing.__str__())
    #     self.assertEqual(str(thing), expected_output)

    def test_type_lowercase_simple(self):
        type = Type("FEnvT")
        expected_output = "#include <llvm-libc-types/fenv_t.h>"
        self.assertEqual(str(type), expected_output)

    def test_type_capitalized(self):
        type = Type("OnceFlagType")
        expected_output = "#include <llvm-libc-types/once_flag.h>"
        self.assertEqual(str(type), expected_output)

    def test_type_ttype(self):
        type = Type("ThrdTType")
        expected_output = "#include <llvm-libc-types/thrd_t.h>"
        self.assertEqual(str(type), expected_output)

    def test_type_many_words(self):
        type = Type("CallOnceFuncType")
        expected_output = "#include <llvm-libc-types/__call_once_func_t.h>"
        self.assertEqual(str(type), expected_output)

    def test_type_double_underscore(self):
        type = Type("QSortRCompareT")
        expected_output = "#include <llvm-libc-types/__qsortrcompare_t.h>"
        self.assertEqual(str(type), expected_output)

    def test_type_all_caps(self):
        type = Type("FILE")
        expected_output = "#include <llvm-libc-types/FILE.h>"
        self.assertEqual(str(type), expected_output)

if __name__ == '__main__':
    unittest.main()