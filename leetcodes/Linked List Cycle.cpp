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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL)
        {
            return false;
        }
        ListNode * ptr1 = head->next;
        ListNode * ptr2 = head;
        
        while(ptr1 != NULL && ptr2 != NULL && ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            if(ptr1 == NULL)
            {
                break;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(ptr1 == NULL || ptr2 == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
};