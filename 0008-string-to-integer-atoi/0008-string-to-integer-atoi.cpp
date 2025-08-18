class Solution {
public:
    int myAtoi(string s) {
        // int n = s.length();
        // int i = 0;

        // // Skip leading spaces
        // while (i < n && s[i] == ' ') i++;

        // // Handle optional sign
        // bool positive = true;
        // if (i < n && (s[i] == '+' || s[i] == '-')) {
        //     positive = s[i] != '-';
        //     i++;
        // }

        // // Build digit string
        // string k = "";
        // while (i < n && isdigit(s[i])) {
        //     k += s[i];
        //     i++;
        // }

        // long ans = 0; // use long to prevent overflow

        // for (char c : k) { // left-to-right processing
        //     ans = ans * 10 + (c - '0');

        //     // Clamp to INT limits
        //     if (positive && ans > INT_MAX) return INT_MAX;
        //     if (!positive && -ans < INT_MIN) return INT_MIN;
        // }

        // return positive ? ans : -ans;

         int n = s.length();
        int i = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // Handle optional sign
        bool positive = true;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            positive = s[i] != '-';
            i++;
        }

        long ans = 0;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow before multiplying by 10
            if (positive) {
                if (ans > (INT_MAX - digit) / 10) return INT_MAX;
            } else {
                if (-ans < (INT_MIN + digit) / 10) return INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return positive ? ans : -ans;
    }
};