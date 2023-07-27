from flask import Flask, request, render_template,jsonify
from flask_restful import Api
from database import db
from resources import routes
from database.Model import product
app = Flask(__name__)
app.config['MONGODB_SETTINGS'] = {
    'host': 'mongodb://localhost:27017/test'
#test is the name of the database
}
db.initialize_db(app)
routes.initialize_route(Api(app))

# @app.route("/vehicle")
# def getvehicles():
#     veh=vehicle.objects(reg="test")
#     return jsonify(veh)

if __name__ == '__main__':
    app.run()
