class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        
         int low = 1, high = m; 
        if(high==0) return 0;
        int ans = -1;
        
        while(low<=high){
            long long mid = (high-low)/2 + low;
            long long val = pow(mid, n);

            if(val<=m){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        if(pow(ans, n)==m) {
            return ans;
        }
        return -1;
    }
};