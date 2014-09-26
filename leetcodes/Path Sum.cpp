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
    bool hasPathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL)
        {
            return false;
        }
        
        bool find = false;
        if(root->left != NULL || root->right != NULL)
        {
            if(root->left != NULL)
            {
                if(hasPathSum(root->left,sum-root->val))
                {
                    find = true;
                }
            }
            if(root->right != NULL)
            {
                if(hasPathSum(root->right,sum-root->val))
                {
                    find = true;
                }
            }
        }
        else
        {
            return (root->val == sum);
        }
        return find;
    }
};