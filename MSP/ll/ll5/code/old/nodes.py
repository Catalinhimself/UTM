from collections import defaultdict


g = {1: [2, 3, 5], 2: [4, 5], 3: [6], 4: [3, 8],
     5: [6, 7], 6: [7], 7: [4, 9], 8: [7, 9], 9: []}
c = {(1, 2): 8, (1, 3): 9, (1, 5): 6, (2, 4): 5, (2, 5): 6, (3, 6): 6, (4, 3): 5, (4, 8): 4, (5, 6): 3, (5, 7): 5, (6, 7): 4, (7, 4): 3, (7, 9): 9, (8, 7): 5, (8, 9): 6}

s = 1
t = 9
m = defaultdict(list)
rg = defaultdict(list)
f = defaultdict(list)
for k in [*c]:
    f[k].append(0)


def dfs(s, t):
    v = s
    path = [v]
    visited = set([v])
    blacklist = []
    while v != t:
        for neighbour in g[v]:
            if neighbour not in visited and neighbour not in blacklist:
                if sum(f[(v, neighbour)]) < c[(v, neighbour)]:
                    v = neighbour
                    path.append(v)
                    break
        blacklist.append(path.pop())
        v = path[len(path)-1]
        for neighbour in rg[v]:
            if neighbour not in visited:
                v = neighbour
                path.append(v)
                break

        visited.add(v)
    return path


def flow(path):
    E = []
    for i in path:
        if i == s:
            prev = i
        if i != s:
            rg[i].append(prev)
            if c[(prev, i)]:
                E.append(c[(prev, i)]-sum(f[(prev, i)]))
            else:
                E.append(sum(f[(prev, i)]))
            prev = i
    print("E _ min", E, end=" = ")
    E = min(E)
    print(E)
    return E


def modify(path, E):
    for i in path:
        if i == s:
            prev = i
        if i != s:
            if c[(prev, i)]:
                f[(prev, i)].append(E)
            else:
                f[(prev, i)].append(-E)
            prev = i


for i in range(3):
    p = dfs(s, t)
    print(p)
    e = flow(p)
    modify(p, e)

# print(f)
