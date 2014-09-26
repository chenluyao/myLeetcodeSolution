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
        fakeHead -> next = head;
        ListNode * pre = fakeHead;
        ListNode * cur = head;
        set<int> saveNode;
        ListNode * save;
        while( cur != NULL)
        {
            
            int valN = cur->val;
            if(saveNode.find(valN) == saveNode.end())
            {
                saveNode.insert(valN);
                pre->next = cur;
                pre = pre->next;
            }
            else
            {
                
            }
            cur = cur->next;
            
        }
        pre->next = NULL;
        return fakeHead->next;
        
    }
};