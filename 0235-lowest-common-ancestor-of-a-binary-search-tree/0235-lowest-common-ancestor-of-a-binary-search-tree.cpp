/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if (root == NULL)
        //     return NULL;
        // TreeNode* cur = root;

        // while (cur) {
        //     if (cur->val > p->val && cur->val > q->val) {
        //         cur = cur->left;
        //     } else if (cur->val < p->val && cur->val < q->val) {
        //         cur = cur->right;
        //     } else
        //         return cur;
        // }
        // return NULL;

        if (root == NULL)
            return NULL;
        TreeNode* cur = root;
        if (cur->val > p->val && cur->val > q->val) {
           return lowestCommonAncestor(root->left, p, q);
        }
        if (cur->val < p->val && cur->val < q->val) {
          return  lowestCommonAncestor(root->right, p, q);
        } else
            return cur;
      
    }
};