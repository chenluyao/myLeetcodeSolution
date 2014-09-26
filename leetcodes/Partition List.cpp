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
    ListNode *partition(ListNode *head, int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL)
        {
            return NULL;
        }
        ListNode * firstPartHead = new ListNode(-1);
        ListNode * secondPartHead = new ListNode(-2);
        ListNode * cur = head;
        ListNode * firstCur = firstPartHead;
        ListNode * secondCur = secondPartHead;
        while(cur!= NULL)
        {
            if(cur->val < x)
            {
                firstCur -> next = cur;
                firstCur = firstCur -> next;
            }
            else
            {
                secondCur -> next = cur;
                secondCur = secondCur -> next;
            }
            cur = cur -> next;
        }
        firstCur -> next = secondPartHead -> next;
        secondCur -> next = NULL;
        ListNode * h = firstPartHead -> next;
        delete firstPartHead;
        delete secondPartHead;
        return h;
    }
};