from company import Company
from person import Person
from medicine import Medicine
import pymysql
def addMedicine(m):
    mydb = None
    dbCursor = None
    flag=False
    try:
        mydb = pymysql.connect(host="localhost", user="root", password="1234", database="doctor")
        dbCursor = mydb.cursor()
        if mydb is not None:
            print("connected")
            sql = "insert into person values (%s,%s,%s)"
            args=(Medicine.company.owner.name,Medicine.company.owner.contact,Medicine.company.owner.city)
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
def nameLocationshow():
        try:
            import pymysql
            mydb = pymysql.connect(host="localhost", user="root", password="1234", database="doctor")
            c = mydb.cursor()
            c.execute('select p.name,c.location from compnay c join person p'
                      'on  where p.name=%s ')
            mydb.commit()
            c.close()
        except Exception as e:
            print(e)
def showwithPricerange(self):
        try:
            import pymysql
            mydb = pymysql.connect(host="localhost", user="root", password="1234", database="doctor")
            c = mydb.cursor()
            c.execute('select name,formula,price from medicine where price between %s and %s', (100, 200))
            all=c.fetchall()
            mydb.commit()
            c.close()
        except Exception as e:
            print(e)
def Locationshow(self):
        try:
            import pymysql
            mydb = pymysql.connect(host="localhost", user="root", password="1234", database="doctor")
            c = mydb.cursor()
            c.execute('update compnay set location=%s where registration_code=%s ', ('lahore', '1234'))
            print("showed")
            f=c.fetchall()
            for i in f:
                print(i)

            mydb.commit()
            c.close()
        except Exception as e:
            print(e)
def deletemedicine(self):

    try:
        import pymysql
        mydb = pymysql.connect(host="localhost", user="root", password="1234", database="doctor")
        c = mydb.cursor()
        c.execute('delete from medicine where formula=%s')
        mydb.commit()
        c.close()
    except Exception as e:
        print(e)
name = input("Enter the name of medicine ")
formula = input("Enter formula of the medicine ")
price = input("Enter the price of the medicine ")
name2 = input("Enter the name of company ")
location = input("Enter the location of the company ")
reg = input("Enter the registration code of the company ")
name3 = input("Enter the name of the person ")
contact = input("Enter the contact no of person ")
city = input("Enter the city of the person ")
p = Person(name3, contact, city)
c = Company(name2, location, p, reg)
m = Medicine(name, c, formula, price)
addMedicine(m)