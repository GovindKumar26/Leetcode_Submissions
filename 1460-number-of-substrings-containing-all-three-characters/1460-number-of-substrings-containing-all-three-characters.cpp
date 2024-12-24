class Solution {
public:
    int numberOfSubstrings(string s) {
        // brute force
        int n = s.length(), l = 0, r = 0;
        unordered_map<char, int>mpp;
        int cnt=0;

        while(r<n){
            mpp[s[r]]++;
            while(mpp.size()==3){
             cnt++;
             cnt = cnt + n - 1 - r;
                
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            r++;
        }
        return cnt;
    }
};