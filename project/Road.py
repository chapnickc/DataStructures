from Graph import *
from Edge import *
from Node import *
from math import sqrt

class Road(object):
    def __init__(self, json_road):
        # osmid:int, nodes:list, name:str)
        self._geoj = json_road
        self._length = len(json_road['geometry']['coordinates'])
        self._osmid = int(json_road['properties']['osm_id'])
        self._name = json_road['properties']['name']
        self.oneway =  bool(json_road['properties']['oneway'])
        coordinates = json_road['geometry']['coordinates']
        self._graph = self._road_graph(coordinates)


    def _road_graph(self, coordinates:list):
        nodes = []
        coordinates = self._geoj['geometry']['coordinates']
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
            node = Node(i, vlat, vlon, edges)
            nodes.append(node)

        graph = Graph(nodes)
        return graph

    @property
    def graph(self):
        return self._graph

    @property
    def json(self):
        return self._geoj

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

