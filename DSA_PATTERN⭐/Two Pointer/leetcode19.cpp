// 19. Remove Nth Node From End of List

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        ListNode *current = head;
        int count = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        if (count == n)
        {
            return head->next;
        }
        ListNode *prev = head;
        int i = 0;
        while (i < count - n - 1)
        {
            prev = prev->next;
            i++;
        }
        ListNode *toDelete = prev->next;
        prev->next = toDelete->next;
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode *newHead = s.removeNthFromEnd(head, 2);
    while (newHead != nullptr)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    return 0;
}