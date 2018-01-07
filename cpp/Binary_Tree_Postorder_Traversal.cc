/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode *root) 
    {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }
    
    void postorderTraversal(TreeNode* node, vector<int>& result)
    {
        if (node == NULL)
            return;
        postorderTraversal(node->left, result);
        postorderTraversal(node->right, result);
        result.push_back(node->val);
    }
*/
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode*> stk;
        if (root != NULL)
        {
            stk.push(root);
        }
        
        while (!stk.empty())
        {
            TreeNode* tmp = stk.top();
            stk.pop();
            result.push_back(tmp->val);
            if (tmp->left != NULL)
            {
                stk.push(tmp->left);
            }
            if (tmp->right != NULL)
            {
                stk.push(tmp->right);
            }
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};
