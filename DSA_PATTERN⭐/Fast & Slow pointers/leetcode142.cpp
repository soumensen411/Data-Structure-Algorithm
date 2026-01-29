// 142. Linked List Cycle II

/* slow abong fast akber milito hole aber slow k head e point   korte hobe then
    slow abong fast duitakei akber kore agaite hobe . jokon ei duijon(slow and fast)
    abr milito hobe oi point tai hobe starting cycle point
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
int main()
{
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node0 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);
    head->next = node2;
    node2->next = node0;
    node0->next = node4;
    node4->next = node2;
    Solution s;
    ListNode *cycleStart = s.detectCycle(head);
    if (cycleStart)
    {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
    }
}