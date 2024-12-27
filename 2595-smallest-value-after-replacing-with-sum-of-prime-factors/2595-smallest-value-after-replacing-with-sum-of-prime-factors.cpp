class Solution {
public:
    int helper(int n) {
        int sum = 0;
        for (int i = 2; i <= n; i++) {

            while (n % i == 0) {
                sum += i;
                n = n / i;
            }
        }
        return sum;
    }

    int smallestValue(int n) {
        
        while(1){
            int sum = helper(n);
            if(sum==n) break;
            n = sum;
        }
        return n;
    }
};