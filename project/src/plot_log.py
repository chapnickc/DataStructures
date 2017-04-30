%pylab
import sys
import numpy as np
from IPython.display import display

sys.argv.append('./dijk0.log')

try:
    with open(sys.argv[1]) as f:
        lines = f.readlines()
except IndexError as e:
    print('Usage: python plot_log.py <filepath>')


results = {};
results['LL'] = {};
func_names = []
for line in lines:
        G, func_name, runtime = line.split()
        fkey = func_name.strip(':()N')
        if fkey not in func_names:
            func_names.append(fkey)
            results['LL'][fkey] = {}
            results['LL'][fkey]['V'] = np.array([])
            results['LL'][fkey]['E'] = np.array([])
            results['LL'][fkey]['T'] = np.array([])
        v, e = [int(x) for x in G.strip('()').split(',')]
        results['LL'][fkey]['V'] = np.append(results['LL'][fkey]['V'], v)
        results['LL'][fkey]['E'] = np.append(results['LL'][fkey]['E'], e)
        results['LL'][fkey]['T'] = np.append(results['LL'][fkey]['T'], float(runtime))

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

