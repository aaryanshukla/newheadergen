class Enumeration:
<<<<<<< Updated upstream
    def __init__(self, name, values):
        self.name = name
        self.values = values

    def __str__(self):
        values_str = ", ".join([f"{name} = {value}" for name, value in self.values.items()])
        return f"enum {self.name} {{{values_str}}};"
=======

    def __init__(self, name, value=None):
        self.name = name
        self.value = value

    def __str__(self):
        if self.value != None:
            return f"{self.name} = {self.value},"
        else:
            return f"{self.name},"
>>>>>>> Stashed changes
