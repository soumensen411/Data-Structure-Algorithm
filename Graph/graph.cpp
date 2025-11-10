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
        adjList = new list<int>[vertices];
    }
    void addEdges(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void printList()
    {
        for (int i = 0; i < newVertices; i++)
        {
            cout << i << " : ";
            for (int height : adjList[i]){
                cout << height<<" ";
        }
        cout << endl;
    }
}
};
int main()
{
    freopen("output.txt","w",stdout);
    Graph g(5);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(1,3);
    g.addEdges(2,3);
    g.addEdges(2,4);
    g.printList();
}