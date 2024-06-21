import unittest
from class_implementation.classes.object import Object

class TestObject(unittest.TestCase):
    def test_object_definition(self):
        obj = Object("stderr", "FILE *")
        expected_output = "extern FILE * stderr"
        self.assertEqual(str(obj), expected_output)

if __name__ == '__main__':
    unittest.main()