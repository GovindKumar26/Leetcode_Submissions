class Solution {
public:
    string reverseWords(string s) {
        // string ans = "";
        // int n = s.length();

        // for (int i = n - 1, j = n - 1; i >= -1; i--) {
        //     if (i == -1 || s[i] == ' ') {

        //         if (i + 1 <= j) {
        //             ans = ans + s.substr(i + 1, j - i) + " ";
        //         }

        //         while (i >= 0 && s[i] == ' ') {
        //             i--;
        //         }

        //         j = i;
        //     }
        // }

        // if (!ans.empty() && ans[ans.length() - 1] == ' ') {
        //     ans.pop_back();
        // }
        // return ans;


        string ans="";
        int i=s.length()-1;

        while(i>=0){
            while(i>=0&&s[i]==' ') i--;
            if(i<0) break;
            int j=i;
            while(i>=0&&s[i]!=' ') i--;
            ans += s.substr(i+1,j-i);
            ans += ' ';
        }

        return ans.substr(0,ans.length()-1);
    }
};