class Solution {
public:

    bool check(vector<int>nums, int mid, int threshold){
        int sum = 0;

        for(auto i : nums){
            sum += ceil((double)(i)/(double)(mid));
        }
        return sum<=threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while(low<=high){
            int mid = (high-low)/2 + low;
            if(check(nums, mid, threshold)){
                high = mid-1;
                ans = mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};