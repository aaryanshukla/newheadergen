import yaml
from header import HeaderFile
from macro import Macro
from type import Type
from function import Function
from include import Include

def yaml_to_ir(yaml_data):
    header_name = yaml_data.get('header', 'unknown.h')
    header = HeaderFile(header_name)

    for macro_data in yaml_data.get('macros', []):
        header.add_macro(Macro(macro_data['name']))

    for type_data in yaml_data.get('types', []):
        header.add_type(Type(type_data))

    for function_data in yaml_data.get('functions', []):
        arguments = [arg['type'] for arg in function_data['arguments']]
        header.add_function(Function(
            function_data['return_type'],
            function_data['name'],
            arguments,
            function_data.get('guard'),
            function_data.get('attributes')
        ))

    for include_data in yaml_data.get('includes', []):
        header.add_include(Include(include_data['name']))

    return header

def load_yaml_file(yaml_file):
    with open(yaml_file, 'r') as f:
        yaml_data = yaml.safe_load(f)
    return yaml_to_ir(yaml_data)
