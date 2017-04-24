
class Node(object):
    def __init__(self, index,  coords):
        self._osmid = index
        self._coords = coords

    @property
    def coords(self):
        return self._coords

    @property
    def osmid(self):
        return self._osmid

    def __repr__(self):
        return f'ID: {self._osmid}'+' ({},{})'.format(*self.coords)

