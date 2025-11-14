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
        if(u == v){
        adjList[u].push_back(v);

        }
        else{
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        }
    }

    // bfs traversal
    void bfs(){
        queue<int>q;
        q.push(0);
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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int numVertices;
    cin>>numVertices;
    Graph g(numVertices);
    int from ,to;
    while(cin>>from>>to){
    g.addEdges(from,to);
    }
    g.printList();
}