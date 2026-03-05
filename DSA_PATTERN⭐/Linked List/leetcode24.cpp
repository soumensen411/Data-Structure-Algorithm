// 24. Swap Nodes in Pairs

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
#define Node ListNode
#define null NULL
    void reverse(Node *head, int times)
    {
        Node *curr = head;
        Node *prev = null;

        while (times--)
        {
            Node *nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return;
    }

    ListNode *swapPairs(ListNode *head)
    {
        Node *left = head;
        Node *right;
        Node *prevleft = null;
        Node *res = null;
        while (true)
        {
            right = left;
            for (int i = 0; i < (2 - 1); i++)
            {
                if (right == null)
                    break;
                right = right->next;
            }
            if (right)
            {
                Node *next_left = right->next;
                reverse(left, 2);
                if (prevleft)
                    prevleft->next = right;
                prevleft = left;
                if (res == null)
                    res = right;
                left = next_left;
            }
            else
            {
                if (prevleft)
                    prevleft->next = left;
                if (res == null)
                    res = left;
                break;
            }
        }
        return res;
    }
};

// Utility function to print linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create linked list from vector
ListNode *createList(vector<int> &nums)
{
    if (nums.empty())
        return nullptr;
    ListNode *head = new ListNode(nums[0]);
    ListNode *curr = head;
    for (int i = 1; i < nums.size(); i++)
    {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

int main()
{
    Solution sol;

    // Test case 1: 1->2->3->4
    vector<int> nums1 = {1, 2, 3, 4};
    ListNode *head1 = createList(nums1);
    cout << "Original List 1: ";
    printList(head1);
    ListNode *result1 = sol.swapPairs(head1);
    cout << "After swapping pairs: ";
    printList(result1);

    cout << "\n";

    // Test case 2: 1->2->3->4->5
    vector<int> nums2 = {1, 2, 3, 4, 5};
    ListNode *head2 = createList(nums2);
    cout << "Original List 2: ";
    printList(head2);
    ListNode *result2 = sol.swapPairs(head2);
    cout << "After swapping pairs: ";
    printList(result2);

    cout << "\n";

    return 0;
}