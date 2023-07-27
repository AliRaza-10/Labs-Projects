from Utils import *
from Controller import *
if __name__ == '__main__':
   displayUserChoices()
   n = input("Enter your choice: ")
   if n == '1':
        displayMainMenu()
        choice = input("Enter your choice: ")
        if choice == '1':
            title = input("Enter Title: ")
            name = input("Enter Author Name: ")
            price = input("Enter Price: ")
            isbn = input("Enter Isbn ")
            isbn = isbn.replace(' ', '').replace('-','')
            if len(isbn)!=13:
                raise Exception("Invalid String") 
            numOfCopies = input("Enter Number of Copies")
            availCopies = input("Enter Available Copies")
            if addBook(title,name,price,isbn,numOfCopies,availCopies):
                print("Add Book successfully")
        elif choice == 2:
            id = input("Enter Book Id you want to delete : ")
            if deleteBook(id):
                print("Book deleted successfully")
            else:
                print("Error deleting book")
        elif choice == 3:
            id = input("Enter Book Id you want to search : ")
            if searchBook(id):
                print("Book found successfully")
            else:
                print("Error searching book")
        else : 
            displayFooter()
            flag = False

            