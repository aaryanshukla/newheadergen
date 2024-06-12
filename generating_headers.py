#!/usr/bin/env python3

import yaml
import argparse

def parse_yaml(yaml_content):
    header = yaml_content.get('header', 'unknown.h')
    macros = yaml_content.get('macros', [])
    types = yaml_content.get('types', [])
    enums = yaml_content.get('enums', [])
    functions = yaml_content.get('functions', [])
    return header, macros, types, enums, functions

def generate_header(header, macros, types, enums, functions):
    header_guard = header.replace('.', '_').upper()
    header_content = f"#ifndef {header_guard}\n"
    header_content += f"#define {header_guard}\n\n"

    for macro in macros:
        header_content += f"#define {macro['name']}\n"

    for type_ in types:
        header_content += f"typedef {type_};\n"

    header_content += "\n"

    for func in functions:
        return_type = func['return_type']
        func_name = func['name']
        params = []
        for param in func['parameters']:
            if isinstance(param, str):
                params.append(param)
            else:
                type_ = param['type']
                qualifiers = " ".join(param.get('qualifiers', []))
                param_str = f"{type_} {qualifiers}".strip()
                params.append(param_str)
        params_str = ", ".join(params)
        header_content += f"{return_type} {func_name}({params_str});\n"

    header_content += f"\n#endif // {header_guard}\n"
    return header_content

def main(yaml_file):
    with open(yaml_file, 'r') as f:
        yaml_content = yaml.safe_load(f)
    
    header, macros, types, enums, functions = parse_yaml(yaml_content)
    header_content = generate_header(header, macros, types, enums, functions)

    with open(header, "w") as header_file:
        header_file.write(header_content)
    
    print(f"Generated header for {header}")
    print(header_content)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate header files from YAML")
    parser.add_argument("yaml_file", help="Path to the YAML file containing header specification")
    args = parser.parse_args()
    
    main(args.yaml_file)
