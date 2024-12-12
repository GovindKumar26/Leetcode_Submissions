class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int currSum = 0, res = INT_MAX;  // Use INT_MAX to represent a large number
        int start = 0;
        
        // Traverse the array
        for (int end = 0; end < nums.size(); ++end) {
            currSum += nums[end];
            
            // Try to minimize the subarray when currSum is >= target
            while (currSum >= target) {
                res = min(res, end - start + 1);  // Update result
                currSum -= nums[start++];         // Shrink window from the left
            }
        }
        
        // If res wasn't updated, return 0 as no valid subarray was found
        return (res == INT_MAX) ? 0 : res;
    }
};