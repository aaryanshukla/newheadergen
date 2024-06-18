import json
import os
from header import HeaderFile
from class_implementation.classes.function import Function
from class_implementation.classes.include import Include

def extract_api_to_ir(api_data):
    headers = {}

    for entry in api_data.get("entries", []):
        module = entry.get("module", {})
        header_name = module.get("name", "unknown") + ".h"
        
        if header_name not in headers:
            headers[header_name] = HeaderFile(header_name)
            headers[header_name].add_include(Include("__llvm-libc-common.h"))

        header = headers[header_name]

        for symbol in entry.get("symbols", []):
            if symbol["kind"]["displayName"] == "Function":
                declaration_fragments = symbol.get("declarationFragments", [])
                return_type = ""
                name = ""
                is_identifier_found = False

                for frag in declaration_fragments:
                    if frag["kind"] == "typeIdentifier":
                        return_type += frag["spelling"] + " "
                    elif frag["kind"] == "identifier" and not is_identifier_found:
                        name = frag["spelling"]
                        is_identifier_found = True
                    elif frag["kind"] == "text":
                        return_type += frag["spelling"]

                return_type = return_type.strip()
                arguments = []

                for param in symbol.get("functionSignature", {}).get("parameters", []):
                    param_fragments = "".join(frag["spelling"] for frag in param["declarationFragments"])
                    param_fragments = param_fragments.replace("restrict", "__restrict")
                    arguments.append(param_fragments.strip())

                guard = None  
                attributes = [] 
                header.add_function(Function(return_type, name, arguments, guard, attributes))

    return headers.values()

def load_json_file(json_file):
    with open(json_file, 'r') as f:
        api_data = json.load(f)
    return extract_api_to_ir(api_data)

def main(json_file):
    headers = load_json_file(json_file)

    output_dir = os.path.join(os.path.dirname(__file__), 'output')
    os.makedirs(output_dir, exist_ok=True)

    for header in headers:
        output_file = os.path.join(output_dir, header.name)
        with open(output_file, "w") as header_file:
            header_file.write(str(header))

        print(f"Generated header for {header.name}")
        print(str(header))

if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description="Generate header files from Clang Extract API JSON")
    parser.add_argument("json_file", help="Path to the JSON file containing Clang Extract API data")
    args = parser.parse_args()

    main(args.json_file)
