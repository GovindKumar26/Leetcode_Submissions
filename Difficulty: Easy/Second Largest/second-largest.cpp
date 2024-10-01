//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
      int n = arr.size();
      int secondLarg = -1;
      int largest = arr[0];
      for(int i=1 ; i<n; i++){
          if(arr[i]>largest){
              secondLarg = largest;
              largest = arr[i];
          }
          else if(arr[i]<largest && secondLarg<arr[i]){
              secondLarg = arr[i];
          }
      }
      return secondLarg;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends