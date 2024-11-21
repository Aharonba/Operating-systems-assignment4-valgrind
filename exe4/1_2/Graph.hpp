#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <stack>

class Graph
{
private:
    int vertices;
    std::unordered_map<int, std::list<int>> adjList;

    // Helper function to check if all non-zero degree vertices are connected
    void DFS(int v, std::vector<bool> &visited)
    {
        visited[v] = true;
        for (int u : adjList[v])
        {
            if (!visited[u])
            {
                DFS(u, visited);
            }
        }
    }

    // Function to check if the graph is connected (ignoring isolated vertices)
    bool isConnected()
    {
        std::vector<bool> visited(vertices, false);

        // Find a vertex with non-zero degree
        int nonZeroDegreeVertex = -1;
        for (int i = 0; i < vertices; ++i)
        {
            if (!adjList[i].empty())
            {
                nonZeroDegreeVertex = i;
                break;
            }
        }

        // If there are no edges in the graph, it is Eulerian
        if (nonZeroDegreeVertex == -1)
            return true;

        // Perform DFS from the first non-zero degree vertex
        DFS(nonZeroDegreeVertex, visited);

        // Check if all vertices with non-zero degree are visited
        for (int i = 0; i < vertices; ++i)
        {
            if (!adjList[i].empty() && !visited[i])
            {
                return false;
            }
        }
        return true;
    }

    // Function to check if all vertices have even degree
    bool hasEvenDegree()
    {
        for (int i = 0; i < vertices; ++i)
        {
            if (adjList[i].size() % 2 != 0)
            {
                return false;
            }
        }
        return true;
    }

public:
    Graph(int V) : vertices(V) {}

    // Add an edge between two vertices
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Function to check if an Euler circuit exists and to print the circuit if it does
    void findEulerCircuit()
    {
        if (!isConnected())
        {
            std::cout << "Graph is not connected, Euler circuit does not exist.\n";
            return;
        }

        if (!hasEvenDegree())
        {
            std::cout << "Not all vertices have an even degree, Euler circuit does not exist.\n";
            return;
        }

        std::stack<int> currentPath;
        std::vector<int> circuit;

        // Start from any vertex with edges
        int currentVertex = 0;
        for (int i = 0; i < vertices; ++i)
        {
            if (!adjList[i].empty())
            {
                currentVertex = i;
                break;
            }
        }

        currentPath.push(currentVertex);

        while (!currentPath.empty())
        {
            if (!adjList[currentVertex].empty())
            {
                // Choose any neighbor
                currentPath.push(currentVertex);
                int neighbor = adjList[currentVertex].front();
                adjList[currentVertex].remove(neighbor);
                adjList[neighbor].remove(currentVertex);
                currentVertex = neighbor;
            }
            else
            {
                // Backtrack to previous vertex
                circuit.push_back(currentVertex);
                currentVertex = currentPath.top();
                currentPath.pop();
            }
        }

        // Print the Euler circuit
        std::cout << "Euler Circuit: ";
        for (int vertex : circuit)
        {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }
};
