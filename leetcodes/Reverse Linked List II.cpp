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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL)
        {
            return NULL;
        }
        ListNode * fakeHead = new ListNode(-1);
        fakeHead -> next = head;
        ListNode * startp;
        ListNode * startn;
        ListNode * endp;
        ListNode * endn;
        ListNode * one;
        ListNode * two;
        ListNode * three;
        if(m == n)
        {
            return head;
        }
        // then must be >= 2
        one = head;
        two = one->next;
        three = two -> next;
        int count = 1;
        startp = fakeHead;
        while(count < m)
        {
            count ++;
            three = three -> next;
            two = two -> next;
            one = one -> next;
            startp = startp -> next;
        }
        //start reverse
        startn = startp->next;
        while(count < n)
        {
            two -> next = one;
            one = two;
            two = three;
            if(three != NULL)//////!
            {
                three = three->next;
            }
            count++;
        }
        endp = one;
        endn = two;
        startp -> next = endp;
        startn -> next= endn;
        return fakeHead->next;///not Head,  may change
    }
};