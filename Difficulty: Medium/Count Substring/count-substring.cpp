class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        // // int n = s.length(), l = 0, r = 0;
        // // unordered_map<char, int>mpp;
        // // int cnt=0;

        // // while(r<n){
        // //     mpp[s[r]]++;
        // //     while(mpp.size()==3){
        // //      cnt++;
        // //      cnt = cnt + n - 1 - r;
                
        // //         mpp[s[l]]--;
        // //         if(mpp[s[l]]==0) mpp.erase(s[l]);
        // //         l++;
        // //     }
        // //     r++;
        // // }
        // // return cnt;


        vector<int> arr(3,-1);
        int count=0;
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']=i;
    
            int minInd = min(min(arr[0],arr[1]), arr[2]);
            count += 1+minInd;
            
        }
        return count; 
    }
};