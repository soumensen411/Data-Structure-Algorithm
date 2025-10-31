#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *previous;
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->previous = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    // constractor
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // destructor
    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    // insert value at head
    void insertAtHead(int value)
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
            head->previous = newNode;
            head = newNode;
        }
    }

    // insert value at tail
    void insertAtTail(int value)
    {
        Node *newNode = new Node(value);
        if (tail == nullptr)
        {
            tail = newNode;
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    // insert value at position
    void insertAtPos(int pos, int value)
    {
        if (pos <= 0)
        {
            cout << "Invalid position\n";
            return;
        }
        else if (pos == 1)
        {
            insertAtHead(value);
            return;
        }
        else
        {
            Node *newNode = new Node(value);
            int index = 1;
            Node *current = head;
            while (index < pos - 1 && current != nullptr)
            {
                current = current->next;
                index++;
            }
            if (current == nullptr)
            {
                cout << "Position out of range\n";
                delete newNode;
                return;
            }
            if (current->next == nullptr)
            {
                current->next = newNode;
                newNode->previous = current;
                tail = newNode;
            }
            else
            {
                newNode->next = current->next;
                current->next->previous = newNode;
                current->next = newNode;
                newNode->previous = current;
            }
        }
    }

    void deleteNode(int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid Position\n";
            return;
        }
        if (head == nullptr)
        {
            cout << "List is already empty\n";
            return;
        }
        if (pos == 1)
        {
            Node *current = head;
            head = current->next;
            if (head != nullptr)
            {
                head->previous =
                    nullptr;
            }
            else
            {
                tail = nullptr;
            }
            delete current;
            return;
        }
        else
        {
            Node *current = head;
            int count = 1;
            while (count < pos - 1 && current != nullptr)
            {
                current = current->next;
                count++;
            }
            if (current == nullptr || current->next == nullptr)
            {
                cout << "Position out of bound\n";
                return;
            }
            else
            {
                Node *toDelete = current->next;
                current->next = toDelete->next;
                if (toDelete->next != nullptr)
                {
                    toDelete->next->previous = current;
                }
                else
                {
                    tail = current;
                }
                delete toDelete;
            }
        }
    }
};
void printListForward(DoublyLinkedList &list)
{
    Node *current = list.head;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}
void printListReverse(DoublyLinkedList &list)
{
    Node *current = list.tail;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->previous;
    }
    cout << endl;
}
void printHeadAndTail(DoublyLinkedList &list)
{
    if (list.head == nullptr)
    {
        cout << "List is Empty..!\n";
    }
    else
        cout << "Head: " << list.head->value << " Tail: " << list.tail->value << endl;
}
void getSize(DoublyLinkedList &list)
{
    int count = 0;
    Node *current = list.head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    cout << "Size of the list: " << count << endl;
}
bool isEmpty(DoublyLinkedList &list)
{
    return list.head == nullptr;
}
void DemoLinkedListOperations()
{
    DoublyLinkedList list;
    list.insertAtHead(40);
    list.insertAtHead(42);
    list.insertAtHead(50);
    list.insertAtTail(44);
    list.insertAtTail(70);
    list.insertAtPos(5, 100);
    getSize(list);
    printListForward(list);
    list.deleteNode(1);
    list.insertAtPos(1, 66);
    printListForward(list);
    printHeadAndTail(list);
    list.insertAtPos(6, 900);
    list.insertAtPos(8, 5222);
    printHeadAndTail(list);
    getSize(list);
    printListForward(list);
    printHeadAndTail(list);
    printListReverse(list);
    printHeadAndTail(list);
}
int main()
{
    freopen("output.txt","w",stdout);
    DemoLinkedListOperations();
    return 0;
}
