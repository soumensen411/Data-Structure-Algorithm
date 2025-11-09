#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;
    
    Node(int value, int pri) : data(value), priority(pri), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* front;
    int size;

public:
    PriorityQueue() : front(nullptr), size(0) {}
    
    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    
    // Insert element with priority (sorted insertion)
    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);
        
        // Case 1: Empty queue or new node has highest priority
        if (isEmpty() || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } 
        // Case 2: Insert in middle or end (find correct position)
        else {
            Node* current = front;
            
            // Traverse to find insertion point
            while (current->next != nullptr && 
                   current->next->priority >= priority) {
                current = current->next;
            }
            
            newNode->next = current->next;
            current->next = newNode;
        }
        
        size++;
    }
    
    // Remove highest priority element
    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
    }
    
    // Get highest priority element without removing
    int peek() const {
        if (isEmpty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return front->data;
    }
    
    // Get highest priority value
    int peekPriority() const {
        if (isEmpty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return front->priority;
    }
    
    bool isEmpty() const {
        return front == nullptr;
    }
    
    int getSize() const {
        return size;
    }
    
    // Display all elements with priorities
    void display() const {
        if (isEmpty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        
        cout << "Priority Queue (Data:Priority):\n";
        Node* temp = front;
        while (temp != nullptr) {
            cout << "[" << temp->data << ":" << temp->priority << "] ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Real-world example: Hospital Emergency Room
void hospitalERSimulation() {
    PriorityQueue er;
    
    cout << "=== Hospital Emergency Room Simulation ===\n\n";
    
    // Patient arrivals (PatientID, Priority)
    // Priority: 10=Critical, 5=Urgent, 1=Minor
    cout << "Patients arriving:\n";
    er.enqueue(101, 5);  // Patient 101: Urgent
    cout << "Patient 101 - Urgent (Priority 5)\n";
    
    er.enqueue(102, 1);  // Patient 102: Minor injury
    cout << "Patient 102 - Minor (Priority 1)\n";
    
    er.enqueue(103, 10); // Patient 103: Critical
    cout << "Patient 103 - CRITICAL (Priority 10)\n";
    
    er.enqueue(104, 5);  // Patient 104: Urgent
    cout << "Patient 104 - Urgent (Priority 5)\n";
    
    er.enqueue(105, 3);  // Patient 105: Moderate
    cout << "Patient 105 - Moderate (Priority 3)\n";
    
    cout << "\n";
    er.display();
    
    cout << "\nTreating patients in priority order:\n";
    while (!er.isEmpty()) {
        int patientID = er.peek();
        int priority = er.peekPriority();
        cout << "Treating Patient " << patientID 
             << " (Priority: " << priority << ")\n";
        er.dequeue();
    }
}

// Real-world example: CPU Task Scheduling
void cpuSchedulingSimulation() {
    PriorityQueue cpu;
    
    cout << "\n\n=== CPU Task Scheduling Simulation ===\n\n";
    
    cout << "Tasks arriving:\n";
    cpu.enqueue(1, 3);   // Task 1: Normal priority
    cout << "Task 1 - Normal (Priority 3)\n";
    
    cpu.enqueue(2, 8);   // Task 2: High priority
    cout << "Task 2 - High (Priority 8)\n";
    
    cpu.enqueue(3, 1);   // Task 3: Low priority
    cout << "Task 3 - Low (Priority 1)\n";
    
    cpu.enqueue(4, 10);  // Task 4: System critical
    cout << "Task 4 - CRITICAL (Priority 10)\n";
    
    cpu.enqueue(5, 5);   // Task 5: Medium priority
    cout << "Task 5 - Medium (Priority 5)\n";
    
    cout << "\n";
    cpu.display();
    
    cout << "\nExecuting tasks in priority order:\n";
    while (!cpu.isEmpty()) {
        int taskID = cpu.peek();
        int priority = cpu.peekPriority();
        cout << "Executing Task " << taskID 
             << " (Priority: " << priority << ")\n";
        cpu.dequeue();
    }
}

int main() {
    freopen("output.txt","w",stdout);
    // Basic operations demo
    cout << "=== Basic Priority Queue Operations ===\n\n";
    
    PriorityQueue pq;
    
    pq.enqueue(10, 2);
    pq.enqueue(20, 5);
    pq.enqueue(30, 1);
    pq.enqueue(40, 8);
    pq.enqueue(50, 3);
    
    cout << "After inserting elements:\n";
    pq.display();
    
    cout << "\nHighest priority element: " << pq.peek() 
         << " (Priority: " << pq.peekPriority() << ")\n";
    
    cout << "\nDequeuing highest priority element...\n";
    pq.dequeue();
    pq.display();
    
    cout << "Size: " << pq.getSize() << "\n";
    
    // Real-world simulations
    hospitalERSimulation();
    cpuSchedulingSimulation();
    
    return 0;
}