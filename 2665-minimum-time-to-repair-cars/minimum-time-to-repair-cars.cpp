class Solution {
public:
    bool check(long long m, vector<int>& ranks, int cars) {
        long long no = 0;
        for (long long i = 0; i < ranks.size(); i++) {
            long long c = sqrt((long long)m / (long long)ranks[i]);
            no += c;
            if (no >= cars) {
                return true;
            }
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        long long r =
            1LL * (*max_element(ranks.begin(), ranks.end())) * cars * cars;
        long long ans = 0;
        while (r >= l) {
            long long m = l + (r - l) / 2;
            if (check(m, ranks, cars)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};