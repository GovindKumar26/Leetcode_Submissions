class Solution {
public:

     int atMost(vector<int>& nums, int goal) {
        int head, tail = 0, sum = 0, result = 0;
        for (head = 0; head < nums.size(); head++) {
            sum += nums[head]%2;
            while (sum > goal && tail <= head) {
                sum -= nums[tail]%2;
                tail++;
            }
            result += head - tail + 1;
        }
        return result;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // same as binary subarrays with sum = k (1->odds and 0->evens)
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};