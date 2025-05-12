class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> map;
        vector<string> res;
        for (int i = 0; i < size(names); i++)
            map[heights[i]] = names[i];
        for (auto i = map.rbegin(); i != map.rend(); ++i)
            res.push_back(i->second);
        return res;
    }
};