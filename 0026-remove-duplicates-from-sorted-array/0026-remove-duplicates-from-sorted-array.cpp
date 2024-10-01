class Solution {
public:

    int setAprr(vector<int>&nums){
        set<int>st;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            st.insert(nums[i]);
        }
         int i=0;
        for(auto s : st){
            nums[i++] = s;
        }
        return i;
    }

    int twoPtr(vector<int>&arr){
        int n = arr.size();
        int i=0;
        for(int j=1 ; j<n ; j++){
            if(arr[j]!=arr[i]){
                arr[i+1] = arr[j];
                i++;
            }
        }
        return i+1;
    }
    int removeDuplicates(vector<int>& nums) {
    //  return setAprr(nums);
        return twoPtr(nums);


        int n =nums.size();
        vector<char>v(n,'_');
        int j=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
               v[j++] = nums[i];
            }
        }
        v[j++] = nums[n-1];
        int count=j;

            for(int i=0;i<count;i++){
                nums[i] = v[i];
            }
      return count;  
    }
};