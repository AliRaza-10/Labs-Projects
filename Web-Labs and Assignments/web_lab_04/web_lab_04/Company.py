
class Company:
    def __init__(self,n,l,Person,rc):
        self.name = n
        self.location=l
        self.owner= Person
        self.registration_code= rc

    def nameLocationshow(self):
        try:
            import pymysql
            mydb = pymysql.connect(host="localhost", user="root", password="Password@.com123", port=80,
                                   database="yasir")
            c = mydb.cursor()
            c.execute('select p.name,c.location from compnay c join person p'
                      'on  where p.name=%s ', ('i am'))
            print("showed")
            mydb.commit()
            c.close()
        except Exception as e:
            print(e)

    def nameLocationshow(self):
        try:
            import pymysql
            mydb = pymysql.connect(host="localhost", user="root", password="Password@.com123", port=80,
                                   database="yasir")
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

c=Company("fff","lahore","56","5667")
c.nameLocationshow()

