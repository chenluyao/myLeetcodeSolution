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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        if(root == NULL)
        {
            return result;
        }
        int i;
        vector<vector<int> > temp;
        vector<int> l;
        
        if(root->left != NULL || root->right != NULL)
        {
            if(root->left != NULL)
            {
                temp = pathSum(root->left,sum-root->val);
                if(temp.size()!=0)
                {
                    for(i = 0; i<temp.size();i++)
                    {
                        l = temp[i];
                        l.insert(l.begin(),root->val);
                        result.push_back(l);
                    }
                }
            }
            if(root->right != NULL)
            {
                temp = pathSum(root->right,sum-root->val);
                if(temp.size()!=0)
                {
                    for(i = 0; i<temp.size();i++)
                    {
                        l = temp[i];
                        l.insert(l.begin(),root->val);
                        result.push_back(l);
                    }
                }
            }
        }
        else
        {
            l.clear();
            if(root->val == sum)
            {
                l.push_back(root->val);
                result.push_back(l);
            }
            else
            {
                
            }
        }
        return result;
    }
};