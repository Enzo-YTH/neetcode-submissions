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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        ListNode* prev_l1 = nullptr;
        ListNode* prev_l2 = nullptr;
        ListNode* ptr = l1;
        while (l1 || l2) {
            int l1_val = (l1) ? l1->val : 0;
            int l2_val = (l2) ? l2->val : 0;
            int sum = l1_val + l2_val + carry;
            carry = sum / 10;
            if (l1) {
                l1->val = sum % 10;
                prev_l1 = l1;
                l1 = l1->next;
                if (l2) {
                    l2 = l2->next;
                    prev_l2 = l2;
                }
                else {
                    prev_l2 = nullptr;
                }
            }
            else {
                l2->val = sum % 10;
                l2 = l2->next;
            }
        }
        if (prev_l2) {
            prev_l1->next = prev_l2;
        }
        while (prev_l1->next) {
            prev_l1 = prev_l1->next;
        }
        if (carry) {
            ListNode* node = new ListNode(carry);
            prev_l1->next = node;
        }
        return ptr;
    }
};
