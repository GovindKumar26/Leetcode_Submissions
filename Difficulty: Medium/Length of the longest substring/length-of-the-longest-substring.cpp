//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // brute force(generating all substrings)
        int maxLen = 0;
        for(int i=0 ; i<s.length() ; i++){
            string temp = "";
            vector<int> hash(255, 0);
            for(int j=i ; j<s.length() ; j++){
                if(hash[s[j]]==1) break;
                hash[s[j]] = 1;
                temp = temp + s[j];
                maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.longestUniqueSubstring(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends