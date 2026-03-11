class Solution {
public:
    
    bool dfs(string recipe,
             unordered_map<string, vector<string>>& graph,
             unordered_set<string>& supplies,
             unordered_set<string>& visiting,
             unordered_map<string,bool>& memo) {

        if(memo.count(recipe)) return memo[recipe];

        if(visiting.count(recipe)) return false; // cycle

        visiting.insert(recipe);

        for(string &ing : graph[recipe]) {

            if(supplies.count(ing)) continue;

            if(!graph.count(ing) || !dfs(ing, graph, supplies, visiting, memo))
                return memo[recipe] = false;
        }

        visiting.erase(recipe);

        supplies.insert(recipe); // now available as supply
        return memo[recipe] = true;
    }

    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& suppliesList) {

        unordered_map<string, vector<string>> graph;

        for(int i=0;i<recipes.size();i++)
            graph[recipes[i]] = ingredients[i];

        unordered_set<string> supplies(suppliesList.begin(), suppliesList.end());

        unordered_set<string> visiting;
        unordered_map<string,bool> memo;

        vector<string> ans;

        for(string &recipe : recipes) {
            if(dfs(recipe, graph, supplies, visiting, memo))
                ans.push_back(recipe);
        }

        return ans;
    }
};