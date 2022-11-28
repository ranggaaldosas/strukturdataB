#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjMatrix;
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex, int endVertex);
    void showVertex();
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjMatrix = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest)
{
    adjMatrix[src].push_back(dest);
    adjMatrix[src].sort();
}

// BFS algorithm
void Graph::BFS(int startVertex, int endVertex)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;

    while (!queue.empty())
    {
        int currVertex = queue.front();
        if (currVertex == endVertex)
        {
            break;
        }
        cout << "(V" << currVertex << ")";
        queue.pop_front();

        for (i = adjMatrix[currVertex].begin(); i != adjMatrix[currVertex].end(); ++i)
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

void Graph::showVertex()
{
    for (int i = 0; i < numVertices; i++)
    {
        list<int>::iterator it;

        int track = 0;
        int through = 0;
        for (it = adjMatrix[i].begin(); it != adjMatrix[i].end(); ++it)
        {
            // int track = 0;
            int temp = *it;
            if (through == 0)
            {
                while (track < temp)
                {
                    cout << " 0 ";
                    ++track;
                    through++;
                }
            }
            else
            {
                while ((track + 1) < temp)
                {
                    cout << " 0 ";
                    ++track;
                    through++;
                }
            }
            cout << " 1 ";
            through++;
        }
        while ((numVertices - through) > 0)
        {
            through++;
            cout << " 0 ";
        }
        cout << endl;
    }
}

int main()
{
    Graph g1(20);
    g1.addEdge(0, 1);   // 1 - 2
    g1.addEdge(0, 2);   // 1 - 3
    g1.addEdge(1, 4);   // 2 - 5
    g1.addEdge(1, 5);   // 2 - 6
    g1.addEdge(4, 7);   // 5 - 8
    g1.addEdge(7, 3);   // 8 - 4
    g1.addEdge(4, 8);   // 5 - 9
    g1.addEdge(8, 9);   // 9 - 10
    g1.addEdge(9, 10);  // 10 - 11
    g1.addEdge(10, 11); // 11 - 12
    g1.addEdge(11, 16); // 12 - 17
    g1.addEdge(5, 6);   // 6 - 7
    g1.addEdge(6, 7);   // 7 - 8
    g1.addEdge(2, 7);   // 3 - 8
    g1.addEdge(7, 12);  // 8 - 13
    g1.addEdge(12, 13); // 13 - 14
    g1.addEdge(12, 14); // 13 - 15
    g1.addEdge(14, 15); // 15 - 16
    g1.addEdge(18, 17); // 19 - 18
    g1.addEdge(14, 18); // 15 - 19
    g1.addEdge(18, 19); // 19 - 20

    cout << endl;
    g1.showVertex();

    return 0;
}