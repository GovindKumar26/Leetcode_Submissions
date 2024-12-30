class Solution {
public:
    const int MOD = 1e9 + 7;
    // int cnt = 0;
    // gives tle
    // int solve(int low, int high, int len, int zero, int one) {
    //     if (len >= low && len <= high) {
    //         cnt++;
    //     }

    //     if (len > high)
    //         return 0;

    //     int a = 0, b = 0;

    //     a = solve(low, high, len + zero, zero, one);

    //     b = solve(low, high, len + one, zero, one);

    //     return cnt;
    // }

    int solve(int low, int high, int len, int zero, int one, vector<int>& dp) {

        if (len > high)
            return 0;
        // Count the current string if length is within range

        if (dp[len] != -1)
            return dp[len];
        int count = (len >= low) ? 1 : 0;

        // Recursive calls: Add '0' and '1'
        count = (count + solve(low, high, len + zero, zero, one, dp)) % MOD;
        count = (count + solve(low, high, len + one, zero, one, dp)) % MOD;

        return dp[len] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int len = 0;
        vector<int> dp(high + 1, -1);
        return solve(low, high, len, zero, one, dp);
    }
};