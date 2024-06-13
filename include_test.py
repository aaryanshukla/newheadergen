import unittest
from include import Include

class TestInclude(unittest.TestCase):
    def test_include_standard_header(self):
        include = Include("stdio.h")
        expected_output = '#include "stdio.h"'
        self.assertEqual(str(include), expected_output)

    def test_include_local_header(self):
        include = Include("myheader.h")
        expected_output = '#include "myheader.h"'
        self.assertEqual(str(include), expected_output)

    def test_include_with_path(self):
        include = Include("path/to/header.h")
        expected_output = '#include "path/to/header.h"'
        self.assertEqual(str(include), expected_output)

if __name__ == '__main__':
    unittest.main()
