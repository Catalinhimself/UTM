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
        self.fMax = 0
        self.L = []
        self.E = []
        self.A = []
        self.X = []
        self.XA = []
        self.WA = []

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
        self.c = defaultdict(int)
        self.f = defaultdict(list)
        self.sursa = 0
        self.destinatia = 0
        self.fMax = 0
        self.L = []
        self.E = []
        self.A = []
        self.X = []
        self.XA = []
        self.WA = []
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
            g, pos, edge_labels=edge_labels, font_size=17)
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
        self.graf[e] = i
        print("capacitatea:")
        c = int(input())
        self.c[(e, i)] = c

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

    def Ford_Fulkerson_pain(self):

        F_max = 0
        s = self.sursa
        t = self.destinatia
        m = defaultdict(list)
        rg = defaultdict(list)
        c = self.c
        g = self.graf

        f = self.f
        for k in [*c]:
            f[k].append(0)

        # cod ciotkii) =>
        z = 1
        A = []
        while True:
            l = [s]
            blacklist = set()
            while l[len(l)-1] != t:
                remove = True
                for v in g[l[len(l)-1]]:
                    # print(l)
                    if v not in l and v not in blacklist:
                        if sum(f[(l[len(l)-1], v)]) != c[(l[len(l)-1], v)]:
                            # print("inainte")
                            m[v].append(("+", l[len(l)-1]))
                            rg[v].append(l[len(l)-1])
                            l.append(v)
                            remove = False
                            break
                for v in rg[l[len(l)-1]]:
                    if v not in l and v not in blacklist:
                        if sum(f[v, (l[len(l)-1])]):
                            # print("inapoi")
                            m[v].append(("-", l[len(l)-1]))
                            l.append(v)
                            remove = False
                            break
                if remove:
                    blacklist.add(l[len(l)-1])
                    if m[l[len(l)-1]]:
                        m[l[len(l)-1]].pop()
                    l.pop()
                    if s in blacklist:
                        A = blacklist
                        break
                # print(blacklist)
            if A:
                break
            # print("l", z, l)
            self.L.append(l)
            E = []
            for i in range(1, len(l)):
                e = list(m[l[i]]).pop()
                if e[0] == "+":
                    E.append(c[(e[1], l[i])]-sum(f[(e[1], l[i])]))
                else:
                    E.append(sum(f[(l[i], e[1])]))
            # print("E", z, " _ min", E, end=" = ")
            self.E.append(E)
            E = min(E)
            # print(E)
            F_max += E
            # print("F_max", F_max)
            for i in l:
                if i == s:
                    p = s
                else:
                    if list(m[i]).pop()[0] == "+":
                        f[(p, i)].append(E)
                    else:
                        f[(i, p)].append(-E)
                    p = i
            z += 1

        # print("A", A)
        X = list(g)
        # print(X)
        XA = [i for i in X if i not in A]
        # print(XA)
        print(A)
        print(XA)
        for o in A:
            for d in XA:
                if (o, d) in [*c]:
                    self.WA.append((o, d))
        self.A = A
        self.X = X
        self.XA = XA
        self.fMax = F_max

    def afiseazadata(self):
        s3 = '‾'*65
        for i in range(0, len(self.L)):
            s1 = "l"+str(i+1) + " = "+str(self.L[i])
            s2 = "E" + str(i+1) + " =  min " + \
                str(self.E[i]) + " = "+str(min(self.E[i]))
            print(s3)
            print('{:30s} {:>1} {:30s}'.format(s1, "|", s2))
        print(s3)

        for a in [*self.f]:
            print("fluxul arcului", a[0], "->", a[1], "=", sum(self.f[a]))
        print(s3)

        print("Secțiunea minimală se obține pentru A =",
              self.XA, "(mulțimea vârfurilor nemarcate )")
        print("W-A", self.WA, "- tăietura de capacitate minimă,")
        capacitatea = 0
        print("c", end="")
        i = 0
        for a in self.WA:
            i += 1
            capacitatea += self.c[a]
            print(self.c[a],   end="")
            if i != len(self.WA):
                print("+", end="")
        print("=", capacitatea, " –capacitatea tăieturii")
        print("Conform teoremei lui Ford-Fulkerson")
        print("F_max =c", end="")
        flux = 0
        i = 0
        for a in self.WA:
            i += 1
            flux += self.c[a]
            print(self.c[a], end="")
            if i != len(self.WA):
                print("+", end="")
        print("=", self.fMax)

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
                self.Ford_Fulkerson_pain()
                self.afiseazadata()
            elif o == "8":
                self.edit()
            elif o == "h":
                print("graf:", self.graf)
                print("capacitati:", self.c)
                print("flux", self.f)


graf = GRAF()

# graf.impota("2")
# graf.afiseazaLista()
# graf.determinare_a_b()
# graf.Ford_Fulkerson_pain()
# graf.afiseazadata()
# graf.deseneazaGraful()

graf.START()
