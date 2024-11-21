#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <cstdlib>  // For srand() and rand()
#include <ctime>    // For time()
#include <getopt.h> // For getopt() to parse command line arguments
#include "Graph.hpp"

// Function to generate a random graph with the given number of vertices and edges
void generateRandomGraph(Graph *g, int vertices, int edges) {
    for (int i = 0; i < edges; ++i) {
        int u = rand() % vertices;
        int v = rand() % vertices;
        // Ensure no self-loop
        while (u == v) {
            v = rand() % vertices;
        }
        g->addEdge(u, v);
    }
}

int main(int argc, char *argv[]) {
    int vertices = 5;     // Default number of vertices
    int edges = 5;        // Default number of edges
    int seed = time(0);   // Default seed is current time

    // Parse command-line arguments using getopt

    //*****example: ./demo -v 5 -e 20 -s 1 ******/// 

    int opt;
    while ((opt = getopt(argc, argv, "v:e:s:")) != -1) {
        switch (opt) {
        case 'v':
            vertices = atoi(optarg);  
            break;
        case 'e':
            edges = atoi(optarg);    
            break;
        case 's':
            seed = atoi(optarg);     
            break;
        default:
            std::cerr << "Usage: " << argv[0] << " [-v vertices] [-e edges] [-s seed]\n";
            return EXIT_FAILURE;
        }
    }

    // Seed the random number generator
    srand(seed);

    Graph *g = new Graph(vertices);

    // Generate a random graph
    generateRandomGraph(g, vertices, edges);

    // Find and print the Euler circuit (if it exists)
    g->findEulerCircuit();

    // Deallocate the memory when we're done
    delete g;

    return 0;
}
