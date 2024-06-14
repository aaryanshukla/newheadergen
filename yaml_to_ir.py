import yaml
import os
from header import HeaderFile
from macro import Macro
from type import Type
from function import Function
from include import Include
from enums import Enumeration

def yaml_to_ir(yaml_data):
    header_name = yaml_data.get('header', 'unknown.h')
    header = HeaderFile(header_name)

    for macro_data in yaml_data.get('macros', []):
        header.add_macro(Macro(macro_data))

    for type_data in yaml_data.get('types', []):
        header.add_type(Type(type_data))

    for enum_data in yaml_data.get('enums', []):
        header.add_enumeration(Enumeration(enum_data['name'], enum_data['values']))

    for function_data in yaml_data.get('functions', []):
        arguments = [arg for arg in function_data['arguments']]
        header.add_function(Function(
            function_data['return_type'],
            function_data['name'],
            arguments,
            function_data.get('guard'),
            function_data.get('attributes')
        ))

    for include_data in yaml_data.get('includes', []):
        header.add_include(Include(include_data))

    return header

def load_yaml_file(yaml_file):
    with open(yaml_file, 'r') as f:
        yaml_data = yaml.safe_load(f)
    return yaml_to_ir(yaml_data)

def main(yaml_file):
    header = load_yaml_file(yaml_file)

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
    parser.add_argument("yaml_file", help="Path to the YAML file containing header specification")
    args = parser.parse_args()

    main(args.yaml_file)
