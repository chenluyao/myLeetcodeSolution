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
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode * fakeHead  = new ListNode(-1);
        fakeHead -> next = head;
        ListNode * current = fakeHead;
        while(current -> next != NULL && current->next->next != NULL)
        {
            ListNode * c1 = current -> next;
            ListNode * c2 = current -> next -> next;
            ListNode * c3 = current -> next -> next -> next;
            current -> next = c2;
            c2 -> next = c1;
            c1-> next = c3;
            current = current->next->next;//or current = c1!!! already change position
        }
        ListNode * re = fakeHead -> next;
        delete []fakeHead;
        return re;
    }
};