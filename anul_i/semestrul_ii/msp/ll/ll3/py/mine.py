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
        self.drumMinim = int()
        self.drumMaxim = int()
        self.minListe = []
        self.maxListe = []
    def adaugaArc(self, initial, terminal, ponderea):
        self.graf[initial].append((terminal, ponderea))

    def citirea(self):
        self.graf = defaultdict(list)
        print("citirea listei de adiacenta")
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
            print("ponderea este")
            ponderea = input()
            if ponderea == "q":
                break
            self.adaugaArc(int(initial), int(terminal), int(ponderea))
            i += 1
        self.curatare()

    def curatare(self):
        for v in [*self.graf]:
            self.graf[v].sort()
            self.graf[v] = list(dict(self.graf[v]).items())
            self.graf[v] = [(varf, pond)
                            for (varf, pond) in self.graf[v] if varf != v]
            for c in self.graf[v]:
                if c[0] not in [*self.graf]:
                    self.graf[c[0]] = []
        self.graf = dict(sorted(self.graf.items()))

    def afiseazaLista(self):
        print("lista de adiacenta")
        for k in [*self.graf]:
            print(k, "-", end=" ")
            for v in self.graf[k]:
                print(str(v[0])+"("+str(v[1])+")", end=", ")
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

    def determinaFordMinim(self):
        ford = PrettyTable()
        ford.field_names = ["i, j", "L ij",
                            "Hj - Hi = L ij", "Distanta", "Eticheta"]
        H = defaultdict(int)
        for k in [*self.graf]:
            H[k] = math.inf
        for k in [*self.graf]:
            H[k] = 0
            break
        for k in [*self.graf]:
            for v in self.graf[k]:
                line = []
                line.append(str(k)+", "+str(v[0]))
                line.append(v[1])
                eq = "H"+str(v[0])+" - H"+str(k)+" = "
                eqn = str(H[v[0]])+" - "+str(H[k])+" = "
                rs = str(H[v[0]]-H[k])
                line.append(eq + eqn + rs + str((" < ", " > ")
                                                [H[v[0]]-H[k] > v[1]])+str(v[1]))
                if H[v[0]] - H[k] > v[1]:
                    distanta = str(H[k])+"+"+str(v[1])
                    eticheta = "H"+str(v[0])+" = " + str(H[k]+v[1])
                else:
                    distanta = "--------"
                    eticheta = "neschimbata"
                line.append(distanta)
                line.append(eticheta)
                if H[v[0]]-H[k] > v[1]:
                    H[v[0]] = H[k]+v[1]
                ford.add_row(line)
        print(ford.get_string(title="Ford drum minim"))
        # tabelulH = PrettyTable()
        # tabelulH.field_names = ["H", "val"]
        # H = dict(sorted(H.items()))
        # for k in [*H]:
        #     tabelulH.add_row(["H"+str(k), str(H[k])])
        # print(tabelulH)
        self.drumMinim = int(H[list(H).pop()])
        self.determinaFordInput(H)
    def determinaFordMaxim(self):
        ford = PrettyTable()
        ford.field_names = ["i, j", "L ij",
                            "Hj - Hi = L ij", "Distanta", "Eticheta"]
        H = defaultdict(int)
        for k in [*self.graf]:
            H[k] = -math.inf
        for k in [*self.graf]:
            H[k] = 0
            break
        for k in [*self.graf]:
            for v in self.graf[k]:
                line = []
                line.append(str(k)+", "+str(v[0]))
                line.append(v[1])
                eq = "H"+str(v[0])+" - H"+str(k)+" = "
                eqn = str(H[v[0]])+" - "+str(H[k])+" = "
                rs = str(H[v[0]]-H[k])
                line.append(eq + eqn + rs + str((" < ", " > ")
                                                [H[v[0]]-H[k] > v[1]])+str(v[1]))
                if H[v[0]] - H[k] < v[1]:
                    distanta = str(H[k])+"+"+str(v[1])
                    eticheta = "H"+str(v[0])+" = " + str(H[k]+v[1])
                else:
                    distanta = "--------"
                    eticheta = "neschimbata"
                line.append(distanta)
                line.append(eticheta)
                if H[v[0]]-H[k] < v[1]:
                    H[v[0]] = H[k]+v[1]
                ford.add_row(line)
        print(ford.get_string(title="Ford drum maxim"))
        self.drumMaxim = int(H[list(H).pop()])
        self.determinaFordInput(H) 
    def determinaFordInput(self,etichete):
        grafInversat = defaultdict(list)
        for k in [*self.graf]:
            for v in self.graf[k]:
                grafInversat[v[0]].append((k,v[1]))
        # print(grafInversat)
        start = list(self.graf).pop(0)    
        finish = list(self.graf).pop()
        drumuri = [[finish]]
        temp = []
        drumuriValide =[]
        while drumuri:
            for drum in drumuri:
                if drum[0]==finish and drum[len(drum)-1]==start:
                    drumF = []
                    for f in drum:
                        drumF.insert(0,f)
                    drumuriValide.append(drumF)
                for v in grafInversat[drum[len(drum)-1]]:
                    if etichete[list(etichete).pop()]==self.drumMinim:
                        if etichete[drum[len(drum)-1]] -v[1] ==etichete[v[0]]:
                            temp.append(drum+[v[0]])
                    else:
                        # print(  etichete[drum[len(drum)-1]] ,etichete[v[0]] ,v)
                        if    etichete[drum[len(drum)-1 ]] - etichete[v[0]]  ==v[1]:
                            temp.append(drum+[v[0]])
                            # print(v)
            if not temp:
                break
            drumuri=temp
            temp = []
       
        if etichete[list(etichete).pop()]==self.drumMinim:
            self.minListe=drumuriValide
            self.afiseazaDrumuri("minim")
        if etichete[list(etichete).pop()]==self.drumMaxim:
            self.maxListe=drumuriValide
            self.afiseazaDrumuri("maxim")
    def determinaBellmanKalabaMinim(self):
        kalaba = PrettyTable()
        kalaba.field_names = [""]+[*self.graf]
        n = list(self.graf).pop()+1
        bk = np.zeros([n, n])
        for i in range(0, n):
            for j in range(0, n):
                bk[i][j] = -1
        varfuri = sorted(list(self.graf))
        for i in varfuri:
            for j in varfuri:
                bk[i][j] = math.inf
                if i == j:
                    bk[i][j] = 0
        for k in [*self.graf]:
            for v in self.graf[k]:
                bk[k][v[0]] = v[1]
        m = n+1
        bk.resize([m, n])
        for i in range(0, n):
            bk[m-1][i] = bk[i][n-1]

        while not (bk[m-2] == bk[m-1]).all():
            m += 1
            bk.resize([m, n])
            for i in varfuri:
                temp = math.inf
                for j in varfuri:
                    if i != j:
                        if bk[m-2][j]+bk[i][j] < temp:
                            temp = bk[m-2][j]+bk[i][j]
                            bk[m-1][i] = temp

        for i in varfuri:
            lista = [i]
            for j in varfuri:
                if math.isinf(bk[i][j]):
                    lista.append(bk[i][j])
                else:
                    lista.append(int(bk[i][j]))
            kalaba.add_row(lista)
        for i in range(n, m):
            lista = []
            lista.append("V"+str(i-n+1))
            for j in varfuri:
                if math.isinf(bk[i][j]):
                    lista.append(bk[i][j])
                else:
                    lista.append(int(bk[i][j]))

            kalaba.add_row(lista)
        print(kalaba.get_string(title="Bellman Kalaba drum minim"))
        self.drumMinim = int(bk[m-1][list(varfuri).pop(0)])
        self.determinaKalabaInput(bk[m-1])
    
    def determinaBellmanKalabaMaxim(self):
        kalaba = PrettyTable()
        kalaba.field_names = [""]+[*self.graf]
        n = list(self.graf).pop()+1
        bk = np.zeros([n, n])
        for i in range(0, n):
            for j in range(0, n):
                bk[i][j] = -1
        varfuri = sorted(list(self.graf))
        for i in varfuri:
            for j in varfuri:
                bk[i][j] = -math.inf
                if i == j:
                    bk[i][j] = 0
        for k in [*self.graf]:
            for v in self.graf[k]:
                bk[k][v[0]] = v[1]
        m = n+1
        bk.resize([m, n])
        for i in range(0, n):
            bk[m-1][i] = bk[i][n-1]

        while not (bk[m-2] == bk[m-1]).all():
            m += 1
            bk.resize([m, n])
            for i in varfuri:
                temp = -math.inf
                for j in varfuri:
                    if i != j:
                        if bk[m-2][j]+bk[i][j] > temp:
                            temp = bk[m-2][j]+bk[i][j]
                            bk[m-1][i] = temp

        for i in varfuri:
            lista = [i]
            for j in varfuri:
                if math.isinf(bk[i][j]):
                    lista.append(bk[i][j])
                else:
                    lista.append(int(bk[i][j]))
            kalaba.add_row(lista)
        for i in range(n, m):
            lista = []
            lista.append("V"+str(i-n+1))
            for j in varfuri:
                if math.isinf(bk[i][j]):
                    lista.append(bk[i][j])
                else:
                    lista.append(int(bk[i][j]))

            kalaba.add_row(lista)
        print(kalaba.get_string(title="Bellman Kalaba drum maxim"))
        self.drumMaxim = int(bk[m-1][list(varfuri).pop(0)])
        self.determinaKalabaInput(bk[m-1])


    def determinaKalabaInput(self,rand):
        start = list(self.graf).pop(0)    
        finish = list(self.graf).pop()
        drumuri = [[start]]
        temp = []
        drumuriValide =[]
        while drumuri:
            for drum in drumuri:
                if drum[0]==start and drum[len(drum)-1]==finish:
                    drumuriValide.append(drum)
                for v in self.graf[drum[len(drum)-1]]:
                    if rand[drum[len(drum)-1]]==rand[v[0]]+v[1]:
                        temp.append(drum+[v[0]])
            if not temp:
                break
            drumuri=temp
            temp = []
        if rand[start]==self.drumMinim:
            self.minListe=drumuriValide
            self.afiseazaDrumuri("minim")
        if rand[start]==self.drumMaxim:
            self.maxListe=drumuriValide
            self.afiseazaDrumuri("maxim")
    def afiseazaDrumuri(self,drum):
        print("D",drum,"= ", (self.drumMinim,self.drumMaxim)[drum=="maxim"])
        for l in (self.minListe,self.maxListe)[drum=="maxim"]:
            pref = list(self.graf).pop(0)
            weight = []
            for v in l:
                if v != pref:
                    print(pref, end="")
                    weight = [item for item in self.graf[pref] if v == item[0]]
                    print(" =("+str(weight.pop()[1]) + ")=>", end=" ")
                pref = v
            print(pref)
            
    def determinareaCatalinHimselfDrumuluiMaxim(self):
        lista = []
        lista2 = []
        start = list(self.graf).pop(0)
        finis = list(self.graf).pop()
        lista.append([start])
        # for v in self.graf[start]:
        #     lista.append([v[0]])
        listePosibile = []
        while lista:
            for l in lista:
                for v in self.graf[l[len(l)-1]]:
                    lista2.append(l+[v[0]])
            lista = lista2
            # print(lista)
            for l in lista:
                if (l[0] == start and l[len(l)-1] == finis):
                    listePosibile.append(l)
            lista2 = []
        listeValide = []
        # print(listePosibile)
        for l in listePosibile:
            suma = 0
            pref = start
            weight = 0
            for v in l:
                if v != start:
                    weight = [item for item in self.graf[pref] if v in item]
                    suma += weight.pop()[1]
                # print("varf", v, "suma", suma, "weight", weight)
                pref = v
            if suma == self.drumMaxim:
                listeValide.append(l)
        print("D maxim = ", self.drumMaxim)
        for l in listeValide:
            pref = start
            for v in l:
                if v != pref:
                    print(pref, end="")
                    weight = [item for item in self.graf[pref] if v in item]
                    print(" =("+str(weight.pop()[1]) + ")=>", end=" ")
                pref = v
            print(pref)
        # print(listeValide)

    def deseneazaGraful(self):
        g = nx.DiGraph()
        for i in [*self.graf]:
            for j in self.graf[i]:
                g.add_edge(i, j[0], weight=j[1])
        pos = nx.circular_layout(g)
        edge_labels = {(u, v): d['weight'] for u, v, d in g.edges(data=True)}
        nx.draw(g, pos, with_labels=True, node_size=1700, font_size=40)
        nx.draw_networkx_edge_labels(g, pos, edge_labels=edge_labels,font_size=20)
        plt.savefig('output.png')
        plt.show()

    def removeVertex(self):
        print(self.graf)
        print("varful pe care doriti sa il stergeti :")
        v = int(input())
        for i in [*self.graf]:
            self.graf[i] = [item for item in self.graf[i] if item[0] != v]
        self.graf.pop(v, None)

    def removeEdge(self):
        print(self.graf)
        print("varful din care iese muchia :")
        e = int(input())
        print("varful in care intra muchia :")
        i = int(input())
        self.graf[e] = [item for item in self.graf[e] if item[0] != i]

    def addEdge(self):
        print(self.graf)
        print("puteti adauga orice muchie (chiar cu varfuri noi)")
        print("varful din care iese muchia :")
        e = int(input())
        print("varful in care intra muchia :")
        i = int(input())
        print("ponderea :")
        p = int(input())
        self.adaugaArc(e, i, p)

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
            print("( 4 ) - FORD minim")
            print("( 5 ) - Kalaba minim")
            print("( 6 ) - FORD maxim")
            print("( 7 ) - Kalaba maxim")
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
                print("graf:",self.graf)
                print("drum minim:",self.drumMinim)
                print("drumurile minime:",self.minListe)
                print("drum maxim:",self.drumMaxim)
                print("drumurile maxim:",self.maxListe)


graf = GRAF()
graf.START()
