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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<int> result;
        if(root == NULL)
        {
            return result;
        }
        
        stack<TreeNode *> st;
        TreeNode * pre = NULL;
        TreeNode * cur;
        st.push(root);
        while(!st.empty())
        {
            TreeNode * p = st.top();
            if(p->left == NULL && p->right == NULL || pre!= NULL && (p->left == pre || p->right == pre) )
            {
                result.push_back(p->val);
                st.pop();
                pre = p;
            }
            else
            {
                if(p->right)
                {
                    st.push(p->right);
                }
                if(p->left)
                {
                    st.push(p->left);
                }
            }
        }
        return result;
        
    }
};