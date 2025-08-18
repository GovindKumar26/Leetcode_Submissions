class Solution {
public:
    bool rotateString(string s, string goal) {

        //brute force
        int n = s.length();
        int k = s.length();
        
        while(k--) {
            char a = s[0];
            for(int i=0 ; i<s.length()-1 ; i++) {
                s[i] = s[i+1];
            }
            s[n-1] = a;
          

            if(s==goal) return true;
        }

        return false;


        //optimal if goal is a rotation of s, then s+s will contain goal.

         if (s.length() != goal.length()) return false;
        return (s + s).find(goal) != string::npos;




    }
};