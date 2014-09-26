/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if(l1 == NULL)
        {
            return l2;
        }
        else if(l2 == NULL)
        {
            return l1;
        }
        
        ListNode * mergeHead;
        if(l1->val > l2->val)
        {
            mergeHead = l2;
            mergeHead -> next = mergeTwoLists(l1,l2->next);
        }
        else
        {
            mergeHead = l1;
            mergeHead -> next = mergeTwoLists(l1->next,l2);
        }
        return mergeHead;
    }
};