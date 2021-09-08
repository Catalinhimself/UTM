#!/bin/python
from math import sqrt

x0 = { 'x': 3, 'y': 3 }
def f(x, y):
    return 3 * x ** 2 + 3 * x * y + 3 * y ** 2 - 3 * x - 3 * y

def derivata_fx(x, y):
    return 6 * x + 3 * y - 3

def derivata_fy(x, y):
    return 3 * x + 6 * y - 3

def magnitudinea(x, y):
    return sqrt(derivata_fx(x, y) ** 2 + derivata_fy(x, y) ** 2)

lamda = 1
gama = 0.5
epsilon = 10 ** -6
sigma = 0.06
k = 0

def z(x, y):
    return {'x': 1, 'y':1}

if __name__ == "__main__":
    print("functia", f(3, 3))
    print("magnitudinea", magnitudinea(3, 3))
