class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //brute 
        // int n = nums.size();
        // vector<int>li;

        // for(int i=0 ; i<n  ;i++){
        //     if(li.size()==0 || li[0]!=nums[i]){
        //         int cnt = 0;
        //         for(int j=0 ; j<n ;j++)
        //             if(nums[i]==nums[j]) cnt++;

        //             if(cnt>n/3) li.push_back(nums[i]);
                
        //     }
        //     if(li.size()==2) break;
        // }
        // return li;

        //hashmap
        // int n = nums.size();
        // unordered_map<int, int>mp;

        // for(int i=0 ; i<n ; i++){
        //     mp[nums[i]]++;
        // }
        // vector<int>ans;
        // for(auto m : mp){
        //     if(m.second>n/3){
        //         ans.push_back(m.first);
        //     }
        // }
        // return ans;


        //Moore's voting algo for majority extended

        int cnt1 = 0, cnt2 = 0;
        int ele1=INT_MIN , ele2=INT_MIN;
        int n = nums.size();

        for(int i=0 ; i<n ; i++){
            if(cnt1==0 && ele2!=nums[i]){
                cnt1 = 1;
                ele1 = nums[i];
            } else if(cnt2==0 && ele1!=nums[i]){
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(ele1==nums[i]) cnt1++;
            else if(ele2==nums[i]) cnt2++;
            else{
                cnt1--, cnt2--;
            }
        }
     
        vector<int>ans;
        cnt1=0, cnt2=0;
        for(int i=0 ; i<n ; i++){
             if(nums[i]==ele1) cnt1++;
             if(nums[i]==ele2) cnt2++;
        }

        if (cnt1 > n / 3) ans.push_back(ele1);
        if (cnt2 > n / 3 && ele2 != ele1) ans.push_back(ele2);  

        return ans;
        
    }
};