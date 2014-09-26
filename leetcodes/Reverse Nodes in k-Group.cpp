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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL || k == 1 || k == 0)
        {
            return head;
        }
        int len = 0;
        ListNode * ptr = head;
        while(ptr != NULL)
        {
            len++;
            ptr = ptr->next;
        }
        if(len < k)
        {
            return head;
        }
        ListNode * fakeHead = new ListNode(-1);
        fakeHead -> next = head;
        int times = len/k;//time >= 1
        //  ---p1 p2-----p3 p4---
        //  ---p1 p3-----p2 p4---
        ListNode * p1,*p2,*p3,*p4;
        p1 = fakeHead;
        ListNode * pre,*cur,*nex;
        pre = head;
        
        int kk;
        while(times > 0)
        {
            times--;
            kk = 1;
            cur = pre->next;
            while(kk < k)
            {
                kk++;
                nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }
            p2 = p1->next;
            p3 = pre;
            p4 = cur;
            p1->next = p3;
            p2->next = p4;
            //reset p1,pre,cur
            p1 = p2;
            pre = p4;
        }
        ListNode * newHead = fakeHead->next;
        delete fakeHead;
        return newHead;
        
    }
};