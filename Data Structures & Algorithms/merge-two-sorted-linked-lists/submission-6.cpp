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
        ListNode temp;
        ListNode* temp_ptr = &temp;
        ListNode* list1_ptr = list1;
        ListNode* list2_ptr = list2;
        while (list1_ptr && list2_ptr) {
            if (list1_ptr->val < list2_ptr->val) {
                temp_ptr->next = list1_ptr;
                temp_ptr = list1_ptr;
                list1_ptr = list1_ptr->next;
            }
            else {
                temp_ptr->next = list2_ptr;
                temp_ptr = list2_ptr;
                list2_ptr = list2_ptr->next;
            }
        }
        temp_ptr->next = (list1_ptr == nullptr) ? list2_ptr : list1_ptr;
        return temp.next;
    }
};
