import json
from collections import defaultdict
import numpy as np

g = json.load(open("1.json"))
temp = defaultdict(list)
for key in [*g]:
    for v in g[key]:
        temp[int(key)].append(v)
g = temp
c = defaultdict(int)
temp = json.load(open("1.c.json"))
for k in [*temp]:
    for l in temp[k]:
        c[(int(k), l[0])] = l[1]
f = defaultdict(list)
for k in [*c]:
    f[k].append(0)
for k in [*g]:
    for v in g[k]:
        if v not in [*g]:
            g[v] = []
print("graf")
print(g)
print("------------------------------------")
print("capacitatea")
print(c)
print("------------------------------------")
print("flux")
print(f)
print("--------------------------------------")
intrari = defaultdict(bool)
for k in [*g]:
    intrari[k] = False
for k in [*g]:
    if not len(g[k]):
        destinatia = k
    for v in g[k]:
        intrari[v] = True
for v in [*intrari]:
    if not intrari[v]:
        sursa = v
gr = np.zeros((destinatia+1, destinatia+1))
for k in [*g]:
    for v in g[k]:
        gr[k][v] = c[(k, v)]
print(gr)


def BFS(graph, s, t, parent):
    # Return True if there is node that has not iterated.
    visited = [False] * len(graph)
    queue = []
    queue.append(s)
    visited[s] = True

    while queue:
        u = queue.pop(0)
        for ind in range(len(graph[u])):
            if visited[ind] is False and graph[u][ind] > 0:
                queue.append(ind)
                visited[ind] = True
                parent[ind] = u

    return True if visited[t] else False


def FordFulkerson(graph, source, sink):
    # This array is filled by BFS and to store path
    parent = [-1] * (len(graph))
    max_flow = 0
    while BFS(graph, source, sink, parent):
        path_flow = float("Inf")
        s = sink

        while s != source:
            # Find the minimum value in select path
            path_flow = min(path_flow, graph[parent[s]][s])
            s = parent[s]

        max_flow += path_flow
        v = sink

        while v != source:
            u = parent[v]
            graph[u][v] -= path_flow
            graph[v][u] += path_flow
            v = parent[v]
    return max_flow


print(FordFulkerson(gr, sursa, destinatia))
