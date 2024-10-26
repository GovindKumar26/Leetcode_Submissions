class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingEle = 0, i = 0, n = arr.size();

        int cnt = 0;
        while (cnt != k && i < n) {
            missingEle++;
            if (arr[i] == missingEle) {
                i++;
            } else {
                cnt++;
            }
        }
        if (cnt == k)
            return missingEle;

        else {
            return arr[n - 1] + k - cnt;
        }
    }
};