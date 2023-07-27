class Contact:
    def __init__(self,name,mobile,city,profession):
        self.name = name
        if mobile[:4]!='+923' and mobile[:2]!='03' or len(mobile)!=13 and len(mobile)!=11:
            raise ValueError("Invalid Mobile Number")
        else:
            self.mobile = mobile
        self.city = city
        self.profession = profession
#Contact("Ali","03001234567","Karachi","Student")
Contact("Ali","+923001234567","Karachi","Student")