from person import Person
class Company:
        def __init__(self,name , location , owner , registrationcode ):
            
            if(type(name) != str):
                raise TypeError("Name must be a string")
            else:
                self.name = name
            if (type(location) != str):
                raise TypeError("Location must be a string")
            else:
                self.location = location
            
            if (type(owner) != str):
                raise TypeError("Owner must be a string")
            else:
                self.owner = owner
            if (type(registrationcode) != str):
                raise TypeError("Registration code must be a string")
            else:
                self.registrationcode = registrationcode

