/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
         // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
        {
            return;
        }
        TreeLinkNode * p = root;//parent
        TreeLinkNode * q = NULL;//last
        TreeLinkNode * next = NULL;//first node each level
        while(p)
        {
            if(p->left)
            {
                if(q != NULL)
                {
                    q->next = p->left;
                }
                q = p->left;
                if(next == NULL)
                {
                    next = q;
                }
            }
            if(p->right)
            {
                if(q != NULL)
                {
                    q->next = p->right;
                }
                q = p->right;
                if(next == NULL)
                {
                    next = q;
                }
            }
            
            p = p->next;
        }
        connect(next);
    }
};