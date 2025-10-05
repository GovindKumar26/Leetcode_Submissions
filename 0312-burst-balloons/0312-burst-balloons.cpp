class Solution {
public:
    int memo(int i, int j, vector<int>&nums, vector<vector<int>>&dp){

        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = -1e9;
        for(int idx=i ; idx<=j ; idx++){
            int coins = nums[idx]*nums[i-1]*nums[j+1] + memo(i, idx-1, nums, dp) + memo(idx+1, j, nums, dp);
            ans = max(ans, coins);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int i=1, j = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>>dp(j+1, vector<int>(j+1, -1));
        return memo(i, j, nums, dp); 
    } 
};