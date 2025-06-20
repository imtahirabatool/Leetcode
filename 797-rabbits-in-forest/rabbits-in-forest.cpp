class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> map;

        for (int num : answers) {
            map[num]++;
        }

        for (auto& p : map) {
            res += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
        }
        return res;
    }
};