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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int carry = 0;
        ListNode * cur1 = l1;
        ListNode * cur2 = l2;
        ListNode * head = new ListNode(-1);
        ListNode * cur = head;
        while(cur1 != NULL || cur2 != NULL)
        {
            int d = 0;
            if(cur1 != NULL)
            {
                d += cur1->val;
                cur1 = cur1->next;
            }
            if(cur2 != NULL)
            {
                d += cur2->val;
                cur2 = cur2->next;
            }
            d += carry;
            carry = d / 10;
            cur->next = new ListNode(d % 10);
            cur = cur->next;
        }
        if(carry == 1)
        {
            cur -> next = new ListNode(1);
        }
        
        ListNode * result = head->next;
        delete head;
        return result;
    }
};