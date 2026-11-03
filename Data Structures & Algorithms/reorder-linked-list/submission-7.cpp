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
        
        if (head == nullptr || head->next == nullptr) return ;

        // 1. find middle node
        ListNode* slow = head;
        ListNode* fast = head->next;
        // [0, 1, 2, 3] => [0, 3, 1, 2]
        // [0, 1, 2, 3, 4] => [0, 3, 1, 2]
        //
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. half-half, reverse second list
        ListNode* dummy = nullptr;
        ListNode* prev = dummy;
        ListNode* cur = slow->next;
        slow->next = nullptr;  // very important to cut the list
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode* second = prev;

        // 3. merge two lists
        ListNode* first = head;
        while (second) {
            ListNode* first_next = first->next;
            ListNode* second_next = second->next;
            first->next = second;
            second->next = first_next;
            first = first_next;
            second = second_next;
        }

    }
};
