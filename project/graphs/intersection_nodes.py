%pylab

import json
import glob
import overpy
import overpy.helper
import matplotlib.style
matplotlib.style.use('ggplot')



class Road(object):
    def __init__(self, osmid:int, coordinates:list, name:str = None):
        self._id = osmid
        self._coords = coordinates
        self._N = len(coordinates)
        self._nodes = None
        self.name = name

    def get_coordinates(self):
        return self._coords

    def num_nodes(self):
        return self._N

    def __repr__(self):
        return f'OSMID: {self._id}\tNodes: {self._N}'




paths = glob.glob('./data/dublin_ireland.imposm-geojson/dublin_*.geojson')

paths=[
    './data/dublin_ireland.imposm-geojson/dublin_ireland_roads.geojson',
    './data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen0.geojson',
    './data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen1.geojson']

paths
data = open(paths[0]).read()
data = open(paths[1]).read()
data = open(filepath).read()

rj = json.loads(data)



roads = list()
plt.clf()

for feature in rj['features']:
    print(feature)

    osmid = int(feature['properties']['osm_id'])
    coords = feature['geometry']['coordinates']
    name = feature['properties']['name']
    roads.append(Road(osmid, coords, name))
    plt.plot([c[0] for c in coords],  [c[1] for c in coords], 'k.')
    plt.plot([c[0] for c in coords],  [c[1] for c in coords], '-')





#----------------------------------------------------------------------
api = overpy.Overpass()

result = api.parse_json(data)









j = json.loads(data)
j.keys()

j['type']
j['crs']

j['features'][1].keys()
feature = j['features'][2]
feature


for i in range(len(roads)):
num_nodes = [road.num_nodes() for road in roads]
ix =num_nodes.index(max(num_nodes))

nodes = roads[ix]._coords

fig = plt.figure()
plt.plot([c[0] for c in nodes], [c[1] for c in nodes], '-.')






bbox='-7.877,52.432,-5.944,54.137'
result = api.query(f'[out:json]; node({bbox}); out;')
print("Nodes: {}\tWays: {}\t\tRelations: {}".format(
        len(result.nodes),
        len(result.ways),
        len(result.relations)))


node_lat_lon = lambda node: (node.lat, node.lon)
nodes = [node_lat_lon(node) for node in result.get_nodes()]


def plot_way():
    fig = plt.figure()
    plt.plot([c[0] for c in nodes], [c[1] for c in nodes], 'k.')
    plt.plot([c[0] for c in nodes], [c[1] for c in nodes], '-.', label=way.tags.get("name", "n/a"))
    plt.legend()


# fetch all ways and nodes
result = api.query('way ["name"="Gielgenstraße"] (50.7,7.1,50.8,7.25); out;')
result.ways


result = api.query('way ["name"="Gielgenstraße"] (50.7,7.1,50.8,7.25); out;')
result.ways


#
result = api.query(f'way({bbox}) ["highway"]; (._;>;); out body;')


plt.clf()

for way in result.get_ways():
    print(way)

    for node in way.get_nodes():

        print(node)


    # print("Name: {}\t\tHighway: {}".format(way.tags.get("name", "n/a"), way.tags.get("highway", "n/a")))
    latlong = []
    for node in way.nodes:
        latlong.append((float(node.lat), float(node.lon)))
    plt.plot([c[0] for c in latlong], [c[1] for c in latlong], 'k.')
    # plt.plot([c[0] for c in latlong], [c[1] for c in latlong], '-', label=way.tags.get("name", "n/a"))

plt.legend()





#---------------------------------------------------------------------
# class Node(object):
    # def __init__(self,id=None, latlong:tuple)
        # self._id = id
        # self._latlong = latlong



# 3600062594 is the OSM id of Chemnitz and is the bounding box for the request
street = overpy.helper.get_street(
    "Straße der Nationen",
    "3600062594"
)



# this finds an intersection between Straße der Nationen and Carolastraße in Chemnitz
intersection = overpy.helper.get_intersection(
    "Straße der Nationen",
    "Carolastraße",
    "3600062594"
)


# this finds an intersection between Straße der Nationen and Carolastraße in Chemnitz
intersection = overpy.helper.get_intersection(
    "Straße der Nationen",
    "Carolastraße",
    "3600062594"
)



node_location = lambda node: (float(node.lat), float(node.lon))
for way in street.ways:
    coordinates = [node_location(node) for node in way.nodes]
    plt.plot([c[0] for c in coordinates], [c[1] for c in coordinates],'k.')
    # plt.plot([c[0] for c in coordinates], [c[1] for c in coordinates],'-.')




node_location = lambda node: (float(node.lat), float(node.lon))
coordinates = [node_location(node) for node in intersection]
plt.plot([c[0] for c in coordinates], [c[1] for c in coordinates],'k.')
plt.plot([c[0] for c in coordinates], [c[1] for c in coordinates],'--')





intersection

node_location = lambda node: (float(node.lat), float(node.lon))
coordinates = [node_location(node) for node in intersection]

