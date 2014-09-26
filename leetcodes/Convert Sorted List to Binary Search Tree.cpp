/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL)
        {
            return NULL;
        }
        if(head->next == NULL)
        {
            return new TreeNode(head->val);
        }
        int len = 0;
        ListNode *pCur = head;
        while(pCur!= NULL)
        {
            pCur = pCur->next;
            len++;
        }
        int middle = len/2;
        TreeNode * root;
        TreeNode * leftTree;
        TreeNode * rightTree;
        
        len = 0;
        pCur = head;
        while(len != middle-1)
        {
            len++;
            pCur = pCur->next;
        }
        ListNode * rootNode = pCur->next;
        pCur->next = NULL;
        pCur = rootNode->next;
        
        root = new TreeNode(rootNode->val);
        leftTree = sortedListToBST(head);
        rightTree = sortedListToBST(pCur);
        root->left = leftTree;
        root->right = rightTree;
        return root;
        
        
    }
};