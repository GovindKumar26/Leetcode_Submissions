//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
         int n = val.size();
    vector<Item> items;
    
    // Create a list of items with their values and weights
    for (int i = 0; i < n; ++i) {
        items.push_back(Item(val[i], wt[i]));
    }
    
    // Sort items by their value-to-weight ratio
    sort(items.begin(), items.end(), compare);
    
    double maxValue = 0.0;
    
    for (auto& item : items) {
        if (capacity >= item.weight) {
            // If the knapsack can take the whole item, take it
            capacity -= item.weight;
            maxValue += item.value;
        } else {
            // If the knapsack can't take the whole item, take the fraction
            maxValue += item.value * ((double)capacity / item.weight);
            break; // Knapsack is full
        }
    }
    
    return maxValue;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends