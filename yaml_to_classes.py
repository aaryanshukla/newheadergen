#!/usr/bin/env python
#
# ===- Generate headers for libc functions  -------------------*- python -*--==#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
# ==-------------------------------------------------------------------------==#

import yaml
import argparse
from pathlib import Path

from header import HeaderFile
from class_implementation.classes.macro import Macro
from class_implementation.classes.type import Type
from class_implementation.classes.function import Function
from class_implementation.classes.include import Include
from class_implementation.classes.enumeration import Enumeration
from class_implementation.classes.object import Object


def yaml_to_classes(yaml_data):
    """
    Convert YAML data to header classes.

    Args:
        yaml_data: The YAML data containing header specifications.

    Returns:
        HeaderFile: An instance of HeaderFile populated with the data.
    """
    header_name = yaml_data.get("header")
    header = HeaderFile(header_name)

    for macro_data in yaml_data.get("macros", []):
        header.add_macro(Macro(macro_data["macro_name"], macro_data["macro_value"]))

    for type_data in yaml_data.get("types", []):
        header.add_type(Type(type_data["type_name"]))

    for enum_data in yaml_data.get("enums", []):
        header.add_enumeration(
            Enumeration(enum_data["name"], enum_data.get("value", None))
        )

    for function_data in yaml_data.get("functions", []):
        arguments = function_data.get("arguments", [])
        header.add_function(
            Function(
                function_data.get("standard", ""),
                function_data["return_type"],
                function_data["name"],
                arguments,
                function_data.get("guard"),
                function_data.get("attributes", []),
            )
        )
    for object_data in yaml_data.get("objects", []):
        header.add_object(
            Object(object_data["object_name"], object_data["object_type"])
        )

    for include_data in yaml_data.get("includes", []):
        header.add_include(Include(include_data))

    return header

def load_yaml_file(yaml_file):
    """
    Load YAML file and convert it to header classes.

    Args:
        yaml_file: The path to the YAML file.

    Returns:
        HeaderFile: An instance of HeaderFile populated with the data from the YAML file.
    """
    with open(yaml_file, "r") as f:
        yaml_data = yaml.safe_load(f)
    return yaml_to_classes(yaml_data)


def save_yaml_file(yaml_file, yaml_data):
    """
    Save the YAML data back to a file.

    Args:
        yaml_file: The path to the YAML file.
        yaml_data: The YAML data to save.
    """
    with open(yaml_file, "w") as f:
        yaml.safe_dump(yaml_data, f)


def fill_public_api(header_str, h_def_content):
    """
    Replace the %%public_api() placeholder in the .h.def content with the generated header content.

    Args:
        header_str: The generated header string.
        h_def_content: The content of the .h.def file.

    Returns:
        The final header content with the public API filled in.
    """
    return h_def_content.replace("%%public_api()", header_str, 1)


def add_function_to_yaml(yaml_file, function_details):
    """
    Add a function to the YAML file.

    Args:
        yaml_file: The path to the YAML file.
        function_details: A list containing function details (name, return_type, guard, attributes, arguments, standards).
    """
    name, return_type, guard, attributes, arguments, standards = function_details
    attributes = attributes.split(",") if attributes != "null" else []
    arguments = [{"type": arg.strip()} for arg in arguments.split(",")]
    standards = standards.split(",") if standards != "null" else []

    new_function = {
        "name": name,
        "standard": standards,
        "return_type": return_type,
        "arguments": arguments,
        "guard": guard if guard != "null" else None,
        "attributes": attributes,
    }

    with open(yaml_file, "r") as f:
        yaml_data = yaml.safe_load(f)

    if "functions" not in yaml_data:
        yaml_data["functions"] = []

    yaml_data["functions"].append(new_function)

    with open(yaml_file, "w") as f:
        yaml.dump(yaml_data, f, sort_keys=False)

    print(f"Added function {name} to {yaml_file}")


def main(yaml_file, h_def_file, output_dir, add_function=None):
    """
    Main function to generate header files from YAML and .h.def templates.

    Args:
        yaml_file: Path to the YAML file containing header specification.
        h_def_file: Path to the .h.def template file.
        output_dir: Directory to output the generated header file.
        add_function: Details of the function to be added to the YAML file (if any).
    """

    if add_function:
        add_function_to_yaml(yaml_file, add_function)

    header = load_yaml_file(yaml_file)

    with open(h_def_file, "r") as f:
        h_def_content = f.read()

    header_str = str(header)
    final_header_content = fill_public_api(header_str, h_def_content)

    output_file_name = Path(h_def_file).stem
    output_file_path = Path(output_dir) / output_file_name

    with open(output_file_path, "w") as f:
        f.write(final_header_content)

    print(f"Generated header file: {output_file_path}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate header files from YAML and .h.def templates"
    )
    parser.add_argument(
        "yaml_file", help="Path to the YAML file containing header specification"
    )
    parser.add_argument("h_def_file", help="Path to the .h.def template file")
    parser.add_argument(
        "--output_dir",
        default=".",
        help="Directory to output the generated header file",
    )
    parser.add_argument(
        "--add_function",
        nargs=6,
        metavar=("NAME", "RETURN_TYPE", "GUARD", "ATTRIBUTES", "ARGUMENTS", "STANDARDS"),
        help="Add a function to the YAML file",
    )
    args = parser.parse_args()

    main(args.yaml_file, args.h_def_file, args.output_dir, args.add_function)
    
# Example command line:
# python3 yaml_to_classes.py yaml/linux_sys_epoll.yaml h_def/sys/epoll.h.def --output_dir output/sys --add_function "bcopy void* null null const void*,void*,size_t llvm_libc_ext"
