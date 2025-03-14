class Solution {
public:
    int maximumCandies(vector<int>& a, long long k) {
        const int n = a.size();

        const auto test = [&a, &n, &k](int x) {
            long p = 0;
            for (int i = 0; i < n; ++i)
                p += a[i] / x;
            return p >= k;
        };

        long s = 0;
        for (int i = 0; i < n; ++i)
            s += a[i];

        int i = 1;
        int j = s / k;
        if (j <= 1)
            return j;

        while (i <= j) {
            const int m = (i + j) / 2;
            if (test(m))
                i = m + 1;
            else
                j = m - 1;
        }
        return j;
    }
};