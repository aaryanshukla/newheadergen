#!/usr/bin/env python3

import yaml
import argparse

def parse_function_spec(yaml_content):
    headers = []
    functions = yaml_content.get('functions', [])
    for function in functions:
        func_name = function['name']
        return_type = function['return_type']
        params = []
        for param in function['parameters']:
            qualifiers = " ".join(param.get('qualifiers', []))
            param_str = "{} {}".format(param['type'], qualifiers).strip()
            params.append(param_str)
        headers.append((func_name, return_type, params))
    return headers

def generate_header(header_name, functions):
    header_content = "#ifndef {}_H\n".format(header_name.upper().replace('.', '_'))
    header_content += "#define {}_H\n\n".format(header_name.upper().replace('.', '_'))
    for func_name, return_type, params in functions:
        param_str = ", ".join(param.split()[0] for param in params)  # Ensure only the parameter types are included
        header_content += "{} {}(\n    {}\n);\n\n".format(return_type, func_name, param_str)
    header_content += "#endif // {}_H\n".format(header_name.upper().replace('.', '_'))
    return header_content

def main(yaml_file):
    with open(yaml_file, 'r') as f:
        yaml_content = yaml.safe_load(f)
    
    header_name = yaml_content.get('header', 'default')
    functions = parse_function_spec(yaml_content)
    
    header_content = generate_header(header_name, functions)
    
    header_file = "{}.h".format(header_name)
    with open(header_file, "w") as f:
        f.write(header_content)
    
    print("Generated header for:", header_name)
    print(header_content)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate header files from YAML")
    parser.add_argument("yaml_file", help="Path to the YAML file containing function definitions")
    args = parser.parse_args()
    
    main(args.yaml_file)
