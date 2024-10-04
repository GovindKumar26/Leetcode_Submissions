//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(vector<int> arr1, vector<int> arr2) {
        
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
        vector<int>ans;
        
        int i = 0, j = 0;
        int n1 = arr1.size(), n2 = arr2.size();
        while(i<n1 && j<n2){
            if(arr1[i]<=arr2[j]){
                if(ans.size()==0 || ans.back()!=arr1[i]){
                    ans.push_back(arr1[i]);
                }
                i++;
            }
            
            else if(arr2[j]<=arr1[i]){
                if(ans.size()==0 || ans.back()!=arr2[j]){
                    ans.push_back(arr2[j]);
                }
                j++;
            }
        }
        
        while(i<n1){
          
                if(ans.size()==0 || ans.back()!=arr1[i]){
                    ans.push_back(arr1[i]);
                }
                i++;
        }
        
        while(j<n2){
           
                if(ans.size()==0 || ans.back()!=arr2[j]){
                    ans.push_back(arr2[j]);
                }
                j++;
        }
        
        return ans.size();
        
    
        
        
    //   set<int>st;
    //   for(auto i : arr1) st.insert(i);
    //   for(auto i : arr2) st.insert(i);
      
    //   vector<int>ans;
    //   for(auto i : st){
    //       ans.push_back(i);
    //   }
      
    //   return ans.size();
     }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> a;
        vector<int> b;

        string input;
        // For a
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // For b
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.doUnion(a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends