from collections import defaultdict
import networkx as nx
import matplotlib.pyplot as plt
import json
import random
from prettytable import PrettyTable
import math
import numpy as np


class GRAF:
    def __init__(self):
        self.graf = defaultdict(list)

    def adaugaArc(self, initial, terminal):
        self.graf[initial].append(terminal)

    def citirea(self):
        self.graf = defaultdict(list)
        print("citirea listei de adiacenta")
        i = 1
        while True:
            print("pentru a termina tastati ( q )")
            print("aveti muchia", i, "cu extremitatea initiala")
            initial = input()
            if initial == "q":
                breakll
            print("si extremitatea terminala")
            terminal = input()
            if terminal == "q":
                break
            # print("ponderea este")
            # ponderea = input()
            # if ponderea == "q":
            #     break
            self.adaugaArc(int(initial), int(terminal))
            i += 1
        self.curatare()

    def curatare(self):
        for v in [*self.graf]:
            self.graf[v].sort()
            self.graf[v] = list(dict(self.graf[v]).items())
            for c in self.graf[v]:
                if c not in [*self.graf]:
                    self.graf[c] = []
        self.graf = dict(sorted(self.graf.items()))

    def afiseazaLista(self):
        print("lista de adiacenta")
        for k in [*self.graf]:
            print(k, "-", end=" ")
            for v in self.graf[k]:
                print(v, end=", ")
            print("0")

    def salveaza(self):
        print("denumirea fisierului")
        f = input()
        json.dump(self.graf, open(f+".json", 'w'))

    def impota(self):
        print("denumirea fisierului")
        f = input()
        self.graf = json.load(open(f+".json"))
        # self.graf = {int(k): [int(i) for i in v] for k, v in self.graf.items()}
        temp = defaultdict(list)
        for key in [*self.graf]:
            for pereche in self.graf[key]:
                temp[int(key)].append(tuple(pereche))
        self.graf = temp
        self.curatare()

    def deseneazaGraful(self):
        g = nx.DiGraph()
        for i in [*self.graf]:
            for j in self.graf[i]:
                g.add_edge(i, j, weightprint(intrari)=1)
        pos = nx.circular_layout(g)
        edge_labels = {(u, v): d['weight'] for u, v, d in g.edges(data=True)}
        nx.draw(g, pos, with_labels=True, node_size=1700, font_size=40)
        nx.draw_networkx_edge_labels(
            g, pos, edge_labels=edge_labels, font_size=20)
        plt.savefig('output.png')
        plt.show()

    def removeVertex(self):
        print(self.graf)
        print("varful pe care doriti sa il stergeti :")
        v = int(input())
        for i in [*self.graf]:
            self.graf[i] = [item for item in self.graf[i] if item != v]
        self.graf.pop(v, None)

    def removeEdge(self):
        print(self.graf)
        print("varful din care iese muchia :")
        e = int(input())
        print("varful in care intra muchia :")
        i = int(input())
        self.graf[e] = [item for item in self.graf[e] if item != i]

    def addEdge(self):
        print(self.graf)
        print("puteti adauga orice muchie (chiar cu varfuri noi)")
        print("varful din care iese muchia :")
        e = int(input())
        print("varful in care intra muchia :")
        i = int(input())
        print("ponderea :")
        p = int(input())
        self.adaugaArc(e, i)

    def edit(self):
        print("puteti :\nsterge un varf - v\nsterge o muchie - m\nadauga o muchie - a")
        o = input()
        if o == "v":
            self.removeVertex()
        elif o == "m":
            self.removeEdge()
        elif o == "a":
            self.addEdge()
        self.curatare()

    def START(self):
        print("program la msp")
        while True:
            print("( q ) - pentru a iesi")
            print(
                "( c ) - pentru a citi din memorie lista de adiacenta (in caz ca a fost salvata precedent )")
            print("( s ) - pentru a scrie in memorie lista de adiacenta")
            print("")
            print("( 1 ) - pentru a citi de la tastatura lista de adiacenta")
            print("( 2 ) - pentru a afisa lista")
            print("( 3 ) - pentru a afisa forma grafica")
            print("( 8 ) - EDITARE")
            print("( 9 ) - pentru a genera un graf intamplator")
            o = input()
            if o == "q":
                break
            elif o == "c":
                self.impota()
                self.determinaFordMinim()
                self.determinaBellmanKalabaMinim()
                self.determinaFordMaxim()
                self.determinaBellmanKalabaMaxim()
                self.deseneazaGraful()
                # self.determinareaCatalinHimselfDrumuluiMaxim()
            elif o == "1":
                self.citirea()
            elif o == "s":
                self.salveaza()
            elif o == "2":
                self.afiseazaLista()
            elif o == "3":
                self.deseneazaGraful()
            elif o == "4":
                self.determinaFordMinim()
            elif o == "5":
                self.determinaBellmanKalabaMinim()
            elif o == "6":
                self.determinaFordMaxim()
            elif o == "7":
                self.determinaBellmanKalabaMaxim()
            elif o == "8":
                self.edit()
            elif o == "9":
                self.graf = defaultdict(list)
                for i in range(0, random.randint(7, 15)):
                    self.adaugaArc(random.randint(1, 7), random.randint(
                        1, 7), random.randint(1, 10))
                self.curatare()
                self.afiseazaLista()
            elif o == "h":
                print("graf:", self.graf)


graf = GRAF()
graf.START()
