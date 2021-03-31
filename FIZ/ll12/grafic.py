import numpy as np
import matplotlib.pyplot as plt
import math
from prettytable import PrettyTable
import csv

x = PrettyTable()


def ptable_to_csv(table, filename, headers=True):
    """Save PrettyTable results to a CSV file.

    Adapted from @AdamSmith https://stackoverflow.com/questions/32128226

    :param PrettyTable table: Table object to get data from.
    :param str filename: Filepath for the output CSV.
    :param bool headers: Whether to include the header row in the CSV.
    :return: None
    """
    raw = table.get_string()
    data = [tuple(filter(None, map(str.strip, splitline)))
            for line in raw.splitlines()
            for splitline in [line.split('|')] if len(splitline) > 1]
    if table.title is not None:
        data = data[1:]
    if not headers:
        data = data[1:]
    with open(filename, 'w') as f:
        for d in data:
            f.write('{}\n'.format(','.join(d)))


l = [0, 10, 20, 26, 28, 29, 30, 31, 32, 33, 34, 36, 40]
B = []
H = []
n = [40, 40, 40, 40, 40, 36, 21, 13, 3, 1, 0.5, 0.25, 0.25]
for e in n:
    B.append(1.26*10 ** (-3) * 7*10 ** (-5)*e*10 ** (-3))
    H.append((1.26*10 ** (-3) * 7*10 ** (-5)*e *
              10 ** (-3))/(4*math.pi*10 ** (-7)))


for i in range(len(B)):
    B[i] = float("{0:.3f}".format(B[i]*10**9))
for i in range(len(H)):
    H[i] = float("{0:.3f}".format(H[i]*10**3))

x.field_names = ["l"]+l
x.add_row(["n"]+n)
x.add_row(["B"]+B)
x.add_row(["H"]+H)
print(x.get_string())

ptable_to_csv(x, "output.csv", True)


# fig, ax = plt.subplots()
# ax.plot(l, B, 'k', label='B=f(l)')
# ax.plot(l, H, 'r', label='H=f(l)')
# leg = ax.legend(loc='upper right', frameon=False)

plt.plot(l, B, label='B=f(l)')
plt.ylabel('T * 10^-9')
plt.xlabel("mm")
plt.legend()
plt.show()
plt.plot(l, H, "r", label='H=f(l)')
plt.ylabel('A/m * 10^-3')
plt.xlabel("mm")
plt.legend()


plt.show()
