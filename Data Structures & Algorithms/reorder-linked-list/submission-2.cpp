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
    void reorderList(ListNode* head) {

        if (!head || !head->next) return;

        // 1. Locate the middle of the list
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split the list into two halves
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        ListNode *cur = second;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        second = prev;
        ListNode *first = head;
        // 3. Interleave the two halves
        while (second) {
            // 1. Save next nodes
            ListNode *fnext = first->next;
            ListNode *snext = second->next;

            // 2. Link nodes
            first->next = second;
            second->next = fnext;

            // 3. Advance pointers
            first = fnext;
            second = snext;
        }
        
    }
};
