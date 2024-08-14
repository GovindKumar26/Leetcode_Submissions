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
        vector<int> a,b ;
        int n = nums.size();

        if(n==1) {
            return nums[0];
        }
        for(int i=0;i<n-1;i++){
            a.push_back(nums[i]);
        }

        for(int i=1;i<n;i++){
            b.push_back(nums[i]);
        }

        int ans1 = spaceOpt(a,n-2);
        int ans2 = spaceOpt(b,n-2);

        return max(ans1,ans2);


    }
};