class contacts:
    def __init__(self,name,mobile,city,profession):
        self.name=name
        # if mobile[:4]!='+923'and len(mobile)!=13:
        #      raise ValueError("Invalid Mobile Number")
        # elif mobile[:2]!='03'and len(mobile)!=11:
        #      raise ValueError("Invalid Mobile Number")
#        else:
        self.mobile = mobile
        self.city=city
        self.profession = profession
c = contacts("ali","03166560902","goj","123")
