class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
         int freq[26] = {0};
        // Count frequency
        for (char c : s) 
            freq[c-'a']++;
        
        // Use a max-heap to hold char
        priority_queue<char> pq;
        for (int i=0; i<26; i++) {
            if (freq[i] > 0) 
                pq.emplace('a'+i);
        }
        
        string ans;
        ans.reserve(s.size());
                
        while (!pq.empty()) {
            char c=pq.top();
            pq.pop();
            
            // Add as many characters as possible (up to k)
            int f=freq[c-'a'];
            int use = min(f, repeatLimit);
            ans.append(use, c);
            f-= use;
            freq[c-'a'] = f;

            if (f > 0) {
                if (pq.empty()) 
                    break; // No other character to interleave
                
                // Use the next character in priority queue to interleave
                char c2= pq.top();
                ans.push_back(c2);
                int f2=--freq[c2-'a'];

                if (f2==0) pq.pop();

                // Re-add the original character 
                pq.emplace(c);
            }
        }
        
        return ans;
    }
};
