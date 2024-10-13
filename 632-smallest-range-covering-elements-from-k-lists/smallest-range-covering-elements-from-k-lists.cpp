vector<pair<int, int>> mergeksortedlist(vector<vector<int>>& nums) {
    int n = nums.size();
    vector<pair<int, int>> op;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            op.push_back({nums[i][j], i});
        }
    }

    sort(op.begin(), op.end());
    return op;
}

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        v = mergeksortedlist(nums);

        int s = 0, e = 0;
        unordered_map<int, int> valid;
        int ans = INT_MAX;
        vector<int> range;
        int size = v.size();
        while (e < size) {
            valid[v[e].second]++;

            if (valid.size() == n) {
                while (valid.size() == n) {
                    valid[v[s].second]--;
                    if (valid[v[s].second] == 0)
                        valid.erase(v[s].second);
                    if (ans > v[e].first - v[s].first) {
                        range.clear();
                        range.push_back(v[s].first);
                        range.push_back(v[e].first);
                        ans = v[e].first - v[s].first;
                    }
                    s++;
                }
            }
            e++;
        }
        return range;
    }
};