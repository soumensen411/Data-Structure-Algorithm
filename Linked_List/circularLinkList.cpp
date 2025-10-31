#include <bits/stdc++.h>
using namespace std;

// ============== singly circular linked list ==============

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
class singlyCircularLinkedList
{
public:
    Node *head;
    Node *tail;
    singlyCircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~singlyCircularLinkedList(){
        if(head == nullptr) return;
        Node *current = head->next;
        while(current != head){
            Node *tmp = current;
            current = current->next;
            delete tmp;
        }
        delete head;
        head = tail = nullptr;
        
    }
    // insert at head
    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    // insert at tail
    void insertAtTail(int value)
    {
        Node *newNode = new Node(value);
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    // insert at given position
    void insertAtPos(int pos, int value)
    {
        if (pos <= 0)
        {
            cout << "Invalid position\n";
            return;
        }
        if (head == nullptr)
        {
            if (pos == 1)
            {
                insertAtHead(value);
            }
            else
            {
                cout << "Position out of bounds\n";
            }
            return;
        }
        if (pos == 1)
        {
            insertAtHead(value);
            return;
        }
        else
        {
            int index = 1;
            Node *current = head;
            while (index < pos - 1 && current->next != head)
            {
                current = current->next;
                index++;
            }
            if (current->next == head && index < pos - 1)
            {
                cout << "Position out of bounds\n";
                return;
            }
            Node *newNode = new Node(value);
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == head)
            {
                tail = newNode;
            }
        }
    }

    // delete node at any position

    void deleteNode(int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid Position\n";
            return;
        }
        // if list is empty
        if (head == nullptr)
        {
            cout << "List is Empty\n";
            return;
        }
        // deleting the first node
        if (pos == 1)
        {
            Node *current = head;
            // if only one node exists
            if (head == tail)
            {
                delete head;
                head = tail = nullptr;
                return;
            }
            else
            {
                head = head->next;
                tail->next = head;
                current->next = nullptr;
                delete current;
            }
        }
        else
        {
            int index = 1;
            Node *current = head;
            Node *toDelete;
            while (index < pos - 1 && current->next != head)
            {
                current = current->next;
                index++;
            }
            if (current->next == head)
            {
                cout << "position out of range\n";
                return;
            }
            toDelete = current->next;
            current->next = toDelete->next;
            if (toDelete == tail)
            {
                tail = current;
            }

            delete toDelete;
        }
    }

    // traversal the whole list
    void printCircularList()
    {
        if(head == nullptr){
            cout<<"List is empty\n";
            return;
        }
        Node *current = head;
        do
        {
            cout << current->value << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // print the head and tail value
    void printHeadAndTail()
    {
        if (head == nullptr)
            cout << "List is empty\n";
        else
        {
            cout << "Head: " << head->value << " Tail: " << tail->value << endl;
        }
    }
};

// ============== doubly circular linked list ==============

class doublyNode
{
public:
    int value;
    doublyNode *next;
    doublyNode *previous;
    doublyNode(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->previous = nullptr;
    }
};
class doublyCircularLinkedList
{
    doublyNode *head;
    doublyNode *tail;

public:
    // constractor

    doublyCircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~doublyCircularLinkedList(){
        if(head == nullptr) return;
        doublyNode *current = head;
        do{
            doublyNode *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        while (current != head);
        head = tail = nullptr;
        
    }
    // insert value at head

    void insertAtHead(int value)
    {
        doublyNode *newNode = new doublyNode(value);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
            head->previous = tail;
        }
        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
            tail->next = head;
            head->previous = tail;
        }
    }
    // insert at tail
    void insertAtTail(int value)
    {
        doublyNode *newNode = new doublyNode(value);
        if (tail == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
            tail->previous = head;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            newNode->next = head;
            head->previous = newNode;
            tail = newNode;
        }
    }

    // insert at given position
    void insertAtpos(int pos, int value)
    {
        if (pos <= 0)
        {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 1)
        {
            insertAtHead(value);
            return;
        }
        else
        {
            int index = 1;
            doublyNode *current = head;
            while (index < pos - 1 && current->next != head)
            {
                current = current->next;
                index++;
            }
            if (current->next == head && index < pos - 1)
            {
                cout << "Position out of the bounds\n";
                return;
            }
            if (current == tail)
            {
                insertAtTail(value);
                return;
            }
            else
            {
                doublyNode *newNode = new doublyNode(value);
                newNode->next = current->next;
                newNode->previous = current;
                current->next->previous = newNode;
                current->next = newNode;
            }
        }
    }

    // delete the value at given position
    void deleteNode(int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid position\n";
            return;
        }
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        if (pos == 1)
        {
            doublyNode *toDelete = head;
            head = head->next;
            head->previous = tail;
            tail->next = head;
            delete toDelete;
            return;
        }
        int index = 1;
        doublyNode *current = head;
        while (index < pos - 1 && current->next != head)
        {
            current = current->next;
            index++;
        }
        if (current->next == head)
        {
            cout << "Position out of bounds\n";
            return;
        }
        if (current->next == tail)
        {
            doublyNode *toDelete = tail;
            tail = tail->previous;
            tail->next = head;
            head->previous = tail;
            delete toDelete;
            return;
        }
        doublyNode *toDelete = current->next;
        current->next = toDelete->next;
        toDelete->next->previous = current;
        toDelete->next = nullptr;
        toDelete->previous = nullptr;
        delete toDelete;
    }

    void printDCListForward()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        doublyNode *current = head;
        do
        {
            cout << current->value << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
    void printDCListReverse()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        doublyNode *current = tail;
        do
        {
            cout << current->value << " ";
            current = current->previous;
        } while (current != tail);
        cout << endl;
    }
    void printHeadAndTail()
    {
        if (head == nullptr)
        {
            cout << "List is Empty\n";
            return;
        }
        else
        {
            cout << "Head : " << head->value << " Tail : " << tail->value << endl;
        }
    }
};

void singlyCircularListOperations()
{
    cout<<"\tSingly Cicular Linked List\n";
    cout << "------------------------------------\n";
    singlyCircularLinkedList list;
    list.insertAtHead(5);
    list.insertAtHead(25);
    list.insertAtHead(50);
    list.insertAtTail(15);
    list.insertAtTail(150);
    list.printCircularList();
    list.printHeadAndTail();
    list.deleteNode(5);
    list.printCircularList();
    list.printHeadAndTail();
}

void doublyCircularListOperations()
{
    cout<<"\tDoubly Cicular Linked List\n";
    cout << "-----------------------------------\n";
    doublyCircularLinkedList list;
    list.insertAtHead(50);
    list.insertAtHead(60);
    list.insertAtHead(70);
    list.insertAtTail(90);
    list.insertAtTail(10);
    list.insertAtpos(1, 100);
    list.printDCListForward();
    list.printDCListReverse();
    list.printHeadAndTail();
    list.printDCListForward();
    list.deleteNode(6);
    list.printDCListForward();
    list.printHeadAndTail();
}

int main()
{
    freopen("output.txt","w",stdout);
    
    singlyCircularListOperations();
    cout << "\n==================================\n\n";
    doublyCircularListOperations();
    return 0;
}
