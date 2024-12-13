class Solution {
public:
    long long findScore(vector<int>& nums) {
         int n = nums.size();
        vector<pair<int, int>> sortedNums(n); // Pair of value and original index
        
        // Fill sortedNums with values and their original indices
        for (int i = 0; i < n; i++) {
            sortedNums[i] = {nums[i], i};
        }
        
        // Sort based on the values
        sort(sortedNums.begin(), sortedNums.end());
        
        long long score = 0;  // Use long long to avoid overflow
        
        // Iterate over the sorted array
        for (int i = 0; i < n; i++) {
            int num = sortedNums[i].first;
            int idx = sortedNums[i].second;
            
            if (nums[idx] != -1) {  // Process only if not already marked
                score += num;  // Increment score by the value of the element
                nums[idx] = -1;  // Mark current index as processed
                if (idx > 0) {
                    nums[idx - 1] = -1;  // Mark left neighbor as processed
                }
                if (idx < n - 1) {
                    nums[idx + 1] = -1;  // Mark right neighbor as processed
                }
            }
        }
        
        return score;

        
    }
};