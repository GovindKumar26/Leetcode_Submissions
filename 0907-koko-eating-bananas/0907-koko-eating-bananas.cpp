class Solution {
public:
    bool canFinish(const vector<int>& piles, int h, int k) {
        long long time = 0;
        for (int pile : piles) {
            time += (pile + k - 1) / k; // Calculate the time required to finish
                                        // each pile with speed k
        }
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFinish(piles, h, mid)) {
                result = mid; // Update the result to a smaller feasible speed
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};