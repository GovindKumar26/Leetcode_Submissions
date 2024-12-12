class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Count the total number of 1's
        int totalOnes = 0;
        for (int num : nums) {
            if (num == 1) totalOnes++;
        }

        // Step 2: If there are no 1's, no swap is needed
        if (totalOnes == 0) return 0;

        // Step 3: Sliding window to find the minimum number of 0's in any window of size totalOnes
        int bad = 0; // Count of 0's in the current window
        for (int i = 0; i < totalOnes; i++) {
            if (nums[i] == 0) bad++;
        }

        int minSwaps = bad;
        
        // Step 4: Slide the window and keep track of the minimum number of 0's in the window
        for (int i = 1; i < n; i++) {
            // Remove the effect of the element going out of the window
            if (nums[i - 1] == 0) bad--;
            // Add the effect of the new element coming into the window
            if (nums[(i + totalOnes - 1) % n] == 0) bad++;
            
            // Update minimum swaps required
            minSwaps = std::min(minSwaps, bad);
        }
        
        return minSwaps;
    }
};