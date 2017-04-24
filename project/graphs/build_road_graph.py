from Graph import *
from Road import *

import json, glob
from functools import reduce

import matplotlib.pyplot as plt
import matplotlib.style
matplotlib.style.use('seaborn-paper')




def read_roads(filepath):
    with open(filepath) as f:
        json_roads = json.loads(f.read())
    roads = []
    for road in json_roads['features']:
        r = Road(road)
        roads.append(r)
    return roads


def connect_road_nodes(coordinates):
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
    return nodes



filepath = '../data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen0.geojson'
roads, json_roads= read_roads(filepath)

nodes = set()
for road in roads:
    for node in road.graph:
        try:
            ix = list(nodes).index(node)
        except ValueError as e:
            nodes.add(node)

        if ix:
            node.edges


all_nodes = [node for node in road.graph for road in roads]
graph = Graph([node for node in road.graph for road in roads])




# graph = road.graph


unique=0
node_set = set()
for road in roads:
    for node in road.graph:
        node_set.add(node.coordinates)

print('Unique Nodes: {:0.2f}%'.format(100*len(node_set)/len(road.graph)))
coords = list(map(lambda s: (s[0], s[1]), node_set))


all_nodes=[node for node in road.graph for road in roads]

for node in all_nodes:
    print(node.id)



len(graph)

node = graph.nodes[0]
node.coordinates
node.









#------------------------------------------------------------------

reduce( (lambda x, y: x * y), [1, 2, 3, 4] )
min(roads, key=lambda road: road.length)
max(roads, key=lambda road: road.length)
max(roads, key=lambda road: road.length)

nodes = [max(road.nodes, key=lambda node: len(node.edges)) for road in roads]
n = max(nodes, key=lambda node: len(node.edges))

