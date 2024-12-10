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
    int countNodes(TreeNode* root) {
        //  queue<TreeNode*>q;
        // int ans=0;
        // if(root==NULL) return 0;
        // q.push(root);
        // while(!q.empty()){
        //     int n=q.size();
        //     for(int i=0;i<n;i++){
        //         TreeNode* temp=q.front();
        //         ans++;
        //         q.pop();
        //         if(temp->left!=NULL) q.push(temp->left);
        //         if(temp->right!=NULL) q.push(temp->right);
        //     }
        // }
        // return ans;

        int l=1, r=1;
        if (!root) return 0;

        TreeNode *left = root, *right = root;
        while (left = left->left)   ++l; 
        while (right = right->right) ++r; 
        
        if (l == r) return (1 << l) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};