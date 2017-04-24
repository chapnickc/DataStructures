
class Edge(object):
    def __init__(self, v:float, w:float, weight:float, directed:bool):
        """
        for example,
            v: 486412304.0
            w: 486412304.1
            weight = 1
            directed=True
        """
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

