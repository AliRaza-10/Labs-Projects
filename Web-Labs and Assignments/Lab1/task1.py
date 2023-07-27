print("1 Add Donor")
print("2 Update/edit Donor")
print("3 Delete Donor")
print("4 Search Donor")
print("5 Display/Print all students")
print("6 Exit")
def display(Donor):
#    data = read_data()
    count = 1
    for x in Donor:
        print(f"The info of Donor {count} is \n"
            " id:", x["id"] ,"\n",
            "name :", x["name"],"\n",
            "Cell No :",  x["cellno"],"\n"
            " age :",  x["age"],"\n"
            " Location :",  x["Location"],"\n"
            " Blood Group :",  x["BloodGroup"],"\n"
            )
#        write_data(data)
        count = count + 1
def AddDonor():
    name = input("Enter your Name : ")
    flag = True
    while (flag):
        try:
            age = input("Enter your age : ")
            while int(age)< 0:
                age = input("Enter your age : ")
            flag = False
        except Exception as e:
            print(str(e))
    flag1= True
    while (flag1):
        try:
            cellno = input("Enter Your Cellno : ")
            while int(cellno)< 0: #or len(cellno)!=11:
                cellno = input("Enter Your Cellno : ")
            flag1 = False
        except Exception as e:
            print(str(e))
    bg = input("Enter your Blood Group : ")
    loc = input("Enter your location : ")
    with open("data.txt","r") as fr:
        l= fr.readline()
        id = int(l.split()[0])
        id += 1
    with open("data.txt", "r") as f:
        lines = f.readlines()
        lines[0] = f"{id} {' '.join(l.split()[1:])}\n"
    with open("data.txt", "w") as f:
        f.writelines(lines)
    with open("data.txt","a") as fr:
        record=str(id)+","+name+","+cellno+","+loc+","+age+","+bg+"\n"
        fr.write(record)
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
def UpdateDonorRecord():
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
                        while int(age)< 0:
                            age = input("Enter your age : ")
                        flag = False
                    except Exception as e:
                        print(str(e))
                flag1= True
                while (flag1):
                    try:
                        cellno = input("Enter Your Cellno : ")
                        while int(cellno)< 0: #or len(cellno)!=11:
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

flag = True
while (flag):
    choice = int(input("Enter your Choice (1-5) "))
    if(choice==1):
        AddDonor()
    elif(choice==2):
        Donor = UpdateDonorRecord()
    elif(choice==3):
        Donor = DeleteDonor()
    elif(choice==4):
        CheckDonorExist()
    elif(choice==5):
        display(Donor)
    elif(choice>5 or choice<1):
        print("Exit")
        flag = False