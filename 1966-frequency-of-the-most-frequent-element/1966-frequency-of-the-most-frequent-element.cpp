class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
         std::sort(nums.begin(), nums.end());
        
        long long total = 0; // Keep track of the total increments needed
        int maxFreq = 1;     // Store the maximum frequency found
        int left = 0;        // Left boundary of the sliding window

        // Iterate through the array using the right boundary
        for (int right = 0; right < nums.size(); ++right) {
            total += (long long)nums[right];
            
            // Check if the total increments needed exceed the allowed `k`
            while ((long long)nums[right] * (right - left + 1) - total > k) {
                total -= nums[left]; // Remove the left element from the window
                left++;              // Move the left boundary to the right
            }
            
            // Update the maximum frequency
            maxFreq = std::max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }
};