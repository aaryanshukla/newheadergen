class Function:
    def __init__(self, return_type, name, arguments, guard=None, attributes=None):
        self.return_type = return_type
        self.name = name
        self.arguments = arguments
        self.guard = guard
        self.attributes = attributes or []

    def __str__(self):
        args_str = ", ".join(self.arguments)
        attributes_str = " ".join(self.attributes)
        function_str = f"{self.return_type} {self.name}({args_str}) {attributes_str};".strip()
        
        if self.guard:
            return f"#ifdef {self.guard}\n{function_str}\n#endif // {self.guard}\n"
        
        return function_str + "\n"
