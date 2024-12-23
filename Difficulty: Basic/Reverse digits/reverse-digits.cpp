//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int reverseDigits(int n) {
        int reverseN = 0, i=1;
        
        while(n){
            int lastDigit = n%10;
            reverseN = i*reverseN + lastDigit;
            n = n/10;
           if(lastDigit) i=i*10;
        }
        return reverseN;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.reverseDigits(n);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends