class Solution {
public:

       bool check(const vector<int>& weights, int cap, int days) {
        int dayReq = 1; // Start with one day.
        int currentWeight = 0;

        for (int weight : weights) {
            // If adding the next weight exceeds the capacity, start a new day.
            if (currentWeight + weight > cap) {
                dayReq++;
                currentWeight = 0;
            }
            currentWeight += weight;
        }

        return dayReq <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int ans ;
        int sum = 0;
        int low = *max_element(weights.begin(), weights.end());
        for(auto i : weights) sum += i;
        int high = sum;

        while(low<=high){
            int mid = (high-low)/2 + low;
            if(check(weights, mid, days)){
                ans = mid;
                high = mid-1;
            } 
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};