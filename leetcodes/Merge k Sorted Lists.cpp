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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = lists.size();
        if(n == 0)
        {
            return NULL;
        }
        if(n == 1)
        {
            return lists[0];
        }
        vector<ListNode *> cur;
        int i;
        for(i = 0; i < n; i++)
        {
            if(lists[i] != NULL)////!!!IMPORTANT
            {
                cur.push_back(lists[i]);
            }
        }
        
        ListNode * fakeHead = new ListNode(-1);
        ListNode * insertPosition = fakeHead;
        int insertTargetIndex;
        
        while(cur.size()!= 0)
        {
            insertTargetIndex = 0;
            for(i = 1; i < cur.size(); i++)
            {
                if((cur[i])->val < cur[insertTargetIndex] -> val)
                {
                    insertTargetIndex = i;
                }
            }
            insertPosition -> next = cur[insertTargetIndex];
            insertPosition = insertPosition -> next;
            cur[insertTargetIndex] = cur[insertTargetIndex]->next;
            if(cur[insertTargetIndex] == NULL)
            {
                cur.erase(cur.begin()+insertTargetIndex);
            }
            
        }
        insertPosition->next = NULL;
        return fakeHead ->next;
    }
};