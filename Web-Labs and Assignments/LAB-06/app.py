from flask import Flask,render_template,request
from Contact import Contact
from SMDBHandler import SMDBHandler
app = Flask(__name__)
@app.route('/')
def registerContact():
    return  render_template("contact.html")

@app.route('/registerContact', methods=["POST", "GET"])
def registerStudent():
    try:
        n=request.form["name"]
        m = request.form["mobile"]
        if m[:4]!='+923' and m[:2]!='03' or len(m)!=13 and len(m)!=11:
            message="Invalid Mobile Number"
        c = request.form["city"]
        p = request.form["profession"]
 #       print(rollno,name,semmester,cgpa)
        student=Contact(n,m,c,p)
        hdlr=SMDBHandler("localhost","root","1234","contacts")
        flag=hdlr.registerContact(student)
        if flag:
            return render_template("contact.html",message="welcome")
        else:
            message="Registration failed"
            return render_template("contact.html" ,message=message)
    except Exception as e:
        message="Registation failed "+str(e)
        return render_template("contact.html" ,message=message)
@app.route('/showContact')
def showContact():
    hdlr=SMDBHandler("localhost","root","1234","contacts")
    flag=hdlr.displayContact()
    if flag!=None:
        return render_template("show.html",name=flag,message="welcome" )
    else:
        message="Registration failed"
        return render_template("show.html",message = message)
@app.route('/search',methods=['GET','POST'])
def s():
    return render_template("search.html")
@app.route('/serch',methods=['GET','POST'])
def search():
    try:
        name = request.form["name"]
        mobile = request.form["mobile"]
        hdlr = SMDBHandler("localhost","root","1234","contacts")
        row=hdlr.check(name,mobile)
        if row is not None:
            message="Search Successfull"
            return render_template("search.html" ,message=message,data=row)
        else:
            message="Search Failed"
            row="List Empty"
            return render_template("search.html" ,message=row)
            
    except Exception as e:
        message="Search Failed"+str(e)
        return render_template("search.html" ,message=message)

if __name__ == '__main__':
    app.run()
