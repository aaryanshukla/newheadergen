#!/usr/bin/env python3

import yaml
import argparse

def parse_function_spec(yaml_content):
    header_name = yaml_content['header']
    functions = []
    for function in yaml_content.get('functions', []):
        func_name = function['name']
        return_type = function['return_type']
        macros = function.get('macros', [])
        includes = function.get('includes', [])
        params = []
        for index, param in enumerate(function['parameters']):
            qualifiers = " ".join(param.get('qualifiers', []))
            param_name = "param{}".format(index)  # Auto-generate parameter names
            param_str = "{} {}".format(param['type'], qualifiers).strip()
            # Replace 'restrict' with '__restrict'
            param_str = param_str.replace(" restrict", " __restrict")
            params.append(param_str + " " + param_name)
        functions.append((func_name, return_type, params, macros, includes))
    return header_name, functions

def generate_function_declaration(func_name, return_type, params):
    return "{} {}(\n    {}\n);".format(return_type, func_name, ",\n    ".join(params))

def generate_header(header_name, functions):
    header_content = "#ifndef {}_H\n".format(header_name.upper().replace('.', '_'))
    header_content += "#define {}_H\n\n".format(header_name.upper().replace('.', '_'))
    
    includes = set()
    macros = set()
    
    for func_name, return_type, params, func_macros, func_includes in functions:
        includes.update(func_includes)
        macros.update(func_macros)
    
    for include in includes:
        header_content += "#include {}\n".format(include)
    if includes:
        header_content += "\n"
    
    for macro in macros:
        header_content += "{}\n".format(macro)
    if macros:
        header_content += "\n"
    
    for func_name, return_type, params, func_macros, func_includes in functions:
        header_content += generate_function_declaration(func_name, return_type, params) + "\n\n"
    
    header_content += "#endif // {}_H\n".format(header_name.upper().replace('.', '_'))
    return header_content

def main(yaml_file):
    with open(yaml_file, 'r') as f:
        yaml_content = yaml.safe_load(f)
    
    header_name, functions = parse_function_spec(yaml_content)
    header_content = generate_header(header_name, functions)
    
    header_file = "{}".format(header_name)
    with open(header_file, "w") as f:
        f.write(header_content)
    
    print("Generated header for:", header_name)
    print(header_content)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate header files from YAML definitions")
    parser.add_argument("yaml_file", help="Path to the YAML file containing function definitions")
    args = parser.parse_args()
    
    main(args.yaml_file)
