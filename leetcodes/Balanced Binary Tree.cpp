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
    int height(TreeNode * root)
    {
        int d1;
        int d2;
        if(root == NULL)
        {
            return 0;
        }
        
            d1 = height(root->left);
            d2 = height(root->right);
            if(d1 > d2)
            {
                return d1+1;
            }
            else
            {
                return d2+1;
            }
       
    }
    int abs(int n)
    {
        return n>0?n:0-n;
    }
    bool isBalanced(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL)
        {
            return true;
        }
        bool result = isBalanced(root->left) && isBalanced(root->right);
        if(result == false)
        {
            return false;
        }
        int r = height(root->left) - height(root->right);
        return  abs(r) <=1;
    }
};