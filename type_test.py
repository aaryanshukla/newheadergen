import unittest
from type import Type

class TestType(unittest.TestCase):
    def test_type_definition(self):
        type = Type("float_t")
        expected_output = "#include <llvm-libc-types/float_t.h>"
        self.assertEqual(str(type), expected_output)

    def test_type_empty_name(self):
        type = Type("")
        expected_output = "#include "
        self.assertEqual(str(type), expected_output)

if __name__ == '__main__':
    unittest.main()