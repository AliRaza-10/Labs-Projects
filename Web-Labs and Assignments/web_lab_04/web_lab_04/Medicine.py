class Medicine:
    def __init__(self,n,Company,f,p):
        self.name = n
        self.company = Company
        self.formula = f
        self.price = p

    def addmedicine(self):
        try:
            import pymysql
            mydb = pymysql.connect(host="localhost", user="root", password="Password@.com123", port=80,
                                   database="yasir")
            c = mydb.cursor()
            c.execute('insert into medicine values(%s,%s,%s,%s)', (self.name, self.company, self.formula, self.price))
            print("inserted")
            mydb.commit()
            c.close()
        except Exception as e:
            print(e)
    def showdetails(self):
        try:
            import pymysql
            mydb = pymysql.connect(host="localhost", user="root", password="Password@.com123", port=80,
                                   database="yasir")
            c = mydb.cursor()
            c.execute('select name,formula,price from medicine where name=%s', (self.name))
            all=c.fetchall()
            for a in all:
                print(a)
            print("showed")
            mydb.commit()
            c.close()
        except Exception as e:
            print(e)

    def showwithPricerange(self):
        try:
            import pymysql
            mydb = pymysql.connect(host="localhost", user="root", password="Password@.com123", port=80,
                                   database="yasir")
            c = mydb.cursor()
            c.execute('select name,formula,price from medicine where price between %s and %s', (100, 200))
            all=c.fetchall()
            mydb.commit()
            c.close()
        except Exception as e:
            print(e)

    def deletemedicine(self):

       try:
           import pymysql
           mydb = pymysql.connect(host="localhost", user="root", password="Password@.com123", port=80, database="yasir")
           c = mydb.cursor()
           c.execute('delete from medicine where formula=%s', ('bhhj'))
           print("deleted")
           mydb.commit()
           c.close()
       except Exception as e:
           print(e)
m=Medicine('yaifff','16778','bhhj',45.55)
m.addmedicine()
m.showdetails()
m.deletemedicine()
m.showwithPricerange()


