class Counter {
    int cnt[3] = {};

public:
    Counter(const string& s) {
        for (char ch : s)
            (*this)[ch]++;
    }
    int& operator[](char ch) { return cnt[ch - 'a']; }
    int min() const { return *min_element(cnt, cnt + 3); }
};

class Solution {
public:
    int takeCharacters(const string& s, const int& k) {
        Counter c(s);
        if (c.min() < k)
            return -1;

        int n = s.size(), res = n;
        for (int i = 0, l = 0; i < n; i++) {
            c[s[i]]--;
            while (c.min() < k)
                c[s[l++]]++;
            res = min(res, n - (i - l + 1));
        }
        return res;
    }
};