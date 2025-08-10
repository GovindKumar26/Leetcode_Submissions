class Solution {
public:
    bool check(vector<int> bloomDay, int mid, int m, int k) {
        int cnt = 0;
        int noOfBlooms = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                cnt++;
            } else {
                noOfBlooms += cnt / k;
                cnt = 0;
            }
        }
        noOfBlooms += cnt / k;
        return noOfBlooms >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        if (bloomDay.size() < val)
            return -1;
        int ans;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (auto i : bloomDay) {
            if (i > maxi)
                maxi = i;
            if (i < mini)
                mini = i;
        }

        int low = mini;
        int high = maxi;

        while (low <= high) {
            int mid = (high - low) / 2 + low;

            if (check(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};