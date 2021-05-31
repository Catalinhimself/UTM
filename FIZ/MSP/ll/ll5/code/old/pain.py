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
    while g[s]:

        for v in g[list(l).pop()]:
            if v not in l:
                if sum(f[(list(l).pop(), v)]) < c[(list(l).pop(), v)]:
                    m[v].append(("+", list(l).pop()))
                    ug[v].add(list(l).pop())
                    l.append(v)
                    break
                if sum(f[(list(l).pop(), v)]) == c[(list(l).pop(), v)]:
                    g[list(l).pop()].remove(v)
                    break
        if list(l).pop() == t:
            break

        print(l)
        if g[list(l).pop()] == []:
            if ug[list(l).pop()]:
                for o in ug[list(l).pop()]:
                    if o not in l:
                        print(o)
                        print(sum(f[(o, list(l).pop())]))
                        if sum(f[(o, list(l).pop())]) > 0:
                            print("hahaha")
                            m[o].append(("-", list(l).pop()))
                            l.append(o)
                            print(l)
                            break
                    else:
                        ug[list(l).pop()].remove(o)
                        break
            else:
                g[l[len(l)-2]].remove(list(l).pop())
                l.pop()
        # if g[list(l).pop()] == []:
        #     g[l[len(l)-2]].remove(list(l).pop())
        #     l.pop()

        if t in g[list(l).pop()]:
            v = t
            if sum(f[(list(l).pop(), v)]) < c[(list(l).pop(), v)]:
                m[v].append(("+", list(l).pop()))
                l.append(v)
                break
    print()
    print("l", n, l)
    E = []
    for i in range(1, len(l)):
        e = list(m[l[i]]).pop()
        if e[0] == "+":
            E.append(c[(e[1], l[i])]-sum(f[(e[1], l[i])]))
        else:
            E.append(sum(f[(e[1], l[i])]))
    print("E", n, "-min", E, end="")

    if g[s] == []:
        break

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
