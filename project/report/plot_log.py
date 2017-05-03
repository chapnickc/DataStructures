%pylab
import sys
import numpy as np

import glob

flist = glob.glob('./dijk?.log')

results = {}
names = ['LL', 'LH', 'ML', 'MH']



for ix, fpath in enumerate(flist):
    with open(fpath) as f:
        lines = f.readlines()
        results[ix] = lines


# try:
    # with open(sys.argv[1]) as f:
        # lines = f.readlines()
# except IndexError as e:
    # print('Usage: python plot_log.py <filepath>')
 
results = {}
func_names = []
for line in lines:
        G, func_name, runtime = line.split()
        fkey = func_name.strip(':()N')
        if fkey not in func_names:
            func_names.append(fkey)
            results[fkey] = {}
            results[fkey]['V'] = np.array([])
            results[fkey]['E'] = np.array([])
            results[fkey]['T'] = np.array([])
        v, e = [int(x) for x in G.strip('()').split(',')]
        results[fkey]['V'] = np.append(results[fkey]['V'], v)
        results[fkey]['E'] = np.append(results[fkey]['E'], e)
        results[fkey]['T'] = np.append(results[fkey]['T'], float(runtime))

results.keys()

for fkey in results.keys():
    v = results[fkey]['V']
    e = results[fkey]['E']
    t = results[fkey]['T']

    plt.plot(np.log2(v), np.log2(t), label=f'{fkey}')
    plt.xlabel(r'$\log(N)$')
    plt.ylabel(r'$\log($runtime$)$')
    plt.legend()

