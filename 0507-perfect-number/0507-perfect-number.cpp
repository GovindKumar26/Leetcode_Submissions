class Solution {
public:
    bool checkPerfectNumber(int num) {
        int cnt = 0;
        for(int i=1 ; i*i<=num ; i++){
            if(num%i==0){
                 cnt += i;
            if((num/i)!=i) cnt += num/i;
            }
        }

        cnt = cnt - num;

        return cnt==num;
    }
};