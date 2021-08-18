# librarii care vor desena graful
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np

fisier = "matrice.txt"


def drawI(matriceDeIncidnta, n, m):
    g = nx.DiGraph()
    for i in range(0, n):
        a = 0
        b = 0
        for j in range(0, m):
            if matriceDeIncidnta[i][j] == -1:
                a = j+1
            if matriceDeIncidnta[i][j] == 1:
                b = j+1
            if matriceDeIncidnta[i][j] == 2:
                a, b = (j+1, j+1)
            g.add_edge(a, b)
        g.remove_node(0)
    nx.draw(g, with_labels=True)
    plt.draw()
    plt.show()
    return


def incident():
    print("citirea matricii de incidenta")
    print("dati numarul de varfuri :")
    x = int(input())
    matrice = np.zeros([x, x])
    n, m = (x, x)
    iese = "ca nu"
    i = 0
    while True:
        print("daca doriti sa finalizati tastati q")
        print("aveti la dispozitie", x, "varfuri. Muchia,", i+1, ":")
        print("iese din varful :")
        iese = input()
        if iese == "q":
            break
        if i == n:
            n += 1
            matrice = np.resize(matrice, (n, m))
            for j in range(0, m):
                matrice[i][j] = 0
        iese = int(iese)-1
        print("intra in varful :")
        intra = int(input())-1
        matrice[i][iese] = -1
        matrice[i][intra] = 1
        if iese == intra:
            matrice[i][intra] = 2
        i += 1
    return (matrice, n, m)


def drawA(matriceAdiacenta, n):
    g = nx.DiGraph()
    for i in range(0, n):
        a = i+1
        b = 0
        for j in range(0, n):
            if matriceAdiacenta[i][j] == 1:
                b = j+1
            g.add_edge(a, b)
        if g.has_node(0):
            g.remove_node(0)
    nx.draw(g, with_labels=True)
    plt.draw()
    plt.show()
    return


def adiacenta():
    print("citirea matricii de adiacenta")
    print("dati numarul de varfuri :")
    x = int(input())
    matrice = np.zeros([x, x])
    muchia = 1
    for i in range(0, x):
        y = "text fara un scop anume"
        while True:
            print("aveti la dispozitie", x, "varfuri. Muchia,", muchia, ":")
            print("daca doriti sa treceti la urmatorul varf tastati n")
            print("daca doriti sa finisati tastati q")
            print("muchia varfuli", i+1, "intra in :")
            y = input()
            if (y == "n" or y == "q"):
                break
            y = int(y)-1
            matrice[i][y] = 1
            muchia += 1
        if (y == "q"):
            break
    return (matrice, x)


def listaCareImiTrebuie():
    print("citirea liseti de  adiacenta")
    G = {}
    e = "dummy text"
    a = "dummy text"
    n = 1
    while True:
        print("pentru a termina tastati q")
        print("dati varful", n)
        e = input()
        if e == "q":
            break
        G[e] = []
        while True:
            print("pentru a trece la varful urmator tastati n")
            print("dati un element din lista de adiacenta pentru varful", e)
            a = input()
            if a == "n" or a == "q":
                break
            G[e].append(a)
        if a == "q":
            break
        n += 1
    return G


def drawList(G):
    g = nx.DiGraph()
    for i in [*G]:
        for j in G[i]:
            g.add_edge(i, j)
    if g.has_node(0):
        g.remove_node(0)
    nx.draw(g, with_labels=True)
    plt.draw()
    plt.show()
    return


def incidentToAdiaent(matrix, n, m):
    matrixA = np.zeros([m, m])
    for i in range(0, n):
        a = 0
        b = 0
        for j in range(0, m):
            if matrix[i][j] == -1:
                a = j
            if matrix[i][j] == 1:
                b = j
            elif matrix[i][j] == 2:
                a, b = (j, j)
        matrixA[a][b] = 1
    return (matrixA, m)


