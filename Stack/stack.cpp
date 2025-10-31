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
class Stack
{
public:
    Node *topNode;
    int count;
    Stack()
    {
        topNode = nullptr;
        count = 0;
    }
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    void pop()
    {
        if (topNode == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }
    int peek()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty\n");
        }
        return topNode->value;
    }
    bool isEmpty()
    {
        return topNode == nullptr;
    }
    int size()
    {
        return count;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "\tstack elements" << endl;
        cout << "\t---------------\n";
        Node *temp = topNode;
        while (temp != nullptr)
        {
            cout << temp->value;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};
void solve()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top Element: " << st.peek() << endl;
    cout << "Size : " << st.size() << endl;

    st.display();

    st.pop();
    cout << "After pop " << endl;
    st.display();

    cout << "Is empty? " << (st.isEmpty() ? "Yes" : "NO") << endl;

    st.push(50);
    st.push(100);

    st.display();
}
int main()
{
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}