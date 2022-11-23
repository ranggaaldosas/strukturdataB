#include <iostream>
#include <iterator>
#include <list>
#include <queue>
using namespace std;

class Graph
{
protected:
    int v;
    list<int> adj[100];
    int pred[100];
    int dist[100];

public:
    Graph(int len)
    {
        v = len;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void showGraph()
    {
        for (int i = 0; i < v; i++)
        {
            list<int>::iterator it;
            cout << i << " ";
            for (it = adj[i].begin(); it != adj[i].end(); ++it)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start)
    {
        cout << "===BFS===" << endl;
        bool visited[100];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
            pred[i] = -1;
            dist[i] = -1;
        }

        queue<int> q;
        visited[start] = true;
        dist[start] = 0;

        list<int>::iterator it;
        q.push(start);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (it = adj[curr].begin(); it != adj[curr].end(); it++)
            {
                int index = *it;
                if (!visited[index])
                {
                    visited[index] = true;
                    q.push(index);
                    dist[index] = dist[curr] + 1;
                    pred[index] = curr;
                }
            }
        }

        for (int i = 0; i < v; i++)
        {
            cout << dist[i] << " " << pred[i] << endl;
        }
    }
};

int main()
{
    Graph g1(8);

    g1.addEdge(0, 1);
    g1.addEdge(0, 3);
    g1.addEdge(1, 2);
    g1.addEdge(3, 4);
    g1.addEdge(3, 7);
    g1.addEdge(4, 5);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(6, 7);

    g1.showGraph();

    g1.BFS(0);
}