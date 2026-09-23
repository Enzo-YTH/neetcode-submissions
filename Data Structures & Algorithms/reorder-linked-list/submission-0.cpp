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

        // 1. walk to the middle node
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. divide two list
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *prev = NULL;
        ListNode *cur = second;
        ListNode *next;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        second = prev;
        ListNode *first = head;
        // 3. combine two list interleavely
        while (second) {
            // 1. save nodes
            ListNode *fnext = first->next;
            ListNode *snext = second->next;

            // 2. concate
            first->next = second;
            second->next = fnext;

            // 3. move
            first = fnext;
            second = snext;
        }

        //return head;
        
    }
};
