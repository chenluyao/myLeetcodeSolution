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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode * first = head;
        ListNode * second = head;
        do
        {
            first = first -> next;
            if(first != NULL)
            {
                first = first -> next;
            }
            else
            {
                break;
            }
            second = second -> next;
        }while(first != NULL && first != second);
        if(first == NULL)
        {
            return NULL;
        }
        else// have cycle
        {
            first = head;
            while(first != second)
            {
                first = first -> next;
                second = second -> next;
            }
            return first;
        }
        
    }
};