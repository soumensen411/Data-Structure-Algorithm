#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        int pos = 1;
        ListNode *temp = head;
        ListNode *before = nullptr;
        while(pos < left){
            before = temp;
            temp=temp->next;
            pos++;
        }
        int times = right - left + 1;
        ListNode *curr = temp;
        ListNode *prev = nullptr;
        while(times--){
            ListNode *nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        if(before)
        before->next = prev;
        else{
            head = prev;
        }
        temp->next = curr;
        return head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    int left = 2;
    int right = 4;

    Solution s;
    ListNode* result = s.reverseBetween(head, left, right);

    cout << "List after reversing from " << left << " to " << right << ": ";
    printList(result);

    // Clean up memory
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}