# librarii care vor desena graful
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import json
from prettytable import PrettyTable

fisier = "secret.txt"


def readIncidenceMatrix():
    print("citirea matricii de incidenta")
    print("dati numarul de varfuri :")
    x = int(input())
    matrice = np.zeros([x, x])
    n, m = (x, x)
    iese = "ca nu"
    i = 0
    while True:
        print("daca doriti sa finalizati tastati q")
        print("aveti la dispozitie", x,
              "varfuri ( !!!nu esiti din aceasta limita, pe urma veti avea poisbilitatea de a modifica ceva ). \nMuchia,", i+1, ":")
        print("extrema initiala :")
        iese = input()
        if iese == "q":
            break
        if i == n:
            n += 1
            matrice = np.resize(matrice, (n, m))
            for j in range(0, m):
                matrice[i][j] = 0
        iese = int(iese)-1
        print("extrema terminala :")
        intra = int(input())-1
        matrice[i][iese] = -1
        matrice[i][intra] = 1
        if iese == intra:
            matrice[i][intra] = 2
        i += 1
    return (matrice, n, m)


def readAdjacencyMatrix():
    print("citirea matricii de adiacenta")
    print("dati numarul de varfuri :")
    x = int(input())
    matrice = np.zeros([x, x])
    muchia = 1
    for i in range(0, x):
        y = "text fara un scop anume"
        while True:
            print("\naveti la dispozitie", x,
                  "varfuri ( !!!nu esiti din aceasta limita, pe urma veti avea poisbilitatea de a modifica ceva )\n. Muchia ,", muchia, ":")
            print("daca doriti sa treceti la urmatorul varf tastati n")
            print("daca doriti sa finisati tastati q")
            print("arcul cu extremitatea initiala",
                  i+1, "are extremitatea terminala :")
            y = input()
            if (y == "n" or y == "q"):
                break
            y = int(y)-1
            matrice[i][y] = 1
            muchia += 1
        if (y == "q"):
            break
    return (matrice, x)


def readAdjacencyList():
    print("citirea liseti de  adiacenta")
    G = {}
    e = "dummy text"
    a = "dummy text"
    n = 1
    while True:
        print("pentru a termina tastati q")
        print("dati varful initial ( poate fi orice numar pozitiv) se recomanda sa fie", n, " :")
        e = input()
        if e == "q":
            break
        # initiez o lista goala
        e = int(e)
        G[e] = []
        while True:
            print("pentru a trece la varful urmator tastati n")
            print("dati un element din lista de adiacenta pentru varful", e)
            a = input()
            if a == "n" or a == "q":
                break
            G[e].append(int(a))
        # este specific pentru python dar a exista si aici jos :/
        if a == "q":
            break
        n += 1
    return G


# cu ajutorul librariei importate va desena grahul ( foarte interesant )
def drawList(G):
    g = nx.DiGraph()
    for i in [*G]:
        for j in G[i]:
            g.add_edge(i, j)
    # deoarece varful 0 este adugat automat si conectat cu toate celelalte varfuri
    if g.has_node(0):
        g.remove_node(0)
    nx.draw(g, with_labels=True)
    plt.draw()
    plt.show()
    return


def incidenceToAdjacency(matrix, n, m):
    # deoarece matricea adiacenta este una patrata
    matrixA = np.zeros([m, m])
    for i in range(0, n):
        for j in range(0, m):
            if matrix[i][j] == -1:
                # deoarece am nevoie sa pastrez randul pe care va trebui sa pun 1
                a = j
            if matrix[i][j] == 1:
                # ca sa aflu in ce coloana sa pun acest 1
                b = j
            # deoarece daca avem o bucla aceasta nu va fi identificata
            elif matrix[i][j] == 2:
                a, b = (j, j)
        matrixA[a][b] = 1
    return (matrixA, m)


