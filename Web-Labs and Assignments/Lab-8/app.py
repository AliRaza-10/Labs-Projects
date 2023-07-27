from flask import Flask ,render_template, request,make_response ,session
import random
from contacts import contacts
from db import SMDBHandler
app = Flask(__name__)
app.secret_key="bsjvhusdhg5565645"

@app.route('/')
def hello_world(): 
    return render_template("index.html")

@app.route("/dashboard")
def dashboard():
    uname=session.get("uname")
    if uname !=None:
        return  render_template("dashboard.html",uname=uname)
    else :
        return render_template("login.html", error="Please login")
@app.route("/register")
def reg():
    return render_template("register.html")
@app.route("/registerr",methods=["POST"])
def register():
    try:
        uname=request.form["uname"]
        pwd = request.form["pwd"]
        if len(pwd) > 8:
            dhlr=SMDBHandler("localhost","root","1234","pu")
            login=dhlr.register(uname,pwd)
            if login:
                session["uname"]=uname
                return render_template("dashboard.html",uname=uname)
            else:
                return render_template("register.html", error="register failed")
        else:
            return render_template("register.html", error="password might be greater than 8 characters")


    except Exception as e:
        return render_template("register.html",error="Registration error"+str(e))


@app.route("/login")
def loginform():
    return render_template("login.html")
@app.route("/loggin",methods=["POST"])
def login():
    try:
        uname=request.form["uname"]
        pwd = request.form["pwd"]
        dhlr=SMDBHandler("localhost","root","1234","pu")
        login=dhlr.login(uname,pwd)
        if login:
            session["uname"]=uname
            return render_template("dashboard.html",uname=uname)
        else:
            return render_template("login.html", error="login failed")

    except Exception as e:
        return render_template("login.html",error="Login error"+str(e))
@app.route("/addcontact")
def addContact():
    return render_template("addcontacts.html")
@app.route("/addcontacts",methods=["POST"])
def addContacts():
    try:
        if session.get("uname") != None:
            uname=session["uname"]
            user=request.form["uname"]
            mobile= request.form["mobile"]
            city= request.form["city"]
            prof= request.form["Profession"]
            print(user,)
            c=contacts(user,mobile,city,prof)
            dhlr=SMDBHandler("localhost","root","1234","pu")
            contact=dhlr.addContacts(c,uname)
            if contact == True:
                contact="Contact Added SuccessFully :_)"
                return render_template("dashboard.html",contact=contact)
            else :
              return render_template("addcontacts.html", error="Please login to add contacts")
        else :
              return render_template("addcontacts.html", error="Try Again :_(")
    except Exception as e:
        return render_template("addcontacts.html", error=str(e))
@app.route("/showcontacts")
def showcontacts():
    try:
        if session.get("uname") != None:
            uname=session["uname"]
            dhlr=SMDBHandler("localhost","root","1234","pu")
            contacts=dhlr.showContacts(uname)
            if contacts!=None:
                return render_template("showcontacts.html",contacts=contacts , uname=session["uname"])
            else:
                er="you didn't add any Contacts :_("
                return render_template("showcontacts.html",contacts = None,error=er , uname=session["uname"])
        else :
              return render_template("login.html", error="Please login to check contacts")
    except Exception as e:
        return render_template("login.html", error=str(e))
@app.route("/searchcontact")
def searchContact():
    return render_template("search.html")
@app.route("/search",methods=["GET","POST"])
def searchContacts():
    try:
        if session.get("uname") != None:
            uname=session["uname"]
            name = request.form["uname"]
            dhlr=SMDBHandler("localhost","root","1234","pu")
            contacts=dhlr.searchContacts(uname,name)
            print(contacts)
            if contacts!=None:
                        return render_template("search.html",contacts=contacts , uname=session["uname"])
            else:
                er="you didn't search any Contacts :_("
                return render_template("search.html",contacts = None,error=er , uname=session["uname"])        
        else :
            return render_template("login.html", error="Please login to check contacts")
            
    except Exception as e:
        message="Search Failed"+str(e)
        return render_template("search.html" ,message=message)

@app.route("/logout")
def logout():
    try:
        session.clear()
        return render_template("login.html")
    except Exception as e:
        return render_template("login.html", error=str(e))

if __name__ == '__main__':
    app.run()
