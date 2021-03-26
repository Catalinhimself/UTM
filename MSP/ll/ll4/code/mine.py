from collections import defaultdict
import json
import random
try:
    import networkx as nx
    import matplotlib.pyplot as plt
    visual_libs = True
except ImportError:
    visual_libs = False
try:
    import colorama
    from colorama import Fore, Back, Style
    colorama.init(autoreset=True)
    color = True
except ImportError:
    color = False


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
        print(f'{Back.YELLOW+Fore.BLACK if color else ""}lista de adiacenta')
        for k in [*self.graf]:
            print(k, "|", end=" ")
            for v in self.graf[k]:
                print(v, end="_ ")
            print("0")

    def graf_de_acoperire(self, start):
        vizitat = set()
        # pasul 1 | fa1 si fa2 vide
        FA1 = []
        FA2 = []
        # de la pasul 10
        while [*self.graf] != list(vizitat):
            # pasul 2 alegem varful initial
            if start not in vizitat:
                FA1.append(start)
            else:
                for v in [*self.graf]:
                    if v not in vizitat:
                        FA1.append(v)
                        break
            # pasul 8 => 10 daca fa1 este vid
            while FA1:
                # pasul 3 => 8 daca fa1 este vid| p primul element extras din fa1
                while FA1:
                    p = FA1.pop(0)
                    vizitat.add(p)
                    # pasul 4 | adaugam fii nevizitati ai lui p in fa2
                    if self.graf[p]:
                        for v in self.graf[p]:
                            if v not in vizitat:
                                FA2.append(v)
                        # pasul 5 | eliminam muchiiile legate intre ele din fa2
                        for a in FA2:
                            for b in FA2:
                                if b in self.graf[a]:
                                    self.graf[a].remove(b)
                        # pasul 6 | eliminam toate toate-1 muchii care laga fa1 si fa2
                        for a in FA2:
                            for b in FA1:
                                if b in self.graf[a]:
                                    self.graf[a].remove(b)
                                if a in self.graf[b]:
                                    self.graf[b].remove(a)
                        # pasul 7 => continuarea ciclului
            # pasul 8
                temp = FA1
                FA1 = FA2
                FA2 = temp
                # pasul 9 => repetam 3 - 8
        # pasul 10 => 2 daca nu avem toate varfurile vizitate

    def salveaza(self):
        f = input("dati denumirea fisierului ( fara extensie ): ")
        json.dump(self.graf, open(f+".json", 'w'))
        print(f'{Back.GREEN+Fore.BLACK if color else ""}fisierul salvat cu succes')

    def impota(self):
        f = input("dati denumirea fisierului ( fara extensie ): ")
        self.graf = json.load(open(f+".json"))
        self.graf = {int(k): [int(i) for i in v] for k, v in self.graf.items()}
        print(f'{Back.GREEN+Fore.BLACK if color else ""}fisierul importa cu succes')

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
            if visual_libs:
                print("( 3 ) - pentru a afisa forma grafica")
            print(
                f'( 4 ) - pentru a efectua genera graful de  {Fore.BLUE if color else ""}acoperire')
            print("( r | random )")
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
                if visual_libs:
                    self.deseneazaGraful()
            elif o == "4":
                v = int(input("radacina grafuli de acoperire este: "))
                if v not in self.graf.keys():
                    print(
                        f'{Fore.BLACK+Back.RED if color else ""}radacina invalida, se va lua radacina {list(self.graf.keys()).pop(0)}')
                    v = list(self.graf.keys()).pop(0)
                self.graf_de_acoperire(v)
                print(
                    f'{Back.GREEN+Fore.BLACK if color else ""}Graful de acoperire generat cu succes')

            elif o == "random" or o == "r":
                self.graf = defaultdict(list)
                maxX = random.randint(20, 100)
                U = random.randint(maxX*2, maxX*10)
                for i in range(U):
                    a = random.randint(0, maxX)
                    b = random.randint(0, maxX)
                    self.adaugaArc(a, b)
                    self.adaugaArc(b, a)
                self.curatare()


graf = GRAF()
graf.START()
