from .resources import VehicleApi,VehApi,VehiclesApi


#api is the instance of the flask restful module
def initialize_route(api):
    api.add_resource(VehiclesApi, '/api/buses/')
    api.add_resource(VehicleApi, '/api/buses/<id>')
    api.add_resource(VehApi, '/api/bus/<text>')
#    api.add_resource(oneVehicleApi, '/api/bus/<apppy>')

