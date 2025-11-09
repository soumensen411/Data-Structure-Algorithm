#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};
class circularQueue
{
    Node *front;
    Node *rear;
    int size;

public:
    circularQueue()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }
    ~circularQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (front == nullptr)
        {
            front = newNode;
        }
        else
        {
            rear->next = newNode;
        }
        rear = newNode;
        rear->next = front;
        size++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        Node *temp = front;
        if (front == rear)
        {
            front = rear = nullptr;
        }
        else
        {
            front = front->next;
        }
        delete temp;
        if (!isEmpty())
        {
            rear->next = front;
        }
        size--;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    int getSize()
    {
        return size;
    }
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        else
        {
            return front->value;
        }
    }
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        else
        {
            return rear->value;
        }
    }
    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }
        Node *temp = front;
        do
        {
            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};
void circularQueueOperations()
{
    circularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);

    cq.display();
    cout << "Front Value: " << cq.getFront() << endl;
    cout << "rear Value: " << cq.getRear() << endl;
    cout << "Size: " << cq.getSize() << endl;
    cq.dequeue();
    cq.display();
    cout << "Size: " << cq.getSize() << endl;

    cout << "Front Value: " << cq.getFront() << endl;
    cout << "rear Value: " << cq.getRear() << endl;

    cout << "is empty: " << (cq.isEmpty() ? "Yes" : "No") << endl;

    cq.dequeue();
    cq.dequeue();
    cq.display();
    cout << "is empty: " << (cq.isEmpty() ? "Yes" : "No") << endl;
}
int main()
{
    freopen("output.txt", "w", stdout);
    circularQueueOperations();
}