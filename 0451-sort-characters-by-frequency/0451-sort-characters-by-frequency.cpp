class Solution {
public:
    string frequencySort(string s) {
        // vector<int> countFreq(256, 0);

        // for (int i = 0; i < s.length(); i++) {
        //     countFreq[s[i]]++;
        // }

        // priority_queue<pair<int, int>> pq; // Max-heap by default

        // string ans = "";

        // for (int i = 0; i < 256; i++) {
        //     pq.push({countFreq[i], i});
        // }

        // while (!pq.empty()) {
        //     char ele = pq.top().second ;
        //     int freq = pq.top().first;
        //     pq.pop();

        //     while (freq--)
        //         ans += ele;
        // }
        // return ans;

         unordered_map<char, int> freq;  // Frequency map for all characters

        // Count frequencies
        for (char c : s) {
            freq[c]++;
        }

        // Max-heap: pair<frequency, character>
        priority_queue<pair<int, char>> pq;
        for (auto &p : freq) {
            pq.push({p.second, p.first});
        }

        string ans = "";

        // Build result string
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();

            ans.append(count, ch);  // append 'ch' 'count' times
        }

        return ans;
    }
};