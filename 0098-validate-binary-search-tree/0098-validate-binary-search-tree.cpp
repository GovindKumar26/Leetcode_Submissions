/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        return validate(root, LONG_MIN, LONG_MAX);
    }

    bool validate(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr)
            return true;

        // Check if the current node's value violates the bounds
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // Recur for left and right subtrees with updated bounds
        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }
};