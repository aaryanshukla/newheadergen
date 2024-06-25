#!/usr/bin/env python3

import argparse
import os
import yaml
import json
from yaml_to_classes import load_yaml_file
from json_to_ir import load_json_file

def save_yaml_file(header, output_file):
    yaml_data = {
        'header': header.name,
        'macros': [macro.name for macro in header.macros],
        'types': [type_.name for type_ in header.types],
        'enums': [
            {
                'name': enum.name,
                'values': enum.values
            } for enum in header.enumerations
        ],
        'functions': [
            {
                'return_type': func.return_type,
                'name': func.name,
                'arguments': [arg for arg in func.arguments],
                'guard': func.guard,
                'attributes': func.attributes
            } for func in header.functions
        ],
        'includes': [include.name for include in header.includes]
    }
    with open(output_file, 'w') as f:
        yaml.safe_dump(yaml_data, f)

def save_json_file(header, output_file):
    json_data = {
        'header': header.name,
        'macros': [macro.name for macro in header.macros],
        'types': [type_.name for type_ in header.types],
        'enums': [
            {
                'name': enum.name,
                'values': enum.values
            } for enum in header.enumerations
        ],
        'functions': [
            {
                'return_type': func.return_type,
                'name': func.name,
                'arguments': [arg for arg in func.arguments],
                'guard': func.guard,
                'attributes': func.attributes
            } for func in header.functions
        ],
        'includes': [include.name for include in header.includes]
    }
    with open(output_file, 'w') as f:
        json.dump(json_data, f, indent=4)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Convert between YAML and JSON with IR representation")
    parser.add_argument("input_file", help="Path to the input YAML or JSON file")
    parser.add_argument("output_file", help="Path to the output YAML or JSON file")
    parser.add_argument("--format", choices=['yaml', 'json'], help="Output format (yaml or json)", required=True)
    args = parser.parse_args()

    input_ext = os.path.splitext(args.input_file)[1].lower()
    output_ext = os.path.splitext(args.output_file)[1].lower()

    if input_ext == '.yaml':
        header = load_yaml_file(args.input_file)
    elif input_ext == '.json':
        header = load_json_file(args.input_file)
    else:
        raise ValueError("Input file must be a .yaml or .json file")

    if args.format == 'yaml':
        save_yaml_file(header, args.output_file)
    elif args.format == 'json':
        save_json_file(header, args.output_file)
    else:
        raise ValueError("Output format must be 'yaml' or 'json'")

#command line argument: python convert_ir.py path/to/input_file.yaml path/to/output_file.json --format json
