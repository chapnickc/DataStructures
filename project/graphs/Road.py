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
        unique_coords = set()
        for i in range(len(coords)):
            v = coords[i] # (lat, lon)
            node_ix = None
            try:
                node_ix = list(unique_coords).index(v)
                print(f'Updating node: {i}')
                node = nodes[node_ix]
            except ValueError as e:
                print('Creating new node')
                unique_coords.add(tuple(v))
                node = Node(self._osmid + i * 0.1, v)

            if (i - 1) >= 0:
                w = coords[i-1]
                d = self._euclid_dist(v, w)
                edge = Edge(node.osmid, self._osmid + 0.1*(i-1), d, self.oneway)
                self.add_edges(edge)

            if (i + 1) < len(coords):
                w = coords[i+1]
                d = self._euclid_dist(v, w)
                edge = Edge(node.osmid, self._osmid + (i+1) * 0.1, d, self.oneway)
                self.add_edges(edge)

            if node_ix:
                self._nodes[node_ix] = node
            else:
                self.add_nodes(node)


    def _road_graph(self, coordinates:list):
        nodes = []
        coordinates = self._json['geometry']['coordinates']
        osmid=self._osmid
        for i in range(len(coordinates)):
            edges = []
            vlat, vlon = coordinates[i]
            if (i-1) >= 0:
                wlat, wlon = coordinates[i-1]
                dist = sqrt( (wlat - vlat)**2 + (wlat-vlon)**2 )
                edge = Edge(i, i-1, dist, self.oneway)
                edges.append(edge)
            if (i+1) < len(coordinates):
                wlat, wlon = coordinates[i+1]
                dist = sqrt( (wlat - vlat)**2 + (wlat-vlon)**2 )
                edge = Edge(i, i+1, dist, self.oneway)
                edges.append(edge)
            node = Node(osmid+i*0.1, vlat, vlon, edges)
            nodes.append(node)

        graph = Graph(nodes)
        return graph


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


if __name__ == '__main__':

    filepath = '../data/dublin_ireland.imposm-geojson/dublin_ireland_roads_gen0.geojson'
    with open(filepath) as f:
        json_roads = json.loads(f.read())

    road = json_roads['features'][0]
    r = Road(road)

