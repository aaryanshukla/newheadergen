class Function:
    def __init__(self, standard, return_type, name, arguments=None, guard=None, attributes=[]):
        self.standard = standard
        self.return_type = return_type
        self.name = name
        self.arguments = [
            arg['type'] for arg in arguments
        ]
        self.guard = guard
        self.attributes = attributes

    def __str__(self):
        args_str = ", ".join(self.arguments)
        attributes_str = " ".join(self.attributes)
        result = f"{self.return_type} {self.name}({args_str}){attributes_str};"
        if self.guard:
            result = f"#ifdef {self.guard}\n{result}\n#endif // {self.guard}"
        return result