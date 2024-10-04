class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorResult = 0;
        for(auto i : nums){
            xorResult = xorResult^i;
        }
        return xorResult;


        // mapping
    //     map<long long, int> mp;
    //     for(int i=0 ; i<nums.size() ; i++){
    //         mp[nums[i]]++;
    //     }
    //    for(auto i : mp){
    //     if(i.second==1) return i.first;
    //    }
    //    return 0;
    }
};