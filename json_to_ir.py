import json
from header import HeaderFile
from macro import Macro
from type import Type
from function import Function
from include import Include

def json_to_ir(json_data):
    header_name = json_data.get('header', 'unknown.h')
    header = HeaderFile(header_name)

    for macro_data in json_data.get('macros', []):
        header.add_macro(Macro(macro_data['name']))

    for type_data in json_data.get('types', []):
        header.add_type(Type(type_data))

    for function_data in json_data.get('functions', []):
        arguments = [arg['type'] for arg in function_data['arguments']]
        header.add_function(Function(
            function_data['return_type'],
            function_data['name'],
            arguments,
            function_data.get('guard'),
            function_data.get('attributes')
        ))

    for include_data in json_data.get('includes', []):
        header.add_include(Include(include_data['name']))

    return header

def load_json_file(json_file):
    with open(json_file, 'r') as f:
        json_data = json.load(f)
    return json_to_ir(json_data)
