import networkx as nx
import matplotlib.pyplot as plt


def _main():
    g = nx.DiGraph()

    g.add_edge(2, 3, weight=1)
    g.add_edge(3, 4, weight=5)
    g.add_edge(5, 1, weight=10)
    g.add_edge(1, 3, weight=15)

    g.add_edge(2, 7, weight=1)
    g.add_edge(13, 6, weight=5)
    g.add_edge(12, 5, weight=10)
    g.add_edge(11, 4, weight=15)

    g.add_edge(9, 2, weight=1)
    g.add_edge(10, 13, weight=5)
    g.add_edge(7, 5, weight=10)
    g.add_edge(9, 4, weight=15)

    g.add_edge(10, 3, weight=1)
    g.add_edge(11, 2, weight=5)
    g.add_edge(9, 6, weight=10)
    g.add_edge(10, 5, weight=15)

    pos = nx.circular_layout(g)

    edge_labels = {(u, v): d['weight'] for u, v, d in g.edges(data=True)}

    nx.draw_networkx_nodes(g, pos, node_size=700)
    nx.draw_networkx_edges(g, pos)
    nx.draw_networkx_labels(g, pos)
    nx.draw_networkx_edge_labels(g, pos, edge_labels=edge_labels)

    plt.title("Graph Title")
    plt.axis('off')

    plt.savefig('output.png')
    plt.show()


if __name__ == '__main__':
    _main()
