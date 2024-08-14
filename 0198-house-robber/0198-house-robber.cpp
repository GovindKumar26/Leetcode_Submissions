class Solution {
public:

    int solve(vector<int>nums){
        int n = nums.size();
         vector<int>dp(n,0);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            if(i>1)
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            else dp[i] = max(dp[i-1],nums[i]);
        }

        return dp[n-1];
    }

    int spaceOpt(vector<int>arr, int n){
        int prev1 = arr[0];
        int prev2 = 0;
        
        for(int i=1 ; i<=n ; i++){
            int take = arr[i];
            if(i>=2) take = arr[i] + prev2;
            
            int notTake = prev1;
            int curr = max(take, notTake);
            
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
      
        int ans = solve(nums);
      //  int ans = spaceOpt(nums,n-1);
        return ans;
    }
};