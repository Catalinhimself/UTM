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
            print("aveti muchia", i, "cu prima extremitate")
            extr1 = input()
            if extr1 == "q":
                break
            print("si a doua extremitate")
            extr2 = input()
            if extr2 == "q":
                break
            self.adaugaArc(int(extr1), int(extr2))
            self.adaugaArc(int(extr2), int(extr1))
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

    def graf_de_acoperire(self, start):
        vizitat = set()
        # pasul 1

        FA1 = []
        FA2 = []
        # de la pasul 10
        while [*self.graf] != list(vizitat):
            # pasul 2
            if start not in vizitat:
                FA1.append(start)
            else:
                for v in [*self.graf]:
                    if v not in vizitat:
                        FA1.append(v)
            while FA1:
                # pasul 3
                while FA1:
                    p = FA1.pop(0)
                    vizitat.add(p)
                    # pasul 4
                    if self.graf[p]:
                        for v in self.graf[p]:
                            if v not in vizitat:
                                FA2.append(v)
                        # pasul 5
                        for a in FA2:
                            for b in FA2:
                                if b in self.graf[a]:
                                    self.graf[a].remove(b)

                        # pasul 6
                        nr = 0
                        for a in FA2:
                            for b in FA1:
                                if b in self.graf[a]:
                                    nr += 1
                        for a in FA2:
                            for b in FA1:
                                if nr:
                                    if b in self.graf[a]:
                                        self.graf[a].remove(b)
                                        nr -= 1
                                    if a in self.graf[b]:
                                        self.graf[b].remove(a)
                                        nr -= 1
                        # pasul 7 => continuarea ciclului
                    # pasul 8
                    temp = FA1
                    FA1 = FA2
                    FA2 = temp
                    # pasul 9 => repetam 3 - 8
                # pasul 10 se trece la 2 daca nu toate v au fost vizitate

    def salveaza(self):
        json.dump(self.graf, open("a.json", 'w'))

    def impota(self):
        self.graf = json.load(open("a.json"))
        self.graf = {int(k): [int(i) for i in v] for k, v in self.graf.items()}

    def deseneazaGraful(self):
        g = nx.DiGraph()
        for i in [*self.graf]:
            for j in self.graf[i]:
                g.add_edge(i, j)
        nx.draw(g, with_labels=True, node_size=1700,
                font_size=40, edge_color='r', width=5)
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
            print("( 4 ) - pentru a efectua genera graful de acoperire")
            print("( 9 ) - pentru a adauga varfurile predefinite ( de profesoara )")
            o = input()
            if o == "q":
                break
            elif o == "c":
                self.impota()
                print("importarea efectuata cu succes")
            elif o == "1":
                self.citirea()
            elif o == "s":
                self.salveaza()
                print("salvarea efectuata cu succes")
            elif o == "2":
                self.afiseazaLista()
            elif o == "3":
                self.deseneazaGraful()
            elif o == "4":
                print(self.graf)
                print("dati varful pentru care doriti sa efectuati cautarea in latime")
                v = input()
                self.graf_de_acoperire(int(v))
            elif o == "9":
                self.adaugaArc(1, 2)
                self.adaugaArc(1, 3)
                self.adaugaArc(2, 4)
                self.adaugaArc(2, 5)
                self.adaugaArc(3, 6)
                self.afiseazaLista()
                self.graf_de_acoperire(1)
                self.parcugereaAdancime(1)
                self.deseneazaGraful()


graf = GRAF()
graf.START()
