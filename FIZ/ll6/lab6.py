import numpy as np
import math
D = 1.02*10 ** -3
R0 = D/2
l = 283*10 ** -3
T = 294.15
g = 9.80665
p = 998.02
R = 8.13
M = 29*10 ** -3
pi = 3.14
P = 99058.5
h = [38*10**-3, 33*10**-3, 27*10**-3]
V = 300*10**-6
t = [137, 149, 200]
n = np.zeros(3)
lam = np.zeros(3)
for i in range(3):
    n[i] = (p*g*h[i]*math.pi*(R0**4)*t[i])/(8*V*l)
    lam[i] = ((3*n[i])/P)*((math.pi*R*T)/(8*M))**(1/2)
print("n", n)
print("lam", lam)
