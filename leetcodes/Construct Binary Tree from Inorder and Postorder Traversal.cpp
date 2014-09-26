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
    TreeNode *subBuildTree(vector<int> &inorder, vector<int> &postorder, int inorderLeft,int inorderRight, int postorderLeft, int postorderRight)
    {
        if(inorderRight - inorderLeft < 1)
        {
            return NULL;
        }
        int rootVal = postorder[postorderRight-1];
        TreeNode * tn = new TreeNode(rootVal);
        int i;
        int delta;
        for(i = inorderLeft; i< inorderRight; i++)
        {
            if(inorder[i] == rootVal)
            {
                delta = i - inorderLeft;
                break;
            }
        }
       
        TreeNode * leftTree = subBuildTree(inorder, postorder,inorderLeft,inorderLeft+delta,postorderLeft,postorderLeft+delta);
        TreeNode * rightTree = subBuildTree(inorder, postorder,inorderLeft+delta+1,inorderRight,postorderLeft+delta,postorderRight-1);
        tn -> left = leftTree;
        tn -> right = rightTree;
        return tn;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(inorder.size() <1)
        {
            return NULL;
        }
        int rootVal = postorder[postorder.size()-1];
        TreeNode * tn = new TreeNode(rootVal);
        int i;
        int rootIndex;
        for(i = 0; i< inorder.size(); i++)
        {
            if(inorder[i] == rootVal)
            {
                rootIndex = i;
                break;
            }
        }
       
        TreeNode * leftTree = subBuildTree(inorder, postorder,0,rootIndex,0,rootIndex);
        TreeNode * rightTree = subBuildTree(inorder, postorder,rootIndex+1,inorder.size(),rootIndex,postorder.size()-1);
        tn -> left = leftTree;
        tn -> right = rightTree;
        return tn;
    }
};