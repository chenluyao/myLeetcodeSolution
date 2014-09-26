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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL)
        {
            return NULL;
        }
        ListNode * fakeHead = new ListNode(-1);
        fakeHead -> next = head;
        ListNode * insertPos = fakeHead;
        ListNode * readPos;
        ListNode * markPos;
        for(;insertPos->next != NULL && insertPos->next->next != NULL; insertPos = insertPos->next)
        {
            markPos = insertPos;
            readPos = insertPos->next;
            for(;readPos -> next != NULL; readPos = readPos -> next)
            {
                if(readPos -> next->val < markPos -> next -> val)
                {
                    markPos = readPos;
                }
            }
            if(markPos != insertPos)
            {
                
                ListNode * mark = markPos -> next;
                ListNode * insert = insertPos -> next;
                ListNode * markNext = markPos -> next->next;
                ListNode * insertNext = insertPos -> next->next;
                insertPos -> next = mark;
                insert->next = markNext;
                if(mark != insertNext)
                {
                    mark -> next = insertNext;
                    markPos->next = insert;
                }
                else
                {
                    mark->next = insert;
                }
                
                
            }
            
        }
        ListNode * newHead = fakeHead->next;
        
        delete fakeHead;
        return newHead;
    }
};