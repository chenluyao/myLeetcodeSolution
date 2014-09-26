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
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL)
        {
            return true;
        }
        queue<TreeNode *> readQ;
        queue<TreeNode *> writeQ;
        vector<int> level;
        readQ.push(root);
        while(readQ.size() != 0)
        {
            while(readQ.size() != 0)
            {
                TreeNode * item = readQ.front();
                readQ.pop();
                if(item != NULL)
                {
                    writeQ.push(item -> left);
                    writeQ.push(item -> right);
                    level.push_back(item->val);
                }
                else
                {
                    level.push_back(INT_MIN);
                }
            }
            int n = level.size();
            int i,j;
            for(i = 0, j = n-1; i < j; i++, j--)
            {
                if(level[i] == level[j])
                {
                    
                }
                else
                {
                    return false;
                }
            }
            readQ.swap(writeQ);
            level.clear();/////////!!!
        }
        return true;
        
    }
};