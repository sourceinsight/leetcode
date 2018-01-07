/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode *root) 
    {
        if (root == NULL)
            return true;
            
        int left = treeHeight(root->left);
        int right = treeHeight(root->right);
        
        if (left - right > 1 || left - right < -1)
        {
            return false;
        }
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int treeHeight(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        
        int left = treeHeight(root->left) + 1;
        int right = treeHeight(root->right) + 1;
        
        return left > right ? left : right;
    }
};