def listToIncidence(g):
    # deoarece mai jos am nevoie de aceste variabile initializate
    m = 0
    n = 0
    for i in [*g]:
        if int(i) > m:
            m = int(i)
            for j in g[i]:
                if int(j) > m:
                    m = int(j)
    # deoarece aceasta matrice poate avea oricare numar de linii
    matrix = np.zeros([1, m])
    for i in [*g]:
        for j in g[i]:
            # redimensionez aceasta matrice de fiecare data
            # de notat ca n la inceput este 0 iar prima redimensionare nu are nici un efect
            n += 1
            matrix = np.resize(matrix, (n, m))
            # am nevoie ca toate elementele de pe rand la inceput sa fie 0
            for z in range(0, m):
                matrix[n-1][z] = 0
            # n-1 - linia curenta
            # i-1 - este varful din care iese muchia considerand ca matricea in memorie se incepe de la 0
            matrix[n-1][int(i)-1] = -1
            if i != j:
                matrix[n-1][int(j)-1] = 1
            else:
                matrix[n-1][int(j)-1] = 2
    return (matrix, n, m)


def adjacencyToList(matrix, n):
    # initiez cutia chestia asat grozava
    megaList = {}
    for i in range(0, n):
        # initiez o lista
        megaList[i+1] = []
        for j in range(0, n):
            if matrix[i][j] == 1:
                megaList[i+1].append(j+1)
    return megaList


def removeVertex(g):
    print(g)
    print("varful pe care doriti sa il stergeti :")
    v = int(input())
    for i in [*g]:
        if v in g[i]:
            g[i].remove(v)
    g.pop(v, None)
    return g


def removeEdge(g):
    print(g)
    print("varful din care iese muchia :")
    e = int(input())
    print("varful in care intra muchia :")
    i = int(input())
    if i in g[e]:
        g[e].remove(i)
    else:
        print("\nnu exista asa muchie\n")
    return g


def addEdge(g):
    print(g)
    print("puteti adauga orice muchie (chiar cu varfuri noi)")
    print("varful din care iese muchia :")
    e = int(input())
    print("varful in care intra muchia :")
    i = int(input())
    if e in g:
        print("varful va fi adaugat")
    else:
        g[e] = []
    g[e].append(i)
    return g


def edit(g):
    print("puteti :\nsterge un varf - v\nsterge o muchie - m\nadauga o muchie - a")
    o = input()
    if o == "v":
        g = removeVertex(g)
    elif o == "m":
        g = removeEdge(g)
    elif o == "a":
        g = addEdge(g)
    return g


def printM(matrix, n, m, o):
    x = PrettyTable()
    t = []
    for i in range(0, m+1):
        if i == 0:
            t.append(' ')
        else:
            t.append("X"+str(i))
    if o == 2:
        t.append("P")
    x.field_names = t
    for i in range(0, n):
        t = []
        if o == 0:
            t.append("U"+str(i+1))
        else:
            t.append("X"+str(i+1))
        for j in range(0, m):
            t.append(int(matrix[i][j]))
        if o == 2:
            t.append(int(matrix[i][m]))
        x.add_row(t)
    if o == 0:
        print(x.get_string(title="Matricea de incidenta"))
    if o == 1:
        print(x.get_string(title="Matricea de adiacenta"))
    if o == 2:
        print(x.get_string(title="Matricea drumurilor"))
    return


def pathMatrix(matrix, n):
    pMatrix = np.zeros([n, n+1])
    for i in range(0, n):
        for j in range(0, n):
            pMatrix[i][j] = matrix[i][j]
    for i in range(0, n):
        for j in range(0, n):
            if matrix[i][j] == 1:
                for y in range(0, n):
                    if matrix[i][y] or matrix[j][y]:
                        pMatrix[i][y] = 1
    for i in range(0, n):
        for j in range(0, n):
            if pMatrix[i][j] == 1:
                pMatrix[i][n] += 1

    # adiacenta
    printM(matrix, n, n, 1)
    # drumuri
    printM(pMatrix, n, n, 2)
    return


