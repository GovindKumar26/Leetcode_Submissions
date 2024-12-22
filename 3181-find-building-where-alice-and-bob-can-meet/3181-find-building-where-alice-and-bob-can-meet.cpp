class Solution {
public:
    // gives tle
    // int findY(int i, int j, vector<int>& heights) {
    //     int n = heights.size();
    //     int alice = heights[i], bob = heights[j];

    //     if (i == j)
    //         return i;

    //     if (i < j) {
    //         if (bob > alice) {
    //             return j;
    //         } else if (bob <= alice) {
    //             int c = j + 1;
    //             while (c < n) {
    //                 if (heights[c] <= bob || heights[c] <=alice)
    //                     c++;
    //                else if (heights[c] > bob && heights[c] > alice)
    //                     return c;
    //             }
    //             return -1;
    //         }
    //     }

    //     else if (i > j) {
    //         return findY(j, i, heights);
    //     }

    //     return -1;
    // }


int search(int height, vector<pair<int, int>>& monoStack) {
        int left = 0;
        int right = monoStack.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (monoStack[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return ans;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {

       

   vector<pair<int, int>> monoStack;
        vector<int> result(queries.size(), -1);
        vector<vector<pair<int, int>>> newQueries(heights.size());
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) swap(a, b);
            if (heights[b] > heights[a] || a == b)
                result[i] = b;
            else
                newQueries[b].push_back({heights[a], i});
        }

        for (int i = heights.size() - 1; i >= 0; i--) {
            int monoStackSize = monoStack.size();
            for (auto& [a, b] : newQueries[i]) {
                int position = search(a, monoStack);
                if (position < monoStackSize && position >= 0)
                    result[b] = monoStack[position].second;
            }
            while (!monoStack.empty() && monoStack.back().first <= heights[i])
                monoStack.pop_back();
            monoStack.push_back({heights[i], i});
        }
        return result;

            // int n = heights.size();
            // vector<int> nextGreater = preprocessNextGreater(heights);

            // vector<int> result;
            // for (auto& query : queries) {
            //     int idx = findY(query[0], query[1], heights, nextGreater);
            //     result.push_back(idx);
            // }
            // return result;
      
    }

    // vector<int> preprocessNextGreater(vector<int>& heights) {
    //     int n = heights.size();
    //     vector<int> nextGreater(n,
    //                             -1); // Initialize with -1 (no greater
    //                             element)
    //     stack<int> st;

    //     for (int i = 0; i < n; i++) {
    //         // Maintain the stack in decreasing order
    //         while (!st.empty() && heights[st.top()] < heights[i]) {
    //             nextGreater[st.top()] = i;
    //             st.pop();
    //         }
    //         st.push(i);
    //     }

    //     return nextGreater;
    // }

    // int findY(int i, int j, vector<int>& heights, vector<int>&
    // nextGreater) {
    //     if (i > j) {
    //         // Swap to always move forward in the array
    //         swap(i, j);
    //     }

    //     if (i == j)
    //         return i; // Same building case

    //     int alice = heights[i], bob = heights[j];

    //     if (alice < bob) {
    //         // Alice is shorter than Bob, return Bob's index
    //         return j;
    //     } else {
    //         // Find next taller building compared to Alice
    //         int idx = nextGreater[j];
    //         while (idx != -1 && heights[idx] <= alice) {
    //             idx = nextGreater[idx];
    //         }
    //         return idx; // -1 if no valid building is found
    //     }
    // }
};