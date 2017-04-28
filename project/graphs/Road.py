from Graph import *
from Edge import *
from Node import *
from math import sqrt
import json

class Road(Graph):
    def __init__(self, json_road):
        super(Road, self).__init__(nodes=[], edges=[])
        self._json = json_road
        self._name = json_road['properties']['name']
        self._osmid = float(json_road['properties']['osm_id'])
        self._length = len(json_road['geometry']['coordinates'])
        self.oneway =  bool(json_road['properties']['oneway'])
        self._link_nodes()

    def _euclid_dist(self, v, w):
        return sqrt(sum([ (w_i - v_i)**2 for v_i, w_i in zip(v, w) ]))

    def _link_nodes(self):
        coords = self._json['geometry']['coordinates']
        for i in range(len(coords)):
            node_id = self._osmid + i*0.1
            v = coords[i]
            node = Node(node_id,  v)
            if (i - 1) >= 0:
                w = coords[i-1]
                dest = self._osmid + (i - 1) * 0.1
                self._add_edge(node, node_id, dest, v, w)
            if (i + 1) < len(coords):
                w = coords[i+1]
                dest = self._osmid + (i + 1) * 0.1
                self._add_edge(node, node_id, dest, v, w)
            self.add_nodes(node)

    def _add_edge(self, node, src, dest, v, w):
        dist = self._euclid_dist(v, w)
        if not node.find_edge(dest, node.osmid):
            edge = Edge(src, dest, dist, self.oneway)
            node.add_edges(edge)
            return True
        return False


    @property
    def json(self):
        return self._json

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

    def __iter__(self):
        for node in self._nodes:
            yield node

if __name__ == '__main__':

    filepath = '../data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen0.geojson'
    with open(filepath) as f:
        json_roads = json.loads(f.read())

    road = json_roads['features'][0]
    r = Road(road)

