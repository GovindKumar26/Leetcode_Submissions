class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

        vector<int> sieve(right + 1, 1);
        sieve[0] = sieve[1] = 0;

        for (int i = 2; i * i <= right; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= right; j = j + i) {
                    sieve[j] = 0;
                }
            }
        }

        vector<int> res;
        int temp = -1;
        int mini = INT_MAX;

        for (int i = left; i <= right; i++) {
            if (sieve[i]) {
                if (temp != -1 && i - temp < mini) {
                    res = {temp, i};
                    mini = i - temp;
                }
                temp = i;
            }
        }

        if (res.size() == 2)
            return res;
        else
            res = {-1, -1};
        return res;
    }
};