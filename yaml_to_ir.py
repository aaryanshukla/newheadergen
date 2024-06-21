import yaml
import os
from header import HeaderFile
from class_implementation.classes.macro import Macro
from class_implementation.classes.type import Type
from class_implementation.classes.function import Function
from class_implementation.classes.include import Include
from class_implementation.classes.enums import Enumeration

def yaml_to_ir(yaml_data):
    header_name = yaml_data.get('header', 'unknown.h')
    header = HeaderFile(header_name)

    for macro_data in yaml_data.get('macros', []):
        header.add_macro(Macro(macro_data))

    for type_data in yaml_data.get('types', []):
        header.add_type(Type(type_data['type_name']))

    for enum_data in yaml_data.get('enums', []):
        header.add_enumeration(Enumeration(enum_data['name'], enum_data['value']))

    for function_data in yaml_data.get('functions', []):
        arguments = [arg for arg in function_data['arguments']]
        header.add_function(Function(
            function_data['return_type'],
            function_data['name'],
            arguments,
            function_data.get('guard'),
            function_data.get('attributes'),
            function_data.get('standard')
        ))

    for include_data in yaml_data.get('includes', []):
        header.add_include(Include(include_data))

    return header

def load_yaml_file(yaml_file):
    with open(yaml_file, 'r') as f:
        yaml_data = yaml.safe_load(f)
    return yaml_to_ir(yaml_data)

def filter_functions(header, function_names):
    filtered_functions = []
    function_name_set = set(function_names)
    for func in header.functions:
        if func.name in function_name_set:
            filtered_functions.append(func)
    return filtered_functions

def main(yaml_files, function_names):
    combined_headers = []

    for yaml_file in yaml_files:
        header = load_yaml_file(yaml_file)
        combined_headers.append(header)

    filtered_headers = []

    for header in combined_headers:
        if function_names:
            header.functions = filter_functions(header, function_names)
        filtered_headers.append(header)

    for header in filtered_headers:
        output_dir = os.path.join(os.path.dirname(__file__), 'output')
        os.makedirs(output_dir, exist_ok=True)

        output_file = os.path.join(output_dir, header.name)
        with open(output_file, "w") as header_file:
            header_file.write(str(header))

        print(f"Generated header for {header.name}")
        print(str(header))

if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description="Generate header files from YAML")
    parser.add_argument("yaml_files", nargs='+', help="Paths to the YAML files containing header specification")
    parser.add_argument("--functions", nargs='*', help="List of function names to include in the header")
    args = parser.parse_args()

    main(args.yaml_files, args.functions)
