from Book import *
from BorrowRecord import *
from Model import DBHandler

def addBook(titel,name,price,isbn,numOfCopies,availCopies):
    bk = Book(titel,name,price,isbn,numOfCopies,availCopies)
    mydb = DBHandler("localhost","root","1234","lib") # creating an object of DBHandler class
    return mydb.addBook(bk)
def deleteBook(id):
    mydb = DBHandler("localhost", "root", "1234", "lib")
    return mydb.delete_student(id)
def searchBook(id):
    mydb = DBHandler("localhost", "root", "1234", "lib")
    return mydb.search_book(id)
def borrowBook(id):
    mydb = DBHandler("localhost", "root", "1234", "lib")
    return mydb.search_book(id)
def returnBook(id):
    mydb = DBHandler("localhost", "root", "1234", "lib")
    return mydb.search_book(id)
def viewHistory(id):
    mydb = DBHandler("localhost", "root", "1234", "lib")
    return mydb.viewHistory(id)
    