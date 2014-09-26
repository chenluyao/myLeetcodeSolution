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
    int subMax(TreeNode * root, int d)
    {
        if(root == NULL)
        {
            return d;
        }
        int s1 = subMax(root->left,d+1);
        int s2 = subMax(root->right,d+1);
        return s1>s2?s1:s2;
    }
    int maxDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        return subMax(root,0);
    }
};