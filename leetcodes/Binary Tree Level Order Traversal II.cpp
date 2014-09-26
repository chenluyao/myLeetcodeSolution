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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        vector<vector<int> > result;
        if(root == NULL)
        {
            return result;
        }
        queue<TreeNode *> readQ;
        queue<TreeNode *> writeQ;
        vector<int> level;
        readQ.push(root);
        
        
        while(readQ.size()!= 0)
        {
            while(readQ.size()!= 0)//a level not end
            {
                TreeNode * node = readQ.front();
                readQ.pop();
                level.push_back(node->val);
                if(node -> left!= NULL)
                {
                    writeQ.push(node->left);
                }
                if(node->right != NULL)
                {
                    writeQ.push(node->right);
                }
            }
            
            result.push_back(level);
            level.clear();
            
            readQ.swap(writeQ);
            
        }
        vector<vector<int> > result2;
        vector<vector<int> > ::reverse_iterator iter;
        for(iter = result.rbegin(); iter != result.rend(); iter++)
        {
            result2.push_back(*iter);
            
        }
        return result2;
    
    }
};