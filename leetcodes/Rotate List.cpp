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
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // k may >= n
        if(head == NULL)
        {
            return NULL;
        }
        if(k == 0)
        {
            return head;
        }
        ListNode * fakeHead = new ListNode(-1);
        ListNode * cur = head;
        int len = 0;
        while(cur != NULL)
        {
            cur = cur->next;
            len ++;
        }
        int kk = k % len;
        if(kk == 0)
        {
            return head;
        }
        fakeHead -> next = head;
        ListNode * point1;
        ListNode * point2;
        point2 = head;
        int count = 1;//asumption kk >= 1
        point1 = fakeHead;
        while(count < kk && point2->next != NULL)
        {
            point2 = point2->next;
            count++;
        }
        while(point2 -> next != NULL)
        {
            point1 = point1 -> next;
            point2 = point2 -> next;
        }
        if(point1 == fakeHead)
        {
            return head;
        }
        else
        {
            fakeHead -> next = point1 -> next;
            point2 -> next = head;
            point1 -> next = NULL;
            return fakeHead -> next;
        }
    }
};