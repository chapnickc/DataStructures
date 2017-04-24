from Road import *
import json

filepath = '../data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen0.geojson'
with open(filepath) as f:
    json_roads = json.loads(f.read())

road = json_roads['features'][0]
r = Road(road)
r.nodes

