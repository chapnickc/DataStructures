import numpy as np
p = np.array([1/2,1/3,1/6])
H = sum(-p*np.log2(p))
print(f'H: {H}')
