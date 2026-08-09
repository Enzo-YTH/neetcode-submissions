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
        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp_ptr->next = list1;
                temp_ptr = list1;
                list1 = list1->next;
            }
            else {
                temp_ptr->next = list2;
                temp_ptr = list2;
                list2 = list2->next;
            }
        }
        temp_ptr->next = (list1 == nullptr) ? list2 : list1;
        return temp.next;
    }
};
