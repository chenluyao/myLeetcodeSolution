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
    void inorderTranverseTree(TreeNode *root,int &find, TreeNode *&firstError, TreeNode *&secondError, TreeNode *&currentVisit)
    {
        if(root -> left != NULL)
        {
            inorderTranverseTree(root->left,find, firstError, secondError, currentVisit);
        }
        //visit(root);
        if(currentVisit == NULL)
        {
            currentVisit = root;
        }
        else
        {
            if(root->val < currentVisit->val)
            {
                if(find == -1)
                {
                    firstError = currentVisit;
                    secondError = root;//IN CASE only one descend
                    find = 0;
                }
                else if(find == 0)
                {
                    secondError = root;
                    find = 1;
                }
            }
            currentVisit = root;
        }
        
        if(root->right != NULL)
        {
            inorderTranverseTree(root->right,find, firstError, secondError, currentVisit);
        }
    }
    void recoverTree(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //O(n) space solution
        if(root == NULL)
        {
            return;
        }
        
        int find = -1;
        TreeNode * firstError = NULL;
        TreeNode * secondError = NULL;
        TreeNode * currentVisit = NULL;
        inorderTranverseTree(root, find, firstError, secondError, currentVisit);
        int temp = secondError->val;
        secondError ->val = firstError-> val;
        firstError-> val = temp;
        
    }
};