class Person:
    def __init__(self, name, contact,city):
        if(type(name) != str):
            raise TypeError("Name must be a string")
        else:
            self.name = name
        if (type(contact) != str):
            raise TypeError("Contact must be a string")
        else:
            self.contact = contact
        if (type(city) != str):
            raise TypeError("City must be a string")
        else:
            self.city = city
