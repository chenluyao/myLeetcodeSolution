/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        RandomListNode * copy;
        map<RandomListNode *, RandomListNode *> mapT;
        if(head == NULL)
        {
            return NULL;
        }
        RandomListNode * currentO;
        RandomListNode * currentC;
        copy = new RandomListNode(INT_MIN);
        currentO = head;
        currentC = copy;
        while(currentO != NULL)
        {
            //RandomListNode * currentON = currentO -> next;
            int val = currentO -> label;
            currentC -> label = val;
            if(currentO -> next != NULL)
            {
                RandomListNode * copyN = new RandomListNode(INT_MIN);
                currentC -> next = copyN;
                
            }
            else
            {
                
            }
            mapT[currentO]=currentC;//!!!
            currentC -> random = currentO; //!!!
            //currentO = currentON;
            currentO = currentO -> next;
            currentC = currentC -> next;
        }
        
        currentO = head;
        currentC = copy;
        while(currentC != NULL)
        {
            if(currentC->random -> random == NULL)
            {
                currentC->random = NULL;//
            }
            else
            {
                currentC -> random = mapT[currentC ->random -> random] ;///////!!!NULL
            }
            currentC = currentC -> next;
        }
        return copy;
    }
};