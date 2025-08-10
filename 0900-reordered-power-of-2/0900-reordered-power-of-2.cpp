class Solution {
public:
    string sortDigits(int x) {
        string s = to_string(x);
        sort(s.begin(), s.end());
        return s;
    }
    
    bool reorderedPowerOf2(int n) {
        string target = sortDigits(n);
        for (int i = 0; i < 31; i++) { // 2^0 to 2^30
            if (target == sortDigits(1 << i))
                return true;
        }
        return false;
    }
};
