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
 void inOrder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }

    bool findTarget(TreeNode* root, int k) {
          vector<int> nums;
        inOrder(root, nums); // Get sorted elements of the BST

        int left = 0, right = nums.size() - 1;
         while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) return true;
            if (sum < k) left++;       // Move left pointer to increase sum
            else right--;              // Move right pointer to decrease sum
        }
        return false;
    }
};