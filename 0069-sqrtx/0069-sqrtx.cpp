class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x; 
        if(high==0) return 0;
        int ans;
        while(low<=high){
            long long mid = (high-low)/2 + low;
            long long val = mid*mid;

            if(val<=x){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};