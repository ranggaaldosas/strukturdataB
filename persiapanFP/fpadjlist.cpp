
#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int verticesNum;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex, int endVertex);
    void showList();
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices)
{
    verticesNum = vertices;
    adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    // adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex, int endVertex)
{
    visited = new bool[verticesNum];
    for (int i = 0; i < verticesNum; i++)
        visited[i] = false;

    list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;

    while (!queue.empty())
    {
        int currVertex = queue.front(); // get the front element
        if (currVertex == endVertex)
        {
            break;
        }
        cout << "(V" << currVertex << ")";
        queue.pop_front();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
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

void Graph::showList()
{
    for (int i = 0; i < verticesNum; i++)
    {
        cout << i << ": ";
        list<int>::iterator it; //  iterator for list
        for (it = adjLists[i].begin(); it != adjLists[i].end(); ++it)
        {
            cout << *it << " "; // *it is the value of the node/ngeakses pointer nya
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

    g1.BFS(0, 19);
    cout << endl;
    g1.showList();

    return 0;
}