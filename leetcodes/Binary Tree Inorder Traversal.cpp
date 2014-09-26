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
    vector<int> inorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        stack<TreeNode *> st;
        if(root == NULL)
        {
            return result;
        }
        
        TreeNode * p = root;
        while(!st.empty() || p != NULL)
        {
            while(p != NULL)
            {
                st.push(p);
                p = p->left;
            }
            if(!st.empty())
            {
                TreeNode * temp = st.top();
                st.pop();
                result.push_back(temp->val);
                p = temp->right;
            }
        }
        return result;
    }
};