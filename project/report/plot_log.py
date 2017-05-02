%pylab
import sys
import numpy as np
from IPython.display import display

sys.argv.append('./dijk2.log')
TT = 'ML'

try:
    with open(sys.argv[1]) as f:
        lines = f.readlines()
except IndexError as e:
    print('Usage: python plot_log.py <filepath>')


results = {};
results[TT] = {};
func_names = []
for line in lines:
        G, func_name, runtime = line.split()
        fkey = func_name.strip(':()N')
        if fkey not in func_names:
            func_names.append(fkey)
            results[TT][fkey] = {}
            results[TT][fkey]['V'] = np.array([])
            results[TT][fkey]['E'] = np.array([])
            results[TT][fkey]['T'] = np.array([])
        v, e = [int(x) for x in G.strip('()').split(',')]
        results[TT][fkey]['V'] = np.append(results[TT][fkey]['V'], v)
        results[TT][fkey]['E'] = np.append(results[TT][fkey]['E'], e)
        results[TT][fkey]['T'] = np.append(results[TT][fkey]['T'], float(runtime))

results[TT].keys()

for TT in results.keys():
    for fkey in results[TT].keys():
        results[TT].keys()
        v = results[TT][fkey]['V']
        e = results[TT][fkey]['E']
        t = results[TT][fkey]['T']

        plt.plot(np.log2(v), np.log2(t), label=f'{TT}-{fkey}')
        plt.xlabel(r'$\log(N)$')
        plt.ylabel(r'$\log($runtime$)$')
        plt.legend()

