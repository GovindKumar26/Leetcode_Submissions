class Solution {
public:
    bool memo(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (i >= 0 && j < 0) {
            for (int a = 0; a <= i; a++) {
                if (p[a] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[j] == p[i] || p[i] == '?') {
            return dp[i][j] = memo(i - 1, j - 1, s, p, dp);
        }

        if (p[i] == '*') {
            return dp[i][j] =
                       (memo(i - 1, j, s, p, dp) | memo(i, j - 1, s, p, dp));
        }

        return dp[i][j] = false;
    }

    bool tab(string& s, string& p) {
        int n = p.length(), m = s.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int j = 1; j <= m; j++)
            dp[0][j] = false;

        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int a = 1; a <= i; a++) {
                if (p[a-1] != '*')
                    flag = false;
                break;
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s[j - 1] == p[i - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }

                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }

    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
         vector<vector<int>>dp(n,vector<int>(m,-1));
         return memo(n-1, m-1, s, p, dp);
       // return tab(s, p);
    }
};