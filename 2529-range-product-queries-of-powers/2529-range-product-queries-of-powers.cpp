
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        int number = n;
        const int MOD = 1e9 + 7; 

        for(int i=30; i>=0 ; i--) {
            if((1<<i)<=n){
                n = n - (1<<i);
                powers.push_back((1<<i));
            }
        }

        sort(powers.begin(), powers.end());

        vector<int> ans;

        for(int i=0 ; i<queries.size() ; i++) {
            int start = queries[i][0], end = queries[i][1], prod = 1;

            for(int j=start ; j<=end ; j++) {
                prod =  (1LL * prod * powers[j]) % MOD ;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};