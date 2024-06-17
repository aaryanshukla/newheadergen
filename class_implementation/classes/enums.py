class Enumeration:
     def __init__(self, name, value=None):
        self.name = name
        self.value = value
     def __str__(self):
         if self.value != None:
            return f"{self.name} = {self.value}"
         else:
            return f"{self.name}"
         