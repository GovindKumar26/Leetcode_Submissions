class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
       
       
     map<int, int>mp; // xor and count
     int preXor = 0;
     long cnt = 0;
   //  mp[0] = 1;
     
     for(int i=0 ; i<arr.size() ; i++) {
         preXor = arr[i]^preXor;
         
         if(preXor==k) {
             cnt ++;
         }
         
         if(mp.find(preXor^k)!=mp.end()) {
             cnt = cnt + mp[preXor^k];
         }
         
        
         mp[preXor]++;
          
     }
     
     return cnt; 
     
    }
};