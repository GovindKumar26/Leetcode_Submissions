/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int maxP(TreeNode*root,int &maximum){
        if(root==NULL) return 0;

        int l = max(0,maxP(root->left,maximum));
        int r = max(0,maxP(root->right,maximum));

        maximum = max(maximum,l+r+root->val);
        return max(l,r) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        maxP(root,maximum);
        return maximum;
    }
};