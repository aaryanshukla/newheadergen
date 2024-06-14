class ArgType:
    def __init__(self, name, prefixes=None, suffixes=None):
        self.name = name
        self.prefixes = prefixes or []
        self.suffixes = suffixes or []

    def __str__(self):
        return_string = ""
        if self.prefixes != []:
            return_string = ' '.join(self.prefixes) + ' ' + self.name 
        else:
            return_string = self.name
        if self.suffixes != []:
            return_string += ' ' + ' '.join(self.suffixes)
        return return_string