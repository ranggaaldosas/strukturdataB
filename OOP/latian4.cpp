#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Vertex
{
private:
    list<int> adj;

public:
    void addEdge(int u, int v)
    {
        if (adj.empty())
            adj.push_back(u);
        adj.push_back(v);
    }

    void printList()
    {
        list<int>::iterator i;
        for (i = adj.begin(); i != adj.end(); i++)
            cout << *i << " ";
        cout << endl;
    }
};

class Graph
{
private:
    int len;
    Vertex vertex[100];

public:
    Graph(int n)
    {
        len = n;
    }

    void AddEdgeVertex(int u, int v)
    {
        vertex[u].addEdge(u, v);
        vertex[v].addEdge(v, u);
    }

    void printVertex()
    {
        for (int i = 0; i < len; i++)
            vertex[i].printList();
    }
};

int main()
{
    Graph _graph1(5);

    _graph1.AddEdgeVertex(0, 1);
    _graph1.AddEdgeVertex(0, 4);
    _graph1.AddEdgeVertex(1, 2);
    _graph1.AddEdgeVertex(1, 3);
    _graph1.AddEdgeVertex(1, 4);
    _graph1.AddEdgeVertex(2, 3);
    _graph1.AddEdgeVertex(3, 4);

    _graph1.printVertex();
}