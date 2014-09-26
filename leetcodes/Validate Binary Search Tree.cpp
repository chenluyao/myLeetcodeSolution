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
    int biggest(TreeNode * root)
    {
        while(root->right != NULL)
        {
            root = root->right;
        }
        return (root-> val);
    }
    int smallest(TreeNode * root)
    {
        while(root->left != NULL)
        {
            root = root->left;
        }
        return (root-> val);
    }
    bool isValidBST(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if(root == NULL)
        {
            return true;
        }
        int valT = root->val;
        if(root->left != NULL)
        {
            if(biggest(root->left) >= valT)
            {
                return false;
            }
            if(!isValidBST(root->left))
            {
                return false;
            }
        }
        if(root->right != NULL)
        {
            if(smallest(root->right) <= valT)
            {
                return false;
            }
            if(!isValidBST(root->right))
            {
                return false;
            }
        }
       
        return true;
        
    }
};