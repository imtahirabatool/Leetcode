class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights){
        vector<string> result;
        vector<pair<int, string>> people;
        int n = names.size();

        for (int i = 0; i < n; ++i) {
            people.push_back({heights[i], names[i]});
        }

        sort(people.rbegin(), people.rend());

        for (const auto& person : people) {
            result.push_back(person.second);
        }

        return result;
    }
};