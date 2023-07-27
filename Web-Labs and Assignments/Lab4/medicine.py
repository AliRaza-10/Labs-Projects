from company import Company
class Medicine:
    def __init__(self,name,company,formula,price):
        if(type(name) != str):
            raise TypeError("Name must be a string")
        else:
            self.name = name
        if(type(company) != Company):
            raise TypeError("Company must be a Company object")
        else:
            self.company = company
        if(type(formula) != str):
            raise TypeError("Formula must be a string")
        else:
            self.formula = formula
        if(type(price) != float):
            raise TypeError("Price must be a float")
        else:
            self.price = price