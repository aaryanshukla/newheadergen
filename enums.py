class Enumeration:
    def __init__(self, name, values):
        self.name = name
        self.values = values

    def __str__(self):
        values_str = ", ".join([f"{name} = {value}" for name, value in self.values.items()])
        return f"enum {self.name} {{{values_str}}};"