def main():

    print("Lucrarea de laborator nr 1\nla Matematici speciale ")
    print("Daca veti dori sa iesiti din program scrieti - iSurrender sau qqq\ndaca veti uita tastati ctrl + c sau restartati pc-ul")
    G = {}
    print("programul dat opereaza cu grafuri le ptueti citi; printa, edita, chiar si sa le vedeti in forma grafica \n( pentru ca nu am imaginatie sa mi le imaginez )")
    while True:
        print("\n\n")
        print("citirea din fisier ( r ) ; scrierea in fisier ( w )")
        print("citire matrice de incidenta tastati ( i ) ; printare ( ii )")
        print("matrice de adiacenta ( a ) ; printare ( aa )")
        print("lista de adiacenta ( l ) ; printare ( ll )")
        print("pentru a edita graful ( e )")
        print("bonus ( b )")
        print("( f )")
        print("( p ) matricea drumurilor")
        o = input()

        if o == "w":
            haltura = np.zeros([m, m])
            for k in [*G]:
                haltura[k-1][0] = k
                j = 1
                for i in G[k]:
                    haltura[k-1][j] = i
                    j += 1
            np.savetxt("lista.txt", haltura, fmt="%d ")
            json.dump(G, open(fisier, 'w'))
        if o == "r":
            G = json.load(open(fisier))
            # convertirea in celelalte tipuri de matrice
            incidenceMatrix, n, m = listToIncidence(G)
            adjacencyMatrix, m = incidenceToAdjacency(incidenceMatrix, n, m)
            # pentru ca , cand  cheia se citeste din fisier automat este caracter
            G = adjacencyToList(adjacencyMatrix, m)
            # convertirea in celelalte tipuri de matrice
        if o == "i":
            incidenceMatrix, n, m = readIncidenceMatrix()
            # convertirea in celelalte tipuri de matrice
            adjacencyMatrix, m = incidenceToAdjacency(incidenceMatrix, n, m)
            G = adjacencyToList(adjacencyMatrix, m)
            # convertirea in celelalte tipuri de matrice
            print(incidenceMatrix)
            drawList(G)
        if o == "a":
            adjacencyMatrix, m = readAdjacencyMatrix()
            # convertirea in celelalte tipuri de matrice
            G = adjacencyToList(adjacencyMatrix, m)
            incidenceMatrix, n, m = listToIncidence(G)
            # convertirea in celelalte tipuri de matrice
            print(adjacencyMatrix)
            drawList(G)
        if o == "l":
            G = readAdjacencyList()
            # convertirea in celelalte tipuri de matrice
            incidenceMatrix, n, m = listToIncidence(G)
            adjacencyMatrix, m = incidenceToAdjacency(incidenceMatrix, n, m)
            # convertirea in celelalte tipuri de matrice
            print(G)
            drawList(G)
        if o == "ii":
            printM(incidenceMatrix, n, m, 0)
        if o == "aa":
            printM(adjacencyMatrix, m, m, 1)
        if o == "ll":
            for k in [*G]:
                print(k, '-', end=" ")
                for i in G[k]:
                    print(i, end=" ")
                print(0)
        if o == "e":
            G = edit(G)
            # convertirea in celelalte tipuri de matrice
            incidenceMatrix, n, m = listToIncidence(G)
            adjacencyMatrix, m = incidenceToAdjacency(incidenceMatrix, n, m)
            # convertirea in celelalte tipuri de matrice
        if o == "b":
            drawList(G)
        if o == "f":
            print(incidenceMatrix)
            print(adjacencyMatrix)
            print(G)
        if o == "p":
            pathMatrix(adjacencyMatrix, m)
        if o == "iSurrender" or o == "qqq":
            break
    return


#  apeleaza functia principala
main()
