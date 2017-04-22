
class Edge(object):
    def __init__(self, v:int, w:int, weight:float, directed:bool):
        self.source = v
        self.destination = w
        self.weight = weight
        self.directed = directed

    def vertices(self):
        return (self.source, self.destination)

    def weight(self):
        return self.weight

    def __repr__(self):
        return f'Indices: ({self.source},{self.destination})' + \
                f'  Weight: {self.weight:{3}.{4}}' + \
               f'  Directed: {self.directed}'
