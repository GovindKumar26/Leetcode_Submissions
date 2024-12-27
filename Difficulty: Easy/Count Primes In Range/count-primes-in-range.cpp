//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    // tle
    // bool isPrime(int n){
    //     if(n==1) return 0; 
        
    //     for(int i=2 ; i*i<=n ; i++){
    //         if(n%i==0) return 0;
    //     }
    //     return 1;
    // }
  
    int countPrimes(int L, int R) {
        //tle
        // int cnt=0;
        // for(int i=L ; i<=R ; i++){
        //     if(isPrime(i)){
        //         cnt++;
        //     }
        // }
        // return cnt;
        
        // sieve of era... method
        vector<bool> sieve(R+1, 1);
        sieve[0] = sieve[1] = 0;
        
        for(int i=2 ; i<=R ; i++){
            if(sieve[i]){
                for(int j=2*i ; j<=R ; j=j+i){
                    sieve[j] = 0;
                }
            }
        }
        
         int cnt=0;
        for(int i=L ; i<=R ; i++){
            if(sieve[i]){
                cnt++;
            }
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends