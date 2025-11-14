#include <bits/stdc++.h>
using namespace std;
class Heap{
public:
    vector<int> v;
    int size;

    Heap()
    {
        size = 0;   
    }
    void insertAtHeap(int value)
    {
        size++;
        v.push_back(value);
        int index = v.size() - 1;
        while (index > 0)
        {
            int parentIndex = (index - 1)/2;
            if (v[index] > v[parentIndex])
            {
                swap(v[index], v[(index - 1) / 2]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void printHeadElement()
    {
        for (int i = 0; i < size; i++)
        {
            cout << v[i] << " ";
        }
    }
};

int main()
{
    freopen("output.txt", "w", stdout);
    Heap h;
    h.insertAtHeap(10);
    h.insertAtHeap(20);
    h.insertAtHeap(30);
    h.insertAtHeap(5);
    h.printHeadElement();
}