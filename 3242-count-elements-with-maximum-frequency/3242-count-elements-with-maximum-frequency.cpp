class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int maxi = 0;
        for (auto it : mp) {
            maxi = max(maxi, it.second);
        }
        int ans = 0;
        for (auto it : mp) {
            if (it.second == maxi)
                ans = ans + maxi;
        }

        return ans;
    }
};