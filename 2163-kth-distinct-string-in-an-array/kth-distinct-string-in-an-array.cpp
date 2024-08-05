class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        for (auto& s : arr) {
            ++map[s];
        }
        for (auto& s : arr) {
            if (map[s] == 1) {
                --k;
                if (k == 0)
                    return s;
            }
        }
        return "";
    }
};