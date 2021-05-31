from collections import defaultdict

gg = {1: [2, 3, 5], 2: [4, 5], 3: [6], 4: [3, 8],
      5: [6, 7], 6: [7], 7: [4, 9], 8: [7, 9], 9: []}
c = {(1, 2): 8, (1, 3): 9, (1, 5): 6, (2, 4): 5, (2, 5): 6, (3, 6): 6, (4, 3): 5, (4, 8)     : 4, (5, 6): 3, (5, 7): 5, (6, 7): 4, (7, 4): 3, (7, 9): 9, (8, 7): 5, (8, 9): 6}

F_max = 0
s = 1
t = 9
m = defaultdict(list)
rg = defaultdict(list)

g = defaultdict(list)
for k in [*gg]:
    g[k] = []
    for v in gg[k]:
        g[k].append(v)

f = defaultdict(list)
for k in [*c]:
    f[k].append(0)

print(gg)
print("######graf")
print(g)
print("######grafrevers")
print(rg)
print("######marcaj")
print(m)
print("######capacitate")
print(c)
print("######flux")
print(f)
print("######")


# cod ciotkii) =>
z = 0
while True:
    l = [s]
    blacklist = set()
    while l[len(l)-1] != t:
        remove = True
        for v in g[l[len(l)-1]]:
            # print(l)
            if v not in l and v not in blacklist:
                if sum(f[(l[len(l)-1], v)]) != c[(l[len(l)-1], v)]:
                    # print("inainte")
                    m[v].append(("+", l[len(l)-1]))
                    rg[v].append(l[len(l)-1])
                    l.append(v)
                    remove = False
                    break
        for v in rg[l[len(l)-1]]:
            if v not in l and v not in blacklist:
                if sum(f[v, (l[len(l)-1])]):
                    # print("inapoi")
                    m[v].append(("-", l[len(l)-1]))
                    l.append(v)
                    remove = False
                    break
        if remove:
            blacklist.add(l[len(l)-1])
            if m[l[len(l)-1]]:
                m[l[len(l)-1]].pop()
            l.pop()
        # print(blacklist)

    print(l)
    E = []
    for i in range(1, len(l)):
        e = list(m[l[i]]).pop()
        if e[0] == "+":
            E.append(c[(e[1], l[i])]-sum(f[(e[1], l[i])]))
        else:
            E.append(sum(f[(l[i], e[1])]))
    print("E _ min", E, end=" = ")
    E = min(E)
    print(E)
    F_max += E
    print("F_max", F_max)
    for i in l:
        if i == s:
            p = s
        else:
            if list(m[i]).pop()[0] == "+":
                f[(p, i)].append(E)
            else:
                f[(i, p)].append(-E)
            p = i
    z += 1
    if z == 10:
        break
    # print("######graf")
    # print(g)
    # print("######grafrevers")
    # print(rg)
    # print("######marcaj")
    # print(m)
    # print("######capacitate")
    # print(c)
    # print("######flux")
    # for k in [*f]:
    #     print(k, sum(f[k]))
    # print("######")
    # break
print("stoped")
