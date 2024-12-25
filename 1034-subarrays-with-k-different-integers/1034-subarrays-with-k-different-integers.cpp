class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        unordered_map<int, int> mpp;

        int head, tail = 0, result = 0;
        for (head = 0; head < nums.size(); head++) {
            mpp[nums[head]]++;
            while (mpp.size() > goal && tail <= head) {
                mpp[nums[tail]]--;
                if(mpp[nums[tail]]==0) mpp.erase(nums[tail]);
                tail++;
            }
            result += head - tail + 1;
        }
        return result;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};