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
        adjList = new list<int>[vertices + 1];
    }

    // insert edges into the graph
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
    void bfs(int startNode)
    {
        queue<int> q;
        q.push(startNode);
        vector<bool> visited(newVertices + 1, false);
        visited[startNode] = true;
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
        cout << endl;
    }
    // dfs traversal

    void dfsHelper(int startNode, vector<bool> &visited)
    {
        cout << startNode << " ";
        visited[startNode] = true;
        for (auto v : adjList[startNode])
        {
            if (!visited[v])
            {
                dfsHelper(v, visited);
            }
        }
    }
    void dfs(int startNode)
    {
        vector<bool> visited(newVertices + 1, false);
        dfsHelper(startNode, visited);
        cout << endl;
    }
    // print adjacency list
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
    cout << "|====== PRINT ADJACENCY LIST ======| \n";
    cout << "--------------------------------------\n";
    g.printList();

    cout << "|====== BFS TRAVERSAL ======| \n";
    cout << "-------------------------------\n";
    g.bfs(1);

    cout << "|====== DFS TRAVERSAL ======| \n";
    cout << "-------------------------------\n";
    g.dfs(1);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    graphOperations();
}