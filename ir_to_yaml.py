import yaml

#Need to add if guards, enums, and change the way types are added 


def ir_to_yaml(header):
    yaml_data = {
        'header': header.name,
        'macros': [{'name': macro.name} for macro in header.macros],
        'types': [type_.name for type_ in header.types],
        'functions': [
            { 
                'name': func.name,
                'return_type': func.return_type, 
                'arguments': [{'type': arg} for arg in func.arguments],
                'guard': func.guard,
                'attributes': func.attributes
            }  for func in header.functions
        ],
        'includes': [{'name': include.name} for include in header.includes]
    }
    return yaml_data

def save_yaml_file(header, yaml_file):
    yaml_data = ir_to_yaml(header)
    with open(yaml_file, 'w') as f:
        yaml.dump(yaml_data, f)