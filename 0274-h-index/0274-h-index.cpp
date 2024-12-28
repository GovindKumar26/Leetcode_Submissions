class Solution {
public:
    int hIndex(vector<int>& citations) {
        // int n = citations.size();
        // int k = n;
        // sort(citations.begin(), citations.end());

        // while (k) {
        //     int cnt = 0;
        //     bool f = 0;
        //  // for counting approach   // for(auto it : citations){
        //     //     if(it>=k) cnt++;
        //     // }
        // // for sorting approach    for (int i = 0; i < n - k + 1; i++) {
        //         if (citations[i] >= k) {
        //             f = 1;
        //             break;
        //         }
        //     }
        //     if (f) {
        //         break;
        //     } else {
        //         k--;
        //     }
        // }
        // return k;


         int n = citations.size();
        sort(citations.begin(), citations.end());

        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i) {
                return n - i;
            }
        }

        return 0;
    }
};