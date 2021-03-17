rd = int(input("resursele disponibile: "))
z = int(input("bunul z (0 in caz ca nu este): "))
x = int(input("costul x: "))
y = int(input("costul y: "))
p = int(input("dati nr de posibilitati de producere: "))
print("\n\n")
# rd = 27000
# x = 300
# y = 900
# z = 0

rd -= z

bx = rd/x
by = rd/y
print("1. Calculam valoarea maxima de producere a bunurilor x si y.")
print("V.max ( bx ) = R.d/Pr.cost =", rd, "/", x, "=", bx, "bunuri max( x )")
print("V.max ( by ) = R.d/Pr.cost =", rd, "/", y, "=", by, "bunuri max( y )")
print("\n\n")


px = bx/p
py = by/p
print("2. Calculam pasul pe axa x si y")
print("V.max b( x )/Nr. de posibilitati =",
      bx, "/", p, "=", px, "(pasul pe axa x)")
print("V.max b( y )/Nr. de posibilitati =",
      by, "/", p, "=", py, "(pasul pe axa x)")
print("\n\n")

tx = []
ty = []
for i in range(0, p+1):
    tx.append(px*i)
    ty.append(by-py*i)

print("3. Construim graficul curbei posibilitatilor de producere in depenenta de pasul pe axa x si y.")
print("\n\n")

print("4. Extragem datele cu privire la posibilitatea de producere in tabel.")

print("x", end=" | ")
for t in tx:
    print('{:>3}'.format(str(int(t))), end=" | ")
print()
print("y", end=" | ")
for t in ty:
    print('{:>3}'.format(str(int(t))), end=" | ")
print()
print("\n\n")
print("5. Verificam daca resursele disponibile sunt utilizate integral.")
print("#(selecteaza doar o optiune)#")
print("\n\n")
for i in range(0, p+1):
    print(tx[i], "*",  x, "+",  ty[i],
          "*",  y, "=", tx[i]*x+ty[i]*y)
print("\n\n")
print("""6. Explicam interdependenta dintre posibilitatile de deplasare a CCP (curbei posibilitatilor de producere) si formele de manifestare ale producerii ---CCP are tendinta să rămână constantă , să se deplaseze la dreapta sau la stânga in cazul in care cpp ramane constanta , agentul economic va implementa o reproducere simplă

daca se va deplasa la dreapta - largita
daca se va deplasa la stânga- reproducere  restransă
""")
if input("aveti matplotlib? [y/n]:") == "y":
    import matplotlib.pyplot as plt
    plt.plot(tx, ty)
    plt.show()
