class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kodane's algotithm

        // int n = nums.size();
        // int maxEle = nums[0];
        // int res = nums[0];
        // for(int i=1 ; i<n ; i++){
        //     maxEle = max(maxEle + nums[i], nums[i]);
        //     res = max(res, maxEle);
        // }
        // return res;
  
        int maxSum = INT_MIN;
        int currentSum = 0;

       for(int i=0 ; i<nums.size(); i++){
        currentSum = currentSum + nums[i];
        maxSum = max(maxSum, currentSum);
        if(currentSum<0) currentSum=0;
       }
       return maxSum;

    }
};