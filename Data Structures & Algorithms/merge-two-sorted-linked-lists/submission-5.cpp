/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. Stack-allocated dummy node (no heap allocation, no memory leak)
        ListNode dummy;
        ListNode* tail = &dummy;

        // 2. Traversal loop using original pointers directly (no extra aliases)
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // 3. Clean Tail Append (attaches remaining elements in O(1))
        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};