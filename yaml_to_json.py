#!/usr/bin/env python3

import yaml
import json
import sys

def yaml_to_json(yaml_file, json_file):
    with open(yaml_file, 'r') as yf:
        yaml_content = yaml.safe_load(yf)
    
    json_content = {
        "metadata": {
            "formatVersion": {
                "major": 0,
                "minor": 5,
                "patch": 3
            },
            "generator": "clang version 19.0.0git"
        },
        "module": {
            "name": "Demo",
            "platform": {
                "architecture": "x86_64",
                "operatingSystem": {
                    "name": "linux"
                },
                "vendor": "unknown"
            }
        },
        "relationships": [],
        "symbols": []
    }

    for function in yaml_content.get('functions', []):
        func_name = function['name']
        return_type = function['return_type']
        parameters = function['parameters']

        declaration_fragments = [
            {"kind": "typeIdentifier", "spelling": return_type},
            {"kind": "text", "spelling": " "},
            {"kind": "identifier", "spelling": func_name},
            {"kind": "text", "spelling": "("}
        ]

        param_list = []
        for param in parameters:
            param_fragments = []
            param_type = param['type']
            param_qualifiers = " ".join(param.get('qualifiers', []))
            param_name = param['name']

            if param_qualifiers:
                param_fragments.append({"kind": "typeIdentifier", "spelling": param_type})
                param_fragments.append({"kind": "text", "spelling": " "})
                param_fragments.append({"kind": "keyword", "spelling": param_qualifiers})
                param_fragments.append({"kind": "text", "spelling": " "})
            else:
                param_fragments.append({"kind": "typeIdentifier", "spelling": param_type})
                param_fragments.append({"kind": "text", "spelling": " "})

            param_fragments.append({"kind": "internalParam", "spelling": param_name})
            param_list.append({
                "declarationFragments": param_fragments,
                "name": param_name
            })
            declaration_fragments.extend(param_fragments)
            declaration_fragments.append({"kind": "text", "spelling": ", "})

        if param_list:
            declaration_fragments.pop() 
        declaration_fragments.append({"kind": "text", "spelling": ");"})

        function_entry = {
            "accessLevel": "public",
            "declarationFragments": declaration_fragments,
            "functionSignature": {
                "parameters": param_list,
                "returns": [{"kind": "typeIdentifier", "spelling": return_type}]
            },
            "identifier": {
                "interfaceLanguage": "c++",
                "precise": f"c:@N@LIBC_NAMESPACE@F@{func_name}"
            },
            "kind": {
                "displayName": "Function",
                "identifier": "c++.func"
            },
            "location": {
                "position": {"character": 1, "line": 1},
                "uri": "file://./llvm-project/libc/src/string/example.h"
            },
            "names": {
                "navigator": [{"kind": "identifier", "spelling": func_name}],
                "subHeading": [{"kind": "identifier", "spelling": func_name}],
                "title": func_name
            },
            "pathComponents": ["LIBC_NAMESPACE", func_name]
        }

        if 'macros' in function:
            function_entry['macros'] = function['macros']
        if 'includes' in function:
            function_entry['includes'] = function['includes']

        json_content['symbols'].append(function_entry)

    with open(json_file, 'w') as jf:
        json.dump(json_content, jf, indent=4)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input_yaml_file> <output_json_file>")
        sys.exit(1)
    yaml_to_json(sys.argv[1], sys.argv[2])
