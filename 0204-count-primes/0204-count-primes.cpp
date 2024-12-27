class Solution {
public:


    int countPrimes(int n) {

        vector<bool> flag(n+1,true);
        flag[0]=flag[1]=false;
        int count = 0;

        for(int i=2;i<n  ;i++){
            if(flag[i]){
                count++;
                for(int j=2*i;j<=n;j=j+i){
                    flag[j]=false;
                }
            }
        }


        
        return count;
    }
};