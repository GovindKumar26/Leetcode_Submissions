//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
  public:
  
    bool checkPalin(int x){
          // Negative numbers and numbers ending with 0 (but not 0 itself) cannot be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0;
        while (x > reversed) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        // Check if the original number equals the reversed number
        // If the number has an odd number of digits, discard the middle digit by reversed / 10
        return x == reversed || x == reversed / 10;
    }
  
    bool PalinArray(vector<int> &arr) {
       for(auto i : arr) {
           if(checkPalin(i)==0) return 0;
       }
       return 1;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        cout << (ob.PalinArray(arr) ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends