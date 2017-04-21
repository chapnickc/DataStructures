%pylab
import json
import glob
import overpy
import overpy.helper
import matplotlib.style
import numpy as np
# matplotlib.style.use('bmh')
matplotlib.style.use('fivethirtyeight')





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

with open(paths[1]) as f:
    rj = json.loads(f.read())


s = set()
figure = plt.figure()
roads = all_cords = list()
for feature in rj['features'][:3000]:
    osmid = int(feature['properties']['osm_id'])
    coords = feature['geometry']['coordinates']
    name = feature['properties']['name']

    plt.plot([c[0] for c in coords],  [c[1] for c in coords], '.')
    plt.plot([c[0] for c in coords],  [c[1] for c in coords], '-')
    plt.title('Roads of Dublin, Ireland')
    plt.show()

matplotlib.style.use('dark_background')


plt.savefig('dublin538.png', dpi=1000)

s.add((c[0], c[1]))
roads.append(Road(osmid, coords, name))

latlong = np.array(list(s))
plt.plot(latlong[:,0], latlong[:,1], 'k.')
plt.plot(latlong[:,0], latlong[:,1], '--')


