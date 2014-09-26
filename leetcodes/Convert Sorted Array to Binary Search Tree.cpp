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
    TreeNode *subA2B(vector<int> &num, int left,int right) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = right - left;
        if(n < 1)
        {
            return NULL;
        }
        int rootIndex ;
        if(n % 2 ==1)
        {
            rootIndex = (n-1)/2+left;
        }
        else
        {
            rootIndex = n/2+left;
        }
        
        TreeNode * tn = new TreeNode(num[rootIndex]);
        tn->left = subA2B(num,left,rootIndex);
        tn->right = subA2B(num,rootIndex+1, right);
        return tn;
        
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = num.size();
        if(n < 1)
        {
            return NULL;
        }
        int rootIndex ;
        if(n % 2 ==1)
        {
            rootIndex = (n-1)/2;
        }
        else
        {
            rootIndex = n/2;
        }
        
        TreeNode * tn = new TreeNode(num[rootIndex]);
        tn->left = subA2B(num,0,rootIndex);
        tn->right = subA2B(num,rootIndex+1, n);
        return tn;
        
    }
};