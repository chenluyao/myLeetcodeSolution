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
    
    int sumNumbers(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //BFS
        if(root == NULL)
        {
            return 0;
        }
        map<TreeNode * , int > mapT;
        queue<TreeNode *> q;
        q.push(root);
        mapT[root] = root->val;
        int sum = 0;
        while(!q.empty())
        {
            TreeNode * node = q.front();
            q.pop();
            int num = mapT[node];
            if(node -> left)
            {
                q.push(node->left);
                mapT[node->left] = num*10+node->left->val;
            }
            if(node -> right)
            {
                q.push(node->right);
                mapT[node->right] = num*10+node->right->val;
            }
            if(!(node->left) && !(node->right))
            {
                sum += num;
            }
        }
        return sum;
        
        
    }
};