class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mao;
        vector<string> res;
        for (int i = 0; i < size(names); i++)
            mao[heights[i]] = names[i];
        for (auto i = mao.rbegin(); i != mao.rend(); ++i)
            res.push_back(i->second);
        return res;
    }
};