import json
import os
import argparse
from class_implementation.classes.macro import Macro
from class_implementation.classes.type import Type
from class_implementation.classes.function import Function
from class_implementation.classes.include import Include
from class_implementation.classes.enums import Enumeration
from header import HeaderFile


def parse_ir_json(json_content):
    header_name = json_content.get('header', 'unknown.h')
    macros = [Macro(m) for m in json_content.get('macros', [])]
    types = [Type(t) for t in json_content.get('types', [])]
    enums = [Enumeration(e['name'], e['value']) for e in json_content.get('enums', [])]
    functions = [Function(
        f['return_type'],
        f['name'],
        [arg for arg in f['arguments']],
        f.get('guard'),
        f.get('attributes', [])
    ) for f in json_content.get('functions', [])]
    includes = [Include(i) for i in json_content.get('includes', [])]
    
    header = HeaderFile(header_name)
    for macro in macros:
        header.add_macro(macro)
    for type_ in types:
        header.add_type(type_)
    for enum in enums:
        header.add_enumeration(enum)
    for function in functions:
        header.add_function(function)
    for include in includes:
        header.add_include(include)
    
    return header

def load_json_file(json_file):
    with open(json_file, 'r') as f:
        json_content = json.load(f)
    return parse_ir_json(json_content)

def main(input_file):
    header = load_json_file(input_file)
    
    output_dir = os.path.join(os.path.dirname(__file__), 'output')
    os.makedirs(output_dir, exist_ok=True)

    output_file = os.path.join(output_dir, header.name)
    with open(output_file, "w") as header_file:
        header_file.write(str(header))

    print(f"Generated header for {header.name}")
    print(str(header))

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate header files from IR JSON")
    parser.add_argument("input_file", help="Path to the JSON file containing IR specification")
    args = parser.parse_args()

    main(args.input_file)
