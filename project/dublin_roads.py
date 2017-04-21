import overpy
import overpy.helper

import json
import glob
from math import sqrt

import numpy as np

import matplotlib.pyplot as plt
import matplotlib.style
matplotlib.style.use('seaborn-paper')


class Edge(object):
    def __init__(self, v, w, weight, directed):
        self.source = v
        self.destination = w
        self.directed = directed
        self.weight = weight

    def vertices(self):
        return (self.source, self.destination)

    def weight(self):
        return self.weight

    def __repr__(self):
        return f'Indices: ({self.source},{self.destination})' + \
                f'  Weight: {self.weight:{3}.{4}}' + \
               f'  Directed: {self.directed}'

class Node(object):
    def __init__(self, index,  lat, lon, edges = []):
        self.ix = index
        self.lat = lat
        self.lon = lon
        self._edges = edges

    def coordinates(self):
        return (self.lat, self.lon)


    @property
    def edges(self):
        return self._edges

#for road in json_roads['features']:

class Road(object):
    def __init__(self, json_road):
        # osmid:int, nodes:list, name:str)
        self._geoj = json_road
        self._length = len(json_road['geometry']['coordinates'])
        self._osmid = int(json_road['properties']['osm_id'])
        self._name = json_road['properties']['name']
        self.oneway =  bool(json_road['properties']['oneway'])

        self.nodes = []
        coordinates = json_road['geometry']['coordinates']
        for i in range(len(coordinates)):
            edges = []
            vlat, vlon = coordinates[i]
            if (i-1) >= 0:
                wlat, wlon = coordinates[i-1]
                dist = sqrt( (wlat - vlat)**2 + (wlat-vlon)**2 )
                e = Edge(i, i-1, dist, self.oneway)
                edges.append(e)
            if (i+1) < len(coordinates):
                wlat, wlon = coordinates[i+1]
                dist = sqrt( (wlat - vlat)**2 + (wlat-vlon)**2 )
                e = Edge(i, i+1, dist, self.oneway)
                edges.append(e)
                node = Node(i, vlat, vlon, edges)
            self.nodes.append(node)

    @property
    def json(self):
        return self._geoj

    @property
    def osmid(self):
        return self._osmid

    @property
    def name(self):
        return self._name

    @property
    def length(self):
        return self._length

    def __repr__(self):
        return f'OSMID: {self._osmid}\tNodes: {self._length}'


if __name__ == __main__:

    path='./data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen0.geojson'
    with open(path) as f:
        json_roads = json.loads(f.read())

    roads = []
    for road in json_roads['features']:
        r = Road(road)
        roads.append(r)


from functools import reduce
reduce( (lambda x, y: x * y), [1, 2, 3, 4] )
min(roads, key=lambda road: road.length)
max(roads, key=lambda road: road.length)

max(roads, key=lambda road: road.length)


nodes = [max(road.nodes, key=lambda node: len(node.edges)) for road in roads]

n= max(nodes, key=lambda node: len(node.edges))








#----------------------------------------------------------
    figure = plt.figure()
    roads = all_cords = list()
    for feature in json_roads['features']:
        osmid = int(feature['properties']['osm_id'])
        coords = feature['geometry']['coordinates']
        name = feature['properties']['name']
        plt.plot([c[0] for c in coords],  [c[1] for c in coords], 'k.')
        plt.plot([c[0] for c in coords],  [c[1] for c in coords], '-')
    plt.title('Roads of Dublin, Ireland')

    matplotlib.style.use('ggplot')
    plt.savefig('road_of_dublin2.png', dpi=1000)
    plt.show()

    s.add((c[0], c[1]))
    r = Road(1234, (0,0), 'default')
    roads.append()
    roads.append(Road(osmid, coords, name))

    latlong = np.array(list(s))
    plt.plot(latlong[:,0], latlong[:,1], 'k.')
    plt.plot(latlong[:,0], latlong[:,1], '--')

# paths = glob.glob('./data/dublin_ireland.imposm-geojson/dublin_*.geojson')
# paths=[ './data/dublin_ireland.imposm-geojson/dublin_ireland_roads.geojson',
        # './data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen0.geojson',
        # './data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen1.geojson']
#------------------------------------------------------------

nodes=[]
for i in range(len(coordinates)):
    edges = []
    vlat, vlon = coordinates[i]
    if (i-1) >= 0:
        wlat, wlon = coordinates[i-1]
        dist = sqrt( (wlat - vlat)**2 + (wlat-vlon)**2 )
        e = Edge(i, i-1, dist, False)
        edges.append(e)
    if (i+1) < len(coordinates):
        wlat, wlon = coordinates[i+1]
        dist = sqrt( (wlat - vlat)**2 + (wlat-vlon)**2 )
        e = Edge(i, i+1, dist, False)
        edges.append(e)
    node = Node(i, vlat, vlon, edges)
    nodes.append(node)


