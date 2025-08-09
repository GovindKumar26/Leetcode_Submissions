class Solution {
  public:
  
  int merge(vector<int>&nums,int s,int mid,int e){
      int cnt=0;
      
        vector<int>res(e-s+1); int i=s,j=mid+1,k=0;

        while(i<=mid && j<=e){
            if(nums[i]<=nums[j]) { res[k++] = nums[i++]; }
            else {res[k++] = nums[j++];cnt += mid-i+1 ;}
        }

        while(i<=mid)  res[k++] = nums[i++];
        while(j<=e)  res[k++] = nums[j++];

        for(int i = 0;i<res.size();i++){
            nums[i+s] = res[i];
        }
        
        return cnt;
    }
        
        
        int mergeSort(vector<int>&nums,int s,int e){
            int cnt=0;
          if(s>=e) return cnt;

          int mid = s + (e-s)/2;
         cnt+= mergeSort(nums,s,mid);
         cnt+= mergeSort(nums,mid+1,e);
         cnt+= merge(nums,s,mid,e);
         return cnt;
      }


    int inversionCount(vector<int> &arr) {
       return mergeSort(arr, 0, arr.size()-1);
        
    }
};