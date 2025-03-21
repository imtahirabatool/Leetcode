class Solution {
    set<string> available;
    map<string, int> recipeIndex;

public:
    bool isAvailable(string& s) { return available.find(s) != available.end(); }
    bool isRecipe(string& s, set<string>& recipes) {
        return recipes.find(s) != recipes.end();
    }

    bool helper(set<string>& recipes, set<string>& visited,
                vector<vector<string>>& ingredients, string& recipe) {
        if (isAvailable(recipe)) return true;
        if (visited.find(recipe) != visited.end()) return false;

        visited.insert(recipe);

        if (!isRecipe(recipe, recipes)) return false;

        bool ans = true;
        for (auto& x : ingredients[recipeIndex[recipe]]) {
            if (isAvailable(x))
                continue;
            else {
                if (visited.find(x) != visited.end())
                    return false;
                else {
                    ans = ans && helper(recipes, visited, ingredients, x);
                    if (ans)
                        available.insert(x);
                    else
                        return false;
                }
            }
        }
        return ans;
    }

    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        available.clear();
        recipeIndex.clear();
        set<string> visited, recipeSet;

        for (int i = 0; i < recipes.size(); i++) {
            recipeSet.insert(recipes[i]);
            recipeIndex[recipes[i]] = i;
        }
        for (auto& x : supplies)
            available.insert(x);

        for (auto& x : recipes) {
            if (isAvailable(x))
                continue;
            else {
                bool check = helper(recipeSet, visited, ingredients, x);
                if (check)
                    available.insert(x);
            }
        }

        vector<string> ans;

        for (auto& x : recipes) {
            if (isAvailable(x))
                ans.push_back(x);
        }

        return ans;
    }
};