class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;

        for (auto& interval : intervals) {
            events.push_back({interval[0], 1});
            events.push_back({interval[1] + 1, -1});
        }

        sort(events.begin(), events.end());
        int max_groups = 0, curr_groups = 0;

        for (auto& event : events) {
            curr_groups += event.second;
            max_groups = max(max_groups, curr_groups);
        }

        return max_groups;
    }
};