%pylab
import sys
import numpy as np
import glob
import matplotlib.style
style.use('ggplot')

flist = glob.glob('./dijk?.log')

raw_data = {}
for ix, fpath in enumerate(flist):
    print(fpath)
    with open(fpath) as f:
        lines = f.readlines()
        raw_data[ix] = lines


N = 9
results = {}
for ix, test in raw_data.items():
    results[ix] = {}
    test_num = 0
    for i in range(1, 6):
        if i % 2 != 0:
            results[ix][test_num] = test[i*N:(i*N + N)]
            test_num += 1


labels = ['Complete Graph', 'Complete Binary Tree', 'Linear Graph']
i = -1
values = {}
for test in results.values():
    i += 1
    values[i] = {}
    plt.figure()
    for ix, data in test.items():
        values[i][ix] = {}
        v = np.array([])
        e = np.array([])
        t = np.array([])
        for line in data:
            G, func_name, runtime = line.split()
            V, E = [int(x) for x in G.strip('()').split(',')]
            v = np.append(v, V)
            e = np.append(e, E)
            t = np.append(t, float(runtime))
        values[i][ix]['v'] = v
        values[i][ix]['e'] = e
        values[i][ix]['t'] = t




        plt.plot(v, np.log2(t), label=labels[ix])
        plt.xlabel(r'$\log(N)$')
        plt.ylabel(r'$\log($runtime$)$')

titles = ['Complete Graph', 'Complete Binary Tree', 'Linear Graph']
labels = ['List/Linear', 'List/Heap', 'Matrix/Linear', 'Matrix/Heap']
for i in range(len(values[0])):
    plt.figure()
    for ix in values:
        plt.plot(values[ix][i]['v'], np.log2(values[ix][i]['t']), label=labels[ix])
        plt.xlabel(r'$N$')
        plt.ylabel(r'$\log($runtime$)$')
    plt.legend()
    plt.title(titles[i])
    plt.savefig(f'figure{i}.png', dpi=300)





















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

