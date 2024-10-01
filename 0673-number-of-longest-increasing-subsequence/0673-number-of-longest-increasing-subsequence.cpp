class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
   
        int n = nums.size();
        vector<int>dp(n,1), count(n,1);
        int maximum = 1;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if(nums[j]<nums[i] && dp[i]==dp[j]+1){
                    count[i] = count[j] + count[i];
                }
            }
            maximum = max(maximum, dp[i]);
        }
      
      int nos = 0;
      for(int i=0 ; i<n ; i++){
        if(dp[i]==maximum) nos = nos + count[i];
      }
    
    return nos;
     
    }
    
};