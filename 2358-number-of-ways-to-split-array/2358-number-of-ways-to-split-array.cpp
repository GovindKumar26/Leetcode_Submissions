class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // int n = nums.size();
        // vector<long long> prefixS(n, 0);
        // prefixS[0] = nums[0];
        // vector<long long> prefixSFromLast(n, 0);
        // prefixSFromLast[n - 1] = nums[n - 1];

        // for (int i = 1; i < n; i++) {
        //     prefixS[i] = prefixS[i - 1] + nums[i];
        // }

        // for (int i = n - 2; i >= 0; i--) {
        //     prefixSFromLast[i] = prefixSFromLast[i + 1] + nums[i];
        // }

        // int cnt = 0;
        // for (int i = 0; i < n - 1; i++) {
        //     if (prefixS[i] >= prefixSFromLast[i + 1])
        //         cnt++;
        // }

        // return cnt;

        int n = nums.size();
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        long long leftSum = 0;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;
            if (leftSum >= rightSum) {
                cnt++;
            }
        }

        return cnt;
    }
};