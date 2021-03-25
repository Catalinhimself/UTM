import numpy as np
import matplotlib.pyplot as plt


l = [0, 10, 20, 26, 28, 29, 30, 31, 32, 33, 34, 36, 40]
B = [3.528, 3.528, 3.528, 3.528, 3.528, 3.175,
     1.852, 1.146, 0.264, 0.088, 0.044, 0.022, 0.022]
H = [2.807, 2.807, 2.807, 2.807, 2.807, 2.526,
     1.473, 0.911, 0.21, 0.07, 0.035, 0.017, 0.017]

fig, ax = plt.subplots()
ax.plot(l, B, 'k', label='B=f(l)')
ax.plot(l, H, 'r', label='H=f(l)')
leg = ax.legend(loc='upper right', frameon=False)

plt.show()
