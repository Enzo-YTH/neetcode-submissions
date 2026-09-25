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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return {};

        ListNode *slow = head;
        ListNode *fast = head;
        //n -= 1;
        // 0, 1, 2, 3, 4, 5
        while (fast) {
            if (n > -1) {
                n -= 1;
            }
            else {
                slow = slow->next;
            }
            fast = fast->next;
        }
        if (slow == head && n == 0) {
            return head->next;
        }
        else {
            slow->next = slow->next->next;
            return head;
        }

    }
};
