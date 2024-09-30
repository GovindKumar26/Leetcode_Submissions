#include<bits/stdc++.h>
class Solution {
public:
    // int solve(vector<int> a, int n, int i, int prev, vector<vector<int>>& dp) {
    //     if (i == n)
    //         return 0;

    //     if (dp[i][prev + 1] != -1)
    //         return dp[i][prev + 1];

    //     int take = 0;

    //     if (prev == -1 || a[i] > a[prev]) {
    //         take = 1 + solve(a, n, i + 1, i, dp);
    //     }

    //     int notTake = 0 + solve(a, n, i + 1, prev, dp);

    //     dp[i][prev + 1] = max(take, notTake);

    //     return dp[i][prev + 1];
    // }

    // int tab(vector<int>& a) {
    //     int n = a.size();
    //     vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

    //     for (int i = n - 1; i >= 0; i--) {
    //         for (int prev = i - 1; prev >= -1; prev--) {
    //             int take = 0;

    //             if (prev == -1 || a[i] > a[prev]) {
    //                 take = 1 + dp[i + 1][i+1];
    //             }

    //             int notTake = 0 + dp[i+1][prev+1];

    //             dp[i][prev + 1] = max(take, notTake);

                
    //         }
    //     }
    //     return dp[0][-1+1];
    // }

    //  int spaceOpt(vector<int>&a, int n){
        
    //     vector<int> next(n+1,0), curr(n+1,0);
        
    //      for (int i = n - 1; i >= 0; i--) {
    //         for (int prev = i - 1; prev >= -1; prev--) {
    //             int take = 0;

    //             if (prev == -1 || a[i] > a[prev]) {
    //                 take = 1 + next[i+1];
    //             }

    //             int notTake = 0 + next[prev+1];

    //             curr[prev + 1] = max(take, notTake);

                
    //         }
    //         next = curr;
    //     }
    //     return next[-1+1];
    // }

    int solve2(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n,1);
        int maximum = 1;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            maximum = max(maximum, dp[i]);
        }
        return maximum;
    }

    int bSearch(vector<int>&nums){
        vector<int>temp;
        int len=1;
        temp.push_back(nums[0]);
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solve2(nums);
        // return spaceOpt(nums, n);
        // return tab(nums);
        // return solve(nums, n, 0, -1, dp);
        return bSearch(nums);
    }
};