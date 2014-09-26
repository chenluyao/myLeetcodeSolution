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
    
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //merge sort
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        int len = 0;
        ListNode *ptr = head;
        while(ptr != NULL)
        {
            ++len;
            ptr = ptr->next;
        }
        int half= len/2-1;
        ListNode *second;
        for(second = head; half > 0;)
        {
            second = second->next;
            --half;
        }
        ListNode *secondHead = second->next;
        second->next = NULL;
        ListNode *firstPart = sortList(head);
        ListNode *secondPart = sortList(secondHead);
        
        ptr = NULL;
        ListNode *newHead = NULL;
        for(;firstPart != NULL && secondPart != NULL;)
        {
            ListNode *chose;
            if(firstPart->val < secondPart->val)
            {
                chose = firstPart;
                firstPart = firstPart->next;
            }
            else
            {
                chose = secondPart;
                secondPart = secondPart->next;
            }
            
            if(newHead == NULL)
            {
                ptr = newHead = chose;
            }
            else
            {
                ptr = ptr->next = chose;                    
            }
        }
        if(firstPart != NULL)
        {
            ptr->next = firstPart;
        }
        if(secondPart != NULL)
        {
            ptr->next = secondPart;
        }
        return newHead;
    }
};