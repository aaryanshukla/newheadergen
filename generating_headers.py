#!/usr/bin/env python3

import yaml
import argparse
import os
from header import HeaderFile
from macro import Macro
from type import Type
from function import Function
from include import Include
from enum import Enumeration

def parse_yaml(yaml_content):
    header_name = yaml_content.get('header', 'unknown.h')
    macros = [Macro(m['name']) for m in yaml_content.get('macros', [])]
    types = [Type(t) for t in yaml_content.get('types', [])]
    #Todo: need to add enums class for enums[value]
    enums = [Enum(t) for t in yaml_content.get('enums', [])]
    functions = [Function(
        f['return_type'],
        f['name'],
        [arg['type'] for arg in f['arguments']],
        f.get('guard'),
        f.get('attributes')
    ) for f in yaml_content.get('functions', [])]
    includes = [Include(i['name']) for i in yaml_content.get('includes', [])]
    return header_name, macros, types, enums, functions, includes 

def main(yaml_file):
    with open(yaml_file, 'r') as f:
        yaml_content = yaml.safe_load(f)

    header_name, macros, types, enums, functions, includes = parse_yaml(yaml_content)
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

    output_dir = os.path.join(os.path.dirname(__file__), 'output')
    os.makedirs(output_dir, exist_ok=True)

    output_file = os.path.join(output_dir, header_name)
    with open(output_file, "w") as header_file:
        header_file.write(str(header))

    print(f"Generated header for {header_name}")
    print(str(header))

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate header files from YAML")
    parser.add_argument("yaml_file", help="Path to the YAML file containing header specification")
    args = parser.parse_args()

    main(args.yaml_file)
