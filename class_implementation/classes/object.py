class Object:
    def __init__(self, name, type):
        self.name = name
        self.type = type

    def __str__(self):
        return f'extern {self.type} {self.name}'

