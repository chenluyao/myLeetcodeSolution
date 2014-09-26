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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result;
        vector<int> line;
        vector<int> lineRev;
        if(root == NULL)
        {
            return result;
        }
        queue<TreeNode*> readQ;
        queue<TreeNode*> writeQ;
        int count = 0;
        int i;
        readQ.push(root);
        while(!readQ.empty())
        {
            line.clear();
            while(!readQ.empty())
            {
                TreeNode * node = readQ.front();
                readQ.pop();
                if(node->left != NULL)
                {
                    writeQ.push(node->left);
                }
                if(node->right != NULL)
                {
                    writeQ.push(node->right);
                }
                line.push_back(node->val);
            }
            if(count == 0)
            {
                result.push_back(line);
            }
            else
            {
                lineRev.clear();
                for(i = line.size()-1; i >= 0; i--)
                {
                    lineRev.push_back(line[i]);
                }
                result.push_back(lineRev);
                
            }
            count = 1- count;
            

            readQ.swap(writeQ);
        }
        return result;
    }
};