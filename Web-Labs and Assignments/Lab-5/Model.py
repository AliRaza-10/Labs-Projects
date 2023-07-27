from Book import *
from BorrowRecord import *
import pymysql

class DBHandler:
    def __init__(self, host, name, password, database):
        self.__host = host
        self.__name = name
        self.__password = password
        self.__database = database

    def addBook(self,Book):
        mydb = None
        dbCursor = None
        flag=False
        try:
            mydb = pymysql.connect(host=self.__host, user=self.__name, password=self.__password,database=self.__database)
            dbCursor = mydb.cursor()
            if mydb is not None:
                print("connected")
                sql = ("INSERT INTO book "
                    "(`title`,`author`, `price`, `isbn`,  `total_copies`, `available_copies` )"
                    "VALUES (%s,%s,%s,%s,%s,%s)")
                args=(Book.title,Book.name,Book.price,Book.isbn,Book.numOfCopies,Book.availCopies)
                dbCursor.execute(sql,args)
                mydb.commit()
                flag=True
        except Exception as e:
            print(str(e))
        finally:
            if dbCursor != None:
                dbCursor.close()
            if mydb != None:
                mydb.close()
            return flag


    def deleteBook(self, id):
        mydb = None
        cursor = None
        returnVal = True
        try:
            mydb = pymysql.connect(host=self.__host, user=self.__name, password=self.__password, database=self.__database)
            cursor = mydb.cursor()
            # get user id from faculty table ( because we need to delete data from user table too )
            query = "select user_id from book where id = %s"
            cursor.execute(query, (id))
            myTuple = cursor.fetchone()

            # if id not present in faculty table, raise exception
            if myTuple == None:
                raise Exception("No user with this id found")
            user_id = myTuple[0]
            # first delete from faculty
            query = "delete from book where id = %s"
            cursor.execute(query, (id))

            # then delete from Borrow table ( we can't delete from user table first as it is used as foreign key in other table )
            # query = "delete from borrowrecord where id = %s"
            # cursor.execute(query, (user_id))
            mydb.commit()

        except Exception as e:
            returnVal = False
            print(str(e))
        finally:
            if mydb != None:
                mydb.close()
            if cursor != None:
                cursor.close()
            return returnVal
    
    def searchBook(self,id):
        mydb = None
        dbCursor = None
        flag=False
        isbn=0
        try:
            mydb = pymysql.connect(host=self.__host, user=self.__name, password=self.__password,database=self.__database)
            dbCursor = mydb.cursor()
            if mydb is not None:
                print("connected")
                sql = "select * from book where id = %s"
                dbCursor.execute(sql,(id))
                rows=dbCursor.fetchone()
                if rows is not None:
                    print("Book Title: ",rows[1])
                    print("Price: ",rows[2])
                    print("Author: ",rows[3])
                    print("ISBN13: ",rows[4])
                    print("Total Copies: ",rows[5])
                    print("Available Copies: ",rows[6])
                elif rows is None:
                    print("No book found")
                mydb.commit()
                flag=True
        except Exception as e:
            print(str(e))
        finally:
            if dbCursor != None:
                dbCursor.close()
            if mydb != None:
                mydb.close()
            return flag
    def viewHistory(self,id):
        mydb = None
        dbCursor = None
        flag=False
        isbn=0
        try:
            mydb = pymysql.connect(host=self.__host, user=self.__name, password=self.__password,database=self.__database)
            dbCursor = mydb.cursor()
            if mydb is not None:
                print("connected")
                sql = "select * from borrowrecord where id = %s"
                dbCursor.execute(sql,(id))
                rows=dbCursor.fetchone()
                if rows is not None:
                    print("Book id: ",rows[1])
                    print("Borrow_by: ",rows[2])
                    print("Borrow date: ",rows[3])
                    print("ISBN13: ",rows[4])
                    print("returning date: ",rows[5])
                    print("fine: ",rows[6])
                    print("fine Status : ",rows[6])
                elif rows is None:
                    print("No book found")
                mydb.commit()
                flag=True
        except Exception as e:
            print(str(e))
        finally:
            if dbCursor != None:
                dbCursor.close()
            if mydb != None:
                mydb.close()
            return flag
    def borrowBook(self,BorrowRecord):
        mydb = None
        dbCursor = None
        flag=False
        try:
            mydb = pymysql.connect(host=self.__host, user=self.__name, password=self.__password,database=self.__database)
            dbCursor = mydb.cursor()
            if mydb is not None:
                print("connected")
                sql = ("INSERT INTO book "
                    "(`title`,`author`, `price`, `isbn`,  `total_copies`, `available_copies` )"
                    "VALUES (%s,%s,%s,%s,%s,%s)")
                args=(Book.title,Book.name,Book.price,Book.isbn,Book.numOfCopies,Book.availCopies)
                dbCursor.execute(sql,args)
                mydb.commit()
                flag=True
        except Exception as e:
            print(str(e))
        finally:
            if dbCursor != None:
                dbCursor.close()
            if mydb != None:
                mydb.close()
            return flag