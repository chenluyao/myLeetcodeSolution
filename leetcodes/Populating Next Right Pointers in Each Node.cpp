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
    TreeLinkNode * getRight(TreeLinkNode * node)
    {
        TreeLinkNode * nextNode = node-> next;
        int count = 0;
        while(nextNode != NULL &&nextNode -> right == node)
        {
            node = nextNode;
            count ++;
            nextNode = node->next;
        }
        if(nextNode == NULL)//root
        {
            return NULL;
        }
        else
        {
            
            while(count >0)
            {
                nextNode = nextNode -> left;
                count --;
            }
            return nextNode;
        }
    }
    void setLevel(TreeLinkNode * node)
    {
        TreeLinkNode * nextNode = node-> next;
        if(nextNode -> right == node)
        {
            nextNode = getRight(node);
            node->next = nextNode;
            if(nextNode == NULL)
            {
                return;
            }
        }
        setLevel(nextNode);
    }
    void setParent(TreeLinkNode * root)
    {
        if(root->left != NULL)
        {
            root->left->next = root->right;
            setParent(root->left);
        }
        if(root->right != NULL)
        {
            root->right->next = root;
            setParent(root->right);
        }
    }
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if(root == NULL)
        {
            return;
        }
        
        root->next = NULL;
        setParent(root);//left->right,right->parent
        
        TreeLinkNode * levelFirstLeft = root->left;
        
        while(levelFirstLeft != NULL)
        {
            setLevel(levelFirstLeft);
            //do something
            levelFirstLeft = levelFirstLeft->left;
        }
        
        
        
    }
};