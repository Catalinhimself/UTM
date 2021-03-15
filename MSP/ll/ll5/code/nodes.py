import sys
import networkx as nx
import matplotlib.pyplot as plt

# Create a list of 10 nodes numbered [0, 9]
nodes = range(10)
node_sizes = []
labels = {}
for n in nodes:
    node_sizes.append(100 * n)
    labels[n] = 100 * n

# Node sizes: [0, 100, 200, 300, 400, 500, 600, 700, 800, 900]

# Connect each node to its successor
edges = [(i, i+1) for i in range(len(nodes)-1)]

# Create the graph and draw it with the node labels
g = nx.Graph()
g.add_nodes_from(nodes)
g.add_edges_from(edges)

nx.draw_random(g, node_size=node_sizes, labels=labels, with_labels=True)
plt.show()
