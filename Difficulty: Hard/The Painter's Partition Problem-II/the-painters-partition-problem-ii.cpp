//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int countStudents(vector<int>&arr, int pages){
      int student = 1; long long pagesAlloc = 0;
      for(int i=0 ; i<arr.size() ; i++){
          if(pagesAlloc+arr[i]<=pages){
              pagesAlloc = pagesAlloc + arr[i];
          }
          else{
              student++;
              pagesAlloc = arr[i];
          }
      }
      return student;
  }
    int findPages(vector<int> &arr, int k) {
       int n  = arr.size();
     //  if(k>n) return -1;
       
       int  low = *max_element(arr.begin(), arr.end());
       int high = accumulate(arr.begin(), arr.end(), 0);
       
       while(low<=high){
           int mid = (high-low)/2 + low;
           int students = countStudents(arr, mid);
           if(students>k){
               low = mid+1;
           }
           else{
               high = mid-1;
           }
       }
       return low;
    }
    long long minTime(vector<int>& arr, int k) {
       return findPages(arr, k);
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
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends