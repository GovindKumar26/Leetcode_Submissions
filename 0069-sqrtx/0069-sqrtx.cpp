class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        while(low<=high){
            long long mid = (high-low)/2 + low;
            long long val = mid*mid;

            if(val<=x){
                low = mid+1;
            }
            else high = mid-1;
        }
        return high;
    }
};