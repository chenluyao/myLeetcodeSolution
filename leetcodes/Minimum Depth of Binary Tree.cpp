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
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if(root == NULL)
        {
            return 0;
        }
        int leftD = INT_MAX;
        int rightD = INT_MAX;
        int D = INT_MAX;
        
        if(root->left != NULL || root->right !=NULL)
        {
            if(root->left != NULL)
            {
                leftD = minDepth(root->left);
                D = leftD +1;
            }
            if(root->right != NULL)
            {
                rightD = minDepth(root->right);
                if(rightD+1 < D)
                {
                    D = rightD +1;
                }
            }
        }
        if(root->left == NULL && root-> right == NULL)
        {
            D = 1;
        }
        
        return D;
    }
};