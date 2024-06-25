class Function:
    def __init__(self, standard, return_type, name, arguments=None, guard=None, attributes=None):
        self.standard = standard
        self.return_type = return_type
        self.name = name
        self.arguments = [arg if isinstance(arg, str) else arg['type'] for arg in (arguments or [])]
        self.guard = guard
        self.attributes = attributes or []

    def __str__(self):
        result = f"{self.return_type} {self.name}({', '.join(self.arguments)});"
        if self.guard:
            return f"#ifdef {self.guard}\n{result}\n#endif // {self.guard}"
        return result
