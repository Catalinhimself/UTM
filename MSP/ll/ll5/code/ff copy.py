from collections import defaultdict

gg = {1: [2, 3, 5], 2: [4, 5], 3: [6], 4: [3, 8],
      5: [6, 7], 6: [7], 7: [4, 9], 8: [7, 9], 9: []}
g = gg
c = {(1, 2): 8, (1, 3): 9, (1, 5): 6, (2, 4): 5, (2, 5): 6, (3, 6): 6, (4, 3): 5, (4, 8): 4, (5, 6): 3, (5, 7): 5, (6, 7): 4, (7, 4): 3, (7, 9): 9, (8, 7): 5, (8, 9): 6}

f = defaultdict(list)
for k in [*c]:
    f[k].append(0)
print("graf")
print(g)
print("------------------------------------")
print("capacitatea")
print(c)
print("------------------------------------")
print("flux")
print(f)
print("--------------------------------------")
print("--------------------------------------")
print("--------------------------------------")
print("--------------------------------------")
s = 1
t = 9
rg = defaultdict(list)
for k in [*g]:
    for v in g[k]:
        rg[v].append(k)
for k in [*rg]:
    rg[k].sort()

while True:
    l = [s]
    m = [("+", s)]
    while list(l).pop() != t:
        # if not g[list(l).pop()]:

        for v in g[list(l).pop()]:
            if v not in l:
                m.append(("+", list(l).pop()))
                l.append(v)
                break
    print("l:", l)
    print(m)
    flux = []
    for i in range(len(l)):
        if l[i] != m[i][1]:
            print(l[i], m[i])
            print(c[(m[i][1], l[i])], "-", list(f[(m[i][1], l[i])]).pop(),
                  c[(m[i][1], l[i])]-list(f[(m[i][1], l[i])]).pop())
            flux.append(c[(m[i][1], l[i])]-list(f[(m[i][1], l[i])]).pop())
    print("E= min", flux, "min:", min(flux))
    for i in range(len(l)):
        if l[i] != m[i][1]:
            f[(m[i][1], l[i])].append(list(f[(m[i][1], l[i])]).pop()+min(flux))
            if list(f[(m[i][1], l[i])]).pop() == c[(m[i][1], l[i])]:
                g[m[i][1]].remove(l[i])
