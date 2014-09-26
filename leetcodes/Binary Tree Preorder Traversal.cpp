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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //iteration version:
        vector<int> result;
        stack<TreeNode*> st;
        if(root == NULL)
        {
            return result;
        }
        TreeNode * p = root;
        while(p != NULL ||!st.empty())
        {
            while(p!=NULL)
            {
                result.push_back(p->val);
                st.push(p);
                p = p->left;
            }
            if(!st.empty())
            {
                p = st.top();
                st.pop();
                p = p->right;
            }
            
        }
        
        return result;
    }
};