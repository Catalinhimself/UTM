# librarii care vor desena graful
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import json

fisier = "lista.txt"


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
    while True:
        print("puteti salva sau importa un graf cu comenzile w si r")
        print("Pentru a citi un graf ")
        print("intr-o matrice de incidenta tastati i")
        print("intr-o matrice de adiacenta tastati a")
        print("intr-o lista tastati l")
        print("s pentru a sari peste")
        option = input()
        if option == "w":
            json.dump(G, open(fisier, 'w'))
        if option == "r":
            G = json.load(open(fisier))
        if option == "i":
            matriceDeIncidnta, n, m = incident()
            # convertirea in celelalte tipuri de matrice
            matriceAdiacenta, m = incidentToAdiaent(matriceDeIncidnta, n, m)
            G = adiacentToList(matriceAdiacenta, m)
            # convertirea in celelalte tipuri de matrice
            print(matriceDeIncidnta)
            drawList(G)
            inMemorie = "o matrice de incidenta"
        if option == "a":
            matriceAdiacenta, m = adiacenta()
            # convertirea in celelalte tipuri de matrice
            G = adiacentToList(matriceAdiacenta, m)
            matriceDeIncidnta, n, m = listToIndecetn(G)
            # convertirea in celelalte tipuri de matrice
            print(matriceAdiacenta)
            drawList(G)
            inMemorie = "o matrice de adiacenta"
        if option == "l":
            G = listaCareImiTrebuie()
            # convertirea in celelalte tipuri de matrice
            matriceDeIncidnta, n, m = listToIndecetn(G)
            matriceAdiacenta, m = incidentToAdiaent(matriceDeIncidnta, n, m)
            # convertirea in celelalte tipuri de matrice
            print(G)
            drawList(G)
            inMemorie = "o lista de adiacenta"

        # whileul a fost ridicat mai sus de aici

        print("in memorie aveti", inMemorie)
        print('pentru a iesi din program dati q')
        print("puteti converti in matrice de incidenta ( i ) ; matrice de adiacenta ( a ) sau lista ( l )")
        print("daca doriti sa vedeti forma grafica a grafului tastati g")
        o = input()
        if o == "q":
            break
        elif o == "i":
            print(matriceDeIncidnta)
            inMemorie = "o matrice de incidenta"
        elif o == "a":
            print(matriceAdiacenta)
            inMemorie = "o matrice de adiacenta"
        elif o == "l":
            print(G)
            inMemorie = "o lista de adiacenta"
        elif o == "g":
            drawList(G)
    return


main()
# 270 linii
