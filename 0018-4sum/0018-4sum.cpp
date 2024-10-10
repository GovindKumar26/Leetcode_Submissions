class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> set1;
        ranges::sort(nums);
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++)
            for (int j = i + 1; j < n - 2; j++) {
                int s = j + 1, e = n - 1;
                while (s < e) {
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                                    (long long)nums[s] + (long long)nums[e];
                    if (sum == target) {
                        set1.insert({nums[i], nums[j], nums[s], nums[e]});

                        s++;
                        e--;

                    } else if (sum > target) {
                        e--;
                    } else
                        s++;
                }
            }
        for (auto s : set1) {
            ans.push_back(s);
        }
        return ans;
    }
};