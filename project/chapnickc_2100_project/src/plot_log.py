%pylab
import sys
import numpy as np
import glob
import matplotlib

style.available
matplotlib.style.use('fivethirtyeight')
matplotlib.rcParams.update({'font.size': 12})

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


titles = ['Complete Graph', 'Complete Binary Tree', 'Linear Graph']
labels = ['List/Linear', 'List/Heap', 'Matrix/Linear', 'Matrix/Heap']
for i in range(len(values[0])):
    plt.figure(figsize=(9,6))
    for ix in values:
        plt.plot(values[ix][i]['v'], np.log2(values[ix][i]['t']), label=labels[ix])
        plt.xlabel(r'$N$')
        plt.ylabel(r'$\log($runtime$)$')
    plt.legend()
    plt.tight_layout(pad=3, w_pad=1.0, h_pad=1.0)
    plt.title(titles[i])
    plt.savefig(f'figure{i}.png', dpi=200)



