class Book:
    def __init__ (self, title,name, price,isbn,numOfCopies,availCopies):
        self.__title = title
        self.__name= name
        self.__price= price
        self.__isbn= isbn
        self.__numOfCopies= numOfCopies
        self.__availCopies= availCopies
    @property
    def title(self):
        return self.__title
    @property
    def name(self):
        return self.__name
    @property
    def price(self):
        return self.__price
    @property
    def isbn(self):
        return self.__isbn
    @property
    def isbn(self):
        return self.__isbn
    @property
    def numOfCopies(self):
        return self.__numOfCopies
    @property
    def availCopies(self):
        return self.__availCopies
    @title.setter
    def title(self, t):
        self.__title = t
    @name.setter
    def name(self,n):
        self.__name = n
    @price.setter
    def price(self,p):
        self.__price = p
    @isbn.setter
    def isbn(self,i):
        self.__isbn = i
    @numOfCopies.setter
    def numOfCopies(self,nc):
        self.__numOfCopies = nc
    @availCopies.setter
    def availCopies(self,ac):
        self.__availCopies = ac