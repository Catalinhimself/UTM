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
f = 9

l = [s]
print(l)
while list(l).pop() != f:
    for v in g[list(l).pop()]:
        if v not in l:
            l.append(v)
            break

print(l)
