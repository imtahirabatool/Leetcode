class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& a, int k) {
        for (int i = 0; i < k - 1; ++i)
            a.push_back(a[i]);
        int g = 0;
        for (int i = 1, w = 1, p = a[0]; i < a.size(); ++i) {
            w *= p != a[i];
            g += ++w >= k;
            p = a[i];
        }
        return g;
    }
};