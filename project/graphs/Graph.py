
class Graph(object):
    def __init__(self, nodes = [], edges = []):
        self.nodes = nodes
        self.edges = edges

    @property
    def nodes(self):
        return self._nodes

    @nodes.setter
    def nodes(self, array):
        self._nodes = array

    @property
    def edges(self):
        return self._nodes

    @edges.setter
    def edges(self, array):
        self._edges = array

    def add_nodes(self, new_nodes):
        self._nodes.append(new_nodes)

    def add_edges(self, new_edges):
        self._edges.append(new_edges)

    def find_node(self, coords):
        return list(filter(lambda node: node.coords == coords, self.nodes))

    def find_node_by_id(self, osmid):
        return list(filter(lambda node: node.osmid == osmid, self.nodes))


    def __iter__(self):
        for node in self._nodes:
            yield node

    def __getitem__(self,index):
        return self._nodes[index]

    def __setitem__(self,index, value):
        self._nodes[index] = value

    def __len__(self):
        return len(self._nodes)

