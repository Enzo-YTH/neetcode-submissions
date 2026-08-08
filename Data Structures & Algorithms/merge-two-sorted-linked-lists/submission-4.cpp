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
        ListNode* temp = new ListNode();
        ListNode* temp_ptr = temp;
        ListNode* list1_ptr = list1;
        ListNode* list2_ptr = list2;
        while (list1_ptr && list2_ptr) {
            if (list1_ptr->val < list2_ptr->val) {
                temp->next = list1_ptr;
                temp = list1_ptr;
                list1_ptr = list1_ptr->next;
            }
            else {
                temp->next = list2_ptr;
                temp = list2_ptr;
                list2_ptr = list2_ptr->next;
            }
        }
        temp->next = (list1_ptr == nullptr) ? list2_ptr : list1_ptr;
        return temp_ptr->next;
    }
};
