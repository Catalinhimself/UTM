from collections import defaultdict

gg = {1: [2, 3, 5], 2: [4, 5], 3: [6], 4: [3, 8],
      5: [6, 7], 6: [7], 7: [4, 9], 8: [7, 9], 9: []}
g = gg
c = {(1, 2): 8, (1, 3): 9, (1, 5): 6, (2, 4): 5, (2, 5): 6, (3, 6): 6, (4, 3): 5, (4, 8)
      : 4, (5, 6): 3, (5, 7): 5, (6, 7): 4, (7, 4): 3, (7, 9): 9, (8, 7): 5, (8, 9): 6}

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
# marcaje
m = defaultdict(list)
rg = defaultdict(list)
for k in [*g]:
    for v in g[k]:
        rg[v].append(k)
        m[v] = []

l = [s]
print(l)
while True:
    ultim = list(l).pop()
    if ultim == t:
        break
    for v in g[ultim]:
        if sum(f[(ultim, v)]) < c[(ultim, v)]:
            m[v].append(("+", ultim)
            # break

# while True:
#     for v in g[ultim]:
#         if sum(f[(ultim, v)]) < c[(ultim, v)]:
#             m[v].append(("+", ultim)
#             l.append(123)
#             break
#     l.append(v)
#     break
# if sum(f[(ultim, v)]) == c[(ultim, v)]:
#     for o in rg[v]:
#         m[o].append(("-", ultim)
#         l.append(o)
#         break
#     break
print(l)
print(m)
