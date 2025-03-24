class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ps = 0, pe = 0, ans = 0;
        for (auto& x : meetings) {
            if (pe + 1 < x[0])
                ans += (x[0] - pe - 1);
            pe = max(pe, x[1]);
        }
        if (days > pe)
            ans += (days - pe);
        return ans;
    }
};