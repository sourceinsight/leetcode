/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) 
    {
        vector<vector<int> > result;
        if (root == NULL)
            return result;
            
        queue<TreeNode*> current, next;
        vector<int> level;
        
        current.push(root);
        while (!current.empty())
        {
            while (!current.empty())
            {
                TreeNode* node = current.front();
                current.pop();
                
                level.push_back(node->val);
                
                if (node->left != NULL)
                    next.push(node->left);
                    
                if (node->right != NULL)
                    next.push(node->right);
            }
            
            result.push_back(level);
            level.clear();
            swap(next, current);
        }
        
        reverse(result.begin(), result.end()); 
        
        return result;
    }
};
