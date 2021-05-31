from collections import defaultdict
import networkx as nx
import matplotlib.pyplot as plt
import json

# pentru coada si stiva voi folosi lista pop append si voi sterge elementu 1 cand am nevoie de el


class GRAF:
    def __init__(self):
        self.graf = defaultdict(list)

    def adaugaArc(self, initial, terminal):
        self.graf[initial].append(terminal)

    def citirea(self):
        # <- pote fi interpretat si ca comentariu
        print("citirea listei de adiacenta")
        self.graf = defaultdict(list)
        i = 1
        while True:
            print("pentru a termina tastati ( q )")
            print("aveti muchia", i, "cu extremitatea initiala")
            initial = input()
            if initial == "q":
                break
            print("si extremitatea terminala")
            terminal = input()
            if terminal == "q":
                break
            self.adaugaArc(int(initial), int(terminal))
            i += 1
        self.curatare()

    def curatare(self):
        self.graf = dict(sorted(self.graf.items()))
        for v in [*self.graf]:
            self.graf[v].sort()
            self.graf[v] = list(dict.fromkeys(self.graf[v]))

    def afiseazaLista(self):
        print("lista de adiacenta")
        for k in [*self.graf]:
            print(k, "-", end=" ")
            for v in self.graf[k]:
                print(v, ",", end="")
            print("0")

    def parcurgereaInLatime(self, start):
        for k in [*self.graf]:
            for v in self.graf[k]:
                if not v in self.graf:
                    self.graf[v] = []
        vizitat = {}
        for k in [*self.graf]:
            vizitat[k] = False
        coada = []
        parcurgerea = []
        coada.append(start)
        vizitat[start] = True
        while coada:
            aici = coada.pop(0)
            parcurgerea.append(aici)
            for varf in self.graf[aici]:
                if not vizitat[varf]:
                    coada.append(varf)
                    vizitat[varf] = True
        capet = False
        for hz in [*vizitat]:
            if not vizitat[hz]:
                capet = True
        if capet:
            print("incepand cu varful", start,
                  "graful nu poate fi parcurs in latime")
            print(vizitat)
        else:
            print("parcurgerea in latime incepand din", start)
            for v in parcurgerea:
                print(v, end=" ")
            print()

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
        json.dump(self.graf, open("a.txt", 'w'))

    def impota(self):
        self.graf = json.load(open("a.txt"))
        self.graf = {int(k): [int(i) for i in v] for k, v in self.graf.items()}

    def deseneazaGraful(self):
        g = nx.DiGraph()
        for i in [*self.graf]:
            for j in self.graf[i]:
                g.add_edge(i, j)
        nx.draw(g, with_labels=True)
        plt.draw()
        plt.show()

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
            print("( 4 ) - pentru a efectua cautarea in lungime")
            print("( 5 ) - pentru a efectua cautarea in adancime")
            print("( 9 ) - pentru a adauga varfurile predefinite ( de profesoara )")
            o = input()
            if o == "q":
                break
            elif o == "c":
                self.impota()
            elif o == "1":
                self.citirea()
            elif o == "s":
                self.salveaza()
            elif o == "2":
                self.afiseazaLista()
            elif o == "3":
                self.deseneazaGraful()
            elif o == "4":
                print(self.graf)
                print("dati varful pentru care doriti sa efectuati cautarea in latime")
                v = input()
                self.parcurgereaInLatime(int(v))
            elif o == "5":
                print(self.graf)
                print("dati varful pentru care doriti sa efectuati cautarea in adancime")
                v = input()
                self.parcugereaAdancime(int(v))
            elif o == "9":
                self.adaugaArc(1, 2)
                self.adaugaArc(1, 3)
                self.adaugaArc(2, 4)
                self.adaugaArc(2, 5)
                self.adaugaArc(3, 6)
                self.afiseazaLista()
                self.parcurgereaInLatime(1)
                self.parcugereaAdancime(1)
                self.deseneazaGraful()


graf = GRAF()
graf.START()
