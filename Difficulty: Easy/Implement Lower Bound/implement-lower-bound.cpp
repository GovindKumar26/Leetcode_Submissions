class Solution {
  public:
    int lowerBound(vector<int>& nums, int x) {
        // code here
        int low = 0, high = nums.size();
        int ans = nums.size();

        while(low<=high) {
            int mid = (high-low)/2 + low;

            if(nums[mid]>=x) {
                ans = mid;
                high = mid -1;
            } 
            else {
                low =mid+1;
            }
        }
        return ans; 
    }
};
