//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    bool check(vector<int>stalls, int dist, int cows){
        int cntCows = 1, last = stalls[0];
        
        for(int i=0 ; i<stalls.size(); i++){
            if(stalls[i]-last>=dist){
                cntCows++;
                last = stalls[i];
            }
            if(cntCows>=cows) return true;
        }
        return false;
    }
        

    int solve(vector<int> &stalls, int k) {
        int ans;
         sort(stalls.begin(),stalls.end());
         int n = stalls.size();
         int low = 1, high = stalls[n-1] - stalls[0];
         
         while(low<=high){
             int mid = (high-low)/2+low;
             
             if(check(stalls,mid,k)){
                 ans = mid;
                 low = mid+1;
             }
             else{
                 high = mid-1;
             }
             
         }
         
         return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.solve(arr, k);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends