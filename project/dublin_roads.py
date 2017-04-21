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

# data = open(paths[0]).read()
data = open(paths[1]).read()

rj = json.loads(data)



roads = list()
figure = plt.figure()
for feature in rj['features'][:3000]:
    osmid = int(feature['properties']['osm_id'])
    coords = feature['geometry']['coordinates']
    name = feature['properties']['name']
    roads.append(Road(osmid, coords, name))
    plt.plot([c[0] for c in coords],  [c[1] for c in coords], 'k.')
    plt.plot([c[0] for c in coords],  [c[1] for c in coords], '-')
plt.title('Roads of Dublin, Ireland')

plt.show()

plt.savefig('dublin.png', dpi=1000)
