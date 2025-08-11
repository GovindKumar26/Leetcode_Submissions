
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // vector<int> powers;
        // int number = n;
        // const int MOD = 1e9 + 7;

        // for (int i = 30; i >= 0; i--) {
        //     if ((1 << i) <= n) {
        //         n = n - (1 << i);
        //         powers.push_back((1 << i));
        //     }
        // }

        // sort(powers.begin(), powers.end());

        // vector<int> ans;

        // for (int i = 0; i < queries.size(); i++) {
        //     int start = queries[i][0], end = queries[i][1], prod = 1;

        //     for (int j = start; j <= end; j++) {
        //         prod = (1LL * prod * powers[j]) % MOD;
        //     }
        //     ans.push_back(prod);
        // }
        // return ans;

        const int MOD = 1e9 + 7;
        vector<int> powers;

        // Extract powers of 2 from n (based on binary representation)
        for (int i = 0; i <= 30; i++) {
            if (n & (1 << i)) {
                powers.push_back(1 << i);
            }
        }

        sort(powers.begin(), powers.end());

        // Precompute prefix products
        vector<long long> prefix(powers.size() + 1, 1);
        for (int i = 0; i < powers.size(); i++) {
            prefix[i + 1] = (prefix[i] * powers[i]) % MOD;
        }

        // precompute answers

        vector<vector<long long>> prods(powers.size(),
                                        vector<long long>(powers.size(), 0));
        for (int i = 0; i < powers.size(); i++) {
            long long product = 1;
            for (int j = i; j < powers.size(); j++) {
                product = (product * powers[j]) % MOD;
                prods[i][j] = product;
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int start = q[0], end = q[1];
            
            ans.push_back(prods[start][end]);
        }

        return ans;
    }
};