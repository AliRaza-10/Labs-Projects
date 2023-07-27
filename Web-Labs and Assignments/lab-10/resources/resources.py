from flask import Flask, request,Response,jsonify,json
from flask_restful import Resource
from database.Model import product

class VehiclesApi(Resource):
    
    def get(self):
        try:
            buses = product.objects().to_json()
            return Response(buses, mimetype="application/json", status=200)
        except Exception as e:
                print(str(e))
    def post(self):
        try:
            body = request.get_json()
            #form
            # reg_no=request.form['reg']
            # model=request.form['model']
            # veh=vehicle(reg=reg_no, model=model).save()
            #/form
            #return jsonify(body)
            veh = product(name = body["name"], description=body["description"],price=body["price"]).save()
            print(veh)
            id=veh.id
            return {'id':str(id),'Inserted':'Done'}, 200
            return Response(veh, mimetype="application/json", status=200)
        except Exception as e:
            print(str(e))

class VehicleApi(Resource):
    def get(self,id):
        try:
            buses = json.loads(product.objects().to_json())
            n = request.args.get("id")
            if n is None:
                return jsonify(buses)
            else:
                num = int(n)
                return jsonify(buses[:num])
        except Exception as e:
                print(str(e))

    def put(self,id):
        try:
            #print("request received", id)
            data = request.get_json()
            # id
            product.objects(id=id).update(**data)
            return {'id': id, 'Updation': 'done'}, 200
            return Response(('name:',data['name']), mimetype="application/json", status=200)
        except Exception as e:
            print(str(e))
    def delete(self, id):
        try:
            print("request received", id)
            # id
            product.objects(id=id).delete()
            #return {'id':str(id), 'delete':'done'},200
            return {'delete':'done'},200
            #return Response(, mimetype="application/json", status=200)
        except Exception as e:
            print(str(e))

class VehApi(Resource):
    def get(self,text):
        try:
            list1=[]
            buses = json.loads(product.objects().to_json())
            for temp in buses:
                if text in temp['description'] or text in temp['name']:
                    list1.append(temp)

            return Response(json.dumps(list1), mimetype="application/json", status=200)
        except Exception as e:
                print(str(e))




# class oneVehicleApi(Resource):
#     def get(self,apppy):
#         try:
#             print("request received",apppy)
#             #id
#             veh=vehicle.objects(reg_no=apppy).to_json()
#             return Response(veh,mimetype="application/json",status=200)
#         except Exception as e:
#            print(str(e))

#     def delete(self, id):
#         try:
#             print("request received", id)
#             # id
#             vehicle.objects(id=id).delete()
#             return {'id':str(id), 'delete':'done'},200
#             #return Response(, mimetype="application/json", status=200)
#         except Exception as e:
#             print(str(e))
#     def put(self, id):
#         try:
#             print("request received", id)
#             data=request.get_json()
#             # id
#             vehicle.objects(id=id).update(**data)
#             return {'id':str(id), 'update':'done'},200
#             #return Response(, mimetype="application/json", status=200)
#         except Exception as e:
#             print(str(e))

