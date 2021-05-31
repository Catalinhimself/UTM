

import networkx as nx

__all__ = ['ford_fulkerson']


def ford_fulkerson_impl(G, s, t, capacity):
    """Legacy implementation of the Edmonds-Karp algorithm"""
    if G.is_multigraph():
        raise nx.NetworkXError(
            'MultiGraph and MultiDiGraph not supported (yet).')

    if s not in G:
        raise nx.NetworkXError('node %s not in graph' % str(s))
    if t not in G:
        raise nx.NetworkXError('node %s not in graph' % str(t))
    if s == t:
        raise nx.NetworkXError('source and sink are the same node')

    auxiliary = _create_auxiliary_digraph(G, capacity=capacity)
    inf_capacity_flows = auxiliary.graph['inf_capacity_flows']

    flow_value = 0   # Initial feasible flow.

    # As long as there is an (s, t)-path in the auxiliary digraph, find
    # the shortest (with respect to the number of arcs) such path and
    # augment the flow on this path.
    while True:
        try:
            path_nodes = nx.bidirectional_shortest_path(auxiliary, s, t)
        except nx.NetworkXNoPath:
            break

        # Get the list of edges in the shortest path.
        path_edges = list(zip(path_nodes[:-1], path_nodes[1:]))

        # Find the minimum capacity of an edge in the path.
        try:
            path_capacity = min([auxiliary[u][v][capacity]
                                 for u, v in path_edges
                                 if capacity in auxiliary[u][v]])
        except ValueError:
            # path of infinite capacity implies no max flow
            raise nx.NetworkXUnbounded(
                "Infinite capacity path, flow unbounded above.")

        flow_value += path_capacity

        # Augment the flow along the path.
        for u, v in path_edges:
            edge_attr = auxiliary[u][v]
            if capacity in edge_attr:
                edge_attr[capacity] -= path_capacity
                if edge_attr[capacity] == 0:
                    auxiliary.remove_edge(u, v)
            else:
                inf_capacity_flows[(u, v)] += path_capacity

            if auxiliary.has_edge(v, u):
                if capacity in auxiliary[v][u]:
                    auxiliary[v][u][capacity] += path_capacity
            else:
                auxiliary.add_edge(v, u, {capacity: path_capacity})

    auxiliary.graph['inf_capacity_flows'] = inf_capacity_flows
    return flow_value, auxiliary


def _create_auxiliary_digraph(G, capacity='capacity'):
    """Initialize an auxiliary digraph and dict of infinite capacity
    edges for a given graph G.
    Ignore edges with capacity <= 0.
    """
    auxiliary = nx.DiGraph()
    auxiliary.add_nodes_from(G)
    inf_capacity_flows = {}
    if nx.is_directed(G):
        for edge in G.edges(data=True):
            if capacity in edge[2]:
                if edge[2][capacity] > 0:
                    auxiliary.add_edge(*edge)
            else:
                auxiliary.add_edge(*edge)
                inf_capacity_flows[(edge[0], edge[1])] = 0
    else:
        for edge in G.edges(data=True):
            if capacity in edge[2]:
                if edge[2][capacity] > 0:
                    auxiliary.add_edge(*edge)
                    auxiliary.add_edge(edge[1], edge[0], edge[2])
            else:
                auxiliary.add_edge(*edge)
                auxiliary.add_edge(edge[1], edge[0], edge[2])
                inf_capacity_flows[(edge[0], edge[1])] = 0
                inf_capacity_flows[(edge[1], edge[0])] = 0

    auxiliary.graph['inf_capacity_flows'] = inf_capacity_flows
    return auxiliary


def _create_flow_dict(G, H, capacity='capacity'):
    """Creates the flow dict of dicts on G corresponding to the
    auxiliary digraph H and infinite capacity edges flows
    inf_capacity_flows.
    """
    inf_capacity_flows = H.graph['inf_capacity_flows']
    flow = dict([(u, {}) for u in G])

    if G.is_directed():
        for u, v in G.edges_iter():
            if H.has_edge(u, v):
                if capacity in G[u][v]:
                    flow[u][v] = max(0, G[u][v][capacity] - H[u][v][capacity])
                elif G.has_edge(v, u) and not capacity in G[v][u]:
                    flow[u][v] = max(0, inf_capacity_flows[(u, v)] -
                                     inf_capacity_flows[(v, u)])
                else:
                    flow[u][v] = max(0, H[v].get(u, {}).get(capacity, 0) -
                                     G[v].get(u, {}).get(capacity, 0))
            else:
                flow[u][v] = G[u][v][capacity]

    else:  # undirected
        for u, v in G.edges_iter():
            if H.has_edge(u, v):
                if capacity in G[u][v]:
                    flow[u][v] = abs(G[u][v][capacity] - H[u][v][capacity])
                else:
                    flow[u][v] = abs(inf_capacity_flows[(u, v)] -
                                     inf_capacity_flows[(v, u)])
            else:
                flow[u][v] = G[u][v][capacity]
            flow[v][u] = flow[u][v]

    return flow


def ford_fulkerson(G, s, t, capacity='capacity'):

    import networkx as nx
    from networkx.algorithms.flow import ford_fulkerson

    G = nx.DiGraph()
    G.add_edge('x', 'a', capacity=3.0)
    G.add_edge('x', 'b', capacity=1.0)
    G.add_edge('a', 'c', capacity=3.0)
    G.add_edge('b', 'c', capacity=5.0)
    G.add_edge('b', 'd', capacity=4.0)
    G.add_edge('d', 'e', capacity=2.0)
    G.add_edge('c', 'y', capacity=2.0)
    G.add_edge('e', 'y', capacity=3.0)

    R = ford_fulkerson(G, 'x', 'y')
    # A dictionary with infinite capacity flows can be found as an
    # attribute of the residual network
    inf_capacity_flows = R.graph['inf_capacity_flows']
    # There are also attributes for the flow value and the flow dict
    flow_value = R.graph['flow_value']
    flow_dict = R.graph['flow_dict']

    flow_value, flow_dict = nx.maximum_flow(
        G, 'x', 'y', flow_func=ford_fulkerson)

    flow_value, R = ford_fulkerson_impl(G, s, t, capacity=capacity)
    flow_dict = _create_flow_dict(G, R, capacity=capacity)
    R.graph['flow_value'] = flow_value
    R.graph['flow_dict'] = flow_dict
    R.graph['algorithm'] = 'ford_fulkerson_legacy'
    return R
