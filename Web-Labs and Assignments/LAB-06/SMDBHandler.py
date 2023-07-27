from Contact import Contact
import pymysql
class SMDBHandler:
    def __init__(self,host,user,password,database):
        self.host=host
        self.user = user
        self.password=password
        self.database=database

    def registerContact(self,s):
        mydb = None
        mydbCursor=None
        inserted = False
        try:
            # Get DB Connection
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            # Get cursor object
            mydbCursor = mydb.cursor()
            sql = "insert into contact (name,mobileno,city,profession) values (%s,%s,%s,%s) "
            args = (s.name,s.mobile,s.city,s.profession)
            mydbCursor.execute(sql, args)
            mydb.commit()
            inserted=True
        except Exception as e:
            print(str(e))
        finally:
            if mydbCursor != None:
                mydbCursor.close()

            if mydb != None:
                mydb.close()
            return  inserted
    def displayContact(self):
        mydb = None
        mydbCursor=None
        exist = None
        try:
            # Get DB Connection
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            # Get cursor object
            mydbCursor = mydb.cursor()
            sql = "Select * from contact"
            mydbCursor.execute(sql)
            row=mydbCursor.fetchall()
            if row !=None:
                exist=row

        except Exception as e:
            print(str(e))
        finally:
            if mydbCursor != None:
                mydbCursor.close()

            if mydb != None:
                mydb.close()
            return  exist
    
    def check(self,name,mobile):
        mydb = None
        mydbCursor=None
        exist = None
        try:
            mydb = pymysql.connect(host=self.host, user=self.user, password=self.password, database=self.database)
            mydbCursor = mydb.cursor()
            sql = "select *from contact where  "
            flag=True
            arg=[]
            if name != "":
                if flag:
                    sql += "name =%s"
                    arg.append(name)
                    flag = False
                else:
                    sql += " and name =%s"
                    arg.append(name)
            if mobile != "":
                if flag:
                    sql += "mobileno =%s"
                    arg.append(mobile)
                    flag = False
                else:
                    sql += " and  mobileno =%s"
                    arg.append(mobile)
            if flag != True:
                mydbCursor.execute(sql, arg)
                row=mydbCursor.fetchall()
                if row !=None and row!=():
                    print(row)
                    exist=row
                else:
                    exist=None
            

        except Exception as e:
            print(str(e))
        finally:
            if mydbCursor != None:
                mydbCursor.close()

            if mydb != None:
                mydb.close()
            return exist


