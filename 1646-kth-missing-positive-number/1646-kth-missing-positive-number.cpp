class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingEle = 0, i = 0, n = arr.size();

        int c = 0;
        while (c != k && i < n) {
            missingEle++;
            if (arr[i] == missingEle) {
                i++;
            } else {
                c++;
            }
        }
        if (c == k)
            return missingEle;

        else {
            return arr[n - 1] + k - c;
        }
    }
};