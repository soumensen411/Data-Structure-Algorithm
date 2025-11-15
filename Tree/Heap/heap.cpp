#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    int size;
    vector<int> v;

    Heap()
    {
        size = 0;
    }

    void insert(int value)
    {
        size++;
        v.push_back(value);
        int index = v.size() - 1;
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;

            if (v[index] > v[parentIndex])
            {
                swap(v[index], v[(index - 1) / 2]);
                index = parentIndex;
            }
            else
                break;
        }
    }

    void deleteMax()
    {
        if (size == 0)
        {
            cout << "heap is already empty\n";
            return;
        }
        v[0] = v[size - 1];
        size--;
        v.pop_back();
        int index = 0;
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;
            if (left < size && v[left] > v[largest])
            {
                largest = left;
            }
            if (right < size && v[right] > v[largest])
            {
                largest = right;
            }
            if (largest != index)
            {
                swap(v[largest], v[index]);
                index = largest;
            }
            else
                break;
        }
    }

    void printHeap()
    {
        if (v.size() == 0)
        {
            cout << "heap is empty\n";
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};


// build max heap
void heapify(vector<int> &arr, int size, int heapifyIndx)
{
    int left = 2 * heapifyIndx + 1;
    int right = 2 * heapifyIndx + 2;
    int leargest = heapifyIndx;
    if (left < size && arr[left] > arr[leargest])
    {
        leargest = left;
    }
    if (right < size && arr[right] > arr[leargest])
    {
        leargest = right;
    }
    if (leargest != heapifyIndx)
    {
        swap(arr[leargest], arr[heapifyIndx]);
        heapify(arr, size, leargest);
    }
}

// build min heap
void Minheapify(vector<int> &arr, int size, int heapifyIndx)
{
    int left = 2 * heapifyIndx + 1;
    int right = 2 * heapifyIndx + 2;
    int smallest = heapifyIndx;
    if (left < size && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right < size && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != heapifyIndx)
    {
        swap(arr[smallest], arr[heapifyIndx]);
        Minheapify(arr, size, smallest);
    }
}

void display(vector<int> v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << "\n\n";
}

int main()
{
    freopen("output.txt", "w", stdout);
    Heap h;
cout << "-----------------------------------------------\n";
cout<<"|\tInsert value and Delete value from heap   |\n";
cout << "-----------------------------------------------\n";

    //  ----------------  Heap insert and delete ---------------
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(20);
    h.insert(10);
    h.insert(35);
    h.insert(45);
    h.printHeap();
    h.deleteMax();
    h.printHeap();
    h.deleteMax();
    h.printHeap();
    h.deleteMax();
    h.printHeap();
    cout<<"\n\n";

    // heapify

    vector<int> v = {54, 53, 55, 52, 50};
    int n = v.size();

    // --------------------- Max heap ----------------------
    cout << "-----------------------\n";
    cout << "|\tBefore heapify:   |\n";
    cout << "-----------------------\n";
    cout<<"\t";
    display(v);

    for (int i = n / 2; i >= 0; i--)
    {
        heapify(v, n, i);
    }

    cout << "----------------------\n";
    cout << "|\tAfter heapify:   |\n";
    cout << "----------------------\n";
    cout<<"\t";display(v);

    // ---------------------Min heap ----------------------
    cout << "--------------------------\n";
    cout << "|\tBefore Min heapify:   |\n";
    cout << "--------------------------\n";
    cout<<"\t";
    display(v);

    for (int i = n / 2; i >= 0; i--)
    {
        Minheapify(v, n, i);
    }

    cout << "-----------------------\n";
    cout << "|\tAfter heapify:   |\n";
    cout << "-----------------------\n";
    cout<<"\t";display(v);
}