/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

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
    /* 递归法
    vector<int> inorderTraversal(TreeNode *root) 
    {
        vector<int> result;
        inorderTraversal(root, result);
    
        return result;
    }
    
    void inorderTraversal(TreeNode* root, vector<int>& result)
    {
        if (root == NULL) 
            return ;
            
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
        
        return ;
    }
    */
    
    // 迭代
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        
        while(cur != NULL || !stk.empty())
        {
            if (cur != NULL)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                result.push_back(stk.top()->val);
                cur = stk.top()->right;
                stk.pop();
            }
        }
        
        return result;
    }
};
