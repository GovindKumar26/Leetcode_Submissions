class Solution {
public:

    int func(int i, int target, vector<int>&arr,vector<vector<int>>&dp){
       
        if(i==0) {
            if(arr[0]==0 && target==0) return 2;
            else if(target==0 || target==arr[0]) return 1;
			 return 0;
        } 

        if(dp[i][target]!=-1) return dp[i][target];

        int notPick = func(i-1,target,arr,dp);
        int pick = 0;
        if(arr[i]<=target) {
            pick = func(i-1,target-arr[i],arr,dp);
        }

        return dp[i][target] = (pick + notPick);
}


    int findTargetSumWays(vector<int>& nums, int target) {
          
         int sum = 0;
         int n = nums.size();
         for(auto a : nums) sum += a;
         
         if((sum-target)%2 || (sum-target)<0) return 0;
         
         int k = (sum-target)/2;
         
         vector<vector<int>>dp(n,vector<int>(k+1,-1));
         return func(n-1,k,nums,dp);
    }
};