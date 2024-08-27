class Solution {
public:
    int solve(vector<int> a, int n, int i, int prev, vector<vector<int>>& dp) {
        if (i == n)
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int take = 0;

        if (prev == -1 || a[i] > a[prev]) {
            take = 1 + solve(a, n, i + 1, i, dp);
        }

        int notTake = 0 + solve(a, n, i + 1, prev, dp);

        dp[i][prev + 1] = max(take, notTake);

        return dp[i][prev + 1];
    }

    int tab(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int take = 0;

                if (prev == -1 || a[i] > a[prev]) {
                    take = 1 + dp[i + 1][i+1];
                }

                int notTake = 0 + dp[i+1][prev+1];

                dp[i][prev + 1] = max(take, notTake);

                
            }
        }
        return dp[0][-1+1];
    }

     int spaceOpt(vector<int>&a, int n){
        
        vector<int> next(n+1,0), curr(n+1,0);
        
         for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int take = 0;

                if (prev == -1 || a[i] > a[prev]) {
                    take = 1 + next[i+1];
                }

                int notTake = 0 + next[prev+1];

                curr[prev + 1] = max(take, notTake);

                
            }
            next = curr;
        }
        return next[-1+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return spaceOpt(nums, n);
        return tab(nums);
        return solve(nums, n, 0, -1, dp);
    }
};