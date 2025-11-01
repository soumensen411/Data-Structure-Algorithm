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
class Queue
{
public:
    Node *front;
    Node *rear;
    int count = 0;
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }
    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (front == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }
    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            if (front == nullptr)
                rear = nullptr;

            delete temp;
        }
        count--;
    }
    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->value;
    }
    int getrear()
    {
        if (rear == nullptr)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return rear->value;
    }
    int size()
    {
        return count;
    }
    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "\t Queue elements" << endl;
        cout << "\t---------------\n";

        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->value;
            if (temp->next != nullptr)
            {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << "\n\n";
    }
};
void queueOperations()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.peek() << endl;
    cout << "Rear element: " << q.getrear() << endl;
    cout << "Queue size: " << q.size() << endl;

    q.dequeue();
    q.display();

    q.enqueue(50);
    q.enqueue(60);
    q.display();
    
    cout << "Front element: " << q.peek() << endl;
    cout << "Rear element: " << q.getrear() << endl;
    cout << "Queue size: " << q.size() << endl;
}
int main()
{
    freopen("output.txt", "w", stdout);
    queueOperations();
    return 0;
}