from contacts import contacts
import pymysql
class SMDBHandler:
    def __init__(self,host,user,password,database):
        self.host=host
        self.user = user
        self.password=password
        self.database=database
    def register(self,user,pwd):
        mydb = None
        mydbCursor = None
        login = False
        try:
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            mydbCursor = mydb.cursor()
            sql = "insert into user(email,password) values(%s,%s)"
            args = (user,pwd)
            mydbCursor.execute(sql, args)
            mydb.commit()
            login=True
        except Exception as e:
            print(str(e))
        finally:
            if mydbCursor != None:
                mydbCursor.close()

            if mydb != None:
                mydb.close()
            return login
    def login(self,user,pwd):
        mydb = None
        mydbCursor = None
        login = False
        try:
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            mydbCursor = mydb.cursor()
            sql = "select email,password from user where email=%s and password=%s"
            args = (user,pwd)
            mydbCursor.execute(sql, args)
            row=mydbCursor.fetchone()
            if row!= None:
                login=True
        except Exception as e:
            print(str(e))
        finally:
            if mydbCursor != None:
                mydbCursor.close()

            if mydb != None:
                mydb.close()
            return login
    def addContacts(self,Cd,user):
        mydb = None
        mydbCursor = None
        login = False
        try:
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            mydbCursor = mydb.cursor()
            sql ="select user_id from user where email=%s"
            arg=(user)
            mydbCursor.execute(sql, arg)
            row=mydbCursor.fetchone()
            sql="insert into contact(user_id,name,mobile,city,profession) values(%s,%s,%s,%s,%s)"
            arg=(row,Cd.name,Cd.mobile,Cd.city,Cd.profession)
            mydbCursor.execute(sql, arg)
            mydb.commit()
            login=True
        except Exception as e:
            print(str(e))
        finally:
            if mydbCursor != None:
                mydbCursor.close()

            if mydb != None:
                mydb.close()
            return login
    def showContacts(self,user):
        mydb = None
        mydbCursor = None
        login = None
        try:
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            mydbCursor = mydb.cursor()
            sql ="select user_id from user where email=%s"
            arg=(user)
            mydbCursor.execute(sql, arg)
            row=mydbCursor.fetchone()
            sql="select user_id,name,mobile,city,profession from contact where user_id=%s"
            mydbCursor.execute(sql, row)
            row=mydbCursor.fetchall()
            print(len(row))
            if len(row) >0:
                login = row
            else:
                login=None
            print(login)
        except Exception as e:
            print(str(e))
        finally:
            if mydbCursor != None:
                mydbCursor.close()

            if mydb != None:
                mydb.close()
            return login
        
    def searchContacts(self,un,n):
        mydb = None
        mydbCursor=None
        exist = None
        row = None
        try:
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            mydbCursor = mydb.cursor()
            sql = "select user_id from user where email =%s "
            args=(un)
            mydbCursor.execute(sql,args)
            exist = mydbCursor.fetchone()
            sql="select user_id,name,mobile,city,profession from contact where name=%s and user_id = %s"
            mydbCursor.execute(sql,(n, exist))
            row=mydbCursor.fetchall()
            mydb.commit()
        except Exception as e:
            print(str(e))

        finally:
            if mydbCursor != None:
                mydbCursor.close()

            if mydb != None:
                mydb.close()
            return row

