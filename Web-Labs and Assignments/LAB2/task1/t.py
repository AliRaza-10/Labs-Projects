class Donor:
        def __init__(self,id =0, name = " ", age = 0,cellno = " ", bg = " ", loc = " " ):
            
            self.__name = name
            self.__id = id
            self.__age = age            
            self.__cellno = cellno            
            self.__bg = bg
            self.__loc = loc
        @property
        def name(self):
            return self.__name
        @name.setter
        def name(self, name):
            if(type(name)!=str):
                self.__name = name
            else:
                raise Exception("Invalid String")
        @property
        def id(self):
            return self.__id
        @id.setter
        def id(self, id):
            if(type(id)!=int):
                self.__id = id
            else:
                raise Exception("Invalid ID")
        @property
        def age(self):
            return self.__age
        @age.setter
        def age(self, age):
            if(self.__age<15):
                self.__age = age
            else:
                raise Exception ("Invalid Age")
        @property
        def cellno(self):
            return self.__cellno
        @cellno.setter
        def cellno(self, cellno):
            if(len(self.__cellno)!=11):
                self.__cellno = cellno
            else:
                raise Exception ("Invalid Cell no")
        @property
        def bg(self):
            return self.__bg
        @bg.setter
        def bg(self, bg):
            if (bg!="A+" or bg!="A-" or bg!="B+" or bg!="B-" or bg!="AB+" or bg!="AB-" or bg!="O+" or bg!="O-"):
                self.__bg = bg
            else:
                raise Exception ("Invalid Blood Group")
        @property
        def loc(self):
            return self.__loc
        @loc.setter
        def loc(self, loc):
            self.__loc = loc 
        def AddDonor(self):
            with open("data.txt","a") as fw:
                fw.write(f"{self.id},{self.name},{self.age},{self.cellno},{self.bg},{self.loc}\n")     
        def UpdateDonorRecord(self):
            flg = True
            id = input("Enter the ID of the Donor you want to update : ")
            with open("data.txt","r") as fr:
                lines = fr.readlines()
                for line in lines:
                    if line.split(",")[0] == id:
                        flg = False
                        print("Donor Found")
                        print("Enter the new details of the Donor")
                        name = input("Enter your Name : ")
                        flag = True
                        while (flag):
                            try:
                                age = input("Enter your age : ")
                                while int(age)< 15:
                                    self.age = input("Enter your age : ")
                                flag = False
                            except Exception as e:
                                print(str(e))
                        flag1= True
                        while (flag1):
                            try:
                                cellno = input("Enter Your Cellno : ")
                                while int(cellno)< 0 or len(cellno)!=11:
                                    cellno = input("Enter Your Cellno : ")
                                flag1 = False
                            except Exception as e:
                                print(str(e))
                        bg = input("Enter your Blood Group : ")
                        loc = input("Enter your location : ")
                        lines[lines.index(line)] = f"{id},{name},{cellno},{loc},{age},{bg}"
            with open("data.txt","w") as fr:
                for line in lines:
                    fr.write(line)

def CheckDonorExist():
    flg = True
    id = input("Enter the ID of the Donor you want to search : ")
    with open("data.txt","r") as fr:
        lines = fr.readlines()
        for line in lines:
            if line.split(",")[0] == id:
                print("Donor Found")
                flg = False
    if flg==True:
        print("No Donor with this ID found")
def DeleteDonor():
    flg = True
    id = input("Enter the ID of the Donor you want to delete : ")
    with open("data.txt","r") as fr:
        lines = fr.readlines()
        for line in lines:
            if line.split(",")[0] == id:
                lines.remove(line)
                flg = False
                print("Donor Deleted Successfully")
    if flg==True:
        print("No Donor with this ID found")
    with open("data.txt","w") as fr:
        for line in lines:
            fr.write(line)
def readfromfile():
    with open("data.txt","r") as fr:
        lines = fr.readlines()
        list = []
        for line in lines:
            rec = line.split(",")
            list.append(rec)
        return list
def display(list):
    for rec in list:
        if len(rec) > 1:
            print(rec[0],rec[1],rec[2],rec[3],rec[4],rec[5])
print("1 Add Donor")
print("2 Update/edit Donor")
print("3 Delete Donor")
print("4 Search Donor")
print("5 Display/Print all students")
print("6 Exit")
flag = True
while (flag):
    choice = int(input("Enter your Choice (1-5) "))
    if(choice==1): 
        
        with open("data.txt","r") as fr:
            l= fr.readline()
            id = int(l.split()[0])
            id += 1
        with open("data.txt", "r") as f:
            lines = f.readlines()
            lines[0] = f"{id} {' '.join(l.split()[1:])}\n"
        with open("data.txt", "w") as f:
            f.writelines(lines)
        name = input("Enter your Name : ")
        flag1 = True
        while (flag1):
            try:
                age = input("Enter your age : ")
                while int(age)<15:
                    age = input("Enter your age : ")
                flag1 = False
            except Exception as e:
                print(str(e))
        flag2= True
        while (flag2):
            try:
                cellno = input("Enter Your Cellno : ")
                while int(cellno)< 0: #or len(cellno)!=11:
                    cellno = input("Enter Your Cellno : ")
                flag2 = False
            except Exception as e:
                print(str(e))
        bg = input("Enter your Blood Group : ")
        loc = input("Enter your location : ")
        s2 = Donor(id,name,age,cellno,bg,loc)
        s2.AddDonor()
    elif(choice==2):
        s3 = Donor()
        s3.UpdateDonorRecord()
    elif(choice==3):
        Donor = DeleteDonor()
    elif(choice==4):
        CheckDonorExist()
    elif(choice==5):
        l=readfromfile()
        display(l)
    elif(choice>5 or choice<1):
        print("Exit")
        flag = False