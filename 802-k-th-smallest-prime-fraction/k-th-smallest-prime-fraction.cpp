class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
        int n = A.size();
        auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
            return A[a.first] * A[b.second] > A[b.first] * A[a.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n - 1; ++i) {
            pq.emplace(i, n - 1);
        }
        while (--k) {
            auto [i, j] = pq.top();
            pq.pop();
            if (j - 1 > i) {
                pq.emplace(i, j - 1);
            }
        }
        return {A[pq.top().first], A[pq.top().second]};
    }
};