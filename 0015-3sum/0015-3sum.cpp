class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> set1;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        for (; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {

                if (nums[i] + nums[j] + nums[k] == 0) {
                    set1.insert({nums[i], nums[k], nums[j]});
                    j++;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    k--;                   
                    while(j<k && nums[k]==nums[k+1]) k--;

                } else if (nums[i] + nums[k] + nums[j] > 0) {
                    k--;
                } else
                    j++;
            }
        }
        for (auto s : set1) {
            ans.push_back(s);
        }
        return ans;

        //brute
        // int n = nums.size();
        // set<vector<int>>st;
        // for(int i=0 ; i<n ; i++){
        //     for(int j=i+1 ; j<n ; j++){
        //         for(int k = j+1 ; k<n ; k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 vector<int>temp = {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }

        // vector<vector<int>>ans(st.begin(), st.end());
      
        // return ans;
    }
};