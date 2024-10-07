class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kodane's algotithm

        int n = nums.size();
        int maxEle = nums[0];
        int res = nums[0];
        for(int i=1 ; i<n ; i++){
            maxEle = max(maxEle + nums[i], nums[i]);
            res = max(res, maxEle);
        }
        return res;
    }
};