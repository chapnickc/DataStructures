
class Node(object):
    def __init__(self, index,  lat, lon, edges = []):
        self.ix = index
        self.lat = lat
        self.lon = lon
        self._edges = edges

    @property
    def coordinates(self):
        return (self.lat, self.lon)

    @property
    def edges(self):
        return self._edges

    def add_edges(self, new_edges):
        self._edges.append(new_edges)
