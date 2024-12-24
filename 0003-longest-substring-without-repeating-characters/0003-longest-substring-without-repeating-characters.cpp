class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // brute force(generating all substrings)
        // int maxLen = 0;
        // for(int i=0 ; i<s.length() ; i++){
        //     string temp = "";
        //     vector<int> hash(255, 0);
        //     for(int j=i ; j<s.length() ; j++){
        //         if(hash[s[j]]==1) break;
        //         hash[s[j]] = 1;
        //         temp = temp + s[j];
        //         maxLen = max(maxLen, j-i+1);
        //     }
        // }
        // return maxLen;
        int n = s.length();
        int maxLen = 0, l=0, r=0;
        vector<int>hash(255, -1);

        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l = hash[s[r]] + 1;
                }
            }
            maxLen = max(maxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};