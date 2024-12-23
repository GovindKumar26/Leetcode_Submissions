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

    int NumberOfSortSwaps(vector<int>&arr){
        int n = arr.size();
        int cnt=0;

    for (int i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted portion
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the minimum element with the first element in the unsorted portion
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            cnt++;
        }
    }
    return cnt;
    }

public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while (!q.empty()) {
            int sizeOfLevel = q.size();
            vector<int> temp;

            for (int i = 0; i < sizeOfLevel; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

           ans += NumberOfSortSwaps(temp);
        }
        return ans;
    }
};