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
        
        // 1. find the middle of list
        ListNode *slow = head;
        ListNode *fast = head->next;
        // 0, 1,   2,3
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. reverse second list
        ListNode *prev = nullptr;
        ListNode *cur = slow->next;
        slow->next = nullptr;  //important

        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // 3. merge two lists
        ListNode *first = head;
        ListNode *second = prev;
        while (second) {
            // 1. save next nodes
            ListNode *first_next = first->next;
            ListNode *second_next = second->next;

            // 2. linking
            first->next = second;
            second->next = first_next;

            // 3. updating
            first = first_next;
            second = second_next;
        }
    }
};
