import unittest
from type import Type

class TestType(unittest.TestCase):
    def test_type_definition(self):
        type = Type("float_t")
        expected_output = "#include <llvm-libc-types/float_t.h>"
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

    def test_double_underscore(self):
        type = Type("QSortRCompareT")
        expected_output = "#include <llvm-libc-types/__qsortcompare_t.h>"
        self.assertEqual(str(type), expected_output)

    def test_type_empty_name(self):
        type = Type("")
        expected_output = "#include "
        self.assertEqual(str(type), expected_output)

if __name__ == '__main__':
    unittest.main()