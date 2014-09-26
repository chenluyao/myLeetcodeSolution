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
    TreeNode * preorder(TreeNode * root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        TreeNode * leftT = preorder(root->left);
        TreeNode * rightT = preorder(root->right);
        root->left = NULL;
        
        TreeNode * current = root;
        if(leftT!=NULL)
        {
            current->right = leftT;
            
            while(current -> right != NULL)
            {
                current = current -> right;
            }
        }
        if(rightT != NULL)
        {
            current->right = rightT;
        }
        return root;
    }
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL)
        {
            return;
        }
        TreeNode * leftT = preorder(root->left);
        TreeNode * rightT = preorder(root->right);
        root->left = NULL;
        TreeNode * current = root;
        if(leftT!=NULL)
        {
            current->right = leftT;
            
            while(current -> right != NULL)
            {
                current = current -> right;
            }
        }
        if(rightT != NULL)
        {
            current->right = rightT;
        }
        
    }
};