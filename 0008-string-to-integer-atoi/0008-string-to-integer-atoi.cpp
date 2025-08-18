class Solution {
public:
    int myAtoi(string s) {
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

        // Build digit string
        string k = "";
        while (i < n && isdigit(s[i])) {
            k += s[i];
            i++;
        }

        long ans = 0; // use long to prevent overflow

        for (char c : k) { // left-to-right processing
            ans = ans * 10 + (c - '0');

            // Clamp to INT limits
            if (positive && ans > INT_MAX) return INT_MAX;
            if (!positive && -ans < INT_MIN) return INT_MIN;
        }

        return positive ? ans : -ans;
    }
};