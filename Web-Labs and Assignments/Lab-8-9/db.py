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
            print("iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii")
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
        
    def searchContacts(self,n,un):
        mydb = None
        mydbCursor=None
        exist = None
        row = None
        flag = False
        try:
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            mydbCursor = mydb.cursor()
            sql = "select user_id from user where email =%s "
            args=(un)
            mydbCursor.execute(sql,args)
            exist = mydbCursor.fetchone()
            print(exist)
            sql="select user_id,name,mobile,city,profession from contact where name=%s and user_id = %s"
            mydbCursor.execute(sql,(n, exist))
            row=mydbCursor.fetchall()
            # print(row)
#            count = mydbCursor.rowcount()
            # print(count)
            # print(row)
            if row!=None and row !=():
                flag = True
            else:
                flag = False
        except Exception as e:
            print(str(e))

        finally:
            if mydbCursor != None:
                mydbCursor.close()

            if mydb != None:
                mydb.close()
            return flag
    def search(self,un,n):
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
            print(exist)
            sql="select user_id,name,mobile,city,profession from contact where name=%s and user_id = %s"
            mydbCursor.execute(sql,(n, exist))
            row=mydbCursor.fetchall()
        except Exception as e:
            print(str(e))

        finally:
            if mydbCursor != None:
                mydbCursor.close()

            if mydb != None:
                mydb.close()
            return row
    def updateContacts(self,c,n,un):
        mydb = None
        mydbCursor=None
        exist = None
        row = False
        try:
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            mydbCursor = mydb.cursor()
            sql = "select user_id from user where email =%s "
            args=(un)
            mydbCursor.execute(sql,args)
            exist = mydbCursor.fetchone()
            sql="update contact set name = %s,mobile =%s,city=%s,profession=%s  where name=%s and user_id = %s"
            mydbCursor.execute(sql,(c.name,c.mobile,c.city,c.profession,n, exist))
            row = True
            mydb.commit()
        except Exception as e:
            print(str(e))

        finally:
            if mydbCursor != None:
                mydbCursor.close()

            if mydb != None:
                mydb.close()
            print(row)
            return row

    def update(self,c,n,e):
        mydb = None
        cursor = None
        returnVal = True
        try:
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            cursor = mydb.cursor()

            # # get id from user table
            query = "select user_id from user where email =  %s"
            cursor.execute(query,(e))
            myTuple = cursor.fetchone()

            # # if username doesn't match in database, raise exception
            # # if myTuple == None:
            # #     raise Exception("No user found with this data")
            user_id = myTuple[0]

            #update data
            query = "update contact set name = %s, mobile = %s, city = %s , profession = %s where name = %s"
            cursor.execute(query, (c.name,c.mobile,c.city,c.profession,n))
            mydb.commit()
        except Exception as e:
            returnVal = False
            print(str(e))
        finally:
            if cursor != None:
                cursor.close()
            if mydb != None:
                mydb.close()
            
            return returnVal
    def deleteContacts(self,n):
        mydb = None
        dbCursor = None
        flag=False
        try:
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            dbCursor = mydb.cursor()
            if mydb is not None:
                sql = "delete from contact where name = %s"
                args=(n)
                dbCursor.execute(sql,args)
                if dbCursor.rowcount > 0:
                    flag = True
                else:
                    flag = False
                mydb.commit()
        except Exception as e:
            print(str(e))
        finally:
            if dbCursor != None:
                dbCursor.close()
            if mydb != None:
                mydb.close()
            return flag