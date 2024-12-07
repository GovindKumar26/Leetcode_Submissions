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
    void zigZag(TreeNode* root, vector<vector<int>>& ans) {
        if (root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp(size);

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                int idx = leftToRight ? i : size - i - 1;
                temp[idx] = front->val;

                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }

            leftToRight = !leftToRight;
            ans.push_back(temp);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        zigZag(root, ans);
        return ans;
    }
};