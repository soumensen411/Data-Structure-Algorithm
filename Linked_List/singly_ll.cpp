#include <bits/stdc++.h>
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

// Node class represent a single elements in the linked list

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

// linked list class with all operations
class linkedlist
{
public:
    Node *head;
    Node *tail;
    // constractor
    linkedlist()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~linkedlist() // destructor
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert at the beginning.

    void InsertAtHead(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert at the end.

    void InsertAtTail(int value) // insertion value at end
    {
        Node *newNode = new Node(value);
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            newNode->next = nullptr;
        }
    }

    // Insert at the specific position.
    void InsertAtPosition(int pos, int value)
    {
        if (pos <= 0)
        {
            cout << "Invalid Position";
            return;
        }
        if (pos == 1)
        {
            InsertAtHead(value);
            return;
        }
        Node *current = head;
        int index = 1;
        while (index < pos - 1 && current != nullptr)
        {
            current = current->next;
            index++;
        }
        if (current == nullptr)
        {
            cout << "Invalid Position\n";
            return;
        }
        Node *newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr)
        {
            tail = newNode;
        }
    }
    // delete at specific position.
    void deleteNode(int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid Position\n";
            return;
        }
        if (head == nullptr)
        {
            cout << "List is Empty\n";
            return;
        }
        if (pos == 1)
        {
            Node *current = head;
            head = current->next;
            if (current == tail)
            {
                tail = nullptr;
            }
            current->next = nullptr;
            delete current;
            return;
        }
        else
        {
            Node *prev = head;
            int indx = 1;
            while (indx < pos - 1 && prev != nullptr)
            {
                prev = prev->next;
                indx++;
            }
            if (prev == nullptr || prev->next == nullptr)
            {
                cout << "Position out of bound\n";
                return;
            }
            Node *current = prev->next;
            prev->next = current->next;
            if (current == tail)
            {
                tail = prev;
            }

            delete current;
        }
    }
};

// traversal into an linked list

void print(linkedlist &list)
{
    Node *current = list.head;
    if (current == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "\nHead: " << list.head->value << " Tail: " << list.tail->value << endl;
}

// Reverse the Linked List.

void reverseNode(linkedlist &List)
{
    Node *previous = nullptr;
    Node *current = List.head;
    Node *forward = nullptr;
    Node *oldHead = List.head;
    while (current != nullptr)
    {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    List.head = previous;
    List.tail = oldHead;
}

// check if list is empty or not

bool isEmpty(linkedlist &list)
{
    return list.head == nullptr;
}

// get the size of the list.

void ListSize(linkedlist &list)
{
    Node *current = list.head;
    int size = 0;
    while (current != nullptr)
    {
        current = current->next;
        size++;
    }
    cout << "Size of the list: " << size << endl;
}
//  demo function with comprehensive tests.
void DemoLinkedListOperations()
{
    linkedlist list;
    list.InsertAtHead(5);
    list.InsertAtHead(10);
    list.InsertAtHead(15);
    list.InsertAtTail(30);
    list.InsertAtPosition(3, 100);
    ListSize(list);
    print(list);
    list.deleteNode(2); // 1 based index position.
    print(list);
    ListSize(list);
    // cout << isEmpty(list) << endl;
    reverseNode(list);
    print(list);
}
int main()
{
    freopen("output.txt","w",stdout);
    DemoLinkedListOperations();
    return 0;
}
