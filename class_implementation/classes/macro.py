class Macro:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return f"#define {self.name}"
    
    

