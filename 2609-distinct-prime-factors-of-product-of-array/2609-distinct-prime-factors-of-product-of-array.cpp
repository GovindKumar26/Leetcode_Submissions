class Solution {
public:
     
    set<int> findPrime(int &n, set<int>&st){

        for(int i=2 ; i<=n ; i++){
            while(n%i==0){
                st.insert(i);
                n = n/i;
            }
        }
        return st;
    }

    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        set<int>st;

        for(int i=0 ; i<n ; i++){
            findPrime(nums[i], st);
        }
        return st.size();
    }
};