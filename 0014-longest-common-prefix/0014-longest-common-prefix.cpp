class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if (strs.empty()) return "";

        // string pref = strs[0];
        // int prefLen = pref.length();

        // for (int i = 1; i < strs.size(); i++) {
        //     string s = strs[i];
        //     while (prefLen > s.length() || pref != s.substr(0, prefLen)) {
        //         prefLen--;
        //         if (prefLen == 0) {
        //             return "";
        //         }
        //         pref = pref.substr(0, prefLen);
        //     }
        // }

        // return pref;      


        string ans="";  
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string first=strs[0],last=strs[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};