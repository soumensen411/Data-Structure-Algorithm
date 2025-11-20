#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int newVertices;
    list<int> *adjList;

public:
    Graph(int vertices)
    {
        this->newVertices = vertices;
        adjList = new list<int>[vertices+1];
    }
    void addEdges(int u, int v)
    {
        if (u == v)
        {
            adjList[u].push_back(v);
        }
        else
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    // bfs traversal
    void bfs()
    {
        queue<int> q;
        q.push(1);
        vector<bool> visited(newVertices, false);
        visited[1] = true;
        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (auto v : adjList[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void printList()
    {
        for (int i = 1; i <= newVertices; i++)
        {
            cout << i << " : ";
            for (int height : adjList[i])
            {
                cout << height << " ";
            }
            cout << endl;
        }
    }
};

void graphOperations()
{
    int numVertices;
    cin >> numVertices;
    Graph g(numVertices);
    int from, to;
    while (cin >> from >> to)
    {
        g.addEdges(from, to);
    }
    g.printList();
    g.bfs();
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    graphOperations();
}