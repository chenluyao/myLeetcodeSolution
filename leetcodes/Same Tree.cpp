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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool isSame = true;
        if(p == NULL && q == NULL)
        {
            return true;
        }
        else if(p == NULL && q != NULL || q == NULL && p!= NULL)
        {
            return false;
        }
        else
        {
            if(p->val != q-> val ||!isSameTree(p->left, q->left)||!isSameTree(p->right,q->right))
            {
                return false;
            }
            
        }
        return true;
        
    }
};