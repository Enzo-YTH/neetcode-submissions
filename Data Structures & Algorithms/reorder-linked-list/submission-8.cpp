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
        ListNode* slow = head;
        ListNode* fast = head->next;
        // [1, 2, 3, 4]
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;
        // 2. reverse second list
        ListNode* prev = nullptr;
        ListNode* cur = second;

        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        second = prev;
        ListNode* first = head;
        // 3. combine 2 lists
        while (second) {
            ListNode* second_next = second->next;
            ListNode* first_next = first->next;
            first->next = second;
            second->next = first_next;
            first = first_next;
            second = second_next;
        }
    }
};
