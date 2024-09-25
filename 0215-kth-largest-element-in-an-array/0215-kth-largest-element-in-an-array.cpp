class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int max = INT_MIN;
        sort(nums.begin(),nums.end());

        return nums[n-k];


        
    }
};