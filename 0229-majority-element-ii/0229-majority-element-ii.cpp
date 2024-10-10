class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //brute 
        int n = nums.size();
        vector<int>li;

        for(int i=0 ; i<n  ;i++){
            if(li.size()==0 || li[0]!=nums[i]){
                int cnt = 0;
                for(int j=0 ; j<n ;j++)
                    if(nums[i]==nums[j]) cnt++;

                    if(cnt>n/3) li.push_back(nums[i]);
                
            }
            if(li.size()==2) break;
        }
        return li;
    }
};