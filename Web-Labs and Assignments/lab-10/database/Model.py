from .db import db


class product(db.Document):
#keys
    name = db.StringField(Required=True)
    description = db.StringField(Required=True)
    price = db.FloatField(Required=True)
    
