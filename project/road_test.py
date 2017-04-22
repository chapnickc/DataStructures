from Road import *
import json, glob
import matplotlib.pyplot as plt
import matplotlib.style
matplotlib.style.use('seaborn-paper')


path='./data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen0.geojson'
with open(path) as f:
    json_roads = json.loads(f.read())
    roads = []
    for road in json_roads['features']:
        r = Road(road)
        roads.append(r)

graph = r.graph




i=0
unique_nodes = set()
for road in roads:
    for node in road.graph:
        i+=1
        unique_nodes.add(node.coordinates)

print('Unique Nodes: {:0.2f}%'.format(100*len(s)/i))

coords =list(map(lambda s: (s[0], s[1]), unique_nodes))






from functools import reduce
reduce( (lambda x, y: x * y), [1, 2, 3, 4] )
min(roads, key=lambda road: road.length)
max(roads, key=lambda road: road.length)

max(roads, key=lambda road: road.length)


nodes = [max(road.nodes, key=lambda node: len(node.edges)) for road in roads]

n= max(nodes, key=lambda node: len(node.edges))



