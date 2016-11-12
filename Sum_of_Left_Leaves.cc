/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree,
with values 9 and 15 respectively. Return 24.
 */
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        int result = 0;

        if (root != NULL)
        {
            sumOfLeftLeaves(root, result, false);
        }
        return result;
    }

private:
    void sumOfLeftLeaves(TreeNode* root, int& result, bool isleft)
    {
        if (root->left == NULL && root->right == NULL && isleft)
        {
            result += root->val;
        }

        if (root->left != NULL)
        {
            sumOfLeftLeaves(root->left, result, true);
        }

        if (root->right != NULL)
        {
            sumOfLeftLeaves(root->right, result, false);
        }
    }
};
