# Python3 program to print all paths of
# source to destination in given graph
from typing import List
from collections import deque

# Utility function for printing
# the found path in graph


def printpath(path: List[int]) -> None:

    size = len(path)
    for i in range(size):
        print(path[i], end=" ")

    print()

# Utility function to check if current
# vertex is already present in path


def isNotVisited(x: int, path: List[int]) -> int:

    size = len(path)
    for i in range(size):
        if (path[i] == x):
            return 0

    return 1


def findpaths(g: List[List[int]], src: int,
              dst: int, v: int) -> None:

    q = deque()

    path = []
    path.append(src)
    q.append(path.copy())

    while q:
        path = q.popleft()
        last = path[len(path) - 1]

        if (last == dst):
            printpath(path)
        for i in range(len(g[last])):
            if (isNotVisited(g[last][i], path)):
                newpath = path.copy()
                newpath.append(g[last][i])
                q.append(newpath)


# Driver code
if __name__ == "__main__":

    # Number of vertices
    v = 4
    g = [[] for _ in range(4)]

    # Construct a graph
    g[0].append(3)
    g[0].append(1)
    g[0].append(2)
    g[1].append(3)
    g[2].append(0)
    g[2].append(1)

    src = 2
    dst = 3
    print("path from src {} to dst {} are".format(
        src, dst))

    # Function for finding the paths
    findpaths(g, src, dst, v)

# This code is contributed by sanjeev2552
