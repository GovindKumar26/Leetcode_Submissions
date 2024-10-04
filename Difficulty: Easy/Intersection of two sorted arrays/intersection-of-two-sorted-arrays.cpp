//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the intersection of two arrays.
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
      
      int n1 = arr1.size(), n2 = arr2.size();
      // brute force
    //   vector<int>ans;
    //   bool visited[n2] = {0};
    //   for(int i=0 ; i<n1 ; i++){
    //       for(int j=0 ; j<n2 ; j++){
    //           if(arr1[i]==arr2[j] && visited[j]==0){
    //               ans.push_back(arr1[i]);
    //               visited[j] = 1;
    //           }
              
    //           if(arr2[j]>arr1[i]){
    //               break;
    //           }
    //       }
          
    //   }
      
    //   return ans;
    
     int i=0, j=0;
     vector<int>ans;
     while(i<n1 && j<n2){
         if(arr1[i]<arr2[j]){
             i++;
         }
         else if(arr2[j]<arr1[i]){
             j++;
         }
         else {
             if(ans.size()==0 || ans.back()!=arr1[i])
             ans.push_back(arr1[i]);
             i++, j++;
         }
     }
     return ans;
    }
};

//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        vector<int> v;
        v = ob.intersection(arr1, arr2);

        if (v.size() > 0) {
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
        } else {
            cout << "[]";
        }

        cout << endl;
        // string tilde;
        // getline(cin, tilde);
    }

    return 0;
}

// } Driver Code Ends