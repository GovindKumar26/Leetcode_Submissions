class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // this is same as longest subarray with at most k zeroes

        // int ans = 0, l = 0, r = 0;
        // int zeroes = 0;

        // while (r < nums.size()) {
        //     if (nums[r] == 0)
        //         zeroes++;
        //     while (zeroes > k) {
        //         if (nums[l] == 0)
        //             zeroes--;
        //         l++;
        //     }

        //     if (zeroes <= k) {
        //         ans = max(ans, r - l + 1);
        //     }
        //     r++;
        // }
        // return ans;

         int ans = 0, l = 0, r = 0;
        int zeroes = 0;

        while (r < nums.size()) {
            if (nums[r] == 0)
                zeroes++;
            if (zeroes > k) {
                if (nums[l] == 0)
                    zeroes--;
                l++;
            }

            if (zeroes <= k) {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};