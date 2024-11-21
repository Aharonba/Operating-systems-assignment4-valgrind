#include "Graph.hpp"

int main()
{
    // Creating a graph with 6 vertices
    Graph g(6);

    // Adding edges to form an Euler circuit
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    g.addEdge(0, 5);
    g.addEdge(1, 5);
    g.addEdge(1, 4);
    g.addEdge(5, 2);
    g.addEdge(4, 5);

    g.addEdge(0, 2);

    // Finding and printing the Euler circuit
    g.findEulerCircuit();

    return 0;
}
