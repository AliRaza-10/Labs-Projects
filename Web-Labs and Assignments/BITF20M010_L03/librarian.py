class Librarian:
    def __init__(self, id = None,username = " ", password = " "):
        self.__id = id
        self.__username = username
        self.__password = password
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
    def username(self):
        return self.__username
    @username.setter
    def username(self, username):
        if(type(username)!=str):
            self.__username = username
        else:
            raise Exception("Invalid Username")
    @property
    def password(self):
        return self.__password
    @password.setter
    def password(self, password):
        if(len(password) > 8):
            self.__password = password
        else:
            raise Exception("Invalid Password")
