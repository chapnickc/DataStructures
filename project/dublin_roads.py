import overpy
import overpy.helper

import json
import glob
from math import sqrt

import numpy as np

import matplotlib.pyplot as plt
import matplotlib.style
matplotlib.style.use('seaborn-paper')

from Graph import *




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


