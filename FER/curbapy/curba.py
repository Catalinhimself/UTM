rd = int(input("resursele disponibile: "))
x = int(input("costul x: "))
y = int(input("costul y: "))
z = int(input("bunul z (0 in caz ca nu este): "))
# rd = 27000
# x = 300
# y = 900
# z = 0

rd -= z

bx = rd/x
by = rd/y
print("1.calculam valoarea maxima a bunurilor x si y")
print("vloumul maxim de x bunuri", bx)
print("vloumul maxim de y bunuri", by)
p = 10
if z:
    p = 5
px = bx/p
py = by/p
print("2.calculam pasul pe axa x si y")
print("pasul x", px)
print("pasul y", py)


tx = []
ty = []
for i in range(0, p+1):
    tx.append(px*i)
    ty.append(by-py*i)

print("3. graficul curbei posibilitatilor")


print("4. extragegrea datelor")

print("x", tx)
print('y', ty)

print("5. verificam datele")
for i in range(0, p+1):
    print(tx[i], "*", x, "+", ty[i], "*", y, "=", tx[i]*x+ty[i]*y)
if input("aveti matplotlib? [y/n]:") == "y":
    import matplotlib.pyplot as plt
    plt.plot(tx, ty)
    plt.show()
