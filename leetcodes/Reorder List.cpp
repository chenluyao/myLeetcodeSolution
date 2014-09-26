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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return;
        }
        //ListNode * fakeHead = new ListNode(-1);
        //ListNode * fakeEnd = new ListNode(-2);
        int len = 0;
        //fakeHead -> next = head;
        ListNode * current = head;
        while(current!= NULL)
        {
            len++;
            current = current->next;
        }
        //len++;
        //current->next = fakeEnd;
        //len++;
        
        ListNode *ptr1 = head;
        ListNode *ptr2 = ptr1->next;
        ListNode *ptr3;
        
        int count = (len-1)/2;
        while(count > 0)
        {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
            count--;
        }
        
        ptr1->next = NULL;//!!
        
        ptr1 = NULL;
        while(ptr2!= NULL)
        {
            ptr3= ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr3;
        }
        
        
        ListNode * cur1 = head;
        ListNode * cur2 = ptr1;
        ListNode * cur1next = cur1->next;
        ListNode * cur2next = cur2->next;
        count = len/2;
        while(count > 0)
        {
            cur1next = cur1->next;//!!
            cur2next = cur2->next;
            cur1->next = cur2;
            cur2->next = cur1next;
            cur1 = cur1next;
            cur2 = cur2next;
            count--;
        }
        
        
        
    }
};