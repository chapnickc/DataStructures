class Node(object):
    def __init__(self, index,  coords, edges = []):
        self._osmid = index
        self._coords = coords
        self._edges = edges

    @property
    def coords(self):
        return tuple(self._coords)

    @property
    def edges(self):
        return self._edges

    def add_edges(self, edges):
        self._edges.append(edges)

    def find_edge(self, osmid1, osmid2):
        for edge in self._edges:
            if edge.source == osmid1 and edge.destination == osmid2:
                return edge
        return False


    def find_source(self, osmid):
        for edge in self._edges:
            if edge.source == osmid:
                return edge
        return False

    def find_destination(self,osmid):
        for edge in self._edges:
            if edge.destination == osmid:
                return edge
        return False

    @property
    def osmid(self):
        return self._osmid

    def __len__(self):
        return len(self.edges)

    def __repr__(self):
        return f'ID: {self._osmid}'+' ({},{})'.format(*self.coords)
