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
       if(k>n) return -1;
       
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
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, k);
    }
};