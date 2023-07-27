#to use in flask ,mongodb as a api
from flask_mongoengine import MongoEngine
#mongoengine instance ,
db = MongoEngine()

#initialize through flask instance
#this function connects flask application to mongodb database


def initialize_db(app):
    db.init_app(app)


