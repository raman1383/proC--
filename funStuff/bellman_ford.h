#include <climits>
#include <iostream>
using std::cout, std::endl, std::cin;
// Wrapper class for storing an edge
class Edge
{
public:
    int src, dst, weight;
};

// Wrapper class for storing a graph
class Graph
{
public:
    int vertexNum, edgeNum;
    Edge *edges;

    // Constructs a graph with V vertices and E edges
    [[maybe_unused]] Graph(int V, int E)
    {
        this->vertexNum = V;
        this->edgeNum = E;
        this->edges = (Edge *)malloc(E * sizeof(Edge));
    }

    // Adds the given edge to the graph
    [[maybe_unused]] void addEdge(int src, int dst, int weight) const
    {
        static int edgeInd = 0;
        if (edgeInd < this->edgeNum)
        {
            Edge newEdge{};
            newEdge.src = src;
            newEdge.dst = dst;
            newEdge.weight = weight;
            this->edges[edgeInd++] = newEdge;
        }
    }
};

// Utility function to print distances
void print(int dist[], int V)
{
    cout << "\nVertex  Distance" << endl;
    for (int i = 0; i < V; i++)
    {
        if (dist[i] != INT_MAX)
            cout << i << "\t" << dist[i] << endl;
        else
            cout << i << "\tINF" << endl;
    }
}

// The main function that finds the shortest path from given source
// to all other vertices using Bellman-Ford.It also detects negative
// weight cycle
[[maybe_unused]] void BellmanFord(Graph graph, int src)
{
    int V = graph.vertexNum;
    int E = graph.edgeNum;
    int dist[V];

    // Initialize distances array as INF for all except source
    // Initialize source as zero
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Calculate the shortest path distance from source to all edges
    // A path can contain maximum (|V|-1) edges
    for (int i = 0; i <= V - 1; i++)
        for (int j = 0; j < E; j++)
        {
            int u = graph.edges[j].src;
            int v = graph.edges[j].dst;
            int w = graph.edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }

    // Iterate inner loop once more to check for negative cycle
    for (int j = 0; j < E; j++)
    {
        int u = graph.edges[j].src;
        int v = graph.edges[j].dst;
        int w = graph.edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Graph contains negative weight cycle. Hence, shortest "
                    "distance not guaranteed."
                 << endl;
            return;
        }
    }

    print(dist, V);
}

/*

    int V, E, gSrc;
    int src, dst, weight;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Graph G(V, E);
    for (int i = 0; i < E; i++)
    {
        cout << "\nEdge " << i + 1 << "\nEnter source: ";
        cin >> src;
        cout << "Enter destination: ";
        cin >> dst;
        cout << "Enter weight: ";
        cin >> weight;
        G.addEdge(src, dst, weight);
    }
    cout << "\nEnter source: ";
    cin >> gSrc;
    BellmanFord(G, gSrc);
*/