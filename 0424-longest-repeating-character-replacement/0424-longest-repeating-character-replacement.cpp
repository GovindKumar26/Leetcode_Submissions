class Solution {
public:
    int characterReplacement(string s, int k) {

        // brute force(generating all substrings)
        // int n = s.length();
        // int ans = 0;
        // for(int i=0 ; i<n ; i++){
        //     vector<int>hash(26, 0);
        //     int maxFreq = 0;
        //     for(int j=i ; j<n ; j++){
        //         hash[s[j]-'A']++;
        //         maxFreq = max(maxFreq, hash[s[j]-'A']); // maximum frequency character
        //         int changes = (j-i+1) - maxFreq;   // number of changes required = len of subs - maxFreq
        //         if(changes<=k) ans = max(ans, j-i+1);
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return ans;


        // int l = 0, r = 0, n = s.length();
        // vector<int>hash(26, 0);

        // while(r<n){
        //     hash[s[r]-'A']++;
        // }

        int n = s.size();
        int r = 0;
        int l = 0;
        int ans = 0;
        int maxi = 0;
        map<char, int>mp;

        while(r < n){
            mp[s[r]]++;
            maxi = max(maxi, mp[s[r]]);
            r++;

            if((r - l - maxi) > k){
                mp[s[l]]--;
                maxi = 0;
                // for(auto i : mp){
                //     maxi = max(maxi, i.second);
                // }
                l++;
            }
            
            if((r-l-maxi) <= k){
                ans = max(ans, (r - l));
            }
        }
        return ans;
    }
};