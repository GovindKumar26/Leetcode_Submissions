class Solution {
public:
    bool isPowerOfTwo(int n) {

        // double x = 1;
        // while (x <= n) {
        //     if (x == n)
        //         return true;
        //     x = x * 2;
        // }
        // return false;

         return n > 0 && not (n & n - 1);
    }
};