#!/usr/bin/env/python3.6

from Graph import *
from Road import *

import numpy as np
import matplotlib.pyplot as plt
import json
from tqdm import tqdm


filepath = '../data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen0.geojson'
with open(filepath) as f:
    json_roads = json.loads(f.read())


graph = Graph()
coords = set(())
repeat_nodes = []
total_nodes=0

step = 100/len(json_roads['features'])
with tqdm(total=100) as pbar:
    for jroad in json_roads['features']:
        road = Road(jroad)
        for node in road:
            total_nodes+=1
            # only add node to graph if new coordinates
            if node.coords not in coords:
                coords.add(node.coords)
                graph.add_nodes(node)
            else:
                repeat_nodes.append(node)
        pbar.update(step)

print('All nodes accounted for: {}'.format(total_nodes == len(graph) + len(repeat_nodes)))
print('Unique Nodes: {}'.format( 100*len(coords)/total_nodes) )


step = 100/len(repeat_nodes)
with tqdm(total=100) as pbar:
    for node in repeat_nodes:
        matching_node, = graph.find_node(coords=node.coords)
        matching_node.add_edges(node.edges)
        pbar.update(step)



len(node.edges)
graph.nodes[0]
graph.nodes[1]


len(graph)
len(repeat_nodes)

subgraph = graph[0:10]
lat = np.array([ node.coords[0] for node in subgraph])
lon = np.array([ node.coords[1] for node in subgraph])


node.edges[0]

srcs = [];
for node in subgraph:
    for edge in node.edges:
        srcs.append(graph.find_node_by_id(edge.source))


graph.find_node_by_id(node.edges[1].destination)

plt.plot(lat, lon, 'k.')
plt.plot(lat, lon, 'k.')



# lat = np.append(lat, node.coords[0])
# lon = np.append(lon, node.coords[1])
graph.add_nodes(node)

coords = set(())
for node in graph:
    lat, lon = node.coords
    if tuple( (lat, lon) ) not in coords:
        coords.add(tuple((lat, lon)))


latlon = np.array([[x,y] for x,y in zip(lat,lon)])
for x,y in latlon:
    if tuple((x,y)) not in coords:
        coords.add(tuple((x, y)))
    else:
        ixs = np.unique(np.where(latlon == [[x,y]])[0])
        repeat_nodes = [graph.nodes[ix] for ix in ixs]
        keep_node = repeat_nodes.pop(0)
        edges = [ graph.nodes[graph.nodes.index(node)].edges for node in repeat_nodes ]
        # for node in repeat_nodes: graph.nodes.remove(node)

for coords in coords
   lat = np.append(lat, c[0])
   lon = np.append(lon, c[1])

plt.plot(lat, lon, 'k.')

plt.savefig('scatter.png',dpi=1000)
