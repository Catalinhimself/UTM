from collections import defaultdict

gg = {1: [2, 3, 5], 2: [4, 5], 3: [6], 4: [3, 8],
      5: [6, 7], 6: [7], 7: [4, 9], 8: [7, 9], 9: []}
c = {(1, 2): 8, (1, 3): 9, (1, 5): 6, (2, 4): 5, (2, 5): 6, (3, 6): 6, (4, 3): 5, (4, 8)
      : 4, (5, 6): 3, (5, 7): 5, (6, 7): 4, (7, 4): 3, (7, 9): 9, (8, 7): 5, (8, 9): 6}

g = defaultdict(list)
for k in [*gg]:
    g[k] = []
    for v in gg[k]:
        g[k].append(v)
f = defaultdict(list)
for k in [*c]:
    f[k].append(0)

s = 1
t = 9
m = defaultdict(list)
ug = defaultdict(list)
for k in [*g]:
    for v in g[k]:
    for v in g[k]:
        ug[v].append(k)
        ug[k].append(v)
print(ug)
while True:
    l = [s]
    while True:
        last = list(l).pop()
        if last == t:
            break
        if g[last] == []:
            g[l[len(l)-2]].remove(last)
            l.pop()
            break
        if t in g[last]:
            v = t
            print("---", v)
            print(sum(f[(last, v)]), c[(last, v)])
            if sum(f[(last, v)]) < c[(last, v)]:
                m[v].append(("+", last))
                l.append(v)
                break
        for v in g[last]:
            # print(g[last])
            if v not in l:
                # print("---", v)
                # print(sum(f[(last, v)]), c[(last, v)])
                if sum(f[(last, v)]) < c[(last, v)]:
                    m[v].append(("+", last))
                    l.append(v)
                    break
                if sum(f[(last, v)]) == c[(last, v)]:
                    g[last].remove(v)
                    break

    print(l)
    # print(m)
    E = []
    for i in range(1, len(l)-1):
        e = list(m[l[i]]).pop()
        if e[0] == "+":
            E.append(c[(e[1], l[i])]-sum(f[(e[1], l[i])]))
        else:
            E.append(sum(f[(e[1], l[i])]))
    print("E-min", E, end="")
    E = min(E)
    print("=", E)

    for i in range(1, len(l)-1):
        e = list(m[l[i]]).pop()
        if e[0] == "+":
            f[(e[1], l[i])].append(E)
        else:
            f[(e[1], l[i])].append(-E)
