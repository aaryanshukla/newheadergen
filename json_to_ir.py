import json
import os
import argparse
from header import HeaderFile
from macro import Macro
from type import Type
from function import Function
from include import Include
from enums import Enumeration

def parse_ir_json(json_content):
    header_name = json_content.get('header', 'unknown.h')
    macros = [Macro(m) for m in json_content.get('macros', [])]
    types = [Type(t) for t in json_content.get('types', [])]
    enums = [Enumeration(e['name'], e['values']) for e in json_content.get('enums', [])]
    functions = [Function(
        f['return_type'],
        f['name'],
        [arg for arg in f['arguments']],
        f.get('guard'),
        f.get('attributes', [])
    ) for f in json_content.get('functions', [])]
    includes = [Include(i) for i in json_content.get('includes', [])]
    return header_name, macros, types, enums, functions, includes

def load_json_file(json_file):
    with open(json_file, 'r') as f:
        json_content = json.load(f)
    return parse_ir_json(json_content)



def main(input_file):
    with open(input_file, 'r') as f:
        content = json.load(f)
    
    header = parse_ir_json(content)
    
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