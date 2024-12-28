class Solution {
public:
    int romanToInt(string s) {
       string roman = {'I','V','X','L','C','D','M'};
        vector<int> number = {1,5,10,50,100,500,1000};
        int ans = 0,num;

       for(int i = 0 ; i<s.size()-1 ; i++){
        char ch = s[i];
        char next = s[i+1];
        int j = roman.find(ch);
        int curr = number[j];
        int nex = roman.find(next);
        int currnext = number[nex];


        if(currnext>curr){
            num = -1*curr ;
            ans = ans + num;
           
        } else {
              num = curr;
              ans = ans + num;
                
        }
        
       
       }
     
     int last = roman.find(s[s.size()-1]);
     int la  = number[last];
     ans = ans + la;

       return ans;
        
    }
};