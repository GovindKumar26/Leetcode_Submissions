//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
       int r=0, l=0, maxLen=-1;
       int n = s.length();
       map<char, int> mpp;
       
       while(r<n){
           mpp[s[r]]++;
           if(mpp.size()==k){
               maxLen = max(maxLen, r-l+1);}
           if(mpp.size()>k){
               while(mpp.size()>k){
                   mpp[s[l]]--;
                   if(mpp[s[l]]==0) mpp.erase(s[l]);
                   l++;
               }
             }
           r++;
          
       }
       return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends