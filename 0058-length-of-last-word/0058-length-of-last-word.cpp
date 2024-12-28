#include <cstring>
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(),len=0;
     int e = n-1;
     while(!isalnum(s[e])){
         --e;
     }
        for(int i=e;i>=0 && s[i]!=' ';i--){
           if(s[i]!=' '){
            len++;
           }
        }
        return len;
    }
};