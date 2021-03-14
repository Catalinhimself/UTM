from collections import defaultdict
import networkx as nx
import matplotlib.pyplot as plt
import json

# import subprocess


class GRAF:
    def __init__(self):
        self.graf = defaultdict(list)
        self.c = defaultdict(int)
        self.f = defaultdict(list)
        self.sursa = 0
        self.destinatia = 0

    def citirea(self):
        print("citirea listei de adiacenta")
        self.graf = defaultdict(list)
        i = 1
        while True:
            print("pentru a termina tastati ( q )")
            print("aveti muchia", i, "cu prima extremitate")
            extr1 = input()
            if extr1 == "q":
                break
            print("si a doua extremitate")
            extr2 = input()
            if extr2 == "q":
                break
            self.graf[int(extr1)].append(int(extr2))
            print("capacitatea arcului", extr1, "->", extr2, "este:")
            self.c[(int(extr1), int(extr2))] = int(input())
            i += 1
        self.curatare()

    def curatare(self):
        # self.graf = dict(sorted(self.graf.items()))
        for v in [*self.graf]:
            for c in self.graf[v]:
                if c not in [*self.graf]:
                    self.graf[c] = []
            self.graf[v].sort()
            self.graf[v] = list(dict.fromkeys(self.graf[v]))
        self.graf = dict(sorted(self.graf.items()))

    def afiseazaLista(self):
        print("lista de adiacenta")
        for k in [*self.graf]:
            print(k, "-", end=" ")
            for v in self.graf[k]:
                print(str(v)+"(" + str(self.c[(k, v)]) + "), ", end="")
            print("0")

    def parcugereaAdancime(self, start):
        for k in [*self.graf]:
            for v in self.graf[k]:
                if not v in self.graf:
                    self.graf[v] = []
        vizitat = {}
        for k in [*self.graf]:
            vizitat[k] = False
        stiva = []
        parcurgerea = []
        parcurgerea.append(start)
        stiva.append(start)
        vizitat[start] = True
        while stiva:
            aici = stiva[len(stiva)-1]
            if not vizitat[aici]:
                parcurgerea.append(aici)
                vizitat[aici] = True
            gata = 0
            for varf in self.graf[aici]:
                if not vizitat[varf]:
                    stiva.append(varf)
                    break
                else:
                    gata += 1
            if not self.graf[aici]:
                stiva.pop()
            elif gata == len(self.graf[aici]):
                stiva.pop()
        capet = False
        for hz in [*vizitat]:
            if not vizitat[hz]:
                capet = True
        if capet:
            print("incepand cu varful", start,
                  "graful nu poate fi parcurs in adancime")
            print(vizitat)
        else:
            print("parcurgerea in adancime incepand din", start)
            for v in parcurgerea:
                print(v, end=" ")
            print()

    def salveaza(self):
        print("denumirea fisierului")
        f = input()
        json.dump(self.graf, open(f+".json", 'w'))

        temp = defaultdict(list)
        for k in [*self.c]:
            temp[k[0]].append([k[1], self.c[k]])
        json.dump(temp, open(f+".c.json", 'w'))

    def impota(self, f=""):
        print("denumirea fisierului")
        if f == "":
            f = input()
        self.graf = json.load(open(f+".json"))
        # self.graf = {int(k): [int(i) for i in v] for k, v in self.graf.items()}
        temp = defaultdict(list)
        for key in [*self.graf]:
            for v in self.graf[key]:
                temp[int(key)].append(v)
        self.graf = temp
        self.curatare()

        temp = json.load(open(f+".c.json"))
        for k in [*temp]:
            for l in temp[k]:
                self.c[(int(k), l[0])] = l[1]

    def deseneazaGraful(self):
        g = nx.DiGraph()
        for i in [*self.graf]:
            text = ""
            for j in self.graf[i]:
                text = str(self.c[(i, j)])
                for e in self.f[(i, j)]:
                    text = text+"("+str(e)+")"
                g.add_edge(i, j, weight=text)
        pos = nx.circular_layout(g)
        edge_labels = {(u, v): d['weight'] for u, v, d in g.edges(data=True)}
        nx.draw(g, pos, with_labels=True, node_size=1700, font_size=40)
        nx.draw_networkx_edge_labels(
            g, pos, edge_labels=edge_labels, font_size=20)
        plt.savefig('output.png')
        plt.show()
        # subprocess.run(["google-chrome", "output.png"])

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

    def determinare_a_b(self):
        intrari = defaultdict(bool)
        for k in [*self.graf]:
            intrari[k] = False
        for k in [*self.graf]:
            if not len(self.graf[k]):
                self.destinatia = k
            for v in self.graf[k]:
                intrari[v] = True
        for v in [*intrari]:
            if not intrari[v]:
                self.sursa = v

    def F_F(self):
        print("ff you")
        for k in [*self.c]:
            self.f[k].append(0)
            print(self.f[k])

        visited = set()
        self.DFS(self.sursa, visited)

    def DFS(self, v, visited):

        visited.add(v)
        print(v, end=' ')

        for neighbour in self.graf[v]:
            if neighbour not in visited:
                self.DFS(neighbour, visited)

    def cat(self):
        print("cat")

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
            print("( 4 ) - FORD-FULKERSON")
            print("( 8 ) - EDITARE")
            print("( 9 ) - pentru a genera un graf intamplator")
            o = input()
            if o == "q":
                break
            elif o == "c":
                self.impota()
                self.determinare_a_b()
                print("sursa", self.sursa, "destinatia", self.destinatia)
                # self.deseneazaGraful()
            elif o == "1":
                self.citirea()
                self.determinare_a_b()
            elif o == "s":
                self.salveaza()
            elif o == "2":
                self.afiseazaLista()
            elif o == "3":
                self.deseneazaGraful()
            elif o == "4":
                self.F_F()
            elif o == "8":
                self.edit()
            elif o == "h":
                print("graf:", self.graf)
                print("capacitati:", self.c)


graf = GRAF()

graf.impota("1")
graf.afiseazaLista()
graf.determinare_a_b()
graf.F_F()
graf.cat()
graf.deseneazaGraful()

# graf.START()
