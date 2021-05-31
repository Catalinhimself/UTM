from collections import defaultdict
gg = {1: [2, 3, 5], 2: [4, 5], 3: [6], 4: [3, 8],
      5: [6, 7], 6: [7], 7: [4, 9], 8: [7, 9], 9: []}
g = defaultdict(list)
for k in [*gg]:
    for v in gg[k]:
        g[k].append(v)
        g[v].append(k)
print(g)

s = 1
t = 9
ml = [[s]]
while True:
    for l in ml:

        l2 = []
        while list(l).pop() != t:
            for v in g[l[len(l)-1]]:
                if v not in l:
                l2.append(l+[v])
                ml.append(l2)
                l2 = []
