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
    TreeNode *subBuildTree(vector<int> &preorder,int preStart, int preEnd, vector<int> &inorder,int inStart, int inEnd)
    {
        if(preEnd < preStart)
        {
            return NULL;
        }
        int rootval = preorder[preStart];
        if(preEnd == preStart)
        {
            return (new TreeNode(rootval));
        }

        
        int i;
        int pos;
        for(i = inStart; i <= inEnd; i++)
        {
            if(inorder[i] == rootval)
            {
                pos = i - inStart;
                break;
            }
        }
        TreeNode * leftNode = subBuildTree(preorder,preStart+1,preStart+pos,inorder,inStart,inStart+pos-1);
        TreeNode * rightNode = subBuildTree(preorder,preStart+pos+1,preEnd,inorder,inStart+pos+1,inEnd);
        TreeNode * root = new TreeNode(rootval);
        root->left = leftNode;
        root->right = rightNode;
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(preorder.size() != inorder.size())
        {
            return NULL;
        }
        int m = preorder.size();
        
        return subBuildTree(preorder,0,m-1,inorder,0,m-1);
        
    }
};