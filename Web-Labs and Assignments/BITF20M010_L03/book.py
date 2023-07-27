class Book:
        def __init__(self,id =None, bookTitle = " ", price =  0,author = " ", ean = " ", group = " ",publisher = " ", title = " ",checkDigit = " " ):
            
            self.__id = id
            self.__bookTitle = bookTitle
            self.__price = price
            self.__author = author
            self.__ean = ean
            self.__group = group
            self.__publisher = publisher
            self.__title = title
            self.__checkDigit = checkDigit
        @property
        def id(self):
            return self.__id
        @id.setter
        def id(self, id):
            if(type(id)!=int):
                self.__id = id
            else:
                raise Exception("Invalid ID")
        @property
        def bookTitle(self):
            return self.__bookTitle
        @bookTitle.setter
        def bookTitle(self, bookTitle):
                self.__bookTitle = bookTitle
        @property
        def price(self):
            return self.__price
        @price.setter
        def price(self, price):
                self.__price = price
        @property
        def author(self):
            return self.__author
        @author.setter
        def author(self, author):
                self.__author = author
        @property
        def ean(self):
            return self.__ean
        @ean.setter
        def ean(self, ean):
            if(type(ean)!=978 or type(ean)!=979):
                self.__ean = ean
            else:
                raise Exception("Invalid EAN")
        @property
        def group(self):
            return self.__group
        @group.setter
        def group(self, group):
            self.__group = group
        @property
        def publisher(self):
            return self.__publisher
        @publisher.setter
        def publisher(self, publisher):
            if(type(publisher)!=int):
                self.__publisher = publisher
            else:
                raise Exception("Invalid Publisher")
        @property
        def title(self):
            return self.__title
        @title.setter
        def title(self, title):
            if(type(title)!=int):
                self.__title = title
            else:
                raise Exception("Invalid Title")
        @property
        def checkDigit(self):
            return self.__checkDigit
        @checkDigit.setter
        def checkDigit(self, checkDigit):
            if(type(checkDigit)!=int):
                self.__checkDigit = checkDigit
            else:
                raise Exception("Invalid Check Digit")
