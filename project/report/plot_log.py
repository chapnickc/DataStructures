%pylab
import sys
import numpy as np
import glob

flist = glob.glob('./dijk?.log')

raw_data = {}
for ix, fpath in enumerate(flist):
    print(fpath)
    with open(fpath) as f:
        lines = f.readlines()
        raw_data[ix] = lines

results = {}
names = ['LL', 'LH', 'ML', 'MH']
for i in range(len(raw_data)):
    results[i] = {}
    func_names = []
    for line in raw_data[i]:
            G, func_name, runtime = line.split()
            fkey = func_name.strip(':()N')
            if fkey not in func_names:
                func_names.append(fkey)
                results[i][fkey] = {}
                results[i][fkey]['V'] = np.array([])
                results[i][fkey]['E'] = np.array([])
                results[i][fkey]['T'] = np.array([])

            v, e = [int(x) for x in G.strip('()').split(',')]
            results[i][fkey]['V'] = np.append(results[i][fkey]['V'], v)
            results[i][fkey]['E'] = np.append(results[i][fkey]['E'], e)
            results[i][fkey]['T'] = np.append(results[i][fkey]['T'], float(runtime))

fkey = 'dijkstra'
labels = ['List/Linear', 'List/Heap', 'Matrix/Linear', 'Matrix/Heap']
for i in range(len(results)):
    v = results[i][fkey]['V']
    e = results[i][fkey]['E']
    t = results[i][fkey]['T']
    plt.plot(np.log2(v), np.log2(t), label=labels[i])
    plt.xlabel(r'$\log(N)$')
    plt.ylabel(r'$\log($runtime$)$')
plt.legend()

