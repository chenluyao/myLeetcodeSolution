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
    int maxPath;
    int subMaxPath(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int maxLeft =0;
        int maxRight =0;
        if(root->left != NULL)
        {
            maxLeft = subMaxPath(root->left);
            if(maxLeft < 0)
            {
                maxLeft = 0;
            }
           
        }
        if(root->right != NULL)
        {
            maxRight = subMaxPath(root->right);
            if(maxRight < 0)
            {
                maxRight = 0;
            }
          
        }
        int path = maxLeft + root->val + maxRight;
        if(path > maxPath)
        {
            maxPath = path;
        }
        if(maxLeft > maxRight)
        {
            return maxLeft + root->val;
        }
        else
        {
            return maxRight + root->val;
        }
    }
    int maxPathSum(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        maxPath = INT_MIN;
        if(root == NULL)
        {
            return 0;
        }
        int maxLeft =0;
        int maxRight =0;
        
        if(root->left != NULL)
        {
            maxLeft = subMaxPath(root->left);
            if(maxLeft < 0)
            {
                maxLeft = 0;
            }
           
        }
        if(root->right != NULL)
        {
            maxRight = subMaxPath(root->right);
            if(maxRight < 0)
            {
                maxRight = 0;
            }
          
        }
        /*
        if(maxRight != INT_MIN || maxLeft != INT_MIN)
        {
            if(maxRight == INT_MIN)
            {
                maxRight = 0;
            }
            if(maxLeft == INT_MIN)
            {
                maxLeft = 0;
            }
        }*/
        int path = maxLeft + root->val + maxRight;
        if(path > maxPath)
        {
            maxPath = path;
        }
        return maxPath;
    }
};