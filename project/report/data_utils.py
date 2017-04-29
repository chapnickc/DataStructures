%pylab
import numpy as np
import glob

N = np.arange(1, 10)

n = 2**N
e = n*(n-1)/2
runtime =  np.array([4e-06, 7e-06, 2.9e-05, 0.000242, 0.002565, 0.032408, 0.435132, 6.31537, 94.4416])

logs = glob.glob('./*.txt')



