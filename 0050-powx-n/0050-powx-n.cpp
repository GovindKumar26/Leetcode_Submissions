class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long nn = n;
        if(n<0) {
            nn = (double)(-1)*n;
        }
        while(nn>0){
            if(nn%2==0){
                x = x*x;
                nn = nn/2;
            }
            else{
                ans = ans*x; 
                nn--;
            }
        }

        if(n<0){
            ans = (double)(1)/(double)(ans);
        }
        return ans;
    }
};