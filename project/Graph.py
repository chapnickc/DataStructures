
class Graph(object):
    def __init__(self, nodes:list):
        self._nodes = nodes

    @property
    def nodes(self):
        return self._nodes

    def __iter__(self):
        for node in self._nodes:
            yield node


if __name__ == '__main__':
    pass
