import book
import librarian
import pymysql
def addBook():
    b = book.Book()
    b.bookTitle= input("Enter the book title: ")
    if(type(b.bookTitle)!=str):
        raise Exception("Invalid Book Title")
    b.price = input("Enter the price: ")
    b.author = input("Enter the author name: ")
    if(type(b.author)!=str):
        raise Exception("Invalid Author")
    isbn = input("Enter the ISBN13: ")
    isbn = isbn.replace(' ', '').replace('-','')
    while len(isbn) != 13:
        isbn = input("Enter the valid ISBN13: ")
        isbn = isbn.replace(' ', '').replace('-','')
    if len(isbn)==13:
        while isbn[:3] not in ["978", "979"]:
            isbn = input("Enter the valid ISBN13: ")
            isbn = isbn.replace(' ', '').replace('-','')
    b.ean=isbn[:3]
    b.group=isbn[3:5]
    b.publisher=isbn[5:9]
    b.title=isbn[9:12]
    b.checkDigit=isbn[12]
    mydb = None
    dbCursor = None
    flag=False
    try:
        mydb = pymysql.connect(host="localhost", user="root", password="1234", database="librarian")
        dbCursor = mydb.cursor()
        if mydb is not None:
            print("connected")
            sql = ("INSERT INTO book "
                   "(`bookName`, `price`, `author`, `ean`, `grop`, `publisher`, `title`, `checkDigit`)"
                   "VALUES (%s,%s,%s,%s,%s,%s,%s,%s)")
            args=(b.bookTitle,b.price,b.author,b.ean,b.group,b.publisher,b.title,b.checkDigit)
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
def searchBook(id):
    b= book.Book()
    mydb = None
    dbCursor = None
    flag=False
    isbn=0
    try:
        mydb = pymysql.connect(host="localhost", user="root", password="1234", database="librarian")
        dbCursor = mydb.cursor()
        if mydb is not None:
            print("connected")
            sql = "select * from book where bookid = %s"
            dbCursor.execute(sql,(id))
            rows=dbCursor.fetchone()
            if rows is not None:
                print("Book Found")
                print("Book Title: ",rows[1])
                print("Price: ",rows[2])
                print("Author: ",rows[3])
                isbn = str(rows[4]) + "-" + str(rows[5]) + "-" + str(rows[6]) + "-" + str(rows[7]) + "-"+str(rows[8])
                print("ISBN13: ",isbn)
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
def deleteBook():
    id = input("Enter the book id: ")
    mydb = None
    dbCursor = None
    flag=False
    try:
        mydb = pymysql.connect(host="localhost", user="root", password="1234", database="librarian")
        dbCursor = mydb.cursor()
        if mydb is not None:
            print("connected")
            sql = "delete from book where bookid = %s"
            args=(id)
            dbCursor.execute(sql,args)
            if dbCursor.rowcount > 0:
                print("Book deleted")
            else:
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
def updateBook():
    b = book.Book()
    b.id = input("Enter the book id: ")
    if searchBook(b.id):
        mydb = None
        dbCursor = None
        flag=False
        try:
            mydb = pymysql.connect(host="localhost", user="root", password="1234", database="librarian")
            dbCursor = mydb.cursor()
            if mydb is not None:
                print("connected")
                sql = "update book set bookName =%s, price =%s, author =%s, ean =%s, grop =%s, publisher =%s, title =%s, checkDigit =%s where bookid = %s"
                b.bookTitle= input("Enter the book title: ")
                if(type(b.bookTitle)!=str):
                    raise Exception("Invalid Book Title")
                b.price = input("Enter the price: ")
                b.author = input("Enter the author name: ")
                if(type(b.author)!=str):
                    raise Exception("Invalid Author")
                isbn = input("Enter the ISBN13: ")
                isbn = isbn.replace(' ', '').replace('-','')
                while len(isbn) != 13:
                    isbn = input("Enter the valid ISBN13: ")
                    isbn = isbn.replace(' ', '').replace('-','')
                if len(isbn)==13:
                    while isbn[:3] not in ["978", "979"]:
                        isbn = input("Enter the valid ISBN13: ")
                        isbn = isbn.replace(' ', '').replace('-','')
                b.ean=isbn[:3]
                b.group=isbn[3:5]
                b.publisher=isbn[5:9]
                b.title=isbn[9:12]
                b.checkDigit=isbn[12]
                args=(b.bookTitle,b.price,b.author,b.ean,b.group,b.publisher,b.title,b.checkDigit,b.id)
                dbCursor.execute(sql,args)
                mydb.commit()
                flag=True
                if flag:
                    print("Book updated")
        except Exception as e:
            print(str(e))
        finally:
            if dbCursor != None:
                dbCursor.close()
            if mydb != None:
                mydb.close()
            return flag
    else:
        print("Book Id not found")
def register():
    l = librarian.Librarian() 
    l.name = input("Enter your name: ")
    if type(l.name) != str:
        raise Exception("Invalid name. Please enter a valid name")
    l.pin = input("Enter your pin: ")
    while len(l.pin) < 8:
        raise Exception("Invalid pin. Please enter valid numeric key")
    mydb = None
    dbCursor = None
    flag=False
    try:

        mydb = pymysql.connect(host="localhost", user="root", password="1234", database="librarian")
        dbCursor = mydb.cursor()
        if mydb is not None:
            print("connected")
            sql = "insert into library values (%s,%s,%s)"
            args=(l.id,l.name,l.pin)
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


def login():
    username = input("Enter your username: ")
    password = input("Enter your password: ")
    if len(password) < 8:
        raise Exception("Invalid pin. Please enter valid numeric key")
    mydb = None
    dbCursor = None
    flag=False
    try:
        mydb = pymysql.connect(
        host="localhost",
        user="root",
        password="1234",
        database="librarian"
    )
        dbCursor = mydb.cursor()
        if mydb is not None:
            print("connected")
            query = "SELECT * FROM library WHERE username = %s AND password = %s"
            values = (username, password)
            dbCursor.execute(query, values)
            mydb.commit()
            result = dbCursor.fetchone()
        if result is not None:
            flag = True
            while flag:
                print("Welcome to the menu!\n")
                print("1. Add book")
                print("2. search book")
                print("3. Update book")
                print("4. Delete book")
                print("5. Exit")
                choice = int(input("Enter your Choice (1-5) "))
                if choice == 1:
                    addBook()
                elif choice == 2:
                    id = input("Enter the book id: ")
                    searchBook(id)
                elif choice == 3:
                    updateBook()
                elif choice == 4:
                    deleteBook()
                elif choice == 5:
                    flag = False
        else:
            print("Data not found in the database.")
    except Exception as e:
        print(str(e))
    finally:
        if dbCursor != None:
            dbCursor.close()

        if mydb != None:
            mydb.close()

        return flag



print("1-Register\n2-Login\n")
flag = True
while (flag):
    choice = int(input("Enter your Choice (1-5) "))
    if(choice==1):
        register()
    elif(choice==2):
        login()
    else:
        flag = False