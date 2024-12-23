class Solution {
public:
    int gcd(int a, int b) {
        while (a && b) {
            if (a > b)
                a = a % b;
            else
                b = b % a;
        }

        if (a == 0)
            return b;
        if (b == 0)
            return a;

            return -1;
    }
    int findGCD(vector<int>& nums) {
        int a = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());

        return gcd(a, b);
    }
};