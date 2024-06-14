import json
import os
import argparse
from header import HeaderFile
from macro import Macro
from type import Type
from function import Function
from include import Include
# from enumeration import Enumeration  # Assuming you have an Enumeration class

def parse_ir_json(json_content):
    header_name = json_content.get('header', 'unknown.h')
    header = HeaderFile(header_name)

    for macro_data in json_content.get('macros', []):
        header.add_macro(Macro(macro_data['name']))

    for type_data in json_content.get('types', []):
        header.add_type(Type(type_data['name']))

    for function_data in json_content.get('functions', []):
        arguments = [arg['type'] for arg in function_data['arguments']]
        header.add_function(Function(
            function_data['return_type'],
            function_data['name'],
            arguments,
            function_data.get('guard'),
            function_data.get('attributes', [])
        ))

    for include_data in json_content.get('includes', []):
        header.add_include(Include(include_data['name']))

    return header

def load_json_file(json_file):
    with open(json_file, 'r') as f:
        json_data = json.load(f)
    return parse_ir_json(json_data)

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
