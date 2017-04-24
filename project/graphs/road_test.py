from Road import *

import json, glob
from functools import reduce

import matplotlib.pyplot as plt
import matplotlib.style
matplotlib.style.use('seaborn-paper')


path='../data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen0.geojson'
with open(path) as f:
    json_roads = json.loads(f.read())
    roads = []
    for road in json_roads['features']:
        road = Road(road)
        roads.append(road)



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

graph = Graph([node for node in road.graph for road in roads])

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

