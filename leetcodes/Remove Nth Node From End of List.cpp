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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL)
        {
            return NULL;
        }
        if(n <= 0)
        {
            return head;
        }
        ListNode * fakeHead = new ListNode(-1);
        fakeHead->next = head;
        ListNode * ptr1 = fakeHead;
        ListNode * ptr2 = fakeHead;
        while(n > 0 && ptr2->next != NULL)
        {
            ptr2 = ptr2->next;
            --n;
        }
        if(n == 0)//can be ptr2->next == NULL
        {
            while(ptr2 ->next!= NULL)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            ListNode * temp = ptr1->next;
            ptr1->next = temp->next;
            delete temp;
        }
        else// n too large
        {
            
        }
        ListNode * result = fakeHead->next;
        delete fakeHead;
        return result;
    }
};