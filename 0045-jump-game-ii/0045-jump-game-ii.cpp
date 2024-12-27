class Solution {
public:
    // recursive gives tle
    // int func(int ind, int jump, int n, vector<int>& nums) {

    //     if (ind >= n - 1)
    //         return jump;
    //     int mini = INT_MAX;

    //     for (int i = 1; i <= nums[ind]; i++) {
    //         mini = min(mini, func(ind + i, jump + 1, n, nums));
    //     }

    //     return mini;
    // }

    int jump(vector<int>& nums) {
        // return func(0, 0, nums.size(), nums);
        int near = 0, far = 0, jumps = 0;

        while (far < nums.size() - 1) {
            int farthest = 0;
            for (int i = near; i <= far; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }

        return jumps;
    }
};