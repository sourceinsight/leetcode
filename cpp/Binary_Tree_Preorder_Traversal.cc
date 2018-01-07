/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    /*
    vector<int> preorderTraversal(TreeNode *root) 
    {
        vector<int> path;
        
        preorder(root, path);
        
        return path;
    }
    
    void preorder(TreeNode* root, vector<int>& path)
    {
        if (root == NULL)
            return ;
        
        path.push_back(root->val);
        
        preorder(root->left, path);
        preorder(root->right, path);
    }
    */
    
    vector<int> preorderTraversal(TreeNode *root) 
    {
        vector<int> result;
        const TreeNode* p;
        stack<const TreeNode*> s;
        
        p = root;
        if (p != NULL)
            s.push(p);
        
        while (!s.empty())
        {
            p = s.top();
            s.pop();
            result.push_back(p->val);
            
            if (p->right != NULL)
                s.push(p->right);
            if (p->left != NULL)
                s.push(p->left);
        }
        
        return result;
    }
    
};
