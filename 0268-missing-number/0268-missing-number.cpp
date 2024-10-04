class Solution {
public:
    int missingNumber(vector<int>& nums) {
    //  hashing approach
    //   int n = nums.size();
    //     vector<int>hash(n+1, 0);

    //     for(int i=0 ; i<n ; i++){
    //         hash[nums[i]] = 1;
    //     }

    //     for(int i=1 ; i<=n ; i++){
    //         if(hash[i]==0) return i;
    //     }
    // return 0;

    // sum method
    int sum = 0;
  
    int n = nums.size();
   int sumTot = n*(n+1)/2;

    for(auto i : nums){
        sum = i+sum;
    }
    return sumTot-sum;
    }
};