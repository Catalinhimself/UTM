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
ug = defaultdict(set)
# for k in [*g]:
#     for v in g[k]:
#         ug[v].append(k)

print(g)
print(c)
print(f)
print(m)
print(ug)
print(s, t)

n = 1
while g[s]:
    l = [s]
    while True:
        if g[s] == []:
            break
        last = list(l).pop()

        # if g[last] == []:
        #     if ug[last]:
        #         for o in ug[last]:
        #             if o not in l:
        #                 if sum(f[(o, last)]) > 0:
        #                     m[o].append(("-", last))
        #                     l.append(o)
        #                     last = list(l).pop()
        #                     break

        if g[last] == []:
            g[l[len(l)-2]].remove(last)
            l.pop()
            last = list(l).pop()
        if last == t:
            break
        if t in g[last]:
            v = t
            if sum(f[(last, v)]) < c[(last, v)]:
                m[v].append(("+", last))
                l.append(v)
                break
        for v in g[last]:
            if v not in l:
                if sum(f[(last, v)]) < c[(last, v)]:
                    m[v].append(("+", last))
                    ug[v].add(last)
                    l.append(v)
                    break
                if sum(f[(last, v)]) == c[(last, v)]:
                    g[last].remove(v)

                    # if last != s:
                    #     m[last].pop()
                    # if g[last] == []:
                    #     g[l[len(l)-2]].remove(last)
                    #     if len(l)-2 != 0:
                    #         m[l[len(l)-2]].pop()
                    #     l.pop()
                    # break
    if g[s] == []:
        break
    print()
    print("l", n, l)
    # print(m)
    E = []
    for i in range(1, len(l)):
        e = list(m[l[i]]).pop()
        if e[0] == "+":
            E.append(c[(e[1], l[i])]-sum(f[(e[1], l[i])]))
        else:
            E.append(sum(f[(e[1], l[i])]))
    print("E", n, "-min", E, end="")
    E = min(E)
    print("=", E)
    # print(m)
    for i in range(1, len(l)):
        e = list(m[l[i]]).pop()
        if e[0] == "+":
            f[(e[1], l[i])].append(E)
        else:
            f[(e[1], l[i])].append(-E)
    # print(f)
    n += 1
print(g)
print(c)
print(f)
print(m)
print(ug)
print(s, t)