def listToIndecetn(g):
    m = 0
    n = 0
    for i in [*g]:
        if int(i) > m:
            m = int(i)
            for j in g[i]:
                if int(j) > m:
                    m = int(j)
    print(m)
    matrix = np.zeros([1, m])
    for i in [*g]:
        for j in g[i]:
            n += 1
            matrix = np.resize(matrix, (n, m))
            for z in range(0, m):
                matrix[n-1][z] = 0
            matrix[n-1][int(i)-1] = -1
            if i != j:
                matrix[n-1][int(j)-1] = 1
            else:
                matrix[n-1][int(j)-1] = 2
    return (matrix, n, m)


def adiacentToList(matrix, n):
    megaList = {}
    for i in range(0, n):
        megaList[i+1] = []
        for j in range(0, n):
            if matrix[i][j] == 1:
                megaList[i+1].append(j+1)
    return megaList


def main():
    inMemorie = "nimic"
    print("Lucrarea de laborator nr 1")
    print("in memorie aveti", inMemorie)
    print("Pentru a citi un graf ")
    print("intr-o matrice de incidenta tastati i")
    print("intr-o matrice de adiacenta tastati a")
    print("intr-o lista tastati l")
    option = input()
    if option == "i":
        matriceDeIncidnta, n, m = incident()
        print(matriceDeIncidnta)
        drawI(matriceDeIncidnta, n, m)
        inMemorie = "o matrice de incidenta"
    if option == "a":
        matriceAdiacenta, n = adiacenta()
        print(matriceAdiacenta)
        drawA(matriceAdiacenta, n)
        inMemorie = "o matrice de adiacenta"
    if option == "l":
        G = listaCareImiTrebuie()
        print(G)
        drawList(G)
        inMemorie = "o lista de adiacenta"
    while True:
        print("in memorie aveti", inMemorie)
        print('pentru a iesi din program dati q')
        print("puteti converti in matrice de incidenta (i) ; matrice de adiacenta (a) sau lista (l)")
        o = input()
        if o == "q":
            break
        elif o == "i":
            if inMemorie == "o matrice de incidenta":
                print("in memorie deja este", inMemorie)
                drawI(matriceDeIncidnta, n, m)
            elif inMemorie == "o lista de adiacenta":
                matriceDeIncidnta, n, m = listToIndecetn(G)
                print(matriceDeIncidnta)
                drawI(matriceDeIncidnta, n, m)
            elif inMemorie == "o matrice de adiacenta":
                G = adiacentToList(matriceAdiacenta, n)
                matriceDeIncidnta, n, m = listToIndecetn(G)
                print(matriceDeIncidnta)
                drawI(matriceDeIncidnta, n, m)
            inMemorie = "o matrice de incidenta"
        elif o == "a":
            if inMemorie == "o matrice de adiacenta":
                print("in memorie deja este", inMemorie)
                drawA(matriceAdiacenta, n)
            elif inMemorie == "o matrice de incidenta":
                matriceAdiacenta, n = incidentToAdiaent(
                    matriceDeIncidnta, n, m)
                print(matriceAdiacenta)
                drawA(matriceAdiacenta, n)
            elif inMemorie == "o lista de adiacenta":
                matriceDeIncidnta, n, m = listToIndecetn(G)
                matriceAdiacenta, n = incidentToAdiaent(
                    matriceDeIncidnta, n, m)
                print(matriceAdiacenta)
                drawA(matriceAdiacenta, n)
        elif o == "l":
            if inMemorie == "o lista de adiacenta":
                print("in memorie deja este", inMemorie)
                drawList(G)
            elif inMemorie == "o matrice de adiacenta":
                G = adiacentToList(matriceAdiacenta, n)
                print(G)
                drawList(G)
            elif inMemorie == "o matrice de incidenta":
                matriceAdiacenta, n = incidentToAdiaent(
                    matriceDeIncidnta, n, m)
                G = adiacentToList(matriceAdiacenta, n)
                print(G)
                drawList(G)
    return


main()
