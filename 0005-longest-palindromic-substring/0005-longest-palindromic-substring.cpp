class Solution {
public:
    bool isPalindrome(string x) {
        int n = x.length();
        for (int i = 0; i < x.length() / 2; i++) {
            if (x[i] != x[n - i - 1])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {

        // int n = s.length();
        // int cnt = 0;
        // string ans = "";

        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         if (isPalindrome(s.substr(i, j - i + 1))) {
        //             if (cnt < j - i + 1) {
        //                 ans = s.substr(i, j - i + 1);
        //                 cnt = j-i+1;
        //             }
        //         }
        //     }
        // }

        // return ans;
      int n = s.length();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--; r++;
            }

            // Even length
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--; r++;
            }
        }

        return s.substr(start, maxLen);

    }
};