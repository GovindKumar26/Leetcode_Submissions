class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       
    if (s1.length() > s2.length()) return false;
    
    vector<int> s1Count(26, 0), s2Count(26, 0);
    
    // Count frequency of each character in s1
    for (char c : s1) {
        s1Count[c - 'a']++;
    }
    
    // Use a sliding window to check substrings of length s1 in s2
    for (int i = 0; i < s2.length(); ++i) {
        s2Count[s2[i] - 'a']++;
        
        // Maintain the window size equal to s1's length
        if (i >= s1.length()) {
            s2Count[s2[i - s1.length()] - 'a']--;
        }
        
        // Compare counts
        if (s1Count == s2Count) return true;
    }
    
    return false;
 
}

    
};