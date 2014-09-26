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
    vector<TreeNode *> subGenerateTrees(int start, int end)
    {
        vector<TreeNode *> result;
        if(start > end)
        {
            result.push_back(NULL);
            return result;
        }
        
        if(start == end)
        {
            result.push_back(new TreeNode(start));
            return result;
        }
        
        int i;
        int j;
        int rootval;
        vector<TreeNode *> leftResult;
        vector<TreeNode *> rightResult;
        for(rootval = start; rootval <= end; rootval++)
        {
            leftResult = subGenerateTrees(start,rootval-1);
            rightResult = subGenerateTrees(rootval+1, end);
            for(i = 0; i < leftResult.size(); i++)
                for(j = 0; j < rightResult.size(); j++)
                {
                    TreeNode * root = new TreeNode(rootval);
                    root->left = leftResult[i];
                    root->right = rightResult[j];
                    result.push_back(root);
                }
        }
        
       
        return result;
        
    }
    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<TreeNode *> result;
        vector<TreeNode *> subResult;
        
        return subGenerateTrees(1,n);
    }
};