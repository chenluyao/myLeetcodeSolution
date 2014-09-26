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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL)
        {
            return NULL;
        }
        ListNode * fakeHead = new ListNode(-1);
        fakeHead->next = head;
        map<int, int> mapL;
        ListNode * cur = head;
        ListNode * pre = fakeHead;
        while(cur != NULL)
        {
            int valL = cur->val;
            if(mapL.find(valL) != mapL.end())
            {
                mapL[valL] ++;
            }
            else
            {
                mapL[valL] = 1;
            }
            cur = cur->next;
        }
        pre  = fakeHead;
        cur = head;
        while(cur != NULL)
        {
            int valL = cur -> val;
            if(mapL[valL] == 1)
            {
                pre->next = cur;
                pre = pre -> next;
            }
            else
            {}
            cur = cur->next;
        }
        pre->next = NULL;
        return fakeHead->next;
        
    }
};