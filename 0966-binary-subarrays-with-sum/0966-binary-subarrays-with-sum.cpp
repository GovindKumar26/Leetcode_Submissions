class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int head, tail = 0, sum = 0, result = 0;
        for (head = 0; head < nums.size(); head++) {
            sum += nums[head];
            while (sum > goal && tail <= head) {
                sum -= nums[tail];
                tail++;
            }
            result += head - tail + 1;
        }
        return result;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // code for number of subarrays with sum = k
        int k = goal;
        //    unordered_map<int, int>mp;
        //    mp[0] = 1;
        //    int preSum = 0, cnt = 0;
        //    for(int i = 0 ; i<nums.size() ; i++){
        //        preSum  = preSum + nums[i];
        //        int remove = preSum - k;
        //        cnt = cnt + mp[remove];
        //        mp[preSum]++;
        //    }
        //    return cnt;

        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};