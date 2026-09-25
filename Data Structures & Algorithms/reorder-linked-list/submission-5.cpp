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
        
        // 1. find middle node
        // 0, 1, 2, 3, 4
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. revert second list
        ListNode *second = slow->next;
        slow->next = nullptr;
        //ListNode *first = head;
        ListNode *prev = nullptr;
        ListNode *cur = second;
        
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // 3. combine two list
        ListNode *first = head;
        second = prev;
        // 0, 1, 2, 3, 4
        while (second) {
            ListNode *first_next = first->next;
            ListNode *second_next = second->next;
            first->next = second;
            second->next = first_next;
            first = first_next;
            second = second_next;
        }
    }
};
