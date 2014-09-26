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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result;
        if(root == NULL)
        {
            return result;
        }
        vector<int> line;
        queue<TreeNode *> readQ;
        queue<TreeNode *> writeQ;
        readQ.push(root);
        while(!readQ.empty())
        {
            line.clear();
            while(!readQ.empty())
            {
                TreeNode * node = readQ.front();
                readQ.pop();
                line.push_back(node->val);
                if(node->left != NULL)
                {
                    writeQ.push(node->left);
                }
                if(node->right != NULL)
                {
                    writeQ.push(node->right);
                }
            }
            result.push_back(line);
            readQ.swap(writeQ);
        }
        return result;
    }
};